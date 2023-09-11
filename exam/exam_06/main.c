#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


typedef struct s_client {
  int id;
  char buff[1024];
} t_client;

t_client clients[1024];
fd_set readFds, writeFds, setFds;
int maxFd = 0;
int nextId = 0;
char readBuffer[150000];
char writeBuffer[150000];

void fatalError(const char *str) {
  if (str) {
    write(2, str, strlen(str));
  } else {
    write(2, "fatal error\n", strlen("fatal error\n"));
  }
  exit(1);
}

void broadcast(int curFd) {
  for (int i = 0; i <= maxFd; ++i) {
    if (FD_ISSET(i, &writeFds) && i != curFd) {
      send(i, writeBuffer, strlen(writeBuffer), 0);
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fatalError(NULL);
  }

  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket < 0) {
    fatalError(NULL);
  }
  maxFd = serverSocket;

  FD_ZERO(&setFds);
  FD_SET(serverSocket, &setFds);
  bzero(&clients, sizeof(clients));

  struct sockaddr_in serverAddr;
  socklen_t len;
  bzero(&serverAddr, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = htonl(2130706433);
  serverAddr.sin_port = htons(atoi(argv[1]));

  if (bind(serverSocket, (const struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
    fatalError(NULL);
  }
  if (listen(serverSocket, 1024) < 0) {
    fatalError(NULL);
  }

  while (1) {
    readFds = writeFds = setFds;
    if (select(maxFd + 1, &readFds, &writeFds, NULL, NULL) < 0) {
      fatalError(NULL);
    }
    for (int fd = 0; fd <= maxFd; ++fd) {
      if (FD_ISSET(fd, &readFds) && fd == serverSocket) {
        int clientSocket = accept(serverSocket, (struct sockaddr*)&serverAddr, &len);
        if (clientSocket < 0) {
          fatalError(NULL);
        }
        maxFd = (clientSocket > maxFd) ? clientSocket : maxFd;
        clients[clientSocket].id = nextId++;
        FD_SET(clientSocket, &setFds);
        sprintf(writeBuffer, "server: client %d just arrived\n", clients[clientSocket].id);
        broadcast(fd);
      } else if (FD_ISSET(fd, &readFds) && fd != serverSocket) {
        int readCnt = recv(fd, readBuffer, sizeof(readBuffer), 0);
        if (readCnt <= 0) {
          sprintf(writeBuffer, "server: client %d jus left\n", clients[fd].id);
          broadcast(fd);
          FD_CLR(fd, &setFds);
          close(fd);
        } else {
          for (int i = 0, j = strlen(clients[fd].buff); i < readCnt; ++i, ++j) {
            clients[fd].buff[j] = readBuffer[i];
            if (clients[fd].buff[j] == '\n') {
              clients[fd].buff[j] = '\0';
              sprintf(writeBuffer, "client %d: %s\n", clients[fd].id, clients[fd].buff);
              broadcast(fd);
              bzero(&clients[fd].buff, sizeofd(clients[fd].buff));
              j = -1;
            }
          }
        }
      }
    }
  }
  return 0;
}