DVD.o:  DVD.cpp DVD.h
	g++ -g -Wall -c DVD.cpp
DVDDriver.o:  DVDDriver.cpp DVD.h
	g++ -g -Wall -c DVDDriver.cpp
DVDDriver:  DVD.o DVDDriver.o
	g++ -g -Wall -o DVDDriver DVD.o DVDDriver.o

DVDArrayP.o:  DVDArrayP.cpp DVDArrayP.h
	g++ -g -Wall -c DVDArrayP.cpp
DVDArrayPDriver.o:  DVDArrayPDriver.cpp DVDArrayP.h
	g++ -g -Wall -c DVDArrayPDriver.cpp
DVDArrayPDriver: DVDArrayP.o DVDArrayPDriver.o
	g++ -g -Wall -o DVDArrayPDriver DVDArrayP.o DVDArrayPDriver.o DVD.o