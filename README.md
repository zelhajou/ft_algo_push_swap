# push swap

## Overview

The "push_swap" project at 42 is a programming challenge that involves sorting a stack of integers using a limited set of instructions. The goal is to develop an efficient algorithm that can transform an unsorted stack into a sorted one, using only a predefined set of operations like pushing and swapping elements between two stacks. It's a test of both algorithmic problem-solving and coding skills.

## The rules

- You have 2 stacks named `a` and `b`.
- At the beginning:
   - The stack `a` contains a random amount of negative and/or positive numbers
which cannot be duplicated.
   - The stack `b` is empty.
- The goal is to sort in ascending order numbers into stack `a`. To do so you have the
following operations at your disposal:
   - `sa` (swap a): Swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements.
   - `sb` (swap b): Swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements.
   - `ss` : `sa` and `sb` at the same time.
   - `pa` (push a): Take the first element at the top of `b` and put it at the top of `a`. Do nothing if b is empty.
   - `pb` (push b): Take the first element at the top of `a` and put it at the top of `b`. Do nothing if a is empty.
   - `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
   - `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
   - `rr` : `ra` and `rb` at the same time.
   - `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
   - `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
   - `rrr` : `rra` and `rrb` at the same time

## Features

- Sorts a stack of integers using push and swap operations.
- Implements an optimized sorting algorithm.
- Provides detailed instructions on running the program and testing.
- Offers a clear and well-structured codebase for easy understanding and modification.

## Getting Started

Follow these steps to get started with the Push Swap project:

1. Clone the repository:

```bash
git clone https://github.com/yourusername/push-swap.git
```
2. Compile the project:

```bash
make
```

3. Run the program with your input:

```bash
./push_swap 3 2 1
```

4. Test the program:
```bash
./push_swap 3 2 1 | ./checker 3 2 1
````

##  Usage
Replace `3` `2` `1` with your own input numbers for testing.
View the detailed usage instructions and available options in the project documentation.

<!--
## Contributing
Contributions are welcome! If you'd like to contribute to the Push Swap project, please follow these guidelines:

1. Fork the repository.
2. Create a new branch: git checkout -b feature/your-feature-name.
3. Make your changes and commit them: git commit -m 'Add some feature'.
4. Push to your branch: git push origin feature/your-feature-name.
Create a pull request, describing your changes and their purpose.

-->
