#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <vector>

using namespace std;

class UDPServer
{
public:
    explicit UDPServer();
    virtual ~UDPServer();
    UDPServer(int port);

    int init();
    int receive(char *receivedMessage, int length);
    vector <unsigned char> receive();
    int sendReplyMessage(char *replyMessage);
    char *getClientIP();
    char *getReceivedMessage();

public:
    static const int BUFLEN = 256;

private:
    int m_port;
    int m_socketFileDescriptor;
    struct sockaddr_in m_serverAddress, m_clientAddres;
    socklen_t client;
    char buffer[BUFLEN];
};

#endif // UDPSERVER_H
