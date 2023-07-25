#include "shell.h"

/**
  * _erratoi - str to int
  *@r: str
  *Return: int
  */

int _erratoi(char *r)
{
	int i = 0;
	unsigned long int result = 0;

	if (*r == '+')
		r++;
	for (i = 0; r[i] != '\0'; i++)
	{
		if (r[i] >= '0' && r[i] <= '9')
		{
			result *= 10;
			result += (r[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
  * pr_error - message for errors
  *@inf: parameter
  *@est: error string
  *Return: int
  */

void pr_error(info_t *inf, char *est)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(est);
}
/**
  * pr_d - prints int
  *@inpu: input
  *@f: file descriptor
  *Return: num of chs
  */
int pr_d(int inpu, int f)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (f == STDER_FILENO)
		__putchar = -eputchar;
	if (inpu < 0)
	{
		_abs_ = -inpu;
		__putchar('-');
		count++;
	}
	else
		_abs_ = inpu;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putcahr('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
  * con_num - converts int to aschi
  *@nu: num
  *@bas: base of int 
  *@flag: arg flag
  *Return: str
  */

char *con_num(long int nu, int bas, int flag)
{
	static char *arr;
	static char buf[50];
	char sign = 0;
	char *p;
	unsigned long n = nu;

	if (!(flag & CONVERT_UNSIGNED) && nu < 0)
	{
		n = -nu;
		sign = '-';
	}
	arr = flag & CONVERT_LOWECASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	p = '\0';

	do {
		*--p = arr[n % bas];
		n /= bas;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
  * rm_comments - removes comments
  * @buf: ptr
  *Return: 0
  */
void rm_comments(char *bu)
{
	int i;

	for (i = 0; bu[i] != '\0'; i++)
	{
		if (bu[i] == '#' && (!i || bu[i - i] == ' '))
		{
			bu[i] = '\0';
			break;
		}
	}
}
