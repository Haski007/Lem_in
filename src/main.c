/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:23:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/06/28 16:46:36 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		print_all_err(void)
{
	int	i;

	i = -1;
	while (++i < 107)
		printf("%d) %s\n", i, strerror(i));
}

void		paint_path(t_list *path)
{
	t_room	*room;
	int		i;

	i = 0;
	while (path)
	{
		room = *(t_room**)path->content;
		++i;
		printf("%s", room->name);
		if (path->next)
			printf("--->");
		else
			printf("\n");
		path = path->next;
	}
	printf("--------------------------------------------------\n");
	printf("Number of steps = %d\n", i);
	printf("--------------------------------------------------\n");
}

void			paint_apath(t_farm farm)
{
	t_list		*list;

	list = farm.path;
	while (list)
	{
		paint_path((t_list*)list->content);
		list = list->next;
	}
}
void			paint_farm(t_list *list)
{
	while (list)
	{
		printf("%zu) ", list->content_size);
		printf("%s", list->content);
		list = list->next;
	}
}

void			paint_rooms(t_list *rooms)
{
	t_room	*room;

	while (rooms)
	{
		room = (t_room*)(rooms->content);
		printf("      ROOM: |%s| |value = %d|", room->name, room->value);
		if (room->rank == 2)
			printf("end\n\n");
		else if (room->rank == 1)
			printf("start\n\n");
		else
			printf("0_o\n\n");
		paint_links(room->tubes);
		rooms = rooms->next;
	}
}

void			paint_links(t_list *tubes)
{
	int		i;
	t_room 	*room;

	i = 0;
	while (tubes)
	{
		room = (*(t_room**)tubes->content);
		printf("link %d   -%5s\n", ++i, room->name);
		tubes = tubes->next;
	}
}

int				main(void)
{
	t_farm	farm;

	farm.rooms = save_farm(&farm);
	// heat_map(&farm);
	movement(&farm);
	// print_all_err();
	// paint_rooms(farm.rooms);
	paint_apath(farm);
	// free_list(&farm.rooms);
	// system("leaks lem-in");
	// exit(0);
	return (0);
}
