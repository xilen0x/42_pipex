#include "../include/pipex.h"

void	ft_execute(t_data *data)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
	{
		dup2(data->infile_fd, STDIN_FILENO);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(data->cmd1_fullpath, data->args_1, NULL);
		close(fd[1]);
		exit(0);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(data->outfile_fd, STDOUT_FILENO); 
		execve(data->cmd2_fullpath, data->args_2, NULL);
		close(fd[0]);
	}
}
