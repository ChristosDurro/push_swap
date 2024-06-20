# push_swap

`push_swap` is a sorting algorithm project that uses two stacks to sort a list of numbers with the minimum number of operations. This project demonstrates efficient sorting techniques and stack manipulation.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Available Commands](#available-commands)
- [Algorithm](#algorithm)

## Introduction

The `push_swap` project involves creating an algorithm to sort numbers using two stacks and a limited set of commands. The goal is to sort the numbers with as few operations as possible.

## Installation

To compile the `push_swap` program, clone this repository and run `make` using the provided Makefile:

```bash
git clone https://github.com/ChristosDurro/push_swap.git
cd push_swap
make
```

## Usage

To run the push_swap program, provide a sequence of numbers as arguments:

```bash
./push_swap 2 1 3 6 5 8
```

## Available Commands

The following commands are used to manipulate the stacks:

- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss: Perform sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr: Perform ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr: Perform rra and rrb at the same time.

## Algorithm

The algorithm used in push_swap involves the following steps:

- Initialization: Start by pushing two numbers from stack A to stack B.
- Iterate and Calculate: For each number in stack A, calculate the moves required to insert it into the correct position in stack B.
- Track Best Moves: Keep track of the sequence of moves that result in the least operations. If a better sequence is found, update the best sequence.
- Optimize Moves: After determining the best moves, replace sequences of ra and rb that are close to each other with rr (same for rrr) to minimize the total number of moves.
- Execute Moves: Execute the optimized sequence of moves and repeat the process for all numbers in stack A until stack A is empty and stack B is sorted.
- Final Step: Transfer the sorted numbers back to stack A.
