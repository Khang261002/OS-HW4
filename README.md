# OS-HW4

This repository contains my implementation of three page replacement algorithms: LRU (Least Recently Used), Optimal, and FIFO (First In First Out). The objective of this assignment is to simulate page replacement in a demand-paging scenario and analyze the performance of these algorithms in terms of the number of page faults.

## Implementation Details

### 1. Requirements
- **Accept Input:** My script accepts a page reference string and the specified number of frames as input to simulate page replacement.
- **Implement Algorithms:** Implemented LRU, Optimal, and FIFO algorithms.
- **Simulate Page Replacement:** Developed algorithms to simulate page replacement and calculate the number of page faults that occur during the simulation for each implemented algorithm.
- **Structured Output:** Provides clear and structured output displaying the number of page faults that occurred at each step of the simulation.

### 2. Sample Input
- **Page reference string:** 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
- **Number of frames:** 4

### 3. Sample Output
#### For LRU Algorithm:
- Step 1: Page fault (1) - Page Table: {1}, Frames: [1], Faults: 1
- Step 2: Page fault (2) - Page Table: {1, 2}, Frames: [1, 2], Faults: 2
- Step 3: Page fault (3) - Page Table: {1, 2, 3}, Frames: [1, 2, 3], Faults: 3
- ...
- Total Page Faults: [Total Faults]

#### For Optimal Algorithm:
- Step 1: Page fault (1) - Page Table: {1}, Frames: [1], Faults: 1
- Step 2: Page fault (2) - Page Table: {1, 2}, Frames: [1, 2], Faults: 2
- Step 3: Page fault (3) - Page Table: {1, 2, 3}, Frames: [1, 2, 3], Faults: 3
- ...
- Total Page Faults: [Total Faults]

#### For FIFO Algorithm:
- Step 1: Page fault (1) - Page Table: {1}, Frames: [1], Faults: 1
- Step 2: Page fault (2) - Page Table: {1, 2}, Frames: [1, 2], Faults: 2
- Step 3: Page fault (3) - Page Table: {1, 2, 3}, Frames: [1, 2, 3], Faults: 3
- ...
- Total Page Faults: [Total Faults]

## Execution Instructions
To run the program:
1. Clone the repository.
2. Navigate to the directory containing the source code.
3. Run the script providing the page reference string and the number of frames as input.

Example:
```bash
g++ hw4.cpp -o hw4
```
```bash
hw4 "1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5" 4
```
