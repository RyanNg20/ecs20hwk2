LDFLAGS = -ljsoncpp

main: main.o Person.o Gps.o Thing.o Time.o Record.o json.cpp
	g++ main.o Person.o Gps.o Thing.o Time.o Record.o json.cpp $(LDFLAGS) -o main

main.o: main.cpp common.h json.cpp
	g++ -c json.cpp main.cpp $(LDFLAGS)

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
