/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 15:51:49 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/10 13:36:43 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		free_list(t_fdlist **head, t_fdlist *node, int ret)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node == *head && !node->next)
		*head = 0;
	if (node == *head && node->next)
		*head = node->next;
	free(node->str);
	free(node);
	return (ret);
}

static int		read_file(int fd, t_fdlist *node)
{
	int		ret;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
	{
		free(buf);
		return (-1);
	}
	buf[ret] = '\0';
	node->str = gnl_strjoin(node->str, buf);
	free(buf);
	if (!node->str)
		return (-1);
	return (ret);
}

static t_fdlist	*new_node(int fd)
{
	t_fdlist *new;

	new = malloc(sizeof(t_fdlist));
	if (!new)
		return (0);
	new->fd = fd;
	new->str = gnl_strdup("", '\0');
	if (!new->str)
	{
		free(new);
		return (0);
	}
	new->prev = 0;
	new->next = 0;
	return (new);
}

static t_fdlist	*find_fd(int fd, t_fdlist **head)
{
	t_fdlist *list;
	t_fdlist *new;

	list = *head;
	while (list)
	{
		if (list->fd == fd)
		{
			return (list);
		}
		list = list->next;
	}
	new = new_node(fd);
	if (!new)
		return (0);
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	t_fdlist		*node;
	static t_fdlist	*head;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	node = find_fd(fd, &head);
	if (!node)
		return (-1);
	ret = 1;
	while (ret > 0 && (gnl_strchr(node->str, '\n') == node->str))
		ret = read_file(fd, node);
	if (ret < 0)
		return (free_list(&head, node, -1));
	line[0] = gnl_strdup(node->str, '\n');
	if (!line[0])
		return (free_list(&head, node, -1));
	node->str = gnl_reset_ptr(node->str);
	if (ret == 0)
		return (free_list(&head, node, 0));
	return (1);
}
