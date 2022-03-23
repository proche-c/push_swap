/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_res result, int ac)
{
	if (ft_check_sort(result, ac) == 1)
		return (0);
	result.b = malloc((ac - 1) * sizeof(int));
	if (!result.b)
		return (1);
	else
	{
		if (ac > 7)
		{
			result = ft_do_start(result, ac);
			result = ft_move_b_to_a(result, ac);
		}
		else
		{
			result = move_stacks_sort(result, ac);
			result = move_stacks_sort_2(result, ac);
			result = move_stacks_sort_3(result, ac);
		}
	}
	free(result.ind_a);
	free(result.ind_b);
	free(result.b);
	return (0);
}
