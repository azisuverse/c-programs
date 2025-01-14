#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to send an HTTP response with the given content
void handle_response(int client_socket, const char *body,
                     const char *content_type) {
  char response[BUFFER_SIZE];

  // Create the response string including the body and headers
  snprintf(response, sizeof(response),
           "HTTP/1.1 200 OK\r\n"
           "Content-Type: %s\r\n"
           "Connection: close\r\n"
           "Content-Length: %zu\r\n"
           "\r\n"
           "%s",
           content_type, strlen(body), body);

  // Send the response to the client
  send(client_socket, response, strlen(response), 0);
}

// Function to handle the /api endpoint
void handle_api(int client_socket) {
  const char *response_body = "{\"message\": \"Hello from API endpoint!\"}";
  handle_response(client_socket, response_body, "application/json");
}

// Function to handle the /hello endpoint
void handle_hello(int client_socket) {
  const char *response_body =
      "{\"message\": \"Hello, Welcome to our server!\"}";
  handle_response(client_socket, response_body, "application/json");
}

// Function to handle the /goodbye endpoint
void handle_goodbye(int client_socket) {
  const char *response_body = "{\"message\": \"Goodbye! Have a great day!\"}";
  handle_response(client_socket, response_body, "application/json");
}

// Function to handle the 404 Not Found case
void handle_not_found(int client_socket) {
  const char *response_body = "{\"error\": \"404 Not Found\", \"message\": "
                              "\"The requested resource could not be found.\"}";
  handle_response(client_socket, response_body, "application/json");
}

// Struct to map request paths to handler functions
typedef struct {
  const char *path;
  void (*handler)(int);
} Route;

// Array of routes to handle requests
Route routes[] = {{"/api", handle_api},
                  {"/api/hello", handle_hello},
                  {"/api/goodbye", handle_goodbye}};

// Number of routes in the array
#define NUM_ROUTES (sizeof(routes) / sizeof(routes[0]))

// Function to process the incoming HTTP request and route to the appropriate
// handler
void handle_request(int client_socket, const char *request) {
  for (int i = 0; i < NUM_ROUTES; ++i) {
    // If the request path matches a route, call the corresponding handler
    if (strstr(request, routes[i].path) == request) {
      routes[i].handler(client_socket);
      return;
    }
  }
  // If no route matches, return 404 Not Found
  handle_not_found(client_socket);
}

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buffer[BUFFER_SIZE];

  // Create a socket for the server
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Bind the socket to the address and port
  if (bind(server_socket, (struct sockaddr *)&server_addr,
           sizeof(server_addr)) < 0) {
    perror("Bind failed");
    close(server_socket);
    exit(EXIT_FAILURE);
  }

  // Listen for incoming client connections
  if (listen(server_socket, 5) < 0) {
    perror("Listen failed");
    close(server_socket);
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", PORT);

  // Wait for and accept incoming client connections
  while (1) {
    client_socket =
        accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
    if (client_socket < 0) {
      perror("Accept failed");
      close(server_socket);
      exit(EXIT_FAILURE);
    }

    // Read the request from the client
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
      perror("recv failed");
      close(client_socket);
      continue;
    }

    buffer[bytes_received] = '\0'; // Null-terminate the request

    // Process the request based on its path
    handle_request(client_socket, buffer);

    // Close the client socket after the response is sent
    close(client_socket);
  }

  close(server_socket);
  return 0;
}
