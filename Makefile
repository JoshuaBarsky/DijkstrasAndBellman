# Makefile for Graph ADT and related modules.
# make 				makes FindPath
# make GraphClient		makes GraphClient
# make PriorityQueueClient	makes PriorityQueueClient
# make ListClient		makes ListClient
# make clean			removes all objects and executable files

FindPath : FindPath.o Graph.o PriorityQueue.o List.o
	gcc -o FindPath FindPath.o Graph.o PriorityQueue.o List.o

GraphClient : GraphClient.o Graph.o PriorityQueue.o List.o
	gcc -o GraphClient GraphClient.o Graph.o PriorityQueue.o List.o

PriorityQueueClient : PriorityQueueClient.o PriorityQueue.o
	gcc -o PriorityQueueClient PriorityQueueClient.o PriorityQueue.o

ListClient : ListClient.o List.o
	gcc -o ListClient ListClient.o List.o

FindPath.o : FindPath.c Graph.h
	gcc -c -ansi -Wall FindPath.c

GraphClient.o : GraphClient.c Graph.h
	gcc -c -ansi -Wall GraphClient.c

PriorityQueueClient.o : PriorityQueueClient.c PriorityQueue.h
	gcc -c -ansi -Wall PriorityQueueClient.c

ListClient.o : ListClient.c List.h
	gcc -c -ansi -Wall ListClient.c

Graph.o : Graph.c Graph.h PriorityQueue.h List.h
	gcc -c -ansi -Wall Graph.c

PriorityQueue.o : PriorityQueue.c PriorityQueue.h
	gcc -c -ansi -Wall PriorityQueue.c

List.o : List.c List.h
	gcc -c -ansi -Wall List.c

clean : 
	rm -f FindPath GraphClient PriorityQueueClient ListClient FindPath.o GraphClient.o PriorityQueueClient.o ListClient.o Graph.o PriorityQueue.o List.o