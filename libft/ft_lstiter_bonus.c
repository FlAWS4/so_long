/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:11:30 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/04 17:22:29 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(&lst->number);
		lst = lst->next;
	}
}

void	func(void *number)
{
	*(int *)number += 1;
}
/*
int	main()
{
	int	*data1 = malloc(sizeof(int));
	int	*data2 = malloc(sizeof(int));
	int	*data3 = malloc(sizeof(int));

	*data1 = 1;
	*data2 = 2;
	*data3 = 3;
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew(data1));
	ft_lstadd_back(&list, ft_lstnew(data2));
	ft_lstadd_back(&list, ft_lstnew(data3));
	
	ft_lstiter(list, func);
	while (list)
	{
		printf("%d\n", *(int *)list->number);
		list = list->next;
	}	
}*/