#ifndef _TCP_SERVER_HPP_
#define _TCP_SERVER_HPP_

#include<iostream>
#include<string>
#include<string.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
using namespace std;

class TcpServer
{
private:
    int listen_sock;
    string ip;
    int port;
public:
    //构造
    TcpServer(string _ip, int _port)
        :listen_sock(-1),
        ip(_ip),
        port(_port)
        {}
    //初始化
    void InitServer()
    {
        //创建套接字
        listen_sock = socket(AF_INET, SOCK_STREAM, 0);
        if(listen_sock < 0)
        {
            cerr << "socker error" << endl;
            exit(2);
        }
        //进行绑定
        struct sockaddr_in local;
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(port);
        local.sin_addr.s_addr = inet_addr(ip.c_str());

        if(bind(listen_sock, (struct sockaddr*)& local, sizeof(local) ) < 0)
        {
            cerr << "bind error" << endl;
            exit(3);
        }

        //进入监听模式
        if(listen(listen_sock, 5) < 0)
        {
            cout << "listen error" << endl;
            exit(4);
        }
    }
    //服务
    void Service(int sock)
    {
        while(1)
        {
        char buf[1024];
        //读
        ssize_t s = read(sock, buf, sizeof(buf) - 1);
        if(s > 0)
        {
        //写
            buf[s] = 0;
            cout << "client# " << buf << endl;
            write(sock, buf, strlen(buf));
        }
        else if(s == 0)
        {
            cout << "client quit!" << endl;
            break;
        }
        else
        {
            cerr << "read error" << endl;
            break;
        }
        }
        close(sock);
    }
    //启动
    void Start()
    {
        struct sockaddr_in peer;
        socklen_t len;
        for(;;)
        {
            len = sizeof(peer);
            //获得新链接
            int sock = accept(listen_sock, (struct sockaddr*) &peer, &len);
            if(sock < 0)
            {
                cerr << "accept error" << endl;
                continue;
            }
            cout << "Get a new client" << sock << endl;
            Service(sock);
        }
    }
    //析构
    ~TcpServer()
    {
        if(listen_sock > 0)
            close(listen_sock);
    }
};













#endif 
