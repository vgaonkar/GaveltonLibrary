#
#  Makefile
#  LibraryProject
#
#  Created by Vijay R. Gaonkar on 9/24/13.
#  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
#
LibraryProject: Media.o Book.o Periodical.o Video.o Film.o SearchEngine.o main.o
	g++ -Wall -pedantic -g -o LibraryProject Media.o Book.o Periodical.o Video.o Film.o SearchEngine.o main.o

main.o: SearchEngine.h main.cpp
	g++ -Wall -pedantic -g -c main.cpp

SearchEngine.o: Media.h Book.h Periodical.h Video.h Film.h SearchEngine.h SearchEngine.cpp
	g++ -Wall -pedantic -g -c SearchEngine.cpp

Film.o: Media.h Film.h Film.cpp
	g++ -Wall -pedantic -g -c Film.cpp

Video.o: Media.h Video.h Video.cpp
	g++ -Wall -pedantic -g -c Video.cpp

Periodical.o: Media.h Periodical.h Periodical.cpp
	g++ -Wall -pedantic -g -c Periodical.cpp

Book.o: Media.h Book.h Book.cpp
	g++ -Wall -pedantic -g -c Book.cpp

Media.o: Media.h Media.cpp
	g++ -Wall -pedantic -g -c Media.cpp

clean:
	rm -rf *.o LibraryProject
