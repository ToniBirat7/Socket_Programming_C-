// Cross-Platform TCP Server (server.cpp)

#if defined(_WIN32) || defined(_WIN64)
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#endif

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
// Platform-specific socket startup for Windows
#if defined(_WIN32) || defined(_WIN64)
  WSADATA wsaData;
  int wsaInit = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (wsaInit != 0)
  {
    cerr << "WSAStartup failed with error: " << wsaInit << endl;
    return -1;
  }
#endif

  // Creating a TCP socket
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0)
  {
    perror("Socket creation failed");
    return -1;
  }

  // Setting up server address
  sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(8080);

  // Binding the socket
  if (bind(server_fd, (sockaddr *)&server_addr, sizeof(server_addr)) < 0)
  {
    perror("Bind failed");
#if defined(_WIN32) || defined(_WIN64)
    closesocket(server_fd);
    WSACleanup();
#else
    close(server_fd);
#endif
    return -1;
  }

  // Listening for incoming connections
  if (listen(server_fd, 3) < 0)
  {
    perror("Listen failed");
    return -1;
  }
  cout << "Server listening on port 8080..." << endl;

  // Accepting a client connection
  sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_fd = accept(server_fd, (sockaddr *)&client_addr, &client_addr_len);
  if (client_fd < 0)
  {
    perror("Accept failed");
    return -1;
  }
  cout << "Client connected." << endl;

  // Receiving data from client
  char buffer[1024] = {0};
  int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
  if (bytes_received > 0)
  {
    cout << "Message received: " << buffer << endl;
  }

  // Sending response to client
  const char *message = "Hello from server";
  send(client_fd, message, strlen(message), 0);
  cout << "Response sent to client." << endl;

// Closing the connection
#if defined(_WIN32) || defined(_WIN64)
  closesocket(client_fd);
  closesocket(server_fd);
  WSACleanup();
#else
  close(client_fd);
  close(server_fd);
#endif

  return 0;
}