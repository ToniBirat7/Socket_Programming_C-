import socket
import threading

bind_ip = "0.0.0.0"
bind_port = 9997

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 🔑 Allow address reuse
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

server.bind((bind_ip,bind_port))
server.listen(5)

print("[*] Listening on %s:%d" % (bind_ip,bind_port))

# this is our client-handling thread

def handle_clinet(client_socket):

  # print out what the client sends
  request = client_socket.recv(1024)

  print("[*] Received: %s" % request)

  # send back a packet
  client_socket.send(b"ACK!")

  client_socket.close()

while True:
  client,addr = server.accept()
  print("[*] Accepted connection from: %s:%d" % (addr[0],addr[1]))

  # spin up our client thread to handle incoming data
  clinet_handler = threading.Thread(target=handle_clinet,args=(client,))

  clinet_handler.start()