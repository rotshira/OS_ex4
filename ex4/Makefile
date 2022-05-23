LD = arm-none-eabi-g++
all: server client

server: server.cpp
	g++ server.cpp -lpthread -o Thread

client: client.cpp
	g++ client.cpp -lpthread -o client

clean:
	rm -f *.o server client Thread

runs:
	./Thread

runc:
	./client