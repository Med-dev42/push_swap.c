*This project has been created as part of the 42 curriculum by mlazar, mokharto.*
 
# push_swap
 
## Description
 
**push_swap** sorts a stack of integers using two stacks (`a` and `b`) and a
limited set of instructions, while printing the shortest sequence of
instructions it can find.
 
At the start, stack `a` contains the given integers (no duplicates, the first
argument is the top of the stack) and stack `b` is empty. The goal is to have
`a` sorted in ascending order, with the smallest number on top.
 
Available operations:
 
| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of `a` / `b` / both |
| `pa` / `pb` | push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | rotate `a` / `b` / both (first element becomes last) |
| `rra` / `rrb` / `rrr` | reverse rotate `a` / `b` / both (last element becomes first) |
 
The program embeds **four strategies**, selectable at runtime, plus an
optional benchmark mode:
 
| Flag | Strategy | Complexity (in number of operations) |
|---|---|---|
| `--simple` | Selection sort | O(n²) |
| `--medium` | Chunk sort (√n chunks) | O(n√n) |
| `--complex` | Radix sort (LSD, on indexes) | O(n log n) |
| `--adaptive` (default) | Chooses one of the three according to the disorder | see below |
| `--bench` | Prints statistics on `stderr` | - |
 
### Stack representation
 
Each stack is a singly linked list of `t_node` (`value`, `index`, `next`).
Both stacks, the operation counters, the measured disorder and the selected
strategy are grouped in a single `t_logic` structure that is passed by
pointer, so the program uses **no global variable**.
 
## Instructions
 
### Compilation
 
```
make        # builds ./push_swap
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```
 
The project is compiled with `cc -Wall -Wextra -Werror`. No external library
is used: the few helper functions needed (`ft_split`, `ft_strjoin`,
`ft_strdup`, `ft_strlen`, `ft_strncmp`, `ft_putstr_fd`, `ft_putnbr_fd`,
`ft_putchar_fd`, `ft_atol`) are re-implemented in the repository.
 
### Usage
 
```
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers>
```
 
The integers can be given as separate arguments, as one quoted string, or
mixed:
 
```
$> ./push_swap 2 1 3 6 5 8
$> ./push_swap "4 67 3 87 23"
$> ./push_swap --complex 5 4 3 2 1
$> ./push_swap --bench --adaptive 4 67 3 87 23 2> bench.txt
```
 
Behaviour:
 
- Operations are printed on `stdout`, one per line.
- If the input is already sorted, nothing is printed.
- With no argument, nothing is printed.
- On error (non-integer argument, value outside the `int` range, duplicate,
  unknown flag, empty string), `Error` followed by a newline is printed on
  `stderr`.
- Flags must come before the numbers.
### Benchmark mode
 
`--bench` prints on `stderr` (so it never pollutes the operations stream):
 
```
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n sqrt(n))
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```
 
The first part of `strategy` is what was requested (`Adaptive`, `Simple`,
`Medium`, `Complex`); the complexity class is the one of the algorithm that
actually ran.
 
Check a result with a checker and keep the statistics:
 
```
ARG="4 67 3 87 23"
./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
```
 
## Algorithms
 
### Disorder metric
 
Disorder is the proportion of *mistakes* among all pairs of the stack. A pair
`(i, j)` with `i < j` is a mistake when `a[i] > a[j]`:
 
```
disorder = mistakes / total_pairs        (0 = sorted, 1 = reversed)
```
 
It is computed **once, before any move**, in O(n²). Since floating point
printing is not available without `printf`, it is stored as an integer
multiplied by 10000 (`3333` means `33.33%`), and printed with integer
division and modulo.
 
### Simple: selection sort - O(n²)
 
While `a` is not empty, find the smallest element, bring it to the top using
the shortest direction (`ra` or `rra`) and push it to `b`. Then push
everything back to `a`: because the smallest numbers were pushed first, they
come back in the right order.
 
### Medium: chunk sort - O(n√n)
 
1. Every element gets an `index` (its rank, from 0 to n-1).
2. With `chunk = √n`, elements whose index is lower than `pushed + chunk` are
   pushed to `b` (the others are skipped with `ra`). An element that is very
   small compared to the current window is sent to the bottom of `b` with
   `rb`. Thus `b` ends up *roughly* ordered by blocks: large values near the
   top, small values at the bottom.
3. Then, repeatedly, the largest element of `b` is brought to the top with
   the shortest rotation and pushed to `a`.
