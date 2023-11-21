/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:59:31 by castorga          #+#    #+#             */
/*   Updated: 2023/10/18 12:59:33 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*Función que obtiene y guarda los argv*/
void	ft_get_argvs(char **argv, t_data *data)
{
	data->infile = argv[1];
	data->args_1 = ft_split(argv[2], ' ');
	data->args_2 = ft_split(argv[3], ' ');
	data->outfile = argv[4];
}

/*Función que obtiene y guarda los envp path*/
void	ft_get_paths(char **envp, t_data *data)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	data->paths = ft_split(&envp[i][5], ':');
}

/*Funcion que abre los archivos de entrada y salida*/
void	ft_open_files(char **argv, t_data *data)
{
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd == -1)
		ft_errors(2);
	data->outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (data->outfile_fd == -1)
		ft_errors(3);
}
