/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_res	move_b_8(t_res result, int ac, t_pos pos)
{
	int	cont;

	cont = 0;
	if (pos.pos_b <= ((ac + *result.ind_b) / 2))
	{
		while (cont < (pos.pos_b - *result.ind_b))
		{
			result = r('b', result, ac);
			ft_putstr_fd("rb\n", 1);
			cont++;
		}
		result = move_b_1(result, ac, pos);
	}
	else
	{
		cont = 1;
		while (cont < (ac - pos.pos_b))
		{
			result = rr('b', result, ac);
			ft_putstr_fd("rrb\n", 1);
			cont++;
		}
		result = move_b_1(result, ac, pos);
	}
	return (result);
}

t_res	move_b_7(t_res result, int ac, t_pos pos)
{
	int	cont;

	cont = 2;
	while (cont < (ac - pos.pos_a))
	{
		result = rr('a', result, ac);
		result = rr('b', result, ac);
		ft_putstr_fd("rrr\n", 1);
		cont++;
	}
	cont = 0;
	while (cont <= (pos.pos_a - pos.pos_b))
	{
		result = rr('b', result, ac);
		ft_putstr_fd("rrb\n", 1);
		cont++;
	}
	result = p('a', result);
	ft_putstr_fd("pa\n", 1);
	return (result);
}

t_res	move_b_6(t_res result, int ac, t_pos pos)
{
	int	cont;

	cont = 1;
	while (cont < (ac - pos.pos_b))
	{
		result = rr('a', result, ac);
		result = rr('b', result, ac);
		ft_putstr_fd("rrr\n", 1);
		cont++;
	}
	cont = 1;
	while (cont < (pos.pos_b - pos.pos_a))
	{
		result = rr('a', result, ac);
		ft_putstr_fd("rra\n", 1);
		cont++;
	}
	result = p('a', result);
	ft_putstr_fd("pa\n", 1);
	return (result);
}

t_res	move_b_5(t_res result, int ac, t_pos pos)
{
	int	cont;

	cont = 1;
	if ((ac - 2 - pos.pos_b) == (ac - 2 - pos.pos_a))
	{
		while (cont <= (ac - 2 - pos.pos_b))
		{
			result = rr('a', result, ac);
			result = rr('b', result, ac);
			ft_putstr_fd("rrr\n", 1);
			cont++;
		}
		result = rr('b', result, ac);
		ft_putstr_fd("rrb\n", 1);
		result = p('a', result);
		ft_putstr_fd("pa\n", 1);
	}
	else if ((ac - 2 - pos.pos_b) < (ac - 2 - pos.pos_a))
		result = move_b_6(result, ac, pos);
	else
		result = move_b_7(result, ac, pos);
	return (result);
}
