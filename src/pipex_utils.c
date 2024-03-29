/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:40:39 by castorga          #+#    #+#             */
/*   Updated: 2023/10/18 13:40:41 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*funcion que crea el fullpath del comando y verifica si existe
para poder guardarlo o no*/
static int	search_command_path1(char *cmd, t_data *data)
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
			data->cmd1_fullpath = full_path;
			return (0);
		}
		i++;
	}
	return (1);
}

/*idem search_command_path1*/
static int	search_command_path2(char *cmd, t_data *data)
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
	return (1);
}

/*Función puente que envia los comandos 1 y 2 a search_command_path */
int	ft_parse_cmds(t_data *data)
{
	if (search_command_path1(data->args_1[0], data) == 1)
	{
		ft_errors(4);
		return (1);
	}
	if (search_command_path2(data->args_2[0], data) == 1)
	{
		ft_errors(4);
		return (1);
	}
	return (0);
}

/*Funcion que muestra mensaje de error y uso correcto*/
int	ft_errors(int n)
{
	if (n == 1)
	{
		write (2, "Use: ./pipex file1 \"1st_com\" \"2nd_com\" file2\n", 53);
		return (1);
	}
	else if (n == 2)
	{
		write (2, "bash: infile: No such file or directory\n", 40);
		exit(1);
	}
	else if (n == 3)
	{
		write (2, "bash: outfile: Permission denied\n", 33);
		exit(1);
	}
	else if (n == 4)
	{
		write (2, "Command not found!\n", 19);
		exit(1);
	}
	else
		write (2, "error", 5);
	return (1);
}
