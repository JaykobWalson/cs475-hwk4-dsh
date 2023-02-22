/*
 * dsh.c
 *
 *  Created on: Aug 2, 2013
 *      Author: chiu
 */
#include "dsh.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <errno.h>
#include <err.h>
#include <sys/stat.h>
#include <string.h>

void userInput()
{
   printf("dsh>");
   char storeHere[MAXBUF];
   fgets (storeHere, 256, stdin);
}

int count(char *str, char* delim){
 // char *pointer = 0;
  int counter = 0;
  char *temp = str;
  while(*temp){
    if(delim == *temp){
      counter++;//instance of delim found.
    }
    temp++;
  }
  return counter;
}
//returns substrings of char from delim.
char** split(char *str, char* delim){
  
  int numTokens = count(str, delim) + 1;
  char** tokens = (char**) malloc(numTokens * sizeof(char*));
  for(int i = 0; i < numTokens-1; i++){//tokens get assigned an index of the array.
    tokens[i] = (char*) malloc(numTokens * sizeof(char*));//make array of numTokens.
  }
  char* temp = strtok(str, delim);
  int counter = 0;
  while(temp != NULL){
    strcpy(tokens[counter], temp);
    counter++;
    temp = strtok(NULL, delim);
  }
  tokens[numTokens] = NULL;
  return tokens;
  


}

//Fills in the spaces of line with non-blank spaces
void cleanUp(char* line){
    for(int i = 0; i < strlen(line); i++){
 // char *pointer = 0;
  int counter = 0;
  char *temp = str;
  while(*temp){
    if(delim[0]){
      counter++;//instance of delim found.
    }
    temp++;
  }
  return counter;
}
{
        if(line[i] != ' '){
            for(int j = 0; j < strlen(line); j++){
              line[j] = line[i + j];
            }
            break;
        }
    }
    for(int i = 0; i < strlen(line); i++){
      if(line[i] == '\n') line[i] = 0;
    }
    for(int i = strlen(line) - 1; i >= 0; i--){
        if(line[i] != ' '&& line[i] != '\n'){
          break;
        }
        else{
          line[i] = 0;
        }
    }

}

//Goes into the System calls if the start of the string starts with /
//Wait is if the last of the string is &

// void mode1(char* line){
//   char **array = (char**) malloc(MAXBUF * sizeof(char*));
//   split(line, ' ');
//   for(int i = 0; i < MAXBUF; i++){
//     array[i] = (char*) malloc(256 * sizeof(char));
//   }
//    if(access(array[0], F_OK| X_OK)){
//       if(0 != fork()){
//         if(array[strlen(line) - 1] == '&'){
//           wait(NULL);
//         }
//       }
//       else{
//         char path*[] = split(array, line); 
//         execv(path, line);
//       }
      
      
//    }
  
// }

