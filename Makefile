CC =gcc
AR =ar
FLAGS = -Wall -g
FUN_H = functions.h
MAIN_O = main.o
MAIN_FIND = mainFind.o
SORT = isort.o
FIND = txtfind.o

all: isort txtfind

.PHONY: all clean

isort : $(MAIN_O) isort.so
	$(CC) $(FLAGS) -o isort $(MAIN_O) ./isort.so

txtfind :$(MAIN_FIND) txtfind.so
	$(CC) $(FLAGS) -o txtfind $(MAIN_FIND) ./txtfind.so

isort.so:$(SORT)
	$(CC) -shared -o isort.so $(SORT)

txtfind.so:$(FIND)
	$(CC) -shared -o txtfind.so $(FIND)

#Create o files

$(MAIN_O): main.c $(FUN_H)
	$(CC) $(FLAGS) -c main.c

$(MAIN_FIND): mainFind.c $(FUN_H)
	$(CC) $(FLAGS) -c mainFind.c

isort.o : isort.c $(FUN_H)
	$(CC) $(FLAGS) -fPIC -c isort.c

txtfind.o : txtfind.c $(FUN_H)
	$(CC) $(FLAGS) -fPIC -c txtfind.c


clean:
	rm -f *.o *.a *.so isort txtfind