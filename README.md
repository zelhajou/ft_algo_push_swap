# push swap

## Overview

The "push_swap" project at 42 is a programming challenge that involves sorting a stack of integers using a limited set of instructions. The goal is to develop an efficient algorithm that can transform an unsorted stack into a sorted one, using only a predefined set of operations like pushing and swapping elements between two stacks. It requires to choose the most optimized algorithm data sorting solution. It's a test of both algorithmic problem-solving and coding skills.

## Objectives 
The project aims to introduce developers to sorting algorithms and their complexities. It emphasizes the importance of understanding algorithmic complexity and the challenges of optimizing sorting for different configurations of integers.

## The rules

Two stacks named 'a' and 'b' are provided. Stack 'a' contains random integers, while stack 'b' is empty. The goal is to sort the numbers in stack 'a' using specific operations like swap, push, rotate, etc

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


## My algorithm

The algorithm is a variation of a divide-and-conquer sorting method designed specifically for two stacks. The approach combines concepts from selection sort, insertion sort, and merge sort.

**Algorithm approach**: The algorithm takes a divide-and-conquer approach for stacks larger than three. It divides stack_a into smaller chunks and pushes these chunks to stack_b. It then sorts the remaining elements in stack_a and gradually pushes back elements from stack_b to stack_a in a sorted manner.

**Stack structure**: The stack structure (t_stack) is assumed to have at least two members: value, which is the integer value of the element, and index, which is the initial position or index of the element in the unsorted stack_a. The stack is implemented as a singly linked list, given the presence of the next pointer

### Step 1: Determine Sorting Approach:

1. Given a list of numbers in Stack A
2. Determine the size of Stack A. The `ft_sort`` function first checks the size of the stack.
3. The function then checks:

- If the size is 2, it calls **`ft_sort_two`**.
- If the size is 3, it calls **`ft_sort_three`**.
- For sizes larger than 3, it calls **`handle_large_sort`** and continue to the next step..

**Calculation**: Determine the size of stack_a.
```c
size = ft_stack_size(*stack_a);
```

**Purpose**: To understand which sorting method to use. Smaller sizes can use simple methods, while larger ones need a more intricate approach.

### Step 2: Divide and Move to Stack B (Divide and Conquer:)

- Based on the size of Stack A, choose a partitioning criterion. This criterion is often based on pivots or ranges of numbers. and partitioned into third
- Push a fraction of numbers from Stack A to Stack B based on the chosen partitioning criterion. The goal is to leave only a small chunk (say, 3 numbers) in Stack A.



#### Partitioning:

**Calculation**: Compute size-based partitions (or pivots) of `stack_a`.

```c
size = ft_stack_size(*stack_a) / 3
```
gives an indication of how many elements to move from `stack_a` to `stack_b` in each pass.

**Purpose:** By creating size-based partitions, the algorithm can manage a controlled number of elements, ensuring that only a small, easily sortable number of elements remain in stack_a.

In **`handle_large_sort`**, the function **`ft_divide_and_move`** is called.

```c
ft_divide_and_move(stack_a, stack_b);
```
This function will repeatedly partition **`stack_a`** and push some elements to **`stack_b`** until **`stack_a`** has only 3 elements left.

#### Moving Elements:

**Calculation**: Within the `ft_partition_and_move` function, the algorithm determines whether the current element should be moved to `stack_b` based on its index and the pivot value. If an element's index is less than the pivot value, it's a candidate to be moved to `stack_b`.

**Purpose**: To distribute elements between the stacks based on their relative values, preparing for the merging phase.

### Step 3: Sort the three elements

With only a few numbers left in Stack A, use simple comparison-based methods to sort them. This is done with `ft_sort_three` in the provided code.

```c
ft_sort_three(stack_a);
```

**Calculation**: For a chunk of three numbers in stack_a, the algorithm calculates their relative order using comparison operations in the `handle_sorting_cases` function.

**Purpose**: This is a straightforward sorting of a small number of elements, ensuring that they're in the correct order before the merging phase

### Step 4: Move back elements from Stack B
Gradually move numbers back from Stack B to Stack A, ensuring they're inserted in the correct order.

## Getting Started

Follow these steps to get started with the Push Swap project:

1. Clone the repository:

```bash
git clone https://github.com/zelhajou/push_swap.git
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
## Folder structure
 * [lib](./lib) `external libraries`
   * [ft_printf](./lib/ft_printf)
   * [libft](./lib/libft)
 * [include](./include) `Header files`
   * [push_swap.h](./include/push_swap.h)
 * [bin](./bin) `Object files (generated by Makefile)`
 * [src](./src) `Source code files` 
   * [stack_operations.c](./src/stack_operations.c) `Stack manipulation functions`
   * [sorting.c](./src/sorting_algorithm.c) `Sorting algorithm implementation`
   * [validation.c](./src/validation.c) `Input validation functions`
   * [push_swap.c](./src/push_swap.c) `Main program file`
   * [utils.c](./src/utils.c) `Utility functions`
 * [Makefile](./Makefile) `Makefile for building the project`

-->


