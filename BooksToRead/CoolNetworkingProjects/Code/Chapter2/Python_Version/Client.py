import socket
import time

target_host = "127.0.0.1"
target_port = 9997

# create a socket object
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# connect the client
client.connect((target_host, target_port))

# send some data (make sure it's in bytes)
# client.send(b"GET / HTTP/1.1\r\nHost: google.com\r\n\r\n")
time.sleep(5)
print("Slept for 5 Seconds")
client.send(b"Hello Server after 5 Seconds")

# receive some data
response = client.recv(4096)

print(response.decode())  # decode bytes to string