/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **arg)
{
	t_res	result;

	result.a = malloc((ac - 1) * sizeof(int));
	result.ind_a = malloc(sizeof(int *));
	result.ind_b = malloc(sizeof(int *));
	if (!result.a || !result.ind_a || !result.ind_b)
		return (1);
	if (ac < 2)
		ft_putstr_fd("Error\n", 1);
	else if (ft_check_args(ac, arg) == 1)
		ft_putstr_fd("Error\n", 1);
	else if (ft_check_limits(ac, arg) == 1)
		ft_putstr_fd("Error\n", 1);
	else if (ft_check_duplicates(ac, arg, result) == 1)
		ft_putstr_fd("Error\n", 1);
	else
	{
		result = ft_fill_list(ac, arg, result);
		push_swap(result, ac);
	}
	free(result.a);
	return (0);
}
