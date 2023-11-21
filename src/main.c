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

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc != 5)
		ft_errors(1);
	else
	{
		ft_get_argvs(argv, &data);
		ft_get_paths(envp, &data);
		ft_open_files(argv, &data);
		ft_parse_cmds(&data);
		ft_execute(&data);
	}
	return (0);
}
