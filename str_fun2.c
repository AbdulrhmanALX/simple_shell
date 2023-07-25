#include "shell.h"

/**
  * _strcpy - cpoies string
  *@des: the dest
  *@sr: the src
  *Return: pointer
  */

char *_strcpy(cahr *des, char *sr)
{
	int i = 0;

	if (des == sr || sr == 0)
		return (des);
	while (sr[i])
	{
		des[i] = sr[i];
		i++;
	}
	des[i] = 0;
	return (des);
}

/**
  * _strdup - duplicate string
  *@str: the str to dup
  *
  *Return: pointer
  */

char *_strdup(const char *st)
{
	int len = 0;
	char *re;

	if (st == NULL)
		return (NULL);
	while (*st++)
		len++;
	re = malloc(sizeof(char) * (len + 1));
	if (!re)
		return (NULL);
	for (len++; len--;)
		re[len] = *--st;
	return (re);
}

/**
  * _puts - write to inputs
  *@sr: the word to print
  *Return: nothing
  */
void _puts(char *sr)
{
	int i = 0;

	if (!sr)
		return;
	while (sr[i] != '\0')
	{
		_putchar(sr[i]);
		i++;
	}
}

/**
  * _putchar - writes a char
  *@c: char to print
  *Return: 1 or -1
  */
int _putchar(char b)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, 1);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
