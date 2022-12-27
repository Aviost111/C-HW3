CC =gcc
AR =ar
FLAGS = -Wall -g
FUN_H = functions.h
MAIN_O = main.o 
#MAIN_FIND = 

all: isort txtfind

.PHONY: all clean 

isort : $(MAIN_O) isort.o
	$(CC) $(FLAGS) -o isort $(MAIN_O) isort.o

txtfind : txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

#Create o files

$(MAIN_O): main.c $(FUN_H)
	$(CC) $(FLAGS) -c main.c

isort.o : isort.c $(FUN_H)
	$(CC) $(FLAGS) -fPIC -c isort.c

txtfind.o : txtfind.c $(FUN_H)
	$(CC) $(FLAGS) -fPIC -c txtfind.c

clean:
	rm -f *.o *.a *.so isort txtfind