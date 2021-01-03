# Prison Cells After N Days

Classic test for work with bits in a byte. 

Following description is for a task on leetcode.com. 
Description on an Amazon online assessment website is different.
The difference described below.

There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

    If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
    Otherwise, it becomes vacant.

(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

```

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]


Note:

    cells.length == 8
    cells[i] is in {0, 1}
    1 <= N <= 10^9

```

The idea of the solution is based of the fact that there are only 2^6 possible combinations of cells because from the second step first
and last cells are always = 0. It means that after 2^6 steps all combinations will repeat again.

So we will keep all combinations of the cells in a hash map until we meet the loop. After it happens we will not calculate the next 
combinations but will take precalculated ones from the hash map.

Discussion and test environment are here:
https://leetcode.com/problems/prison-cells-after-n-days/

The difference on an Amazon online assessment website.

1. The first and the last cells in the row can't have two adjacent neighbors so we should consider
these cells as the cells that always have vacant neighbors. In other words an imaginary 
cells before the first cell and after the last cells are always empty.

2. If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes vacant.
So the first and the last cells are always occupied.