#include <Ws2tcpip.h>
#include <sstream>
#include <iostream>
#include <conio.h>
#define DEFAULT_BUFLEN 512
#define PORT 7000
#define start_simulator "C:/Users/vasil_000/Desktop/start_simulator/bin/Debug/start_simulator.exe"

using namespace std;

WSADATA wsaData;
int iResult;
SOCKET ConnectSocket = INVALID_SOCKET;
struct sockaddr_in clientService;
char recvbuf[DEFAULT_BUFLEN];
int recvbuflen = DEFAULT_BUFLEN;
stringstream ss;
ostringstream rasp;
string srasp;


void open_connection();
void read_buffer();
void close_connection();
void write();
void clear_output_buffer();
///**************************************************************************************************

#define DEBUG 1

#if DEBUG
#define cin ss
#define cout rasp
#endif
///**************************************************************************************************

int main()
{
    if(DEBUG) open_connection();
    if(DEBUG) read_buffer();
    if(DEBUG) clear_output_buffer();
    if(DEBUG) write();
    if(DEBUG) close_connection();
    return 0;
}


///**************************************************************************************************
#undef cout
void read_buffer()
{
    strcpy(recvbuf,"");
    getch();
    iResult=recv(ConnectSocket, recvbuf, recvbuflen, 0);
    cout<<"received "<<iResult<<'\n';
    ss.clear();
    ss.str(recvbuf);
}

void open_connection()
{
    WinExec(start_simulator,SW_SHOW);
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    clientService.sin_port = htons( PORT );
    iResult = connect( ConnectSocket, (SOCKADDR*) &clientService, sizeof(clientService) );

}
void close_connection()
{
    closesocket(ConnectSocket);
    WSACleanup();
}

void clear_output_buffer()
{
     rasp.str("");
    rasp.clear();
}
void write()
{
    srasp=rasp.str();
    send( ConnectSocket, srasp.c_str(),srasp.length(), 0 );
}
