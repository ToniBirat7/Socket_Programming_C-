import socket

SERVER_IP = "0.0.0.0"
PORT = 8080
BUFFER_SIZE = 1024

# Create and bind the server socket using 'with' to ensure proper cleanup
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.bind((SERVER_IP, PORT))
    server_socket.listen(3)
    print(f"Server listening on {SERVER_IP}:{PORT}...")

    # Accept a client connection
    client_socket, client_address = server_socket.accept()
    with client_socket:  # Ensure the client socket is also closed properly
        print(f"Client connected from {client_address}")

        # Receive data from the client
        data = client_socket.recv(BUFFER_SIZE).decode()
        print(f"Message received: {data}")

        # Send response to the client
        response = "Hello from server"
        client_socket.send(response.encode())
        print("Response sent to client.")

print("Connection closed.")
