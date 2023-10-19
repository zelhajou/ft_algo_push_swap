/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:33:14 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/19 13:52:20 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function to parse command line arguments and initialize stacks.
int parseArguments(int argc, char* argv[], Stack* stackA) {
    // Check if the number of arguments is valid.
    if (argc < 2) {
        printf("Usage: %s <integer1> <integer2> ... <integerN>\n", argv[0]);
        return 1; // Exit with an error code.
    }

    // Initialize stackA.
    stackA->top = NULL;

    // Parse integers from command line arguments and push them onto stackA.
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]); // Convert string to integer.
        push(stackA, value);
    }

	/*
	
	// Parse integers from command line arguments and push them onto stackA.
    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];

        // Check if the argument is enclosed in quotes.
        if (arg[0] == '"') {
            // Extract the number from the quoted string.
            int value = atoi(arg + 1); // Skip the opening quote.

            // Push the extracted value onto stackA.
            push(stackA, value);
        } else {
            // If the argument is not enclosed in quotes, parse it as an integer.
            int value = atoi(arg);
            push(stackA, value);
        }
	
	*/

    return 0; // Success.
}