WordSearch: wordSearch_Source.o main.o
	g++ wordSearch_Source.o main.o -o WordSearch
wordSearch_Source.o: wordSearch_Source.cpp wordSearch_Head.h
	g++ -g -Wall -c wordSearch_Source.cpp
main.o: main.cpp wordSearch_Head.h
	g++ -g -Wall -c main.cpp
clean:
	rm main.o wordSearch_Source.o WordSearch
