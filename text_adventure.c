/* text_adventure.c - main program file for a simple text adventure */

#include <stdio.h>
#include <string.h>
#include "location.h"


static char input[100];   // string buffer for keyboard input


/* getInput() function - gets keyboard input and passes it back to the main
 * program using a return value */
static int getInput()
{
  printf("\n--> ");       // Player prompt
  return fgets(input, sizeof(input), stdin) != NULL;
}


/* parseAndExecute() function to take the keyboard input, parse it and execute
 * the given command or return an error */
static int parseAndExecute()
{

  /* simple 2 line verb and noun parser using strtok to change the input string
   * into 'tokens' */
  char *verb = strtok(input, " \n");    
  char *noun = strtok(NULL, " \n");

  /* IF statements using strcmp to match keyboard input with known verbs to run
   * commands */
  if (verb != NULL) {
    if (strcmp(verb, "quit") == 0) {
      return 0;         // return a zero to make the main loop end
    }
    else if (strcmp(verb, "look") == 0) {
      executeLook(noun);
    }
    else if (strcmp(verb, "go") == 0) {
      executeGo(noun);
    }
    else {
      printf("I don't know how to '%s'.\n", verb);
    }
  }

  return 1;
}


/* main program loop - runs the getInput and parseAndExecute functions untill a
 * FALSE is returned */
int main()
{
  printf("Welcome to Little Cave Adventure.\n");
 
  executeLook("around");
  
  while (getInput() && parseAndExecute());
 
  printf("\nBye!\n");

  return 0;
}

