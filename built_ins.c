#include "shell.h"

/**
  * _myexit - __exits__shell__
  *@inf: struct
  *@Return: int
  */

int_myexit(info_t *inf)
{
	int exitcheck;

	if (inf->argv[1])
	{
		exitcheck = _erratoi(inf->argv[1]);
		if (exitcheck == -1)
		{
			inf->status = 2;
			pnt_err(inf, "wrong number: ");
			_eputs(inf->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inf->err_num = _erratoi(inf->argv[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
  * _mycd - __changes__directory__
  *@inf: struct
  *@Return: int
  */

int _mycd(info_t *inf)
{
	char *s, *d, buf[1024];
	int chd;

	s = getcwd(buf, 1024);
	if (!s)
		_puts("getcwd failure");
	if (!inf->argv[1])
	{
		d = _getenv(inf, "HOME=");
		if (!d)
			chd = chdir((d = _getenv(inf, "PWD=")) ? d : "/");
		else
			chd = chdir(d);
	}
	else if (_strcmp(inf->argv[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD")), _putchar('\n');
		chd = chdir((d = _getenv(inf, "OLDPWD=")) ? d : "/");
	}
	else
		chd = chdir(inf->argv[1]);
	if (chd == -1)
	{
		prt_err(inf, "cant cd");
		_puts(inf->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(inf, "OLDPWD", _getenv(inf, "pwd="));
		_setenv(inf, "PWD", getcwd(buf, 1024));
	}
	return (0);
}

/**
  * _myhelp - __shows__shell__help__
  *@inf: struct
  *@Return: int
  */

int _myhelp(info_t *inf)
{
	char **arg;

	arg = inf->argv;
	_puts ("help \n");
	if (0)
		_puts(*arg);
	return (0);
}
