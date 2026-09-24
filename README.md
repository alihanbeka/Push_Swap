*This project has been created as part of the 42 curriculum by masik, ebeka.*

## Description

Push_swap is a sorting project written in C. Its goal is to sort unique integers in ascending order using two stacks, named `a` and `b`, and a limited set of operations, while keeping the number of operations as low as possible.

Initially, stack `a` contains the input integers and stack `b` is empty. After sorting, stack `a` contains the integers in ascending order, with the smallest value at the top, and stack `b` is empty.

The program provides four sorting strategies:
- **Simple:** repeatedly extracts the smallest remaining element.
- **Medium:** sorts elements using a moving range of indices.
- **Complex:** sorts indices using binary radix sort.
- **Adaptive:** selects a strategy based on the initial disorder of the input.

An optional `--bench` mode reports the initial disorder, selected strategy, complexity class, and operation counts.


## Instructions

### Requirements

- A C compiler available through `cc`.
- `make`.
- A Unix-like environment, such as Linux or Ubuntu through WSL.

The required `libft` library is included in the repository and compiled automatically by the Makefile.

### Compilation

Run the following command from the root of the repository:

```bash
make
```

This creates the `push_swap` executable using the compiler flags `-Wall -Wextra -Werror`.

Available commands:

| Command | Description |
| --- | --- |
| `make` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files, the executable, and the compiled library |
| `make re` | Clean and rebuild the project |

### Execution

Run the program with a list of unique integers:

```bash
./push_swap 4 67 3 87 23
```

Integers can also be passed as a space-separated string:

```bash
./push_swap "4 67 3 87 23"
```

Select a sorting strategy explicitly:

