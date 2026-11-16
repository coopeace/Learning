import os
import readline
import socket
import sys
import threading

HOST = "127.0.0.1"
PORT = 65432

def receive_messages(sock):
    while True:
        try :
            data = sock.recv(1024)
            if not data:
                sys.stdout.write("\r\033[2K[Client] Disconnected from server.\n")
                sys.stdout.flush()
                os._exit(0)

            incoming = data.decode("utf-8")

            current_line = readline.get_line_buffer()

            sys.stdout.write(f"\r\033[2k{incoming}\nYou : {current_line}")
            sys.stdout.flush()

        except OSError:
            break

def main():
    username = input("Enter a username: ").rstrip("\r\n")
    if not username:
        print("Username cannot be blank")
        return

    sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    try:
        sock.connect((HOST,PORT))
    except ConnectionRefusedError:
        print("[Client] Could not connect. Is the server running?")
        return

    # Send Username
    sock.sendall(username.encode("utf-8"))
    print(f"[Client] Connected as '{username} . Type message and hit Enter. \n")
    
    recv_thread = threading.Thread(
            target=receive_messages,args=(sock,), daemon=True
            )
    
    recv_thread.start()

    try :
        while True :
            msg = input("You: ").rstrip("\r\n")
            if not msg:
                continue
            if msg.lower() == "/exit":
                break
            sock.sendall(msg.encode("utf-8"))
    except (KeyboardInterrupt,EOFError):
        pass
    finally:
        sock.close()
        print("\n [Client] Exited chat:")

if __name__ == "__main__":
    main()
