/*
 ============================================================================
 Name        : AutoInstrucionalED1.c
 Author      : Lucas Camacho
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

void equals(char *str1, char *str2){
	if(strcmp(str1,str2) != 0){
		printf("Não são iguais!");
	}
	else{
		printf("São iguais!");
	}
}
void equalsIgnoreCase(char *str1, char *str2){
	if(strcicmp(str1, str2) == 0){
		printf("São iguais");
	}
	else{
		printf("Não são iguais");
	}
}

char* subString(char *str1, char *str2, int inicio, int final){
	int input_len = strlen (str1);

	  if (inicio + final > input_len)
	  {
	     return NULL;
	  }

	  strncpy (str2, str1 + inicio, final);
	  return str2;
}

int lenght(char *str1){
	return strlen(str1);
}
char* toUpperCase(char *str1){
	return toupper(str1);
}
char* toLowerCase(char *str1){
	return tolower(str1);
}

int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower(*a) - tolower(*b);
        if (d != 0 || !*a)
            return d;
    }
}
struct  {
	char str[50];
	char str2[50];
	char caractere;

	void (*equals)(char*,char*);
	void (*equalsIgnoreCase)(char*,char*);
	char* (*subString)(char*,char*,int,int);
	int (*lenght)(char*);
	char* (*toUpperCase)(char*);
	char* (*toLowerCase)(char*);

}string = {.equals = equals,.equalsIgnoreCase = equalsIgnoreCase,
		.subString = subString, .lenght = lenght, .toUpperCase = toUpperCase, .toLowerCase = toLowerCase};

int main(void) {
	setbuf(stdout, NULL);

	char str[50],str2[50];
	printf("\n--------------------------------------\n");
		printf("\nReceber duas strings");

		printf("\nDigite a primeira string: ");
		fflush(stdin);
		gets(str);

		printf("\nDigite a segunda string: ");
		fflush(stdin);
		gets(str2);

		//string.equals(str,str2);
		//string.equalsIgnoreCase(str,str2);
		//printf(string.subString(str,str2,0,5));
		//printf("%d",string.lenght(str));
		printf(string.toUpperCase(str));
		printf(string.toLowerCase(str2));

	return EXIT_SUCCESS;
}
