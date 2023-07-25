#include "shell.h"

/**
  * input_buf - ___buf__chain___
  *@inf: struct
  *@bu: buffer
  *@len: length
  *@Return: bytes
  */

ssize_t input_buf(info_t *inf, char **bu, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*bu);
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(bu, &len_p, stdin);
#else
		r = _getline(inf0, bu, &len_p);
#endif
		if (r > 0)
		{
			if ((*bu) [r - 1] == '\n')
			{
				(*bu)[r - 1] = '\0';
				r--;
			}
		}
		inf->linecount_flag = 1;
		remove_comments(*bu);
		build_hist_list(inf, *bu, inf->histcount++);
		{
			*len = r;
			inf->cmd_buf = bu;
		}

	return (r);
}

/**
  * get_input - _get__line___
  *@inf: struct
  *@Return: int
  */

ssize_t get_input(info_t *inf)
{
	static char *bu;
	static size_t i, j, len;
	size_t r = 0;
	char ** bu_p = &(inf->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(inf, &bu, &len);
	ir (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = bu + 1;
		chekc_chain(inf, bu, &j, i, len);
		while (j < len)
		{
			if (is_chain(inf, bu, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			inf->cmb_buf_type = CMD_NORM;
		}
		*bu_p = p;
		return (_strlen(p));
	}
	*bu_p = bu;
	return (r);
}

/**
  * read_buf - __reads__buf__
  *@inf: struct
  *@bu; buf
  *@i; __size__
  *@Return: int
  */

ssize_t read_buf(info_t *inf, char* bu, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(inf->readfd, bu, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
  * _getline - __get__line__input__
  *@inf: struct
  *@pt: ptr
  *@len: length
  *@Return: int
  */

int _getline(info_t *inf, char **pt, size_t *len)
{
	static char bu[READ_BUF_SIZE];
	static size_t i, le;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *pt;
	if (p && len)
		s = *len;
	if (i == le)
		i == le = 0;
	r = read_buf(inf, bu, &le);
	if (r == -1 || (r == 0 && le == 0))
		return (-1);
	c =_strchar(bu + i, '\n');
	k = c ? 1 + (unsigned int) (c - bu) : le;
	new_p = realloc(p, s, s ? s + k: k + 1);
	if (!new_p)
		return (p ? free(p), -1 :  -1);
	if (s)
		_strncat(new_p, bu + 1, k - i);
	else
		_strncpy(new_p, bu + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;
	if (len)
		*len = s;
	*pt = p;
	return (s);
}

/**
  * sigintHandler - __blocks__ctrl-c__
  *@sig_num: __signal__number__
  *@Return: void
  */

void sigintHandler(__atribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
