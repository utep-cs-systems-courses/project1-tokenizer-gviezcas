#include <stdio.h>
#include "tokenizer.h"
#include "malloc.h"
/*Returns 1 if the char is a space, tab, or null. Otherwise, returns 0.*/
int space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\0')
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
/*Returns 1 if the char is not a space, tab, or null. Otherwisse, returns 0.*/
int non_space_char(char c)
{
  if(c != ' ' && c != '\t' && c != '\0')
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
/*Loops through the string until there is a non-space char and returns that pointer.*/
char *word_start(char *str)
{
  while(space_char(*str))
  {
    if(non_space_char(*str))
    {
     return str;
    }
	*str++;
  }
  return str;
}
/*Loops throught the string until there is a space char and returns that pointer.*/
char *word_terminator(char *word)
{
  while(non_space_char(*word))
    {
      if(space_char(*word))
	  {
	    return word;
	  }
	*word++;
      }
    return word;
}
/*Loops through the first character of every word and counts each word.*/
  int count_words(char *s)
  {
    int counter = 0;

    while(*s != '\0')
    {
      if(non_space_char(*s))
      {
	counter++;
	s = word_terminator(s);
	*s++;
      }
     }
    return counter;
  }
/*Copies the original string with terminatos at the end of each word.*/
  char *copy_str(char *inStr, short len)
  {
    char *stringCopy = malloc((len + 1) * sizeof(char));
    int i = 0;
    for(i = 0; i <= len; i++)
      {
	if(space_char(inStr[i]))
	  {
	    stringCopy[i] = '\0';
	  }
	else
	  {
	    stringCopy[i] = inStr[i];
	  }
      }
    return stringCopy;
  }
/*Prints the tokenized string.*/
void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL)
    {
      printf("[%d] = %s\n", i, tokens[i]);
      i++;
    }
}
/*Free the allocated memory.*/
void free_tokens(char **tokens)
{
  int lenWords = count_words(*tokens);
  int i = 0;
  for(i = 0; i < lenWords; i++)
    {
      free(tokens[i]);
    }
	free(tokens);
}
/*Counts every letter in the string including spaces.*/
int count_letters(char *s)
{
  int counter = 0;

  while(*s++ != '\0')
    {
      counter++;
    }
  return counter;
}
/*Removes the any extra spaces that are found in the string.*/
char *remove_spaces(char *s, char *newString)
{
  int c = 0;
  int d = 0;

  while(s[c] != '\0')  //loops through until end of string.
    {
      if(!(s[c] == ' ' && s[c+1] == ' ')) //Checks that there is only one space after each word.
	{
	  newString[d] = s[c]; //Copies over when it is a char.
	  d++;
	}
      c++;
    }
  newString[d] = '\0';  //Adds terminator at end of string.
  return newString;
}
/*Tokenizes the string using a double pointer.*/
char **tokenize(char *str)
{
  int lettersLen = count_letters(str);
  char *token;
  token = copy_str(str, lettersLen); //Create a copy of the input string with terminators.
  int wordsLen = count_words(token);
  char **tokenizedString = malloc((wordsLen + 1)* sizeof(char)); //Allocate memory for each "row" of the pointers.
  int i = 0;
  if(tokenizedString == NULL)
    {
      printf("No memory at tokenizedString\n"); //Check double pointer memory is allocated.
    }
  for(i = 0; i < (wordsLen + 1); i++) //Allocate memory for each "column" of pointers.
  {
    tokenizedString[i] = malloc((lettersLen + 1) * sizeof(char));
    if(tokenizedString[i] == NULL)
      {
	printf("No memory at tokenizedString[i]\n");  //Check each pointer memory is allocated.
      }
  }

  for(i = 0; i < (wordsLen + 1); i++)  //Repeat until all words are looked at.
  {
    if(i == wordsLen) //When reaching the end of double pointer add terminator.
    {
      tokenizedString[i] = '\0';
    }else
    {
      tokenizedString[i] = token;  //Point each row to address of first character.
      token = word_terminator(token);  //Move pointer to terminator of word.
      *token++;  //Move pointer to beggining of next word.
      while(space_char(*token))  //Keep moving pointer if it is a space char.
      {
	*token++;
      }
    }
  }
  return tokenizedString;
}
