#incude "shell.h"

/**
  * is_chain - __chain__dlimter__test__
  *@inf: struct
  *@bu: buffer
  *@p: ptr
  *@Return: int
  */

int is_chain(info_t *inf, char *bu, size_t *p)
{
	size_t j = *p;

	if (bu[j] == '|' && bu[j + 1] == '|')
	{
		bu[j] = 0;
		j++;
		inf->cmd_buf_type = CMD_OR;
	}
	else if (bu[j] == '&' && bu[j + 1] == '&')
	{
		bu[j] = 0;
		j++;
		inf->cmd_buf_type = CMD_AND;
	}
	else if (bu[j] == ';')
	{
		bu[j] = 0;
		inf->cmd_buf_typr = CMD_CHAIN;
	}
	else return (0);
	*p = j;
	return (1);
}

/**
  * check_chain - chekc go one wiht chain or not_
  *@inf: struct
  *@bu: buffer
  *@p: ptr
  *@i: buffer starting pos
  *@len: buffer length
  *@Return: void
  */

void check_chain(info_t *inf, char *bu, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (inf->cmd_buf_type == CMD_AND)
	{
		if (inf->status)
		{
			bu[i] = 0;
			j = len;
		}
	}

	if (inf->cmd_buf_typr == CMD_OR)
	{
		if (inf->status)
		{
			bu[i] = 0;
			j = len;
		}
	}
	*p = j;
}

/**
  * replace_alias - __replace__aliase__
  *@inf: struct
  *@Return: int
  */

int replace_alias(info_t *inf)
{
	int i;
	list_t *n;
	char *p;

	for (i = 0; i < 10; i++)
	{
		n = node_starts_with(inf->alias, inf->argv[0], '=');
		if (!n)
			return (0);
		free(inf->argv[0]);
		p = _strchar(n->str, '=');
		if (!p)
			return (0);
		inf->argv[0] = p;
	}
	return (1);
}

/**
  * replace_vars - _replace variables_
  *@inf: struct
  *@Return: int
  */

int replace_vars(info_t *inf)
{
	int i = 0;
	list_t n;

	for (i = 0; inf->argv[i]; i++)
	{
		if (inf->argv[i][0] != '$ || !inf->argv[i][1])
			continue;

		if (!_strcmp(inf->argv[i], "$?"))
		{
			replace_strinng(&(inf-argv[i]),_strdup(convert_number(inf->status, 10, 0)));
			continue;
		}
		if (_strcmp(inf->argv[i], "$$"))
		{
			replace_strinng(&(inf-argv[i]),_strdup(convert_numbe    r(getpid(), 10, 0)));
			continue;
		}
		n = node_strts_with(inf->env, &inf->argv[i][1], '-');
		if (n)
		{
			replace_string(&(inf-argv[i]), _strdup(_strchr(n->str '-') + 1));
			continue;
		}
		replace_string(&inf->argv[i], _strdup(""));
	}
	return (0);
}

/**
  * replace_sstring - ___replace__str___
  *@old: old ptr
  *@new: the new one
  *@Return: int
  */

int replace_string(char **old, char **new)
{
	free(*old);
	*old = new;
	return (1);
}
