# Critical Routers

You are given an undirected connected graph. An articulation point (or cut vertex) is defined as a vertex which, when removed along with associated edges, makes the graph disconnected (or more precisely, increases the number of connected components in the graph). The task is to find all articulation points in the given graph.

Input:
The input to the function/method consists of three arguments:

    numNodes, an integer representing the number of nodes in the graph.
    numEdges, an integer representing the number of edges in the graph.
    edges, the list of pair of integers - A, B representing an edge between the nodes A and B.

Output:
Return a list of integers representing the critical nodes.

Example:

Input: numNodes = 7, numEdges = 7, edges = [[0, 1], [0, 2], [1, 3], [2, 3], [2, 5], [5, 6], [3, 4]]

Output: [2, 3, 5]

Easy-to-understand explanation video

https://www.youtube.com/watch?v=aZXi1unBdJA

Source code for the video: https://github.com/williamfiset/Algorithms/tree/master/src/main/java/com/williamfiset/algorithms

Related problems:

    https://leetcode.com/discuss/interview-question/372581
    https://leetcode.com/problems/critical-connections-in-a-network/    
    https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
    https://cp-algorithms.com/graph/cutpoints.html
