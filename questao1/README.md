## #1235. Maximum Profit in Job Scheduling

![image](https://github.com/user-attachments/assets/d68c25a9-b939-4682-959f-c730a0332363)

[Link para a questão](https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/)

### Gravação

Link da gravação: [Clique aqui](https://youtu.be/I_tPc1NYn5E)

#### Dificuldade: Difícil

### Enunciado

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Example 1:

![image](https://github.com/user-attachments/assets/5f5687a2-ec8a-47c4-a85b-6163596bab42)

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Example 2:

![image](https://github.com/user-attachments/assets/42f33af4-20f6-4161-a798-7c6495d4a70f)

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.

Example 3:

![image](https://github.com/user-attachments/assets/523ede4e-0397-4015-ac56-e6634be50300)

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6


Constraints:

- 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
- 1 <= startTime[i] < endTime[i] <= 10^9
- 1 <= profit[i] <= 10^4


### Submissões: 
![image](https://github.com/user-attachments/assets/994d023b-8bbd-4a30-8e8d-526f080f67d4)
![image](https://github.com/user-attachments/assets/c1a42c5c-29c6-4113-a784-c1db499c8832)






