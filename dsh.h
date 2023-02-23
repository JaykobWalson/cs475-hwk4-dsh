/*
 * dsh.h
 *
 *  Created on: Aug 2, 2013
 *      Author: chiu
 */

#define MAXBUF 256

/*
 * dsh.h
 *
 *  Created on: Aug 2, 2013
 *      Author: chiu
 */

#define MAXBUF 256
#define HISTORY_LEN 100
#define num 256

// TODO: Your function prototypes below

//sets up the fgets() for the list with a max size of MAXBUF
void userInput();

//Tokenizes stuff in string and then allocates them.
char** split(char *str, char *delim);
//Counts the delimiter instances.
int count(char *str, char* delim);
//Puts non blank spaces in line's spaces
void cleanUp(char* line);
//Checks if a command starts with / and then goes to check if it ends with &.
void mode1(char* line);
//Switches the directory
void cd(char* line);
//prints the current directory.
void pwd(char* line);
//error message
void errorMsg();