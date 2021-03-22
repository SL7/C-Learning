#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(void) {
    int sock; 
    unsigned long addr;
    struct sockaddr_in server;
    memset(&server, 0, sizeof(struct sockaddr_in)); 
    addr = inet_addr("www.google.com");
    memcpy((char *) &server.sin_addr, &addr, sizeof(addr));
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock < 0) {
        printf("[-] Failed to init socket.\n");
        exit(0);
    }

    if (connect(sock, (struct sockaddr*) &server, sizeof(server)) >= 0) {
        printf("[+] Connection successful\n");
    } else {
        printf("[-] Connection failed\n");
        exit(0);
    }
}
