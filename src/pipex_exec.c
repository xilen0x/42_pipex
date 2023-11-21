#include "../include/pipex.h"

/*Función que ejecuta los comandos cmd1_fullpath y cmd2_fullpath conectando
 la salida del primero con la entrada del segundo mediante un pipe.*/
void	ft_execute(t_data *data)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
	{
		dup2(data->infile_fd, STDIN_FILENO);//Redirigir la entrada estándar al archivo de entrada
		close(fd[0]);//Se cierra el descriptor de lectura del pipe (fd[0]) ya que no se utilizará en este proceso.
		dup2(fd[1], STDOUT_FILENO);//Se redirige la salida estándar al fd[1] para que la salida del primer comando vaya al pipe.
		execve(data->cmd1_fullpath, data->args_1, NULL);//Se ejecuta el primer comando
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
