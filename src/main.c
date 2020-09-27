#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAX_SIZE 300

int main()
{
  int loop = 1;

  while(loop)  //Continue looping through program.
  {
    char *userInput = malloc(MAX_SIZE * sizeof(char));  //Pointer to initial user input.
    char *newString = malloc(MAX_SIZE * sizeof(char));  //Pointer for copy of user input.
    if(userInput == NULL || newString == NULL)
    {
      printf("No Memory\n");  //Check pointers are allocated with memory.
      return 1;
    }
    
    printf("Please enter the item to tokenize:  (Enter q to quit)\n");
    printf("$");
    fgets(userInput, MAX_SIZE, stdin);  //Get user input.
    newString = remove_spaces(userInput, newString);  //Remove extra spaces from user input.

    if(*newString == 'q')  //Check if user wants to quit the program.
    {
      loop = 0;
    }else{
      char **tokenizedInput = tokenize(newString);  //Tokenize the string.
      printf("Tokenized item:\n");
      print_tokens(tokenizedInput);  //Print the string.
      free(*tokenizedInput);
      //free_tokens(tokenizedInput);  //Free all allocated memory.
    }
    free(userInput);
    free(newString);
  }
  printf("Thank you. Goodbye.\n");
  return 0;
}
