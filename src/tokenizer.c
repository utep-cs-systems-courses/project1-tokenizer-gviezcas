#inlcude <stdio.h>
#include <header.h>
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

char *word_start(char *s)
{
  while(space_char(*s))
  {
    if(non_space_char(*s)
    {
     return s;
    }
	*s++;
  }
  return s;
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

  char *copy_str(char *inStr, int len)
  {
    len = word_terminator(inStr) - word_start(inStr);
    char *stringCopy = malloc((len + 1) * sizeof(char));

    for(int i = 0; i <= len; i++)
      {
	if(non_space_char(*inStr))
	  {
	    stringCopy[i] = inStr[i];
	  }
	else if(space_char(*inStr))
	  {
	    stringCopy[i] = '\0';
	  }
      }
    return stringCopy;
  }
