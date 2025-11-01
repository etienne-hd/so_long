/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:18:26 by ehode             #+#    #+#             */
/*   Updated: 2025/10/16 19:20:24 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_lst;
	t_list	*temp_lst;

	if (!lst || !del)
		return ;
	current_lst = *lst;
	while (current_lst)
	{
		temp_lst = current_lst;
		current_lst = current_lst->next;
		del(temp_lst->content);
		free(temp_lst);
	}
	*lst = NULL;
}
