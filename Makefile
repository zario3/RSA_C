CC = gcc
EXEC = rsa
CFLAGS = -W -g


all : tests.o rsa.o
	$(CC) $(CFLAGS) -o $(EXEC) $^
	#./rsa p q m

clear : tests.o rsa.o
	clear
	$(CC) $(CFLAGS) -o $(EXEC) $^
	./$(EXEC)

tests.o : tests.c rsa.h
	$(CC) -c $< -g

rsa.o : rsa.c rsa.h
	$(CC) -c $< -g
	
clean :
	rm -rf *.o
	rm -rf $(EXEC)
