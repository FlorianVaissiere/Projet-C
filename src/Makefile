# compilateur
CC := gcc
# options de compilation
CFLAGS := -std=c99 -Wall -g -Wextra -pedantic -ggdb 

# règle de compilation --- exécutables
all : projet

projet : projet.o
	$(CC) $(CFLAGS) -o $@ $^	

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

# options de compilation
clean:
	rm *.o projet 