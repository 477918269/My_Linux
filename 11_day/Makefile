PHONY.:all
all:udpServer udpClient
CC=g++

udpServer:udpServer.cc
	$(CC) -o $@ $^
udpClient:udpClient.cc
	$(CC) -o $@ $^

.PHONY:clean
clean:
	rm -f udpServer udpClient

