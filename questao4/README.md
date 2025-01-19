## #435. Non-overlapping Intervals
![image](https://github.com/user-attachments/assets/0c6f16e5-d0a1-48f6-87dd-07108692a16b)


[Link para a questão](https://leetcode.com/problems/non-overlapping-intervals/description/)

### Gravação

Link para a Gravação: [Clique Aqui](https://youtu.be/i8M7JXTIGwc?feature=shared)

#### Dificuldade: Média

### Enunciado

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]<br>
Output: 1<br>
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]<br>
Output: 2<br>
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.


Example 3:
Input: intervals = [[1,2],[2,3]]<br>
Output: 0<br>
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

Constraints:

- 1 <= intervals.length <= 105
- intervals[i].length == 2
- -5 * 104 <= starti < endi <= 5 * 104


### Submissões: 
![image](https://github.com/user-attachments/assets/f44fc4fd-9af3-40b1-b06f-ba7e04523a7c)
![image](https://github.com/user-attachments/assets/0da679ec-0e53-4488-959a-8bad1e62f2c4)








