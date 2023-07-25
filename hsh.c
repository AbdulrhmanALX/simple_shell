#include "shell.h"

/**
  * hsh - __main__shell_loop
  *@inf: struct
  *@argv: argument vec
  *@Return: int
  */

int hsh(info_t *inf, char **argv)
{
	ssize_t r = 0;
	int built = 0;

	while (r !- 01 && bulit ! = -2)
	{
		clear_info(inf);
		if (interactive(inf))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(inf);
		if (r != -1)
		{
			set_info(inf, argv);
			built = find_builtin(inf);
			if (built == -1)
				find_cmd(inf);
		}
		else if (interactive(inf))
			_putchar('\n');
		free_info(inf, 0);
	}
	write_history(inf);
	free_info(inf, 1);
	if (!interactive(inf) && inf->status)
		exit(inf->status);
	if (built == -1)
	{
		if (inf->err_num == -1)
			exit(inf->status);
	}
	return (built);
}

/**
  * find_builtin - _bulitins_finder
  *@inf: struct
  *@Return: int
  */

int find_builtin(info_t *inf)
{
	int i, built = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhist},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};
	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(inf->argv[0], bulitintbl[i].type) == 0)
		{
			inf->line_count++;
			buil = builintbl[i].func(inf);
			break;
		}
	return (built);
}

/**
  * find_cmd - _replace variables_
  *@inf: struct
  *@Return: int
  */

void find_cmd(info_t *inf)
{
	char *path = NULL;
	int i, k;

	inf->path = inf->argv[0];
	if (inf->linecount_flag == 1)
	{
		inf->line_count++;
		inf->liecount_flag = 0;
	}
	for (i = 0, k = 0; inf->arg[i]; i++)
		if (!is_delim(inf->arg[i], " \t\n"))
			k++;
	if (!k)
		return;
	path = find_path(inf, _getenv(inf, "PATH="), inf->argv[0]);
	if (path)
	{
		inf->path = path;
		fork_cmd(inf);
	}
	else
	{
		if ((interactive(inf) || _getenv(inf, "PATH=") || inf->argv[0][0] == '/') & is_cmd(inf, inf->argv[0]))
			fork_cmd(inf);
		else if (*(inf->arg != '\n'))
		{
			inf->status = 127;
			prt_er(inf, "not found\n");
		}
	}
}

/**
  * fork_cmd - _replace variables_
  *@inf: struct
  *@Return: int
  */

void fork_cmd(info_t *inf)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(inf->path, inf->argv, get_environ(inf)) == -1)
		{
			free_info(inf, 1);
			if (errno = EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(inf->status));
		if (WIFEXITED(inf->status))
		{
			inf->status == WEXITSTATUS(inf->status);
			if (inf->status == 126)
				prt_err(inf, "permissin denied\n");
		}
	}
}
