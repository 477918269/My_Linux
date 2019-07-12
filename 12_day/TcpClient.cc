#include"TcpClient.hpp"

void Usage(string s)
{
    cout << "Usage: " << s << " Server_IP Server_PORT" << endl;

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
    TcpClient * cli = new TcpClient(ip, port);
    cli->InitClient();
    cli->Start();
    return 0;
}
