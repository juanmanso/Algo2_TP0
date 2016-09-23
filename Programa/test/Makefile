# Makefile para compilar el Trabajo Práctico 0 de Algoritmos y Programación II

## .PHONY se utiliza para destacar que las reglas con targets 'phoneados' no generan 
## archivos con esos nombres. Por lo tanto, no busca la existencia de ellos y opera solo
## si es llamado y siempre. También se usa para evitar ambiguedades (como con el comando view)



# DIR_INCLUDE = -I ./cmdline -I ./complejo -I ./am_proc
DIR_INCLUDE= -I.
CXXARGS  = #-ansi -pedantic -Wall -g
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

# Testing targets
# 
#	MODIFICAR Y HACER LAS PREUBAS!!!!!
#
#runtest.exe: runtest.cc
#	$(CXX) $(CXXFLAGS) -o runtest.exe runtest.cc
#
#test tests: cmdline.exe runtest.exe
#	runtest.exe cmdline.tests


# Cleaning target

.PHONY: clean
clean:
	$(RM) -vf *.o *.exe *.t *.out *.err
