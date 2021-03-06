#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<unistd.h>
#include"split.h"
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_SYM_STR 100
#define MAX_ARG 10
#define MAX_SYM 10
#define MAX_OPER 25

// Считываем команды из файла, разделяем их, получаем список команд и запихиваем его в функцию execvp //

void help_execvp(FILE* f_in) {
	pid_t pid;
	char* func_name;
	char* separator = " ";
	char* string_of_comands;
	char** tokens;
	int* quantity;
	int* time_delay;
	int offset = 0;
	int* status;
    int iter = 0;
    int counter = 0;
	int i = 0;
	tokens = (char**)calloc(MAX_OPER, sizeof(char*));
    time_delay = (int*)calloc(MAX_OPER, sizeof(int));
	quantity = (int*)calloc(MAX_ARG, sizeof(int));
	while(!feof(f_in)){
		string_of_comands = (char*)calloc(MAX_SYM_STR, sizeof(char));	
		fgets(string_of_comands, MAX_SYM_STR, f_in);
		string_of_comands[strlen(string_of_comands) - 1] = 0;
		Split(string_of_comands, separator, tokens, quantity);
		time_delay[counter] = atoi(tokens[0]);
		func_name = tokens[1];
		offset = 1;
		pid = fork();
		if(pid == 0) {
            sleep(time_delay[counter]);
			execvp(func_name, tokens + offset);
			exit(0);
		} else {
            wait(status);
        }
        for(iter = 0; iter < MAX_OPER; iter++) {
            if(tokens[iter] != NULL); free(tokens[iter]);
        }
		free(string_of_comands);
        counter++;
	}
	free(tokens);

}
		
int main(int argc, char** argv) {
	FILE* f_in = fopen(argv[1], "r");
	help_execvp(f_in);
return 0;
}
	
		
