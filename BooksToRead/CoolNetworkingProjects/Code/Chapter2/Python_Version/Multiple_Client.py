import socket
import threading

target_host = "127.0.0.1"
target_port = 9997

def make_request(i):
    try:
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client.connect((target_host, target_port))
        print(f"[Test Client {i}] Connected")

        # ✅ Send first
        print(f"[Test Client {i}] Sending Data")
        client.send(f"Testing Client {i}".encode())

        # ✅ Then receive response
        response = client.recv(4096)
        print(f"[Test Client {i}] Received: {response.decode()}")

        client.close()
    except Exception as e:
        print(f"[Test Client {i}] Failed to connect: {e}")

# Launch 10 clients
for i in range(10):
    t = threading.Thread(target=make_request, args=(i,))
    t.start()
