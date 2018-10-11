all: Master Slave

CC=gcc

Master: master.o
	$(CC) -o master master.o
Slave: slave.o
	$(CC) -o slave slave.o
