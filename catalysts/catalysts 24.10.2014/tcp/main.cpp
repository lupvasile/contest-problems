#include <Ws2tcpip.h>
#define DEFAULT_BUFLEN 512
#define PORT 7000

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

stringstream ss;
string s;

int main() {
WinExec("C:/Users/vasil_000/Desktop/start_simulator/bin/Debug/start_simulator.exe",SW_SHOW);
    ///----------------------
    /// Declare and initialize variables.
    WSADATA wsaData;
    int iResult;

    SOCKET ConnectSocket = INVALID_SOCKET;
    struct sockaddr_in clientService;

    char *sendbuf = "move 3\n";
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    clientService.sin_port = htons( PORT );
    iResult = connect( ConnectSocket, (SOCKADDR*) &clientService, sizeof(clientService) );


    /// shutdown the connection since no more data will be sent
    ///iResult = shutdown(ConnectSocket, SD_SEND);
    /// Receive until the peer closes the connection
    do {
        strcpy(recvbuf,"");
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        ss.clear();
        ss.str(recvbuf);
        while (ss>>s) cout<<s<<'\n';
        int i=send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
        cout<<i<<'\n';
    } while( iResult > 0 );

    /// cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}
