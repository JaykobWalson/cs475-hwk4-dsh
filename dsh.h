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
int count(char *str, char delim);

void cleanUp(char* line);
void mode1(char* line);