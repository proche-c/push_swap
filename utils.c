/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == 32)
		return (1);
	return (0);
}

static int	ft_check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

long long int	ft_atoi_mod(const char *str)
{
	int				i;
	int				sign;
	long long int	num;
	long long int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = ft_check_sign(str[i]);
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		num = str[i] - 48;
		result = result * 10 + num;
		i++;
	}
	return (result * sign);
}

t_res	ft_fill_list(int ac, char **arg, t_res result)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		result.a[i - 1] = ft_atoi(arg[i]);
		i++;
	}
	*result.ind_a = 0;
	*result.ind_b = ac - 1;
	return (result);
}

int	ft_check_sort(t_res result, int ac)
{
	int	i;

	if (*result.ind_a != 0)
		return (0);
	i = 0;
	while (i < (ac - 2))
	{
		if (result.a[i] > result.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
