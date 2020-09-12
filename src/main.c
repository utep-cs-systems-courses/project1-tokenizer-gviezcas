#include <stdio.h>

int main()
{
  char userInput[200];

  printf("Please enter the item to tokenize:\n");
  printf("$");
  fgets(userInput, sizeof(userInput), stdin);
  printf("Tokenized item:\n");
  puts(userInput);

  return 0;
}
