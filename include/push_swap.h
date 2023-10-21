/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:00:04 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/21 18:51:46 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Include header files
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

// Define the data structure
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack	*parse_arguments(int argc, char *argv[]);
void	push(t_stack **stack, int value);

#endif