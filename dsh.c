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

int count(char* str, char *delim){
 // char *pointer = 0;
  int counter = 0;
  char *temp = str;
  while(*temp){
    if(delim[0] == temp[0]){
      counter++;//instance of delim found.
    }
    temp++;
  }
  return counter;
}
//returns substrings of char from delim.
char** split(char* str, char *delim){
  
  int numTokens = count(str, delim) + 1;
  char** tokens = (char**) malloc((numTokens + 1) * sizeof(char*));
  for(int i = 0; i < numTokens; i++){//tokens get assigned an index of the array.
    tokens[i] = (char*) malloc(MAXBUF * sizeof(char));//make array of numTokens.
  }
  char* temp = strtok(str, delim);
  int counter = 0;
  while(temp != NULL){
    strcpy(tokens[counter], temp);
    counter++;
    temp = strtok(NULL, delim);
  }
  tokens[numTokens] = NULL;
  free (tokens);
  return tokens;
  


}

void cd(char *line){
  printf("is cd getting called?");
  char* home = getenv("HOME");//get the path to home.
  char** array = split(line, " ");//holds terms.
  printf("Is split getting called?");
  char* path;//currentpath
  char* currentDirectory = (char*) malloc (256 *sizeof(char));
  if(strcmp(array[0] , "cd") == 0 && array[1] != NULL){      
      path = getcwd(currentDirectory, 256);
      strcat(path, "/");
      strcat(path, array[1]);
      printf("%s\n", path);
      chdir(path);
      free (currentDirectory);
  }
  else{
      chdir(home);
  }

}
//Gets and shows current working directory.
void pwd(char* line){
  char* currentDirectory = (char*) malloc(256 * sizeof(char));
  printf("%s", currentDirectory);
  free (currentDirectory);
}

//Fills in the spaces of line with non-blank spaces
void cleanUp(char* line){
    for(int i = 0; i < strlen(line); i++){
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

void mode1(char* line){
  char** array = split(line, " ");
   if(access(array[0], F_OK| X_OK)){
      if(0 != fork()){
        if(line[strlen(line) - 1] == '&'){
          wait(NULL);
        }
      }
      else{
        execv(array[0], array);
      }

   }
}

//Check to see if there are more paths
void mode2(char* line){
  char** array = split(line, " ");
  if(access(path, F_OK| X_OK) == 0){
    char *paths = getenv(" ");
    if(paths == NULL){
      errorMsg;
    }
    else{
      strcat(paths, line);
      mode1(line);
    }
    if(0 != fork()){
        if(line[strlen(line) - 1] == '&'){
          wait(NULL);
        }
      }
      else{
        execv(array[0], array);
      }
  }
}

void errorMsg(){
  printf("Error: Command not found.");
}


