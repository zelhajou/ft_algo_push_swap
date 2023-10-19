/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:00:04 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/19 13:38:32 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// Include header files
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "ft_printf.h"

// Define the data structure
typedef struct Node
{
	int			data;
	struct Node	*next;

}	t_node;

typedef struct Stack {
    t_node* top;
}	Stack;

int parseArguments(int argc, char *argv[], Stack *stackA);

#endif