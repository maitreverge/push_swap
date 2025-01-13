<p align="center">
  <img src="img/push_swap.png" width="70%"/>
</p>

## 🚀 SYNOPSIS

The `push_swap` project at 42 school plunges students into the realm of algorithmic optimization and sorting strategies within the C language.

This challenging task requires a nuanced understanding of data structures, algorithmic complexity, and efficient problem-solving.
Students are tasked with developing a program that efficiently sorts a stack of numbers using a restricted set of operations, pushing the boundaries of algorithmic creativity and optimization.

Beyond the algorithmic intricacies, push_swap serves as a platform for refining skills in memory management, linked list manipulation, and the strategic orchestration of operations.

Successful completion of this project not only demonstrates mastery in algorithmic design but also showcases a keen ability to devise efficient solutions for real-world computational challenges.

## 🛠️ PROGRAM SPECIFICITIES AND CONSIDERATIONS

Clone the project:

```bash
git clone git@github.com:maitreverge/push_swap.git && cd push_swap
```

> [!IMPORTANT]
> The program only output the list of operations needed to sort the input stack a while ensuring compliance with the project rules.

At the heart of the push_swap project lies a set of predefined operations that manipulate the stacks a and b. These operations are fundamental building blocks for sorting the numbers efficiently. Understanding these commands is crucial:

- `ra` (rotate a): Moves the first element of stack `a` to the bottom.

- `rra` (reverse rotate a): Moves the last element of stack `a` to the top.

- `rb` (rotate b): Moves the first element of stack `b` to the bottom.

- `rrb` (reverse rotate b): Moves the last element of stack `b` to the top.

- `rr` (rotate both): Simultaneously applies `ra` and `rb`.

- `rrr` (reverse rotate both): Simultaneously applies `rra` and `rrb`.

- `sa` (swap a): Swaps the first two elements of stack `a`.

- `sb` (swap b): Swaps the first two elements of stack `b`.

- `ss` (swap both): Simultaneously applies `sa` and `sb`.

- `pa` (push a): Moves the top element from stack `b` to stack `a`.

- `pb` (push b): Moves the top element from stack `a` to stack `b`.

The command :
```bash
./push_swap 4 3 2 1 
```
actually outputs :

```text
rra
pb
ra
sa
pa
```

> [!WARNING]
> Invalid input (e.g., non-integer values, duplicates, inputs outside of a regular `i32` limits) should result in an appropriate error message without causing undefined behavior.

## 🤝 CONTRIBUTION
Contributions are open, open a Github Issue or submit a PR 🚀
