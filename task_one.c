#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<unistd.h>
#include<string.h>
#include"split.h"
#define MAX_SYM 1000
#define MAX_WORDS 100
#define MAX_SEP 100
int main() {
	char* str_in;
	int cnt = 0;	
	int* quantity;
	char** tokens;
	char* separator;
	tokens = (char**)calloc(MAX_WORDS, sizeof(char*)); // Выделение памяти для всей конструкции //
	separator = (char*)calloc(MAX_SEP, sizeof(char));
	quantity = (int*)calloc(MAX_WORDS, sizeof(int));
    str_in = (char*)calloc(MAX_SYM, sizeof(char));
	printf("please, give me a string to divide it into tokens\n");
	fgets(str_in, MAX_SYM, stdin);
	str_in[strlen(str_in) - 1] = 0;
    printf("please, give me a symbol to divide\n");
	fgets(separator, MAX_WORDS, stdin);
	separator[strlen(separator) - 1] = 0;
	Split(str_in, separator, tokens, quantity);
	free(tokens); // Удаление всей конструкции //
	free(separator);
	free(quantity);
	free(str_in);
return 0;
}

void Split(char* str_in, char* separator, char** tokens, int* quantity) {
        int counter = 0;
        int iter = 0;
        char* istr;
        int length_of_token = 0;
        char* new_str = str_in;
        strcat(str_in, separator);
        if(str_in != NULL && separator != NULL) {
            printf("Result:\n");
                for(iter == 0; iter <= strlen(str_in); iter++) {
                        istr = strstr(str_in, separator);
                        length_of_token = strlen(str_in) - strlen(istr);
                        if(istr == NULL) {
                                tokens[counter] = (char*)calloc(strlen(new_str), sizeof(char)); // Выделение памяти под конкретное число токенов //
                                strcpy(tokens[counter], new_str);
                                break;
                        } else {
                                tokens[counter] = (char*)calloc(length_of_token, sizeof(char));
                                strncpy(tokens[counter], str_in, length_of_token);
                                str_in = istr + strlen(separator);

                        }
                        printf("%s ",tokens[counter]);                
		                counter++;
                        free(tokens[counter]); // Удаление токенов //
                }
                printf("\n");
        *quantity = counter;
        }
}

