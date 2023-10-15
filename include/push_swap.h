/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:00:04 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/04 17:45:55 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// Include header files
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"	   // Example: Include your local "libft" library header
#include "ft_printf.h" // Example: Include your local "ft_printf" library header

// Define the data structure
typedef struct node
{
	int data;
	struct node *next;

} node_t;

#endif