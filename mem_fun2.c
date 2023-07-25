#include "shell.h"

/**
  * bfree - frees mem
  *@pt
  *Return: int
  */

int bfree(void **pt)
{
	if (pt && *pt)
	{
		free(*pt);
		*pt = NULL;
	}
	return (0);
}
