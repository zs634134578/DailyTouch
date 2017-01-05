.IGNORE: clean

targets = *.o 001 002 003 004


001: 001_binary_search.o
	g++ -o 001 001_binary_search.o -lglog

001_binary_search.o: 001_binary_search.cpp
	g++ -c 001_binary_search.cpp

002: 002_binary_search.o
	g++ -o 002 002_binary_search.o -lglog

002_binary_search.o: 001_binary_search.cpp
	g++ -c 002_binary_search.cpp

003: 003_binary_search_first_ge.o
	g++ -o 003 003_binary_search_first_ge.o -lglog

003_binary_search_first_ge.o: 003_binary_search_first_ge.cpp
	g++ -c 003_binary_search_first_ge.cpp

004: 004_binary_search_first_gt.o
	g++ -o 004 004_binary_search_first_gt.o -lglog

004_binary_search_first_gt.o: 004_binary_search_first_gt.cpp
	g++ -c 004_binary_search_first_gt.cpp

clean:
	rm $(targets)
