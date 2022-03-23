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

t_pos	find_pos_a_2(t_res result, int ac, t_pos pos, int min)
{
	int	i;

	i = min;
	while (i < (ac - 2))
	{
		if (result.a[i] < result.b[pos.pos_b]
			&& result.a[i + 1] > result.b[pos.pos_b])
			pos.pos_a = i;
		i++;
	}
	i = *result.ind_a;
	while (i < min)
	{
		if (result.a[i] < result.b[pos.pos_b]
			&& result.a[i + 1] > result.b[pos.pos_b])
				pos.pos_a = i;
		i++;
	}
	return (pos);
}

t_pos	find_pos_a(t_res result, int ac, t_pos pos)
{
	int	min;

	min = ft_find_min(result, ac);
	if (result.b[pos.pos_b] < result.a[min])
		pos.pos_a = min - 1;
	else if (min == (ac - 2) && (result.b[pos.pos_b] > result.a[min]
			&& result.b[pos.pos_b] < result.a[*result.ind_a]))
			pos.pos_a = *result.ind_a - 1;
	else
		pos = find_pos_a_2(result, ac, pos, min);
	return (pos);
}

t_res	move_b_4(t_res result, int ac, t_pos pos)
{
	int	cont;

	cont = 0;
	while (cont <= (pos.pos_a - *result.ind_a))
	{
		result = r('a', result, ac);
		result = r('b', result, ac);
		ft_putstr_fd("rr\n", 1);
		cont++;
	}
	while (cont < (pos.pos_b - *result.ind_b))
	{
		result = r('b', result, ac);
		ft_putstr_fd("rb\n", 1);
		cont++;
	}
	result = p('a', result);
	ft_putstr_fd("pa\n", 1);
	return (result);
}

t_res	move_b_3(t_res result, int ac, t_pos pos)
{
	int	cont;

	cont = 0;
	while (cont < (pos.pos_b - *result.ind_b))
	{
		result = r('a', result, ac);
		result = r('b', result, ac);
		ft_putstr_fd("rr\n", 1);
		cont++;
	}
	while (cont <= (pos.pos_a - *result.ind_a))
	{
		result = r('a', result, ac);
		ft_putstr_fd("ra\n", 1);
		cont++;
	}
	result = p('a', result);
	ft_putstr_fd("pa\n", 1);
	return (result);
}

t_res	move_b_2(t_res result, int ac, t_pos pos)
{
	int	cont;

	cont = 1;
	if ((pos.pos_b - *result.ind_b) == (pos.pos_a - *result.ind_a))
	{
		while (cont <= (pos.pos_b - *result.ind_b))
		{
			result = r('a', result, ac);
			result = r('b', result, ac);
			ft_putstr_fd("rr\n", 1);
			cont++;
		}
		result = r('a', result, ac);
		ft_putstr_fd("ra\n", 1);
		result = p('a', result);
		ft_putstr_fd("pa\n", 1);
	}
	else if ((pos.pos_b - *result.ind_b) < (pos.pos_a - *result.ind_a))
		result = move_b_3(result, ac, pos);
	else
		result = move_b_4(result, ac, pos);
	return (result);
}
