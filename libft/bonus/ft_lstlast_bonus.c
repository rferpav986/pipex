/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:28:38 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 17:07:27 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
int main(void)
{
    t_list *first = (t_list *)malloc(sizeof(t_list));
    first->content = "Primero";
    first->next = NULL;
    
    t_list *second = (t_list *)malloc(sizeof(t_list));
    second->content = "Segundo";
    second->next = NULL;

    t_list *third = (t_list *)malloc(sizeof(t_list));
    third->content = "Tercero";
    third->next = NULL;

    first->next = second;
    second->next = third;
    t_list *last = ft_lstlast(first);
    if (last) {
        printf("El último elemento contiene: %s\n", (char *)last->content);
    } else {
        printf("La lista está vacía.\n");
    }
    free(first);
    free(second);
    free(third);

    return 0;
}
*/
