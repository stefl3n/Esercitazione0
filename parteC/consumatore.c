#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	
	// fare controllo argomenti
	if (argc != 2 && argc!=3) { 
		perror("Numero di argomenti sbagliato.\n"); 
		exit(1);
	}
	
	char *file_in, read_char, *prefix; 
	int i, fd, preflen, nread, trovato;
	
	prefix =argv[1];
	preflen=strlen(prefix);
	
	if(argc==3){
		
		close(0);
		file_in = argv[2];
		fd = open(file_in, O_RDONLY);
		
		if (fd!=0){
			perror("Apertura file errata.\n"); 
			exit(2); 
		}
		
		while(nread = read(fd, &read_char, sizeof(char))){
			/* un carattere alla volta fino ad EOF*/
	
			if (nread > 0){
				trovato=0;
				
				for(i=0; i<preflen && !trovato; i++){
					if(read_char==prefix[i])
						trovato=1;
				}
				
				if(!trovato)
					putchar(read_char);
			}
			else
			{	
				printf("(PID %d) impossibile leggere dal file %s", getpid(), file_in);
				perror("Errore!"); close(fd); exit(3);
			}
		
		}
		close(fd);
	}
	else if(argc==2){
		
		while((read_char=getchar())!=EOF){
			/* un carattere alla volta fino ad EOF*/
				trovato=0;

				for(i=0; i<preflen && !trovato; i++){
					if(read_char==prefix[i])
						trovato=1;
				}
				
				if(!trovato)
					putchar(read_char);
		}
	}
}