# push_swap

Sort a stack of integers using two stacks and eleven instructions — as few
moves as possible.

> Part of the **42 school curriculum**. Built by **Arda Aycan**.

The interesting part is not sorting itself, but doing it with a tiny instruction
set where every rotation costs a move and every move is counted.

## How it works

The program implements the **cheapest-move** strategy (often called the Turk
algorithm):

1. If the stack is already sorted, print nothing.
2. Two or three numbers get their own short paths (`sa`, `ra`, `rra`).
3. Otherwise:
   - Push numbers to stack B in a way that keeps the larger half in A, then
     index every node by its final position.
   - For every node in B, find its target in A (the next larger value) and
     compute the cost of bringing both to the top: rotate up or down, and
     whether both rotations can share a `rr`/`rrr`.
   - Mark the cheapest node and execute its combined rotations, then `pa`.
   - When B is empty, rotate A until the smallest value is on top.

The cost is computed once per pass; the stack is a doubly linked list, so
`prev` and `next` make both directions equally cheap.

## Build

```bash
make        # builds ./push_swap
make clean
make fclean
make re
```

Only the C standard library; `-Wall -Wextra -Werror`.

## Usage

```bash
./push_swap 2 1 0
./push_swap 4 67 3 87 23
./push_swap "3 2 1"        # a single quoted string also works
```

Output is one instruction per line, from the eleven allowed operations:

`sa` `sb` `ss` · `pa` `pb` · `ra` `rb` `rr` · `rra` `rrb` `rrr`

If the numbers are already sorted, nothing is printed.

Examples from a run of this build (random permutations, counts vary):

| Input | Instructions |
| --- | --- |
| 3 numbers | 0–3 |
| 5 numbers | about 5–9 |
| 100 numbers | about 580 |
| 500 numbers | about 5400 |

## Rules the input must follow

- Only integers that fit in an `int`.
- No duplicates.
- Arguments may be separate (`./push_swap 3 1 2`) or one quoted string
  (`./push_swap "3 1 2"`).

Anything else — letters, empty arguments, overflow, repeated numbers — prints
`Error` and exits.

## Project layout

| File | Contents |
| --- | --- |
| `push_swap.c` | entry point and validation order |
| `error_checkers_*.c` | numeric and duplicate checks |
| `args_to_linked_list.c` | builds stack A |
| `get_digit_*.c` | argument parsing helpers |
| `instructions_*.c` | the eleven operations |
| `sort_stack_*.c` | cost calculation and the sorting loop |
| `utils_*.c` | list helpers |

## Notes

- There is no checker binary: the project is the mandatory part only.
- Rotations that affect both stacks are merged into `rr` / `rrr` before being
  printed, so the move count reflects real cost rather than bookkeeping.

## Author

**Arda Aycan** ([@EpicYamo](https://github.com/EpicYamo)).
