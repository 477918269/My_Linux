#include"TcpServer.hpp"

void Usage(string s)
{
    cout << "Usage: " << s << " IP PORT" << endl;

}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }
    int port = atoi(argv[2]);
    string ip = argv[1];
    TcpServer * tcp = new TcpServer(ip, port);
    tcp->InitServer();
    tcp->Start();
    return 0;
}
