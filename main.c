#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define MAX_INPUT_SIZE 1024

char *stdinISA(void){

    int bufferSize = MAX_INPUT_SIZE;

    char *buffer = malloc(sizeof(char) * bufferSize); //init allocation

    int c; // for input

    int position = 0; 

    if(!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    while(1){
        c=getchar();

        if (c==EOF||c=='\n'){
            buffer[position]='\0';
            printf("%s",buffer);
            return buffer;
        }
        else {
            buffer[position] = c;
        }
        position++;

        if(position >= bufferSize) {
            bufferSize+=MAX_INPUT_SIZE;
            buffer=realloc(buffer,bufferSize);
            if(!buffer){
                fprintf(stderr,"lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    free(buffer);
}

int main (int argc, char *argv[]) {
    // argc is the number of arguments
    // argv is the strings themselves

    stdinISA();

    return 0;
}




