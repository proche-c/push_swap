/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_res	ft_split_stacks(t_res result, int ac, int pivot, int init)
{
	int	i;

	i = 1;
	while (result.a[i] != init)
	{
		if (result.a[i] > pivot)
		{
			pivot = result.a[i];
			result = r('a', result, ac);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			result = s('a', result);
			ft_putstr_fd("sa\n", 1);
			result = p('b', result);
			ft_putstr_fd("pb\n", 1);
			i++;
		}
	}
	return (result);
}

t_res	ft_do_start(t_res result, int ac)
{
	int	pivot;
	int	init;
	int	max;

	max = ft_find_max(result, ac);
	if (max == 0)
	{
		result = r('a', result, ac);
		ft_putstr_fd("ra\n", 1);
	}
	pivot = result.a[0];
	init = pivot;
	result = ft_split_stacks(result, ac, pivot, init);
	return (result);
}

t_pos	ft_find_best(t_res result, int ac, t_pos pos)
{
	int	i;
	int	m_mov;

	i = *result.ind_b;
	pos = ft_calculate_mov(result, i, ac, pos);
	m_mov = pos.mov;
	pos.pos_b = i;
	i = i + 1;
	while (i < (ac - 1))
	{
		pos = ft_calculate_mov(result, i, ac, pos);
		if (pos.mov < m_mov)
		{
			m_mov = pos.mov;
			pos.pos_b = i;
		}
		i++;
	}
	return (pos);
}

t_res	ft_move_b(t_res result, int ac, t_pos pos)
{
	if (result.b[pos.pos_b] < result.a[*result.ind_a]
		&& result.b[pos.pos_b] > result.a[ac - 2])
		result = move_b_9(result, ac, pos);
	else
	{
		if (pos.pos_b == *result.ind_b)
			result = move_b_1(result, ac, pos);
		else if (pos.pos_b <= ((*result.ind_b + ac) / 2)
			&& pos.pos_a <= ((*result.ind_a + ac) / 2))
			result = move_b_2(result, ac, pos);
		else if (pos.pos_b > ((*result.ind_b + ac) / 2)
			&& pos.pos_a > ((*result.ind_a + ac) / 2))
			result = move_b_5(result, ac, pos);
		else
			result = move_b_8(result, ac, pos);
	}
	return (result);
}

t_res	ft_move_b_to_a(t_res result, int ac)
{
	t_pos	pos;
	int		min;

	pos.pos_a = 0;
	pos.pos_b = 0;
	pos.mov = 0;
	while (*result.ind_a > 0)
	{
		pos = ft_find_best(result, ac, pos);
		pos = find_pos_a(result, ac, pos);
		result = ft_move_b(result, ac, pos);
	}
	min = ft_find_min(result, ac);
	result = put_min_first(result, ac);
	return (result);
}
