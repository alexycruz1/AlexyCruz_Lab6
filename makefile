pro: usuarios.o juegos.o main.o 
	g++ usuarios.o juegos.o main.o -o pro

main.o: main.cpp usuarios.h juegos.h
	g++ -c main.cpp

juegos.o: juegos.cpp juegos.h
	g++ -c juegos.cpp

usuarios.o: usuarios.cpp usuarios.h
	g++ -c usuarios.cpp