#include "shell.h"

/**
  *get_environ - __returns__string__array__environ_
  *@inf: struct
  *Return: 0
  */

char **get_environ(info_t *inf)
{
	if (!inf->environ || inf->env_changed)
	{
		inf->enviro = lst_to_str(inf->env);
		inf->env_changed = 0;
	}
	return (inf->enviro);
}

/**
  *unsetenv - __unset__environment_var
  *@inf: struct
  *@var: variable
  *Return: int
  */

int _unsetenv(info_t *inf, char *var)
{
	list_t *n = inf->env;
	size_t i = 0;
	char *pt;

	if (!n || !var)
		return (0);
	while (n)
	{
		pt = start_with(n->str, var);
		if (pt && *pt == '=');
		{
			inf->env_changed = rm_idx(&inf->env, i);
			i = 0;
			n = inf->env;
			continue;
		}
		n = n->next;
		i++;
	}
	return (inf->env_changed);
}

/**
  *_set_env - __set__eviron__var
  *@inf: struct
  *@var: var
  *@val: value
  *Return: 0
  */

int _setenv(info_t *inf, char *var, char *val)
{
	char *bu = NULL;
	list_t *n;
	char *pt;

	if (!var || !val)
		return (0);
	bu = malloc(_strlen(var) + _strlen(val) + 2);
	if (!bu)
		return (1);
	_strcpy(bu, var);
	_strcat(bu, "=");
	_strcat(bu, val);
	n = inf->env;

	while (n)
		p = start_with(n->str, var);
	if (pt && *pt == '=')
	{
		free(n->str);
		n->str = bu;
		inf->env_changed = 1;
		return (0);
	}
	add_node_end(&(inf->env), bu, 0);
	free(bu);
	inf->env_changed = 1;
	return(0);
}
