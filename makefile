exec: main.o playfair.o
	  g++ -Wall -g main.o playfair.o -o exec

main.o: main.cpp playfair.h
		g++ -Wall -g -c main.cpp

playfair.o: playfair.cpp playfair.h
		  g++ -Wall -g -c playfair.cpp

clean:
	  rm -f *.o exec