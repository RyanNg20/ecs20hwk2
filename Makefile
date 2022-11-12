LDFLAGS = -ljsoncpp

main.o: main.cpp Person.cpp Time.cpp Thing.cpp Gps.cpp Record.cpp json.cpp
	g++ main.cpp Person.cpp Time.cpp Thing.cpp Gps.cpp Record.cpp json.cpp $(LDFLAGS) -o main.o
