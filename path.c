#include "shell.h"

/**
  * is_cmd - __is__excutabel__shell__
  *@inf: struct
  *@path: path
  *@Return: int
  */

int is_cmd(info_t *inf, char *path)
{
	struct stat st;

	(void)inf;
	if(!path || stat(path, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
  * is_cmd - __is__excutabel__shell__
  *@inf: struct
  *@path: path
  *@Return: int
  */

/**
  * dup_chars - __duplicates__chars_in_shell__
  *@path: path__string
  *@beg: first indx
  *@end: last idx
  *@Return: pointer
  */

char *dup_chars(char* path, int beg, int end)
{
	static char bu[1024];
	int i = 0, k = 0;

	for (k = 0, i = beg; i < end; i++)
		if (path[i] != ':')
			bu[k++] = path[i];
	bu[k] = 0;
	return (bu);
}

/**
  * find_path - __finf__path__shell__
  *@inf: struct
  *@path: path
  *@cm: comm
  *@Return: ptr
  */

char *find_path(info_t *inf, char *path, char *cm)
{
	int i = 0 , cur = 0;
	char *p;

	if (!path)
		return (NULL);
	if ((_strlen(cm) > 2) && start_wih(cm, ",/"))
	{
		if (is_cmd(inf, cm))
			return (cm);
	}
	while (1)
	{
		if (!path[i] || path[i] == ':')
		{
			path = dup_chars(path, cur, i);
			if (!*path)
				_strcat(p, cm);
			else
			{
				_strcat(p, "/");
				_strcat(p, cm);
			}
			if (is_cm(inf, p))
				return (p);
			if (!path[i])
				break;
			cur = i;
		}
		i++;
	}
	return (NULL);
}
