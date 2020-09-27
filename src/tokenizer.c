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
  int i = 0;
  while(tokens[i] != NULL)
    {
      printf("[%d] = %s\n", i, tokens[i]);
      i++;
    }
}

int count_letters(char *s)
{
  int counter = 0;

  while(*s++ != '\0')
    {
      counter++;
    }
  return counter;
}

char *remove_spaces(char *s, char *newString)
{
  int c = 0;
  int d = 0;

  while(s[c] != '\0')
    {
      if(!(s[c] == ' ' && s[c+1] == ' '))
	{
	  newString[d] = s[c];
	  d++;
	}
      c++;
    }
  newString[d] = '\0';
  return newString;
}

char **tokenize(char *str)
{
  int lettersLen = count_letters(str);
  char *token;
  token = copy_str(str, lettersLen);
  int wordsLen = count_words(token);
  char **tokenizedString = malloc((wordsLen + 1)* sizeof(char));
  if(tokenizedString == NULL)
    {
      printf("No memory at tokenizedString\n");
    }
  for(int i = 0; i < (wordsLen + 1); i++)
  {
    tokenizedString[i] = malloc((lettersLen + 1) * sizeof(char));
    if(tokenizedString[i] == NULL)
      {
	printf("No memory at tokenizedString[i]\n");
      }
  }

  for(int i = 0; i < (wordsLen + 1); i++)
  {
    if(i == wordsLen)
    {
      tokenizedString[i] = '\0';
    }else
    {
      tokenizedString[i] = token;
      token = word_terminator(token);
      *token++;
      while(space_char(*token))
      {
	*token++;
      }
    }
  }
  return tokenizedString;
}
