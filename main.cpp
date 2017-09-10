#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Server 1: " << endl;
    int sockFD, port;
    socklen_t client;
    char buffer[256];
//    declare serv_addr and cli_addr struct to deal with the internet addresses
    struct sockaddr_in serv_addr, cli_addr;


    sockFD = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockFD < 0){
        printf("ERROR: Cannot opening a socket file descriptor");
        return -1;
    }
// set value of serv_addr struct to 0, not important
    bzero((char *) &serv_addr, sizeof(serv_addr));

    port = 3000;

//    setup the host_addr structure for using in bind call
//    server byte order
    serv_addr.sin_family = AF_INET;
//    automatically be filled with the current host's IP address (127.0.0.1)
    serv_addr.sin_addr.s_addr = INADDR_ANY;
//    convert port value (unsigned integer) into network byte order -- big-endian
    serv_addr.sin_port = htons(port);

    if(bind(sockFD, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0 ){
        printf("ERROR: Cannot bind unix file descriptor in to port");
        return -1;
    }

    listen(sockFD, 5);
    client = (socklen_t) sizeof(cli_addr);
    while(true){
        int rc = recvfrom(sockFD, buffer, sizeof(buffer), 0, (struct sockaddr *) &cli_addr, &client);
        if(rc < 0){
            printf("ERROR: Cannot reading from socket");
        }else{
            cout << "server has been received messaage: " << buffer << endl;
        }
        char *replyMessage = "reply message";
        int rp = sendto(sockFD, replyMessage, strlen(replyMessage), 0, (struct sockaddr *)&cli_addr, client);
        if(rp < 0){
            printf("ERROR: Cannot writting to socket");
        }
    }
    return 0;
}
