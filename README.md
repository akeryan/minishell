# Overview
The Minishell project is a fundamental part of the 42 curriculum designed to deepen your understanding of Unix system programming and shell implementation. This project involves creating a simple, yet functional, Unix shell that can execute commands, handle pipelines, and manage environment variables. It’s an excellent exercise for developing a strong grasp of process management, memory allocation, and user input handling.
# Features
- **Command Execution**: Supports execution of binaries from the system PATH.
- **Built-in Commands**: Implements basic built-in commands like cd, echo, pwd, export, unset, and exit.
- **Pipelines**: Allows the use of pipelines (e.g., ls | grep minishell) for chaining commands.
- **Redirections**: Handles input (<), output (>), and append (>>) redirections.
- **Signal Handling**: Manages Unix signals (e.g., SIGINT, SIGQUIT) to handle interrupts gracefully.
- **Environment Variables**: Supports setting, unsetting, and using environment variables within commands.
- **Error Handling**: Provides robust error detection and reporting for invalid commands, redirections, and system calls.

# Technical Details
## Process Management
The shell uses **fork()** to create new processes and **execve()** to execute commands. It also employs **waitpid()** to handle child process termination, ensuring proper synchronization between the parent and child processes.

## Command Parsing
Commands are parsed using a lexer and parser approach to handle complex input cases, including quotes, escape characters, and nested commands. Tokenization breaks down the input string into manageable components for execution.

## Memory Management
Dynamic memory allocation is extensively used for handling user input, environment variables, and command execution. Proper memory management practices are employed to avoid leaks and ensure efficient resource utilization.

## Redirections and Pipes
The shell uses file descriptors to manage input and output redirections. For pipelines, the **pipe()** system call creates communication channels between processes, allowing the output of one command to serve as the input to another.

## Signal Handling
Custom signal handlers are implemented to manage signals like **SIGINT** (Ctrl+C) and **SIGQUIT** (Ctrl+). These handlers ensure the shell can respond to user interrupts without crashing.

# Installation
To build and run the Minishell project, follow these steps:
1. Clone the repository:
   
![clone repository](https://github.com/akeryan/minishell/blob/main/images/clone.png)

2. Compile the project:

![compile project](https://github.com/akeryan/minishell/blob/main/images/make.png)

3. Run the shell:

![run the shell](https://github.com/akeryan/minishell/blob/main/images/run.png)
