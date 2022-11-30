LDFLAGS = -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client

all: hw5Home hw5Forest hw5GrandmaHome

hw5Home.h: hw5.json
	jsonrpcstub hw5.json --cpp-server=hw5Forest --cpp-client=hw5Home

hw5Forest.h: hw5.json
	jsonrpcstub hw5.json --cpp-server=hw5Forest --cpp-client=hw5Home

hw5Home.o: hw5Home.cpp hw5Home.h
	g++ -c hw5Home.cpp $(LDFLAGS)

hw5Forest.o: hw5Forest.cpp hw5Forest.h
	g++ -c hw5Forest.cpp $(LDFLAGS)

hw5GrandmaHome.o: hw5GrandmaHome.cpp hw5Forest.h
	g++ -c hw5GrandmaHome.cpp $(LDFLAGS)

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

hw5Home: hw5Home.o Person.o Gps.o Thing.o Time.o Record.o json.o
	g++ hw5Home.o Person.o Gps.o Thing.o Time.o Record.o json.o $(LDFLAGS) -o hw5Home

hw5Forest: hw5Forest.o Person.o Gps.o Thing.o Time.o Record.o json.o
	g++ hw5Forest.o Person.o Gps.o Thing.o Time.o Record.o json.o $(LDFLAGS) -o hw5Forest

hw5GrandmaHome: hw5GrandmaHome.o Person.o Gps.o Thing.o Time.o Record.o json.o
	g++ hw5GrandmaHome.o Person.o Gps.o Thing.o Time.o Record.o json.o $(LDFLAGS) -o hw5GrandmaHome

clean:
	rm -f *.o *~ core hw5home.h hw5forest.h hw5Home hw5Forest hw5GrandmaHome