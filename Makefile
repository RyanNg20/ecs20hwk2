LDFLAGS = -ljsoncpp

main.o: main.cpp Thing.cpp Time.cpp
	g++ main.cpp Thing.cpp Time.cpp $(LDFLAGS) -o main.o