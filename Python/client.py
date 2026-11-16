import socket

HOST = "127.0.0.1"
PORT = 65432

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as client_sock :
    print(f"[Client] Connecting to {HOST}:{PORT}...")
    client_sock.connect((HOST,PORT))
    print(f"[Client] Connected Successfully!\n")
    
    while True:
        msg = input("Enter message (or 'exit'): ")
        if not msg.strip():
            print("[Client] (Empty input skipped)")
            continue
        if msg.strip().lower() == "exit" :
            print("[Client] Exiting.")
            break

        print(f"[Client] Sending: '{msg}'...")
        client_sock.sendall(msg.encode("utf-8"))
        
        print("[Client] Waiting for response...")
        reply = client_sock.recv(1024)
        print(f"[Server Echoed] : {reply.decode('utf-8')}")
