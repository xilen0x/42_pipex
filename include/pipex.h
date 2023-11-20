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
	char	*infile_path;
	char	*outfile_path;
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

// ------------------------ Utils -------------------------- //


// ------------------------ Checks ------------------------ //


// ------------------------ List & nodes ------------------ //
//t_stack	*ft_init_list(char **av);
//t_stack	*ft_newnode(int num);
//t_stack	*ft_get_last_node(t_stack *stack);
//void	ft_stack_add_back(t_stack **stack, t_stack *newnode);
//void	ft_printstack(t_stack *stack_a, t_stack *stack_b, char *str);
//int		ft_lst_size(t_stack *stack);
//int		ft_find_max(t_stack *stack);
//int		ft_find_min(t_stack *stack);


#endif