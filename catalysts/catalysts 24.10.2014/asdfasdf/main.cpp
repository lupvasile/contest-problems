#include <Ws2tcpip.h>
#include <sstream>
#include <iostream>
#include <conio.h>
#include <string>
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

#define DEBUG 0

#if DEBUG
#define cin ss
#define cout rasp
#endif
///**************************************************************************************************

#define a 5.8

string cmd;
double speed,current_distance,time,next_limit,dist_to_next_limit,current_limit;
double brake_distance;
bool ok;
double limit_abs_dist;

void accel(int x)
{
    cout<<"throttle "<<x<<'\n';
}

void brake(int x)
{
    cout<<"brake "<<x<<'\n';
}
void opreste()
{
    accel(0);
    brake(100);
}

void stabilize(double speed,double limit)
{
    if(speed<limit-5)
    {
        accel(20);
        brake(0);
        return;
    }
    if(speed>limit)
    {
        opreste();
        return;
    }

    {
        accel(0);
        brake(0);
        return;
    }

}

int main()
{
    if(DEBUG) open_connection();
    while(1)
    {
    if(DEBUG) read_buffer();
    cin>>cmd>>speed;
    cin>>cmd>>current_distance;
    cin>>cmd>>time;
    cin>>cmd>>current_limit>>dist_to_next_limit>>next_limit;
    cin>>cmd;
    if(DEBUG) clear_output_buffer();

    if(current_distance>=1500-2)
    {
        opreste();
        continue;
    }
    if(current_limit==0) {
        accel(100);
        brake(0);
        continue;
    }
    if(next_limit==0)
    {
        stabilize(speed,current_limit);
        continue;
    }
    if(current_limit<=next_limit) stabilize(speed,current_limit);
    else
    {
        brake_distance=(100.0/(36*36))*(speed*speed-next_limit*next_limit)/(2.0*a)+3;
        if(dist_to_next_limit<=brake_distance) stabilize(speed,next_limit);
        else stabilize(speed,current_limit);
    }



    if(DEBUG) write();
    }
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
   /// cout<<"received "<<iResult<<'\n';
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
