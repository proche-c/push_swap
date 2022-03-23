/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_res	move_sort_2(t_res result, int ac, int min)
{
	int	cont;

	cont = 1;
	while (cont < (ac - min))
	{
		result = rr('a', result, ac);
		ft_putstr_fd("rra\n", 1);
		cont++;
	}
	p('b', result);
	ft_putstr_fd("pb\n", 1);
	return (result);
}

t_res	move_sort_1(t_res result, int ac, int min)
{
	int	cont;

	cont = 0;
	while (cont < (min - *result.ind_a))
	{
		result = r('a', result, ac);
		ft_putstr_fd("ra\n", 1);
		cont++;
	}
	p('b', result);
	ft_putstr_fd("pb\n", 1);
	return (result);
}

t_res	move_stacks_sort(t_res result, int ac)
{
	int		min;
	int		i;
	t_pos	pos;

	pos.pos_a = 0;
	pos.pos_b = ac - 2;
	i = 0;
	while (i <= ((ac - 2) / 2))
	{
		min = ft_find_min(result, ac);
		if (min == *result.ind_a)
		{
			p('b', result);
			ft_putstr_fd("pb\n", 1);
		}
		else if (min <= ((*result.ind_a + ac - 2) / 2))
			result = move_sort_1(result, ac, min);
		else
			result = move_sort_2(result, ac, min);
		pos.pos_a = pos.pos_a + 1;
		pos.pos_b = pos.pos_b - 1;
		i++;
	}
	return (result);
}

t_res	move_stacks_sort_2(t_res result, int ac)
{
	int	max;

	max = ft_find_max(result, ac);
	if (max == *result.ind_a)
	{
		result = r('a', result, ac);
		ft_putstr_fd("ra\n", 1);
	}
	else if (max == (*result.ind_a + 1))
	{
		result = rr('a', result, ac);
		ft_putstr_fd("rra\n", 1);
	}
	if (result.a[*result.ind_a] > result.a[*result.ind_a + 1])
	{
		result = s('a', result);
		ft_putstr_fd("sa\n", 1);
	}
	return (result);
}

t_res	move_stacks_sort_3(t_res result, int ac)
{
	int	cont;

	cont = 0;
	while (cont <= (ac - *result.ind_b))
	{
		p('a', result);
		ft_putstr_fd("pa\n", 1);
		cont++;
	}
	return (result);
}
