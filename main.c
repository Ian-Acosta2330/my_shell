#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define TOK_MAX_SIZE 64
#define TOK_DELILM " \t\r\n\a"

//reading standard input function
char *read_stdin(void){

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
            buffer[position]='\0'; // done reading line, finish with null term
            // printf("%s",buffer);
            return buffer;
        }
        else { //not done
            buffer[position] = c; //write out to buffer
        }
        position++;

        if(position >= bufferSize) { //if we go beyong the init alloc
            bufferSize+=MAX_INPUT_SIZE; //double then reallocate
            buffer=realloc(buffer,bufferSize);
            if(!buffer){
                fprintf(stderr,"lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return buffer;
}

//parsing through the read line | tokenizing
char **parse_split(char *line){

    //allocate the array of strings
    char **temp_split = malloc(MAX_INPUT_SIZE * sizeof(char *)); 
    char *tok = strtok(line, TOK_DELILM); //individual string starter
    int i = 0;
    int bufferSize = MAX_INPUT_SIZE;

    while(tok!=NULL){
        temp_split[i]=tok; //assign strings to array (**)
        i++;
        if(i>=bufferSize){
            bufferSize+=MAX_INPUT_SIZE; //reallocate if needs more
            temp_split = realloc(temp_split, bufferSize*sizeof(char *));
            if(!temp_split){ //err
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        tok = strtok(NULL, TOK_DELILM);
    }
    temp_split[i]=NULL; //finish off with null for looping later
        
    return temp_split;
}

int main (int argc, char *argv[]) {

    char* line;

    line = read_stdin();

    char** parsed_line;

    parsed_line = parse_split(line);

    for(int i = 0; parsed_line[i]!=NULL;i++){
        printf("Token: %s\n", parsed_line[i]);
    }

    free(line);
    free(parsed_line);

    return 0;
}




