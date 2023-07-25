#include "shell.h"

/**
  * _strncpy - copy first n chars
  *@des: the dest
  *@sr: the src
  *@m : the first digits of the str
  *Return: copy
  */

char *_strncpy(char *des, char *sr, int m)
{
	int i, j;
	char *s = des;
	
	i = 0;
	while (sr[i] != '\0' && i < n - 1)
	{
		des[i] = sr [i];
		i++;
	}
	if (i < m)
	{
		j = i;
		while (j < n)
		{
			des[j] = '\0';
			j++'
		}
	}
	return(s);
}

/**
  * _strncat - concatenates first n chars
  *@des: the dest
  *@sr: the src
  *@m : the first digits of the str
  *Return: concatenation
  */

char *_strncat(char *des, char *sr, int m)
{
	int i, j;
	char *r = des;

	i = 0;
	j = 0;
	while (des[i] != '\0')
		i++;
	while (sr != '\0' && j < m)
	{
		des[i] = sr[j];
		i++;
		j++;
	}
	if (j < n)
		des[i] = '\0';
	return (r);
}

/**
  * _strchr - find the place of a char in string
  *@r: the string
  *@b: the char
  *Return: pointer
  */

char *_strchr(char *r, char b)
{
	do {
		if (*r == b)
			return (r);
	} while (*r++ != '\0');

	return (NULL);
}
