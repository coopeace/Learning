import socket
import threading

HOST = "127.0.0.1"
PORT = 65432

clients = {}
clients_lock = threading.Lock()

def broadcast(message : str , sender_sock = None):
    """Send a message to all connected clients except the sender."""
    with clients_lock :
        for client_sock in list(clients.keys()) :
            if client_sock != sender_sock :
                try :
                    client_sock.sendall(message.encode("utf-8"))
                except OSError :
                    client_sock.close()
                    del clients[client_sock]

def handle_client(client_sock,client_addr):
    """Runs in a dedicated thread for each connected client"""
    username = "Anonymous"
    try :
        username = client_sock.recv(1024).decode("utf-8").rstrip("\r\n")
        if not username:
            client_sock.close()
            return
        
        with clients_lock:
            clients[client_sock] = username

        welcome_msg = f"[System] {username} join the chatroom!"
        print(f"{welcome_msg} ({client_addr})")
        broadcast(welcome_msg,sender_sock=client_sock)
        
        # Message Loop
        while True:
            data = client_sock.recv(1024)
            if not data:
                break

            text = data.decode("utf-8").rstrip("\r\n")
            if text:
                broadcast(f"{username} : {text}" ,sender_sock=client_sock)

    except ConnectionResetError :
        pass
    
    finally :
        with clients_lock :
            if client_sock in clients :
                del clients[client_sock]
        client_sock.close()

        leave_msg = f"[System] {username} left the chatroom"
        print(leave_msg)
        broadcast(leave_msg)


def main():
    try :
        with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as server_sock :
            server_sock.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
            server_sock.bind((HOST,PORT))
            server_sock.listen()
            print(f"[Server] Chat server running on {HOST}:{PORT}....")

            while True:
                conn,addr = server_sock.accept()
                thread = threading.Thread(
                        target=handle_client,args=(conn,addr),daemon=True
                        )
                thread.start()
    except KeyboardInterrupt :
        pass
    finally :
        print(f"\r[Server] Chat server is closed.")

if __name__ == "__main__":
    main()
