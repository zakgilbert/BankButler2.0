FLAGS = -ansi -pedantic-errors -Wall

all: p2

p2: userInterface.o llist.o main.o 
	g++ -o p2 userInterface.o llist.o main.o

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

llist.o: llist.cpp
	g++ $(FLAGS) -c llist.cpp

userInterface.o: userInterface.cpp
	g++ $(FLAGS) -c userInterface.cpp

clean:
	rm p2 text.txt userInterface.o llist.o main.o

debug:
	g++ $(FLAGS) -DDEBUG_MODE -c main.cpp
	g++ $(FLAGS) -DDEBUG_MODE -c llist.cpp
	g++ $(FLAGS) -DDEBUG_MODE -c userInterface.cpp
	g++ -o p2 userInterface.o llist.o main.o
