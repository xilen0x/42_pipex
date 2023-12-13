/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:14:12 by castorga          #+#    #+#             */
/*   Updated: 2023/09/04 15:14:15 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>//para open
# include <sys/wait.h>//para wait

// ------------------------ Structs ------------------------ //
typedef struct s_data
{
	char	*infile;
	char	*outfile;
	int		infile_fd;
	char	outfile_fd;
	char	**args_1;
	char	**args_2;
	char	**paths;
	char	**cmd_1;
	char	**cmd_2;
	char	*cmd1_fullpath;
	char	*cmd2_fullpath;
}t_data;

void	ft_get_argvs(char **argv, t_data *data);
void	ft_get_paths(char **envp, t_data *data);
void	ft_open_files(char **argv, t_data *data);
int		ft_parse_cmds(t_data *data);
void	ft_execute(t_data *data);
int		ft_errors(int n);
#endif