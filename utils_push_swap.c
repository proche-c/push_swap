/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pos	ft_calculate_mov(t_res result, int i, int ac, t_pos pos)
{
	if (i == *result.ind_b)
		pos.mov = 1;
	else if (i <= ((ac - 1 + *result.ind_b) / 2))
			pos.mov = i - *result.ind_b + 1;
	else
		pos.mov = ac - i;
	pos.pos_a = *result.ind_a;
	while (result.b[i] > result.a[pos.pos_a])
		pos.pos_a++;
	if (pos.pos_a < (ac - 2 + *result.ind_a) / 2)
		pos.mov = pos.mov + (pos.pos_a - *result.ind_a + 1);
	else
		pos.mov = pos.mov + (ac - pos.pos_a + 1);
	return (pos);
}

int	ft_find_min(t_res result, int ac)
{
	int	min;
	int	i;

	min = *result.ind_a;
	i = *result.ind_a;
	while (i <= (ac - 2))
	{
		if (result.a[i] < result.a[min])
			min = i;
		i++;
	}
	return (min);
}

int	ft_find_max(t_res result, int ac)
{
	int	max;
	int	i;

	max = *result.ind_a;
	i = *result.ind_a;
	while (i <= (ac - 2))
	{
		if (result.a[i] > result.a[max])
			max = i;
		i++;
	}
	return (max);
}

t_res	put_min_first_2(t_res result, int ac, int min)
{
	int	cont;

	if (min <= ((ac - 2) / 2))
	{
		cont = 1;
		while (cont++ < min)
		{
			result = r('a', result, ac);
			ft_putstr_fd("ra\n", 1);
		}
		result = r('a', result, ac);
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		cont = 2;
		while (cont++ < ac)
		{
			result = rr('a', result, ac);
			ft_putstr_fd("rra\n", 1);
		}
		result = rr('a', result, ac);
		ft_putstr_fd("rra\n", 1);
	}
	return (result);
}

t_res	put_min_first(t_res result, int ac)
{
	int	min;

	min = ft_find_min(result, ac);
	if (min == *result.ind_a)
		return (result);
	else
		result = put_min_first_2(result, ac, min);
	return (result);
}
