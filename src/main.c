#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAX_SIZE 300

int main()
{
  int loop = 1;

  while(loop)
  {
    char *userInput = malloc(MAX_SIZE * sizeof(char));
    char *newString = malloc(MAX_SIZE * sizeof(char));
    if(userInput == NULL)
    {
      printf("No Memory\n");
      return 1;
    }
    
    printf("Please enter the item to tokenize:  (Enter q to quit)\n");
    printf("$");
    fgets(userInput, MAX_SIZE, stdin);
    newString = remove_spaces(userInput, newString);

    if(*newString == 'q')
    {
      loop = 0;
    }else{
      char **tokenizedInput = tokenize(newString);
      printf("Tokenized item:\n");
      print_tokens(tokenizedInput);
      free(*tokenizedInput);
      //free_tokens(tokenizedInput);
    }
    free(userInput);
    free(newString);
  }
  printf("Thank you. Goodbye.\n");
  return 0;
}
