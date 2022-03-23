/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_res
{
	int	*a;
	int	*b;
	int	*ind_a;
	int	*ind_b;
}	t_res;

typedef struct s_pos
{
	int	pos_a;
	int	pos_b;
	int	mov;
}	t_pos;

t_res			ft_fill_list(int ac, char **arg, t_res result);
int				ft_check_args(int ac, char **arg);
int				ft_check_limits(int ac, char **arg);
long long int	ft_atoi_mod(const char *str);
int				ft_check_duplicates(int ac, char **arg, t_res result);
int				ft_check_dup(t_res result, int ac);
int				push_swap(t_res result, int ac);
int				ft_check_sort(t_res result, int ac);
t_res			s(char c, t_res result);
t_res			p(char c, t_res result);
t_res			r(char c, t_res result, int ac);
t_res			rr(char c, t_res result, int ac);
t_res			ft_do_start(t_res result, int ac);
t_res			ft_split_stacks(t_res result, int ac, int pivot, int init);
t_res			ft_move_b_to_a(t_res result, int ac);
t_pos			ft_find_best(t_res result, int ac, t_pos pos);
t_pos			ft_calculate_mov(t_res result, int i, int ac, t_pos pos);
t_pos			find_pos_a_2(t_res result, int ac, t_pos pos, int min);
t_pos			find_pos_a(t_res result, int ac, t_pos pos);
t_res			move_b_1(t_res result, int ac, t_pos pos);
t_res			move_b_2(t_res result, int ac, t_pos pos);
t_res			move_b_3(t_res result, int ac, t_pos pos);
t_res			move_b_4(t_res result, int ac, t_pos pos);
t_res			move_b_5(t_res result, int ac, t_pos pos);
t_res			move_b_6(t_res result, int ac, t_pos pos);
t_res			move_b_7(t_res result, int ac, t_pos pos);
t_res			move_b_8(t_res result, int ac, t_pos pos);
t_res			move_b_9(t_res result, int ac, t_pos pos);
t_res			put_min_first(t_res result, int ac);
int				ft_find_min(t_res result, int ac);
int				ft_find_max(t_res result, int ac);
t_res			move_stacks_sort(t_res result, int ac);
t_res			move_stacks_sort_2(t_res result, int ac);
t_res			move_stacks_sort_3(t_res result, int ac);
t_res			move_sort_1(t_res result, int ac, int min);
t_res			move_sort_2(t_res result, int ac, int min);

#endif
