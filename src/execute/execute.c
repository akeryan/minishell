#include "execute.h"

char **execute(t_node *node, t_data *d)
{
	if (node->node_type == PIPELINE)
		return (pipeline(node, d));
	if (node->node_type == COMMAND)
		return (command (node, d));
	if (node->node_type == PREFIX)	
		return (prefix(node, d));
	if (node->node_type == SUFFIX)
		return (suffix(node, d));
	if (node->node_type == IO_REDIR)
		return (redirect(node, d));
	if (node->node_type == IO_REDIR)
		return (newline(node, d));
	return (NULL);
}

char **pipeline(t_node *node, t_data *d)
{
	//setup pipe
	//dup2 stdin
	//dup2 stdout
	execute(node->left, d);
	execute(node->right, d);
}



char **suffix(t_node *node, t_data *d)
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
