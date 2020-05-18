CPPFLAGS= -c -g -Wall -pedantic -std=c++17

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o example.o Prostopadloscian.o Bryla.o graniastoslup6.o dron.o Zbiornik.o ZbiorWierzcholkow.o
	g++ -o example.out example.o ZbiorWierzcholkow.o Dr3D_gnuplot_api.o Prostopadloscian.o Bryla.o dron.o graniastoslup6.o Zbiornik.o -lpthread

example.o: example.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o example.o example.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

graniastoslup6.o: graniastoslup6.cpp graniastoslup6.hh Bryla.hh InterfejsRysowania.hh ZbiorWierzcholkow.hh
	g++ ${CPPFLAGS} -o graniastoslup6.o graniastoslup6.cpp

Bryla.o: Bryla.cpp Bryla.hh ZbiorWierzcholkow.hh SMacierz.hh
	g++ ${CPPFLAGS} -o Bryla.o Bryla.cpp

ZbiorWierzcholkow.o: ZbiorWierzcholkow.cpp ZbiorWierzcholkow.hh Wektor3D.hh
	g++ ${CPPFLAGS} -o ZbiorWierzcholkow.o ZbiorWierzcholkow.cpp

Prostopadloscian.o: Prostopadloscian.cpp Prostopadloscian.hh Bryla.hh InterfejsRysowania.hh ZbiorWierzcholkow.hh
	g++ ${CPPFLAGS} -o Prostopadloscian.o Prostopadloscian.cpp

dron.o: dron.cpp dron.hh Prostopadloscian.hh graniastoslup6.hh InterfejsRysowania.hh
	g++ ${CPPFLAGS} -o dron.o dron.cpp

Zbiornik.o: Zbiornik.cpp Zbiornik.hh
	g++ ${CPPFLAGS} -o Zbiornik.o Zbiornik.cpp

clear:
	rm example.out example.o Dr3D_gnuplot_api.o Prostopadloscian.o Bryla.o graniastoslup6.o Zbiornik.o dron.o ZbiorWierzcholkow.o
