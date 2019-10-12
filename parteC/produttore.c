#define MAX_STRING_LENGTH 256
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char* argv[]){ // preparazione programma
    int fd, written; char *file_out;
	char c;
	
	//controllo argomenti
	if (argc != 2) { 
		perror(" numero di argomenti sbagliato …"); exit(EXIT_FAILURE);
	}
	
	file_out = argv[1];
	fd = open(file_out, O_WRONLY|O_CREAT|O_TRUNC, 00640);

	if (fd < 0) { 
		perror("P0: Impossibile creare/aprire il file"); exit(EXIT_FAILURE);
	}
	
	// corpo produttore
	printf("Inserisci testo\n");
	do{
		c = getchar();
		
		if(c!=EOF){
			written = write(fd, &c, 1); // uso della primitiva
		
			if (written <= 0){ 
				perror("P0: errore nella scrittura sul file"); exit(2);
			}
		}
		
	} while(c!=EOF);
	

close(fd);
}