// Cross-Platform TCP Client (client.cpp)

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
#if defined(_WIN32) || defined(_WIN64)
  WSADATA wsaData;
  int wsaInit = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (wsaInit != 0)
  {
    cerr << "WSAStartup failed with error: " << wsaInit << endl;
    return -1;
  }
#endif

  int client_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (client_fd < 0)
  {
    perror("Socket creation failed");
    return -1;
  }

  sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  if (connect(client_fd, (sockaddr *)&server_addr, sizeof(server_addr)) < 0)
  {
    perror("Connection failed");
    return -1;
  }
  cout << "Connected to server." << endl;

  const char *message = "Hello from client";
  send(client_fd, message, strlen(message), 0);
  cout << "Message sent to server." << endl;

  char buffer[1024] = {0};
  int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
  if (bytes_received > 0)
  {
    cout << "Response from server: " << buffer << endl;
  }

#if defined(_WIN32) || defined(_WIN64)
  closesocket(client_fd);
  WSACleanup();
#else
  close(client_fd);
#endif

  return 0;
}