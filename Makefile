LDFLAGS = -ljsoncpp

main.o: main.cpp Person.cpp Time.cpp Thing.cpp Gps.cpp Record.cpp
	g++ main.cpp Person.cpp Time.cpp Thing.cpp Gps.cpp Record.cpp $(LDFLAGS) -o main.o
