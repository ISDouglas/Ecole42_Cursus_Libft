/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:18:22 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:54:51 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_rev_rotate(t_list	**stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list	**a)
{
	ft_rev_rotate(a);
}

void	rrb(t_list	**b)
{
	ft_rev_rotate(b);
}

void	rrr(t_list	**a, t_list	**b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
}
