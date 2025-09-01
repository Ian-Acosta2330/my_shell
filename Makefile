FLAG = -o

all: main.o header.h
	gcc main.o $(FLAG) my_shell

main.o: main.c 
	gcc -c main.c

clean: 
	rm main.o my_shell

# clean:
#  @echo "deleting...."
#  del *.o my_shell.exe


