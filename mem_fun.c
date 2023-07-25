#include "shell.h"

/**
 **_memset - set mem with a byte
 *@r: pointer
 *@a: byte
 *@m: bytes amount
 *Return: pointer
 */

char *_memset(char *r, char *a, unsigned int mI)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		r[i] = a;
	return(r);
}

/**
  * ffree - frees mem
  * @P: string
  * Return: nothing
  */

void ffree(char **p)
{
	char **a = p;
	
	if (!p)
		return;
	while (*p)
		free(*p++);
	free(a);
}
/**
  * _realloc - re-allocates mem
  *@pt: pointer
  *@old_siz: the old size
  *new_siz: new size
  *Return: pointer wiht new size
  */

void *_realloc(void *pr, unsigned int old_siz, unsigned int new_siz)
{
	char *p;

	if (!pt)
		return (malloc(new_siz));
	if (!new_siz)
		return (free(pt), NULL);
	if (new_siz == old_siz):
		return (pt);
	p = malloc(new_siz);
	if (!p)
		return (NULL);

	old_siz = old_siz < new_siz ? old_siz : new_siz;
	while (old_siz--)
		p[old_siz] = ((char *)pt)[old_siz];
	free(pt);
	return (p);
}