Correctness does not depend on `b` being perfectly ordered, only the number
of operations does.
 
### Complex: radix sort - O(n log n)
 
LSD radix sort on the indexes (always non-negative, from 0 to n-1), in base
2. For each bit, from the least significant one: elements whose bit is `0`
go to `b` (`pb`), the others stay in `a` (`ra`); then everything returns to
`a` (`pa`). Each pass is stable, so after the last bit the stack is sorted.
 
### Adaptive
 
The strategy is chosen from the measured disorder:
 
| Disorder | Method | Operations |
|---|---|---|
| < 0.2 | selection sort | O(n²) |
| 0.2 <= d < 0.5 | chunk sort | O(n√n) |
| >= 0.5 | radix sort | O(n log n) |
 
**Rationale for the thresholds.** The values 0.2 and 0.5 are the limits
imposed by the subject for the three regimes. The methods inside each regime
are our own choice: selection sort is the simplest O(n²) method and works
well when the stack is nearly sorted; chunk sort is a good compromise for
medium disorder; radix sort has a cost that does not depend on the input
order, which makes it the safest choice when the stack is very disordered.
 
## Complexity (upper bounds, in the Push_swap operation model)
 
Let `n` be the number of elements.
 
- **Selection sort:** `n` extractions, each costing at most `n/2` rotations
  plus one `pb`; then `n` `pa`. Total: O(n²).
- **Chunk sort:** pushing to `b` takes about `n / √n` passes over `a` of at
  most `n` operations each, that is O(n√n); bringing the maximum back takes
  about `√n` rotations per element since it stays near the top of `b`, that
  is O(n√n) again. This second argument is a heuristic (it relies on `b`
  being roughly ordered), not a strict proof; we checked the growth
  experimentally with `--bench`.
- **Radix sort:** `⌈log₂ n⌉` passes, each with at most `n` operations
  (`pb`/`ra`) plus at most `n` `pa`, so at most `2n` per pass. Total:
  O(n log n).
- **Adaptive:** the cost of the chosen method, plus the O(n²) computation of
  the disorder, which does not generate any operation.
- **Space:** O(n): two linked lists (at most `n` nodes in total) with one
  extra `index` per node. The strategies themselves use O(1) extra memory
  (a few integers and the 11 operation counters).
## Performance
 
Targets from the subject:
 
| Numbers | Pass | Good | Excellent |
|---|---|---|---|
| 100 | < 2000 | < 1500 | < 700 |
| 500 | < 12000 | < 8000 | < 5500 |
 
Measured results (random inputs, to be filled in with real measurements):
 
| Strategy | 100 numbers | 500 numbers |
|---|---|---|
| `--simple` | ... | ... |
| `--medium` | ... | ... |
| `--complex` | ... | ... |
| `--adaptive` | ... | ... |
 
How to measure:
 
```
ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' ')
./push_swap --bench $ARG 2> /dev/null | wc -l
./push_swap $ARG | ./checker_linux $ARG
```
 
## Project structure
 
| Folder | Content |
|---|---|
| `mandatory_part/` | `main.c` |
| `helper_functions/` | parsing, list utilities, the 11 operations, disorder, bench, small libc-like helpers |
| `Simple_algorithm/` | selection sort |
| `Medium_algorithm/` | chunk sort |
| `Complex_algorithm/` | Radix sort |
| `adaptive_algorithm/` | strategy choice (`choose`, dispatcher) |
 
## Contributions
 
- **mlazar:** mandatroy part, bonus part , medium alghrithm, complex alghrithm, whit some helper functions, with README file.
- **mokharto:**  simple alghrithm, Custom adaptive algorithm, with: instructions(optins for example: sa, pb, ra, rrr...), with some helper functions ,Makefile, headerfile (*.h).
 
## Resources
 
- Subject of the project (push_swap, version 1.2).
- Big-O notation: https://en.wikipedia.org/wiki/Big_O_notation
- Selection sort: https://algomaster.io/learn/dsa/selection-sort
- Radix sort: https://en.wikipedia.org/wiki/Radix_sort
- Inversions of a sequence (the disorder metric):
  https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)
### Use of AI
 
AI was used as a learning and review tool, for these tasks:
 
- explaining concepts (Chunk-based , `struct`,
  arithmetic on `argv`, macros);
- reviewing the code and spotting mistakes (wrong function names, norm issues);
- suggesting a first version of the radix sort.
Every suggestion was tested, read and discussed before being kept, and both
learners can explain the final code.
 
