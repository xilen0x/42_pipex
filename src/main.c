/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:40:25 by castorga          #+#    #+#             */
/*   Updated: 2023/10/18 13:40:29 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Archivos a entregar:Makefile, *.h, *.c
Makefile: NAME, all, clean, fclean, re
Argumentos: archivo1 comando1 comando2 archivo2

Funciones autorizadas: • open, close, read, write, malloc, free, perror, strerror, access, dup, 
dup2, execve, exit, fork, pipe, unlink, wait, waitpid, ft_printf, libft and any equivalent YOU coded

Descripción: Este proyecto va sobre el manejo de pipes. Tu programa deberá ejecutarse de la siguiente forma:
	./pipex archivo1 comando1 comando2 archivo2

Deberá utilizar 4 argumentos:
• archivo1 y archivo2 son nombres de arhivos.
• comando1 y comando2 son comandos de shell con sus respectivos parámetros.

La ejecución del programa pipex deberá hacer lo mismo que el siguiente comando:
	$> < archivo1 comando1 | comando2 > archivo2
Ejemplo
	$> ./pipex infile "ls -l" "wc -l" outfile
deberá hacer lo mismo que 
			 “<infile ls -l | wc -l >outfile”
*/

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

static int	ft_look_for_cmd1(char *cmd, t_data *data)
{
	char	*cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	while (data->paths[i])//falta estudiar + este while
	{
		cmd_path = ft_strjoin("/", cmd);
		full_path = ft_strjoin(data->paths[i], cmd_path);
		free(cmd_path);
		if (access(full_path, F_OK) == 0)
		{
			data->cmd1_fullpath = full_path;
			return (0);
		}
		i++;
	}
	return (0);
}

static int	ft_look_for_cmd2(char *cmd, t_data *data)
{
	char	*cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	while (data->paths[i])
	{
		cmd_path = ft_strjoin("/", cmd);
		full_path = ft_strjoin(data->paths[i], cmd_path);
		free(cmd_path);
		if (access(full_path, F_OK) == 0)
		{
			data->cmd2_fullpath = full_path;
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_parse_cmds(t_data *data)
{
	if (ft_look_for_cmd1(data->args_1[0], data) == 1)
		return (1);
	if (ft_look_for_cmd2(data->args_2[0], data) == 1)
		return (1);
	return (0);
}

void	ft_check(char **argv, t_data *data)
{
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd == -1)
	{
		//ft_printf("bash: %s", data->infile_path);
		perror("Error trying to open file!");
		return ;
	}
	data->outfile_fd = open(argv[4], O_WRONLY);
	if (data->outfile_fd == -1)
	{
		//ft_printf("bash: %s", data->outfile_path);
		perror("Error trying to write to file!");
		return ;
	}

}

static void	ft_get_args(char **argv, t_data *data)
{
	data->args_1 = ft_split(argv[2], ' ');
	data->args_2 = ft_split(argv[3], ' ');
}

static void	ft_get_paths(char **envs, t_data *data)
{
	int	i;

	i = 0;
	while (ft_strnstr(envs[i], "PATH=", 5) == NULL)
		i++;
	data->paths = ft_split(&envs[i][5], ':');
}

void	ft_init_pipex(char **argv, char **envs, t_data *data)
{
	data->infile_path = argv[1];
	data->outfile_path = argv[4];
	ft_get_args(argv, data);
	ft_get_paths(envs, data);

}

int	main(int argc, char *argv[], char *envs[])
{
	t_data	data;

	if (argc == 5)
	{
		ft_init_pipex(argv, envs, &data);
		ft_check(argv, &data);
		ft_parse_cmds(&data);
		ft_execute(&data);
	}
	return (0);
}

/* Test propios:
$ <infile ls -l | wc -l >outfile
$ cat outfile
10

$ <infile cat | grep "ho"  >outfile
$ cat outfile 
holamundo
hohoho

*/