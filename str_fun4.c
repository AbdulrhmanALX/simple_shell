#include "shell.h"

/**
  * strtow - tokenize a string
  * @st: the str
  * @c: delimeter
  * Return: pointer
  */

char **strtow(char * st, char *c)
{
	int i, j, k, m, numword = 0;
	char **r;

	if (st == NULL || st[0] == 0)
		return (NULL);
	if(!d)
		d = " ";
	for (i = 0; st[i] != '\0'; i++)
		if(!is_delim(st[i], c) && (is_delim(st[i + 1], c) || !st[i + 1]))
			numword++;

	if (numword == 0)
		return (NULL);
	r = malloc((1 + numword) * sizeof(char *));
	if (!r)
		return (NULL);
	for (i = 0, j = 0; j < numword; j++)
	{
		while (is_delim(st[i], c))
			i++;
		k = 0;
		while (is_delim(st[i + k], c) && st[i + k])
			K++;
		r[j] = malloc((k + 1) * sizeof(char));
		if (!r[j])
		{
			for (k = 0; k < j; k++)
				free (r[k]);
			free(r);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			r[j][m] = st[i++];
		r[j][m] = 0;
	}
	r[j] = NULL;
	return (r);
}

/**
  * strtow2 - tokenize a string
  * @st: the str
  * @c: delimeter
  * Return: pointer
  */


char **strtow(char *st, char c)
{
	int i, j, k, m, numword = 0;
	char **r;

	if (st == NULL || st[0] == 0)
		return (NULL);
	for (i = 0; st[i] != '\0'; i++)
		if((st[i] != c && st[i + 1] == c) || (st[i] != c && !st[i + 1]) || st[i + 1] == c)
			numword++;

	if (numword == 0)
		return (NULL);
	r = malloc((1 + numword) * sizeof(char *));
	if (!r)
		return (NULL);
	for (i = 0, j = 0; j < numword; j++)
	{
		while (st[i] == c && st[i] != c)
			i++;
		k = 0;
		while (st[i + k] != c  && st[i + k] && st[i + k] != d)
			K++;
		r[j] = malloc((k + 1) * sizeof(char));
		if (!r[j])
		{
			for (k = 0; k < j; k++)
				free (r[k]);
			free(r);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			r[j][m] = st[i++];
		r[j][m] = 0;
	}
	r[j] = NULL;
	return (r);
}
