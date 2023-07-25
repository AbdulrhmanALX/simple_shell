#include "shell.h"

/**
  * add_node - adds node at the beggining og a list
  *@h: head ptr
  *@st: str
  *@num: index
  *Return: list size
  */

list_t *add_node(list_t **h, const char *st, int num)
{
	list_t *n_h;

	if (!h)
		return (NULL);
	n_h = malloc(sizeof(list_t));
	if (!n_h)
		return (NULL);
	_memset((void *)n_h, 0, sizeof(list_t));
	if (str)
	{
		n_h->str = _strdup(str);
		if (!n_h->st)
		{
			free(n_h);
			return (NULL);
		}
	}
	n_h->next = *h;
	*h = n_h;
	return (n_h);
}

/**
  * add_node_end - add node to end
  *@h: head ptr
  *@str: str
  *@num: index
  *Return: list size
  */

list_t *add_node_end(list_t **h, const char *str, int num)
{
	list_t *n_n, *node;

	if (!h)
		return (NULL);
	node = *h;
	n_n = malloc(sizeof(list_t));
	if (!n_n)
		return (NULL);
	_memset((void *)n_n, 0, sizeof(list_t));
	n_n->num = num;
	if (str)
	{
		n_n->str = _strdup(str);
		if (!n_n->str)
		{
			free(n_n);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = n_n;
	}
	else
		*h = n_n;
	return (n_n);
}

/**
  * pr_lst_str - output as print the string element of a list
  *@head: head ptr
  *Return: list size
  */

size_t pr_lst_str(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("/n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
  * d_node_idx - remove node at an indx
  * @h: head ptr
  * @idx: the idx
  *Return: int
  */

int d_node_idx(list_t **h, unsigned int idx)
{
	list_t *node, *prv;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);
	if (!idx)
	{
		node = *h;
		*h = (*h)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (i == idx)
		{
			prv->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prv = node;
		node = node->next;
	}
	return (0);
}

/**
  * free_list - free the entire list
  * @h_ptr: head ptr
  *Return: nothing
  */

void free_list(list_t **h_ptr)
{
	list *n, *next_n, *h;

	if (!h_ptr || !*h_ptr)
		return;
	h = *h_ptr;
	n = h;
	while (n)
	{
		next_n = n->next;
		free(n->str);
		free(n);
		n = next_n;
	}
	*h_ptr = NULL;
}
