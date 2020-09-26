#include <stdio.h>
#include "tokenizer.h"
#include "tokenizer.c"

#define MAX_SIZE 300

int main()
{
  int loop = 1;

  while(loop)
  {
    char *userInput = malloc(MAX_SIZE * sizeof(char));
    if(userInput == NULL)
    {
      printf("No Memory\n");
      return 1;
    }
    
    printf("Please enter the item to tokenize:\n");
    printf("$");
    fgets(userInput, MAX_SIZE, stdin);

    if(*userInput == 'q')
    {
      loop = 0;
    }else{
      char **tokenizedInput = tokenize(userInput);
      printf("Tokenized item:\n");
      print_tokens(tokenizedInput);
    }
  }
  printf("Thank you. Goodbye.\n");
  return 0;
}
