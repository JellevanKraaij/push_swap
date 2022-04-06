/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 17:29:42 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/12/17 16:57:41 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_p(const char *str, int *number)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	if (*str == '-' && ft_isdigit(*(str + 1)))
	{
		sign = -1;
		str++;
	}
	else if (*str == '+' && ft_isdigit(*(str + 1)))
		str++;
	while (ft_isdigit(*str))
	{
		ret = (ret * 10) + (*str - '0');
		if ((sign == 1 && ret > INT_MAX) \
		|| (sign == -1 && (ret * sign) < INT_MIN))
			return (-1);
		str++;
	}
	if (*str != '\0')
		return (-1);
	ret *= sign;
	*number = (int)ret;
	return (0);
}
