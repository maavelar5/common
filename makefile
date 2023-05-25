all : main.cc
	g++ -lSDL2 -I/usr/include/SDL2 main.cc -o main.exe
