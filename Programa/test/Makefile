# Makefile para compilar el Trabajo Práctico 0 de Algoritmos y Programación II

DIR_INCLUDE= -I.
CXX = g++
CXXARGS  = -ansi -pedantic -Wall -g
CXXFLAGS = $(DIR_INCLUDE) $(CXXARGS)
RM = -rm -f


all: tp0.exe
	
tp0.exe: main.o cmdline.o complejo.o am_proc.o cmdline.h complejo.h am_proc.h 
	$(CXX) $(CXXFLAGS) -o tp0.exe main.o cmdline.o complejo.o am_proc.o


# Declaración de targets de objetos para tp0
main.o: main.cc
	$(CXX) $(CXXFLAGS) -c -o main.o main.cc
main.cc: cmdline.h complejo.h am_proc.h

cmdline.o: cmdline.cc
	$(CXX) $(CXXFLAGS) -c -o cmdline.o cmdline.cc
cmdline.cc: cmdline.h

complejo.o: complejo.cc
	$(CXX) $(CXXFLAGS) -c -o complejo.o complejo.cc
complejo.cc: complejo.h

am_proc.o: am_proc.cc
	$(CXX) $(CXXFLAGS) -c -o am_proc.o am_proc.cc
am_proc.cc: am_proc.h complejo.h 


# Cleaning target

.PHONY: clean
clean:
	$(RM) -vf *.o *.exe *.t *.out *.err .*.swp
