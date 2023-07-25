#include "shell.h"

/**
  * _myenv - __prints__current__enviroment__
  *@inf: __strurct_containing__potential__args__
  *Retrun: 0
  */

int _myenv(info_t *inf)
{
	prt_lst_str(inf->env);
	return (0);
}

/**
  * _getenv - __get__enviroment__
  *@inf: __strurct_containing__potential__args__
  *@n: name of env variable
  *Retrun: 0
  */

char *_getenv(info_t *inf, const char *n)
{
	list_t *n = inf->env;
	char *pt;

	while (n)
	{
		pt = starts_with(n->str, n);
		if (pt && *pt)
			return (pt);
		n = n->next;
	}
	return (NULL);
}

/**
  * _mysetenv - __intialize__new__enviroment__var__
  *@inf: __strurct_containing__potential__args__
  *Retrun: 0
  */

int _mysetenv(info_t *inf)
{
	if (inf->argc !=3)
	{
		_eputs("incrorect argc\n");
		return (1);
	}
	if (_setenv(inf, inf0>argv[1], inf_>argv[2]))
		return (0);
	return(1);
}

/**
  * _myunsetenv - __remove__enviroment__var__
  *@inf: __strurct_containing__potential__args__
  *Retrun: 0
  */

int _myunsetenv(info_t *inf)
{
	int i;

	if (inf->argc == 1)
	{
		_eputs("need more args \n");
		return (1);
	}
	for (i = 1; i <= inf->argc; i++)
		_unsetenv(inf, inf->argv[1]);

	return (0);
}

/**
  * pop_env_lst - __fetch__enviroment__list__
  *@inf: __strurct_containing__potential__args__
  *Retrun: 0
  */

int pop_env_lst(info_t *inf)
{
	list_t *n = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&n, environ[i], 0);
	inf->env = n;
	retunr(0);
}

