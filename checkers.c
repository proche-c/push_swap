/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(int ac, char **arg)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (arg[i][j])
		{
			if (ft_isdigit(arg[i][j]) != 1 && arg[i][j] != 43
				&& arg[i][j] != 45)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_limits(int ac, char **arg)
{
	long long int	*a;
	int				i;

	a = malloc((ac - 1) * sizeof(long long int));
	if (!a)
		return (1);
	i = 1;
	while (i < ac)
	{
		a[i - 1] = ft_atoi_mod(arg[i]);
		if (a[i - 1] > 2147483647 || a[i - 1] < -2147483648)
		{
			free (a);
			return (1);
		}
		i++;
	}
	free (a);
	return (0);
}

int	ft_check_dup(t_res result, int ac)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < (ac -1))
	{
		count = 0;
		j = 0;
		while (j < (ac - 1))
		{
			if (result.a[i] == result.b[j])
				count++;
			j++;
		}
		if (count > 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_duplicates(int ac, char **arg, t_res result)
{
	result = ft_fill_list(ac, arg, result);
	result.b = result.a;
	if (ft_check_dup(result, ac) == 1)
		return (1);
	return (0);
}
