#include <stdio.h>
#include "tokenizer.h"
#include "tokenizer.c"

int main()
{
  char userInput[200];

  printf("Please enter the item to tokenize:\n");
  printf("$");
  fgets(userInput, sizeof(userInput), stdin);
  char **tokenizedInput = tokenize(userInput);
  printf("Tokenized item:\n");
  print_tokens(tokenizedInput);

  return 0;
}