```bash
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

If no strategy is specified, `--adaptive` is used.

Enable benchmark reporting with `--bench`:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Options must appear before the integers. The strategy selector and `--bench` can appear in either order.

Sorting operations are written to standard output, one per line. Benchmark information is written to standard error.

### Input Validation

The program accepts unique integers between `-2147483648` and `2147483647`.

Invalid inputs, such as duplicate values, non-integer arguments, empty strings, or values outside this range, produce `Error` followed by a newline on standard error.

Running the program without arguments produces no output. Already sorted inputs generate no sorting operations.


## Resources

- **42 Push_swap subject (version 1.1):** project rules, required sorting strategies, disorder calculation, benchmark requirements, and evaluation criteria.
- [NIST Dictionary of Algorithms and Data Structures](https://xlinux.nist.gov/dads/): reference material on algorithms, data structures, and complexity.
- [NIST — Radix Sort](https://xlinux.nist.gov/dads/HTML/radixsort.html): explanation of radix sorting.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/html_node/index.html): documentation on Makefile rules, dependencies, and compilation.

### AI Usage

AI was used to assist with the following tasks:

- Reviewing argument parsing, sorting logic, memory cleanup, and benchmark reporting.
- Discussing function-length adjustments for Norm compliance, particularly in the disorder calculation.
- Preparing test commands for sorting strategies, invalid inputs, integer boundaries, and benchmark output.
- Explaining how to use the provided checker and separate standard output from standard error.
- Clarifying subject requirements and assisting with the structure and wording of this README.

## Algorithms

The complexity of each strategy is evaluated by the number of generated Push_swap operations, as required by the subject.

Before sorting, each value receives an index from `0` to `n - 1` representing its position in ascending order. Sorting these indices preserves the order of the original values and allows negative and positive integers to be handled in the same way.

### Simple — Minimum Extraction

The simple strategy uses a selection-sort approach:

1. Find the smallest remaining index in stack `a`.
2. Bring it to the top using `ra` or `rra`, choosing the direction requiring fewer rotations.
3. Push it to stack `b` using `pb`.
4. Repeat until stack `a` is empty.
5. Push all elements back to stack `a` using `pa`.

Elements are transferred to `b` from smallest to largest. Returning them to `a` therefore places the smallest element at the top and produces ascending order.

**Why this algorithm was selected:** It provides a straightforward baseline that is easy to understand and compare with the other strategies. Choosing the shorter rotation direction reduces unnecessary operations.

**Operation complexity:** With `m` elements remaining, bringing the minimum to the top requires at most `floor(m / 2)` rotations. Summing this cost over all elements, together with the pushes between stacks, gives an `O(n²)` upper bound.

**Space complexity:** The two stacks together store `n` nodes, requiring `O(n)` space. The sorting algorithm uses `O(1)` additional space for pointers and counters.


### Medium — Moving Index Range

The medium strategy distributes elements using a moving range of indices, then returns them in descending index order.

The range size is:

`k = floor(sqrt(n))`

A counter `i` tracks the number of elements already pushed to stack `b`.

For the top element of stack `a`:

1. If its index is at most `i`, perform `pb` followed by `rb`, placing it at the bottom of stack `b`.
2. Otherwise, if its index is at most `i + k`, perform `pb`, leaving it at the top of stack `b`.
3. Otherwise, perform `ra` to examine another element.

After each push, `i` increases, advancing the accepted range.

Once stack `a` is empty, repeatedly locate the largest remaining index in stack `b`, bring it to the top using the shorter direction (`rb` or `rrb`), and perform `pa`.

Returning elements from largest to smallest produces ascending order in stack `a`.

**Why this algorithm was selected:** Accepting a range of indices creates more opportunities to push elements than searching for one exact value. Placing lower indices at the bottom of stack `b` and higher indices at the top also limits the rotations needed during reconstruction.

**Operation complexity:**

The operation count can be bounded by analyzing both phases:

- **Distribution — `O(n² / k + n)`:** After `i` pushes, at least `k + 1` of the remaining indices are within the accepted range, unless fewer elements remain. A complete traversal of stack `a` therefore removes at least `k + 1` elements. There are `O(n / k + 1)` such traversals, each costing at most `O(n)` operations.

- **Reconstruction — `O(nk)`:** Elements pushed without `rb` form a group in reverse insertion order; elements pushed with `rb` form another group in insertion order. Consider the circular boundary connecting the newest ends of these groups. The largest remaining index stays within `O(k)` positions of this boundary. For the first group, this follows because an index accepted after `i` pushes is greater than `i` and at most `i + k`. For the second group, at most `k` smaller indices can still be waiting in stack `a` when an element is appended. Removing larger indices preserves these bounds. Consecutive maximum extractions therefore require `O(k)` rotations each, giving `O(nk)` operations overall.

Combining both phases gives:

`O(n² / k + nk + n)`

With `k = floor(sqrt(n))`, the total is `O(n√n)` Push_swap operations.

**Space complexity:** The two stacks together require `O(n)` space. The algorithm reuses existing nodes and uses `O(1)` additional space for pointers and counters.


### Complex — Binary LSD Radix Sort

The complex strategy sorts the assigned indices by processing their binary digits, starting with the least significant bit.

For each bit position:

1. Examine each of the `n` elements in stack `a` once.
2. If the current bit of the top element's index is `0`, push it to stack `b` using `pb`.
3. If the bit is `1`, rotate stack `a` using `ra`.
4. After processing all elements, push every element from stack `b` back to `a` using `pa`.

Each pass groups indices according to the current bit while preserving their relative order within each group. This preserves the ordering established by earlier passes. After all relevant bits have been processed, stack `a` is sorted and stack `b` is empty.

**Why this algorithm was selected:** Binary radix sort provides a predictable operation bound. Using indices instead of the original values allows negative numbers and large integer values to be handled without special cases in the sorting algorithm.

**Operation complexity:** The largest index is `n - 1`, so `O(log n)` bit passes are required. Each pass generates `n` distribution operations (`pb` or `ra`) and at most `n` return operations (`pa`). Therefore, the total operation count is `O(n log n)`.

**Space complexity:** The stacks require `O(n)` space in total. The algorithm reuses existing nodes and uses `O(1)` additional space for pointers and counters.

### Adaptive — Disorder-Based Selection

The adaptive strategy selects one of the three sorting algorithms according to the initial disorder of stack `a`. It is the default strategy when no selector is provided.

Disorder is calculated before any sorting operations by counting inversions. An inversion is a pair of elements where the larger value appears before the smaller value.

For `n >= 2`:

`disorder = inversions / (n × (n - 1) / 2)`

For fewer than two elements, disorder is `0`.

A disorder of `0` represents an already sorted input, while `1` represents a reverse-sorted input.

The strategy selects an algorithm using these thresholds:

| Disorder | Selected algorithm | Operation complexity |
| --- | --- | --- |
| `disorder < 0.20` | Simple — Minimum Extraction | `O(n²)` |
| `0.20 <= disorder < 0.50` | Medium — Moving Index Range | `O(n√n)` |
| `disorder >= 0.50` | Complex — Binary LSD Radix Sort | `O(n log n)` |

Exactly `20%` disorder selects Medium, and exactly `50%` selects Complex. Already sorted inputs generate no operations.

**Why this strategy was selected:** The thresholds follow the regimes specified by the subject. The design reuses the simple baseline for low disorder, range-based sorting for medium disorder, and radix sorting for high disorder. It makes strategy selection depend on the initial ordering without requiring another independent sorting implementation.

This selection follows the required complexity regimes; it does not guarantee the smallest operation count among all three algorithms for every individual input.

**Operation complexity:** Calculating disorder and selecting a strategy generate no Push_swap operations. Each branch therefore inherits the operation bound of its selected algorithm.

The pairwise disorder calculation takes `O(n²)` CPU time, which is separate from the generated-operation complexity used by the subject.

**Space complexity:** The stacks require `O(n)` space in total. Disorder calculation and strategy selection use `O(1)` additional space.

## Contributions

The project was developed collaboratively by `masik` and `ebeka` using Visual Studio Code Live Share.

Both learners worked together on the implementation and review of argument parsing, stack operations, index assignment, disorder calculation, sorting strategies, and benchmark reporting.

| Learner | Contributions |
| --- | --- |
| `masik` | Participated in collaborative coding sessions, discussed implementation choices, and reviewed the code together with `ebeka`. |
| `ebeka` | Participated in collaborative coding sessions, discussed implementation choices, and reviewed the code together with `masik`. |

Work was shared through pair programming rather than divided into separately owned files. Both learners contributed throughout the project and share responsibility for understanding and explaining the complete implementation.

## Testing

Use the Linux checker provided with the subject to verify the generated operations. Place `checker_linux` in the project directory and give it execution permission:

```bash
chmod +x checker_linux
```

Pass the same input values to both programs:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

The expected result is `OK`, indicating that stack `a` is sorted and stack `b` is empty.

### Test All Strategies

```bash
ARG="8 3 7 1 6 2 5 4"

for strategy in simple medium complex adaptive; do
    echo "$strategy"
    ./push_swap --"$strategy" $ARG | ./checker_linux $ARG
done
```

### Test with Benchmark Reporting

```bash
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
cat bench.txt
```

Only sorting operations are passed to the checker. Benchmark information is saved separately in `bench.txt`.

### Random Inputs and Operation Counts

For 100 distinct integers:

```bash
ARG="$(shuf -i 1-10000 -n 100 | tr '\n' ' ')"
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

For 500 distinct integers:

```bash
ARG="$(shuf -i 1-10000 -n 500 | tr '\n' ' ')"
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

The subject specifies the following operation-count thresholds:

| Input size | Minimum pass | Good | Excellent |
| --- | --- | --- | --- |
| 100 integers | < 2000 | < 1500 | < 700 |
| 500 integers | < 12000 | < 8000 | < 5500 |

These values are evaluation targets, not measured results. Repeat the tests with different inputs to assess correctness and performance.