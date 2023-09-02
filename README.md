# 42cursus - push_swap

## About

Given a set of integers, sort it using a predefined set of instructions using
two stacks. The instruction set is defined below. This program outputs a program
in push_swap instructions that sorts the input integers.
## Instruction set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Algorithm

For the stacks with size less than 6 I wrote a simple bubble sort algorithm which.
For the stacks with size longer than 6, I used a combination of the insertion sort algorithm and the shellsort algorithm. I first move the numbers thar were already sorted from stack a to b. After that, I evaluate the number of movements requiered to place every single number that remains in the stack a to b and I choose the option that requieres less number of movements.

## How to use it  
### 1. **Compiling the archives**. 
To compile the proiect, open the terminal and run:  
```shell  
$ cd path/to/push_swap.c && make
```  
### 2. **Cleaning all binary (.o) and executable files (.a)**.  
```shell  
$ cd path/to/push_swap.c && make fclean
```  
