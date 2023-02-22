/*
 * main.c
 *
 *  Created on: Mar 17 2017
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "dsh.h"

int main(int argc, char **argv)
{
	// char* line = (char*) malloc(256);
	// while(strcmp(line, "exit")){
	// 	printf("dsh> ");
	// 	fgets(line, 256, stdin);
	// 	printf("before = %s\n", line);  
	// 	cleanUp(line);
	// 	printf("after = %s\n", line); 
	// 	split(line, " ");
		
	// 	// if(line[0] == '/'){
	// 	// 	mode1(line);
	// 	// }
	// }

	// char* test = malloc(9 * sizeof(char));
    // strcpy(test,"hi hi hi");
    // char** result = split(test, " ");
    // for(int i = 0; i < sizeof(test); i++){
    //     printf("%s\n",result[i]);
    // }
	char* test = "dsh sure is a hard method to code in.";
	char delim = ' ';
	int c = count(test, delim);
	printf("%d", c);
         return 0;
}
