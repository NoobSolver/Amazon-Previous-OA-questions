# Critical Connections

Given an undirected connected graph with n nodes labeled 1..n. A bridge (cut edge) is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph). Equivalently, an edge is a bridge if and only if it is not contained in any cycle. The task is to find all bridges in the given graph. Output an empty list if there are no bridges.

Input:

    n, an int representing the total number of nodes.
    edges, a list of pairs of integers representing the nodes connected by an edge.

Example 1:

Input: n = 5, edges = [[1, 2], [1, 3], [3, 4], [1, 4], [4, 5]]

Output: [[1, 2], [4, 5]]

Explanation:
There are 2 bridges:
1. Between node 1 and 2
2. Between node 4 and 5
If we remove these edges, then the graph will be disconnected.
If we remove any of the remaining edges, the graph will remain connected.

Example 2:

Input: n = 6, edges = [[1, 2], [1, 3], [2, 3], [2, 4], [2, 5], [4, 6], [5, 6]]

Output: []
Explanation:
We can remove any edge, the graph will remain connected.

Example 3:

Input: n = 9, edges = [[1, 2], [1, 3], [2, 3], [3, 4], [3, 6], [4, 5], [6, 7], [6, 9], [7, 8], [8, 9]]

Output: [[3, 4], [3, 6], [4, 5]]

Easy-to-understand explanation video

https://www.youtube.com/watch?v=aZXi1unBdJA

Source code for the video: https://github.com/williamfiset/Algorithms/tree/master/src/main/java/com/williamfiset/algorithms

URL to Amazon question:
https://leetcode.com/discuss/interview-question/372581
URL to Leetcode task:
https://leetcode.com/problems/critical-connections-in-a-network/
