# push_swap

## Overview
push_swap is a 42 School algorithmic project that challenges students to create an efficient sorting program using two stacks and a limited set of operations. The goal is to sort a random list of integers in ascending order using only two stacks (stack A and stack B) and eleven specific movements. The challenge lies in developing a custom sorting algorithm that minimizes the number of operations performed.

## Status
- Completion Date: 12/12/2024
- Grade: 125/100 ✨

## Subject Requirements

### Available Operations
The program must implement exactly these 11 operations:
- `sa`: Swap the first two elements at the top of stack A
- `sb`: Swap the first two elements at the top of stack B
- `ss`: Execute `sa` and `sb` simultaneously
- `pa`: Push the top element from stack B onto stack A
- `pb`: Push the top element from stack A onto stack B
- `ra`: Rotate stack A upwards (first element becomes last)
- `rb`: Rotate stack B upwards (first element becomes last)
- `rr`: Execute `ra` and `rb` simultaneously
- `rra`: Reverse rotate stack A downwards (last element becomes first)
- `rrb`: Reverse rotate stack B downwards (last element becomes first)
- `rrr`: Execute `rra` and `rrb` simultaneously

### Visual Example
Initial state:
```
Stack A: 3 2 1     (top to bottom)
Stack B: (empty)
```

After `sa`:
```
Stack A: 2 3 1     (top to bottom)
Stack B: (empty)
```

### Performance Requirements
The algorithm's efficiency is evaluated based on the number of operations:
- For 100 numbers: maximum 700 operations allowed
- For 500 numbers: maximum 5500 operations allowed

## Implementation: The Turk Algorithm

### Algorithm Overview
The implementation uses the Turk Algorithm, originally designed by a former 42 student. The algorithm's strategy is to:
1. Sort numbers in descending order in stack B through strategic pushes and rotations
2. Push all elements back to stack A, resulting in ascending order

### Detailed Process
1. Initial Setup (when stack A has more than 3 elements):
   - Push the first two elements to stack B without comparison
   - For remaining elements, analyze to find the "cheapest" element to move

2. Main Sorting Phase:
   - Calculate the cheapest element based on:
     * Cost to bring the element to the top of stack A
     * Cost to position it correctly in stack B
     * Total combined operation count

3. Building Stack B:
   - After identifying the cheapest move, execute rotations on both stacks
   - Push the element to stack B
   - Continue until stack B is sorted in descending order

4. Final Phase:
   - Push all elements from stack B back to stack A
   - The `order_a` function performs final rotations (`ra` or `rra`) to ensure the smallest element is at the top
   - Result is a completely sorted stack A in ascending order

### Example
Initial state:
```
Stack A: 5 2 9 0 -65     (top to bottom)
Stack B: (empty)
```

After complete sorting:
```
Stack A: -65 0 2 5 9     (top to bottom)
Stack B: (empty)
```

## Potential Improvements
The algorithm could be optimized in several ways:

1. Function Call Optimization:
   - Reduce redundant calls to `target_node` and `ops_calcul`
   - Implement caching for operation counts
   - Store calculation results rather than recomputing

2. Operation Efficiency:
   - Better utilize simultaneous operations (ss, rr, rrr)
   - Implement smarter rotation choices
   - Optimize the path-finding for element movements

## Testing

### Basic Usage
```bash
# Compile the program
make

# Run with a list of integers
./push_swap 5 2 9 0 -65
```

### Example Output
The program outputs the sequence of operations that sorts the list:
```
pb
pb
ra
sa
rra
pa
ra
pa
ra
ra
```

### Test Cases
Comprehensive testing should include:
- Pre-sorted sequences
- Reverse-sorted sequences
- Random large datasets
- Negative numbers
- Edge cases:
  * Duplicate numbers (should error)
  * Non-numeric input (should error)
  * Maximum/minimum integer values

## Installation

```bash
# Clone the repository
git clone git@github.com:maranici/push_swap.git

# Navigate to the project directory
cd push_swap

# Compile the program
make
```

## Error Handling
The program implements robust error checking for:
- Non-numeric arguments
- Duplicate numbers in the input
- Integer overflow/underflow
- Missing or invalid arguments
- Memory allocation failures

## License
This project is developed at 42 School and follows its guidelines. Usage and redistribution are permitted under the school's terms.

---
Author: macuesta  
Last Updated: 21/12/2024
