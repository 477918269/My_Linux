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
    cerr << "Usage: " << s << " IP PORT" << endl;
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
    //绑定
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(atoi(argv[2]));
    local.sin_addr.s_addr = inet_addr(argv[1]);
    
    if(bind(sock, (struct sockaddr*)& local, sizeof(local)) < 0)
    {
        cerr << "bind error" << endl;
        return 3;
    }
    
    char buf[1024];
    for(;;)
    {
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        ssize_t s = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&peer, &len);
        if(s > 0)
        {
            buf[s] = 0;
            cout << "cllient# " << buf<< endl;
            sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&peer, len);
        }
        
    }

    close(sock);
    return 0;
}





