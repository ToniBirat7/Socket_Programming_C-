import socket

SERVER_IP = "127.0.0.1"
PORT = 8080
BUFFER_SIZE = 1024

# Use 'with' to ensure the client socket is properly closed
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
    # Connect to the server
    client_socket.connect((SERVER_IP, PORT))
    print(f"Connected to server at {SERVER_IP}:{PORT}")

    # Send data to the server
    message = "Hello from client"
    client_socket.send(message.encode())
    print("Message sent to server.")

    # Receive response from the server
    data = client_socket.recv(BUFFER_SIZE).decode()
    print(f"Response from server: {data}")

print("Connection closed.")
