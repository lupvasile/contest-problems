#include <Ws2tcpip.h>
#include <sstream>
#include <iostream>
#include <conio.h>
#include <fstream>
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


void brake(int x)
{
    cout << "brake " << x << '\n';
}
void accel(int x)
{
    cout << "throttle " << x << endl;
}

#define a 5.8

string s;
string semafor_state;
double speed, dist, time, current_limit, distance_to_next, next_limit;
double decel_distance,semafor_dist, remaining_time;
double stop_distance,semafor_time;
bool ok;
void stabilise(double current_limit)
{
    if (speed > current_limit - 1 && speed < current_limit + 5)
    {
        accel(0);
        brake(0);
        return;
    }
    if(speed<current_limit)
    {
        if (ok) accel(0);
        else if(dist<30 ) accel(10);
        else if (dist < 250) accel(60);
        else accel(60);
        brake(0);
        return;
    }
    if(speed==current_limit)
    {
        accel(0);
        brake(0);
        return;
    }
    if(speed>current_limit)
    {
        accel(0);
        brake(100);
        return;
    }
}

void speed_riding()
{

    if (distance_to_next == 0 && next_limit == -2)
    {
        stabilise(current_limit);
        return;;
    }
    if (current_limit<=next_limit)
    {
        stabilise(current_limit);
    }
    else
    {
        decel_distance=(10.0/36.0)*(speed-next_limit)*(speed-next_limit)/(2.0*a) + 1;

        // decel_distance=70;
        // if(next_limit==28) decel_distance=80;
        if (current_limit == 100) cerr << decel_distance << endl;
        int limit;
        limit = distance_to_next- decel_distance;
        if(distance_to_next < decel_distance + 10)
        {
            stabilise(next_limit);
            return;;
        }
        else
        {

            stabilise(current_limit);
            return;;
        }

    }
}
int main()
{
    if(DEBUG) open_connection();
    while (true)
    {
        if(DEBUG) read_buffer();
        cin >> s >> speed;
        cin >> s >> dist;
        cin >> s >> time;
        cin >> s >> current_limit >> distance_to_next >> next_limit;
        current_limit -= 3;
        next_limit -= 2;
        cin >> s >> semafor_dist >> semafor_state >> remaining_time;
        if (semafor_state == "") remaining_time += 10;
        cin >> s;
        if(DEBUG) clear_output_buffer();

        if(DEBUG) write();

        if (dist >= 1000)
        {
            accel(0);
            brake(100);
            continue;
        }

        stop_distance =(10.0/36.0)*(speed)*(speed)/(2.0*a) +2;
        semafor_time = speed / semafor_dist;
        if (semafor_dist < 5) ok = false;
        /*if (semafor_state != "Green" && semafor_dist < 10 && dist <= 50) {
            accel(0);
            brake(100);
            continue;
        }*/
        if (semafor_state == "Green" && remaining_time >= semafor_time)
        {
            speed_riding();
            continue;
        }
        if (semafor_state == "Yellow" && remaining_time <= semafor_time)
        {
            speed_riding();
            continue;
        }
        if (semafor_state != "Green" && stop_distance > semafor_dist)
        {
            ok=true;
            accel(0);
            brake(100);
            continue;
        }

        speed_riding();


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
