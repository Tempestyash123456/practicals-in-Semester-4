## Experiment: 4

**Aim:** To find minimum spanning tree using kruskal's algorithm

**Algorithm:** Below are the steps for finding MST using Kruskal’s algorithm:

1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
3. Repeat step#2 until there are (V-1) edges in the spanning tree.

**Program code:** [Source-code](https://github.com/Tempestyash123456/practicals-in-Semester-4/blob/Design-and-Analysis-of-Algorithms/Exp4/kruskalAlgorithm_Exp4.c)

**Output:**

![Image](https://simple2code.com/wp-content/uploads/2020/05/Kruskal%E2%80%99s-Algorithm-in-C-1.png)
