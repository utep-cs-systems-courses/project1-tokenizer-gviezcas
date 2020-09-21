#include <stdio.h>
#include "tokenizer.h"
#include "malloc.h"

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

  int count_words(char *s)
  {
    int counter = 1;

    for(int i = 0; s[i] != '\0'; i++)
      {
	if(space_char(s[i]))
	  {
	    counter++;
	  }
      }
    return counter;
  }

  char *copy_str(char *inStr, short len)
  {
    char *stringCopy = malloc((len + 1) * sizeof(char));

    for(int i = 0; i <= len; i++)
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

void print_tokens(char **tokens)
{
  for(int i = 0; **tokens != '\0'; i++)
    {
      printf("\n[%d] = %s", i, tokens[i]);
    }
}

int count_letters(char *s)
{
  int counter = 0;

  while(*s++ != '\0')
    {
      counter++;
    }
}

char **tokenize(char *str)
{
  int lettersLen = count_letters(str);
  int wordsLen = count_words(str);
  char **tokenizedString = malloc((wordsLen + 1)* sizeof(char));
  char *token = malloc((lettersLen + 1) * sizeof(char));
  token = copy_str(str, lettersLen);

  for(int i = 0; i < (lettersLen + 1); i++)
    {
      tokenizedString[i] = token;
      token = word_terminator(token);
      *token++;
    }
}
