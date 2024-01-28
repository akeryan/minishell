/* GNU bash, version 3.2.57(1)-release (x86_64-apple-darwin19)
Copyright (C) 2007 Free Software Foundation, Inc. */

#ifndef EXECUTE_H
# define EXECUTE_H

#include <unistd.h>
#include "node.h"
#include "pid_list.h"
#include "pipe_list.h"


typedef struct s_data 
{
	char		**env;
	t_pid_node	*pid_list;
	t_pipe_node	*pipe_list;
 } t_data;

 

#endif