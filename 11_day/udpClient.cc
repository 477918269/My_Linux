#include<iostream>
#include<unistd.h>
#include<cstring>
#include<sys/types.h>
#include<sys/socket.h>
#include<string>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int Usage(string s)
{
    cerr << "Usage: " << s << " SERVER_IP SERVER_PORT" << endl;
    cerr << "Version: 0.0.1" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        return 1;
    }
    //创建套接字
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        cerr << "socket error" << endl;
    }
    cout << "sock: " << sock << endl;
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    char buf[1024];
    for(;;)
    {
        //发送信息
        cout << "Please Enter# ";
        cin >> buf;
        sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&server, sizeof(server));
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        //接收消息
        ssize_t s = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&peer, &len);
        if(s > 0)
        {
            buf[s] = 0;
            cout << "server echo#  " << buf  << endl;
        }
        
    }

    close(sock);
    return 0;
}





