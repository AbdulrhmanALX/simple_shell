#include "shell.h"

/**
  * _strlen - returns string length
  *@r: the string
  *Return: the length
  */

int _strlen(char *r)
{
	int i = 0;
	
	if (!r)
		return (0);
	while (*r++)
		i++;
	return (i);
}

/** _strcmp - compares two strings
  *@r1: the 1st string
  *@r2: the 2nd
  *Return: int
  */

int _strcmp(char *r1, char *r2)
{
	while (*r1 && *r2)
	{
		if (*r1 != r2)
			return (*r1 - *r2);
		r1++;
		r2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 *start_with - checks sub string in string
 *@haystac: string
 *@needl: substring
 *Return: pointer 
 */

char *start_with(const char *haystac, const char needl)
{
	while (*needl)
	{
		if (*needl++ != *haystac++)
			return (NULL);
	}
	return ((char *)haystac);
}

/**
  * _strcat - concatenates strings
  * @des: the dest
  * @sr: the source
  *Return: pointer
  */

char *_strcat(char *des, char *sr)
{
	char *re = des;

	while (*des)
		des++;
	while (*sr)
		*des++ = *sr++;
	*des = *sr;
	return (re);
}
