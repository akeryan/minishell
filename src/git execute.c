#include "execute.h"

char **execute(t_node *node)
{
	if (node->node_type == PIPELINE)
		return (pipeline(node));
	if (node->node_type == COMMAND)
		return (command (node));
	if (node->node_type == PREFIX)	
		return (prefix(node));
	else //....
}

char **pipeline(t_node *node)
{
	//setup pipe
	//dup2 stdin
	//dup2 stdout
	execute(node->left);
	execute(node->right);
}

char **command(t_node *node)
{
	char **argv;

	//fork()
	execute(node->left); //prefix
	argv = execute(node->right); //suffix
	//execve(WORD)	
}

char **prefix(t_node *node)
{
	
}



