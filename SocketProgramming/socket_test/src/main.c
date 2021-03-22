#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

short socketCreate(void) {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreateSocket(int hSocket) {
    int iRetval = -1;
    int clientPort = 4949;
    struct sockaddr_in remote = {0};

    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort);
    iRetval = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;


int main(void) {
    int socket_desc, sock, clientLen, read_size;
    struct sockaddr_in server, client;

    char client_message[200] = {0};
    char message[100] = {0};
    const char *pMessage = "hello there\n";

    socket_desc = SocketCreate();

    if (socket_desc == -1) {
        
    }
}
