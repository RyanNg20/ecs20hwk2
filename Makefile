LDFLAGS = -ljsoncpp

main: main.o Person.o Gps.o Thing.o Time.o Record.o json.cpp
	g++ main.o Person.o Gps.o Thing.o Time.o Record.o json.cpp $(LDFLAGS) -o main

main.o: main.cpp Person.o Gps.o Thing.o Time.o Record.o common.h json.cpp
	g++ -c Person.o Gps.o Thing.o Time.o Record.o json.cpp main.cpp $(LDFLAGS)

person.o: Person.cpp Person.h
	g++ -c Person.cpp $(LDFLAGS)

gps.o: Gps.cpp Gps.h
	g++ -c Gps.cpp $(LDFLAGS)

thing.o: Thing.cpp Thing.h
	g++ -c Thing.cpp $(LDFLAGS)

time.o: Time.cpp Time.h
	g++ -c Time.cpp $(LDFLAGS)

record.o: Record.cpp Record.h
	g++ -c Record.cpp $(LDFLAGS)
