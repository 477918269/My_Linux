 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
  
void Usage()
    {  printf("usage: ./server [ip] [port]\n"); }
   
   int main(int argc, char* argv[]) {  if (argc != 3) {    Usage();    return 1; 
