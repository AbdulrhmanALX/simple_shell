#include "shell.h"

/**
  * clear_info - __intialze __ info_t __ struct__
  *@inf: adress
  */

void clear_info(info_t *inf)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
  *set_inf0 - __intialize__info_t__structure__
  *@inf: adress
  *@argv: vector of arguments
  *Return: void
  */

void set_info(info_t *inf, char **argv)
{
	int i = 0;

	inf->fname = argv[0];
	if (inf->arg)
	{
		inf->argv = strtow(inf->arg, " \t");
		if (! inf->argv)
		{
			inf->argv = malloc(sizeof(char *) * 2);
			if(inf->argv)
			{
				inf->argv[0] = _strdup(inf->arg);
				inf->argv[1] = NULL;
			}
		}
		for ( i = 0; inf->argv && inf->argv[i]; i++)
			;
		inf->argc = i;

		replace_alias(inf);
		replace_vars(inf);
	}
}

/**
  * free_info - __frees__info_t__structure__field
  *@inf: adress
  *@a: if all fields are free is true
  *Return: void
  */

void free_info(info_t *inf, int a)
{
	ffree(inf->argv);
	inf->argv = NULL;
	inf->path = NULL;
	if (a)
	{
		if (!inf->cmd_buf)
			free(inf->arg);
		if (inf->env)
			free_list(&(inf->env));
		if (inf->history)
			free_list(&(inf->history));
		if (inf->alias)
			free_list(&(inf->alias));
		ffre(inf->environ);
		inf->environ = NULL;
		bfree((void **)inf->cmd_buf);
		inf (inf->readfd > 2)
			close(inf->readfd);
		_putchar(BUF_FLUSH);
	}
}
