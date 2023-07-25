#include "shell.h"

/**
  * _myhist - __shows__history__
  *@inf: struct
  *@Return: int
  */

int _myhist(info_t *inf)
{
	prt_lst (inf->history);
	return (0);
}

/**
  * unset_alias - __delete__alias__
  *@inf: struct
  *@s: str
  *@Return: int
  */

int unset_alias(info_t *inf, char *s)
{
	char *pt, c;
	int r;

	pt = _strchar(s, '=');
	if (!pt)
		return (1);
	c = *pt;
	*pt = 0;
	r = rm_idx(&(inf->alias), get_n_idx(inf->alias, n_start_with(inf->alias, s, -1)));
	*pt = c;
	return (r);
}

/**
  * set_laias - __create__alias__
  *@inf: struct
  *@s: str
  *@Return: int
  */

int set_alias(info_t *inf, char *s)
{
	char *pt;

	pt = _strchar(s, '=');
	if(!pt)
		return (1);
	if (!*++p)
		return (unset_alias(inf, s));

	unset_alias(inf, s);
	return (add_node_end(&(inf->alias), s, 0) == NULL);
}

/**
  * print_alias - __prints__alias__
  *@n: node
  *@Return: int
  */

int print_alias(list_t *n)
{
	char *pt = NULL, *a = NULL;

	if (n)
	{
		pt = _strchar(n->str, '=');
		for (a = n->str; a <= pt; a++)
			_putchar(*a);
		_putchar('\');
		_puts(p + 1);
		_puts("\n");
		return (0);
	}
	return (1);
}

/**
  * _myalias - __work as alis__bulitin__
  *@inf: struct
  *@Return: int
  */

int _myalias(info_t *inf)
{
	int i = 0;
	char *pt = NULL;
	list_t *n = NULL;

	if (inf->argc == 1)
	{
		n = inf->alias;
		while (n)
		{
			print_alias(n);
			n = n->next;
		}
	return (0);
	}
	for (i = 1; inf->argv[i]; i++)
	{	
		pt = _strchar(inf->argv[i], '=');
		if (pt)
			set_alias(inf, inf->argv[i]);
		else
			print_alias(node_starts_with(inf->alias, inf->arg[i], '='));
	}
	return (0);
}
