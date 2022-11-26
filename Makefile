LDFLAGS = -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client

all: server client

client.h: hw5.json
	jsonrpcstub hw5.json --cpp-server=server --cpp-client=client

server.h: hw5.json
	jsonrpcstub hw5.json --cpp-server=server --cpp-client=client

client: client.o Person.o Gps.o Thing.o Time.o Record.o json.o
	g++ client.o Person.o Gps.o Thing.o Time.o Record.o json.o $(LDFLAGS) -o client

server: server.o Person.o Gps.o Thing.o Time.o Record.o json.o
	g++ server.o Person.o Gps.o Thing.o Time.o Record.o json.o $(LDFLAGS) -o server

client.o: client.cpp client.h
	g++ -c client.cpp $(LDFLAGS)

server.o: server.cpp server.h
	g++ -c server.cpp $(LDFLAGS)

json.o:		json.cpp $(INC)
	g++ -c json.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp $(LDFLAGS)

Gps.o: Gps.cpp Gps.h
	g++ -c Gps.cpp $(LDFLAGS)

Thing.o: Thing.cpp Thing.h
	g++ -c Thing.cpp $(LDFLAGS)

Time.o: Time.cpp Time.h
	g++ -c Time.cpp $(LDFLAGS)

Record.o: Record.cpp Record.h
	g++ -c Record.cpp $(LDFLAGS)

