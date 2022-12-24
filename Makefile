CC =gcc
AR =ar
FLAGS = -Wall -g
FUN_H = functions.h
MAIN_O = main.o 

all: isort findtxt

.PHONY: all clean 

isort : $(MAIN_O) isort.o
	$(CC) $(FLAGS) -o isort $(MAIN_O) isort.o

findtxt : findtxt.o
	$(CC) $(FLAGS) -o findtxt findtxt.o

#Create o files

$(MAIN_O): main.c $(FUN_H)
	$(CC) $(FLAGS) -c main.c

isort.o : isort.c $(FUN_H)
	$(CC) $(FLAGS) -fPIC -c isort.c

findtxt.o : findtxt.c $(FUN_H)
	$(CC) $(FLAGS) -fPIC -c findtxt.c

clean:
	rm -f *.o *.a *.so isort findtxt