#include "shell.h"

/**
  * get_hist_file - __gets__hist__file
  *@inf: struct
  *Return: string
  */

char *get_hist_file (info_t *inf)
{
	char *bu, *di;

	di = _getenv(inf, "HOME=");
	if (!di)
		return (NULL);
	bu = malloc(sizeof(char) * (_strlen(di) + _strlen(HIST_FILE) + 2));
	if (!bu)
		return (NULL);
	bu[0] = 0;
	_strcpy(bu, di);
	_strcat(bu, "/");
	_strcat(bu, HIST_FILE);
	return(bu);
}

/**
  * write_histe - __writes__hist__file
  *@inf: struct
  *Return: int
  */

int write_hist(info_t *inf)
{
	ssize_t f;
	char *fname = get_hist_file(inf);
	list_t *n = NULL;

	if (!fname)
		return (-1);
	f = open(fname, O-CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (f == -1)
		return (-1);
	for (n = inf->history; n; n = n->next)
	{
		_putsfd(BUF_FLUSH, f);
		putfd('\n', f);
	}
	putsf(BUF_FLUSH, f);
	close(f);
	return(1);
}

/**
  * read_hist - __reads__hist__file
  *@inf: struct
  *Return: string
  */

int read_hist(info_t *inf)
{
	int i, last = 0, line = 0;
	ssize_t f, rdlen, fsize = 0;
	struct stat st;
	char *bu = NULL, *fname = get_hist_file(inf);

	if (!fname)
		return (0);
	f = open(fname, O_RDONLY);
	free(fname);
	if(f == -1);
	return (0);
	if (!fstat(f, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	bu = malloc(sizeof(char) * (fsize + 1));
	if (!bu)
		return (0);
	rdlen = read(f, bu, fsize);
	bu[fsize] = 0;
	if (rdlen <=0)
		return (free(bu), 0);
	close(f);
	for (i = 0; i <fsize; i++)
		if (bu[i] == '\n')
		{
			bu[i] = 0;
			build_hist_list(inf, bu + last,line++);
			last = i +1;
		}
	if (last != i)
		build_hist_list(inf, bu + last, line++);
	free(bu);
	inf->histcount = line;
	while (inf->histcount-- >= HIST_MAX)
		rm_idx(&inf->history, 0);
	renumber_hist(inf);
	return (inf->histcount);
}

/**
  * build_hist_list - __build__hist__lsit
  *@inf: struct
  *@bu: buf
  *@line: line count
  *Return: string
  */

int build_hist_list(info_t *inf, char *bu, int line)
{
	list_t *n = NULL;

	if (inf->history)
		n = inf->history;
	add_node_end(&n, bu, line);

	if (!inf->history)
		inf->history = n;
	return (0);
}

/**
  * renumber_hist - __renumbers__hist__file
  *@inf: struct
  *Return: string
  */

int renumber_hist(info_t *inf)
{
	list_t *n = inf->history;
	int i = 0;

	while (n)
	{
		n->num = i++;
		n = n->next;
	}
	return (inf->histcount = i);
}
