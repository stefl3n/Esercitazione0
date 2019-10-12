#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_STRING_LENGTH 256
int main(int argc, char* argv[]){
	
	if (argc != 2 && argc!=3) { 
		perror(" numero di argomenti sbagliato"); 
		exit(1);
	}
	
	char *file_in, read_char, *prefix, buff[MAX_STRING_LENGTH]; 
	int i, j, fd, preflen, nread, bo;
	
	if(argc==3){
		
		close(0);
		file_in = argv[2];
		fd = open(file_in, O_RDONLY);
		
		if (fd!=0){
			perror("P0: Impossibile aprire il file."); 
			exit(2); 
		}
	}
	
	prefix =argv[1];
	preflen=strlen(prefix);

	// fare controllo argomenti
	while(nread = read(fd, &read_char, sizeof(char))){
	/* un carattere alla volta fino ad EOF*/
	
		if (nread > 0){
			i=1;
			if(read_char==prefix[0]){
				buff[0]=read_char;
				bo=1;
				while((i<preflen && bo)){
					read(fd, &read_char, sizeof(char));
					buff[i]=read_char;
					
					if(read_char!=prefix[i])
						bo=0;
					i++;
						
				}
				
				if(!bo){
					for(j=0; j<i; j++)
						putchar(buff[j]);
						
				}
			}
			else{
				putchar(read_char);
			}	
		
		}
		else
		{
			printf("(PID %d) impossibile leggere dal file %s", getpid(), file_in);
			perror("Errore!"); close(fd); exit(3);
		}
	}
	
close(fd);
}