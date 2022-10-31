LDFLAGS = -ljsoncpp

main.o: main.cpp Person.cpp Time.cpp Thing.cpp Gps.cpp
	g++ main.cpp Person.cpp Time.cpp Thing.cpp Gps.cpp $(LDFLAGS) -o main.o
