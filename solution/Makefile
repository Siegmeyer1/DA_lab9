all: solution

solution: main.o OW_graph.o
	g++ -std=c++14 -O3 main.o OW_graph.o -o solution

main.o: main.cpp
	g++ -std=c++14 -O3 -c main.cpp

OW_graph.o: OW_graph.cpp
	g++ -std=c++14 -O3 -c OW_graph.cpp

clean:
	rm -rf *.o solution
