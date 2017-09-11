#include "udpserver.h"

UDPServer::UDPServer()
{
    bzero((char *) &m_serverAddress, sizeof(m_serverAddress));
}

UDPServer::~UDPServer(){

}

UDPServer::UDPServer(int port){
    m_port = port;
    bzero((char *) &m_serverAddress, sizeof(m_serverAddress));
}

int UDPServer::receive(char *receivedMessage, int length){
    return 0;
}

vector<unsigned char> UDPServer::receive(){
    vector<unsigned char> res;
    return res;
}

int UDPServer::sendReplyMessage(char *replyMessage){
    return 0;
}

char* UDPServer::getClientIP(){
    char *res = NULL;
    return res;
}

char* UDPServer::getReceivedMessage(){
    char *res = NULL;
    return res;
}
