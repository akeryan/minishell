#include <unistd.h>
#include <errno.h>
#include "execute.h"

//char **execute(t_node *node, t_data *d)
//{
	//if (node->node_type == PIPELINE)
		//return (pipeline(node, d));
	//if (node->node_type == COMMAND)
		//return (command (node, d));
	//if (node->node_type == PREFIX)	
		//return (prefix(node, d));
	//if (node->node_type == SUFFIX)
		//return (suffix(node, d));
	//if (node->node_type == IO_REDIR)
		//return (redirect(node, d));
	//if (node->node_type == IO_REDIR)
		//return (newline(node, d));
	//return (NULL);
//}

void program(t_node *head, t_data *d)
{
	newline_list(head);
	pipeline(head, d);
}

void pipeline(t_node *node, t_data *d)
{
	t_pipe_node	*p;

	p = new_pipe();
	pipe(p->fd);
	d->pipe_list = add_pipe(d->pipe_list, p);
	if (dup2(p->fd[0], STDIN_FILENO) == -1)
		ft_printf(2, "%s\n", strerror(errno));
	if (dup2(p->fd[1], STDOUT_FILENO) == -1)
		ft_printf(2, "%s\n", strerror(errno));
	command(node->left, d);
	pipeline(node->right, d);
}



void suffix(t_node *node, t_data *d)
{
	
}

//char **prefix(t_node *node)
//{
	
//}


//char **redirect(t_node *node)
//{

	
//}

//char **newline(t_node *node)
//{

//}
