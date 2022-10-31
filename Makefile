LDFLAGS = -ljsoncpp

main.o: main.cpp Thing.cpp Time.cpp
	g++ main.cpp Person.cpp $(LDFLAGS) -o person
