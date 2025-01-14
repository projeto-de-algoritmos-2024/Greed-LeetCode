## #1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

![image](https://github.com/user-attachments/assets/6d34392b-9bb3-4e4e-839b-534b7f63e586)

[Link para a questão](https://leetcodecomproblemsfind-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)

### Gravação

#### Dificuldade: Difícil

### Enunciado

Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

Example 1:

![image](https://github.com/user-attachments/assets/500a8dbc-c668-4a01-b679-4e08c8c9144f)

Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:

![image](https://github.com/user-attachments/assets/4e384437-bf29-46fd-999a-e078b5a28264)

Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

Example 2:

![image](https://github.com/user-attachments/assets/86203dec-8e02-428e-a93c-e1bf11c14196)

Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.

Constraints:

- 2 <= n <= 100
- 1 <= edges.length <= min(200, n * (n - 1) / 2)
- edges[i].length == 3
- 0 <= ai < bi < n
- 1 <= weighti <= 1000
- All pairs (ai, bi) are distinct.


### Submissões: 
![image](https://github.com/user-attachments/assets/d3b2fcef-db43-4336-a91b-7b7367d6c853)
![image](https://github.com/user-attachments/assets/e9cc6ba1-4b53-46fb-8e99-106e4304c007)





