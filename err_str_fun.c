#include "shell.h"

/**
  *e_puts - ___input string to be printed___
  *@st: str
  *Return: void
  */

void _eputs(char *st)
{
	int i = 0;

	if (!st)
		return;
	while (st[i] != '\0')
	{
		_eputchar(st[i]);
		i++;
	}
}

/**
  * _eputchar - ___writes the ch to stderr
  *@c: the ch
  *Return: int
  */

int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
  * _putfd - write to a specifc file discriptor
  *@c: chatchter
  *@f: fd to write in
  *Return: int
  */

int _putfd(char c, int f)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(f, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
  * _putsfd - write string to a specifc file discriptor
  *@st: str
  *@f: fd to write in
  *Return: str len
  */

int _putsfd(char *st, int f)
{
	int i = 0;

	if (! st)
		return (0);
	while (*st)
	{
		i += _putfd(*st++, f);
	}
	return (1);
}
