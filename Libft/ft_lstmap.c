/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:03:08 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/06 12:25:37 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Junta um no no fim da lista nova.
** EN: Attaches one node to the end of the new list.
*/
static void	ft_lstmap_add(t_list **lst, t_list **tail, t_list *new_node)
{
	if (!*lst)
		*lst = new_node;
	else
		(*tail)->next = new_node;
	*tail = new_node;
}

/*
** PT: Limpa o conteudo atual e o que ja foi criado.
** EN: Cleans the current content and everything built so far.
*/
static void	ft_lstmap_clear(void *content, t_list **new_lst,
					void (*del)(void *))
{
	if (content)
		del(content);
	ft_lstclear(new_lst, del);
}

/*
** PT: Cria um no novo com o conteudo transformado por f.
** EN: Creates a new node with the content transformed by f.
*/
static t_list	*ft_lstmap_new(t_list *lst, t_list **new_lst,
					void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*new_node;

	content = f(lst->content);
	if (!content)
	{
		ft_lstclear(new_lst, del);
		return (NULL);
	}
	new_node = ft_lstnew(content);
	if (!new_node)
		ft_lstmap_clear(content, new_lst, del);
	return (new_node);
}

/*
** PT: Faz uma lista nova transformando cada conteudo antigo.
** EN: Builds a new list by transforming each old content value.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_lst;
	t_list	*tail;

	new_lst = NULL;
	tail = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstmap_new(lst, &new_lst, f, del);
		if (!new_node)
			return (NULL);
		ft_lstmap_add(&new_lst, &tail, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
