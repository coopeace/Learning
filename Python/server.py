import socket

HOST = "127.0.0.1"
PORT = 65432

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as server_sock :
    server_sock.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)

    server_sock.bind((HOST,PORT))
    server_sock.listen()
    print(f"[Server] Listening of {HOST}:{PORT}...")
    conn,addr = server_sock.accept()
    with conn:
        print(f"[Server] Connected by {addr}")
        while True:
            data = conn.recv(1024)
            if not data:
                print("[Server] Client disconnected")
                break

            message = data.decode("utf-8")
            print(f"[Server Received] : {message}")

            response = f"ECHO: {message.upper()}".encode("utf-8")
            conn.sendall(response)

