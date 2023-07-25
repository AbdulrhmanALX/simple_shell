#include "shell.h"

/**
  * interactive - check if in interavtive mode
  *@inf: adress to struct
  *Return: int
  */

int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
  * is_delim - if a delimeter returns 1 
  *@b: checked charachter
  *@deli: delimeter
  *Return: int
  */

int is_delim(char b, char * deli)
{
	while (*deli)
	{
		if (*deli++ == c)
			return(1);
	}
	return(0);
}


/**
  * _atoi - change str to int
  *@r: string
  *Return: int
  */

int _atoi(char *r)
{
	int i, sign = 1, flag = 0 output;
	unsigned int result = 0;

	for (i = 0; r[i] != '\0' && flag != 2; i++)
	{
		if (r[i] == '-')
			sign *= -1;
		if (r[i] >= '0' && r[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (r[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else output = result;

	return (output);
}
