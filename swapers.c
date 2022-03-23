/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_res	s(char c, t_res result)
{
	int	temp;

	if (c == 'a')
	{
		temp = result.a[*result.ind_a];
		result.a[*result.ind_a] = result.a[*result.ind_a + 1];
		result.a[*result.ind_a + 1] = temp;
	}
	else
	{
		temp = result.b[*result.ind_b];
		result.b[*result.ind_b] = result.b[*result.ind_b + 1];
		result.b[*result.ind_b + 1] = temp;
	}
	return (result);
}	

t_res	p(char c, t_res result)
{
	if (c == 'a')
	{
		result.a[*result.ind_a - 1] = result.b[*result.ind_b];
		*result.ind_a = *result.ind_a - 1;
		*result.ind_b = *result.ind_b + 1;
	}
	else
	{
		result.b[*result.ind_b - 1] = result.a[*result.ind_a];
		*result.ind_b = *result.ind_b - 1;
		*result.ind_a = *result.ind_a + 1;
	}
	return (result);
}

t_res	r(char c, t_res result, int ac)
{
	int	temp;
	int	i;

	if (c == 'a')
	{
		temp = result.a[*result.ind_a];
		i = *result.ind_a - 1;
		while (++i < (ac - 2))
			result.a[i] = result.a[i + 1];
		result.a[ac - 2] = temp;
	}
	else
	{
		temp = result.b[*result.ind_b];
		i = *result.ind_b - 1;
		while (++i < (ac - 2))
			result.b[i] = result.b[i + 1];
		result.b[ac - 2] = temp;
	}
	return (result);
}

t_res	rr(char c, t_res result, int ac)
{
	int	temp;
	int	i;

	if (c == 'a')
	{
		temp = result.a[ac - 2];
		i = ac - 1;
		while (--i > *result.ind_a)
			result.a[i] = result.a[i - 1];
		result.a[*result.ind_a] = temp;
	}
	else
	{
		temp = result.b[ac - 2];
		i = ac - 1;
		while (--i > *result.ind_b)
			result.b[i] = result.b[i - 1];
		result.b[*result.ind_b] = temp;
	}
	return (result);
}
