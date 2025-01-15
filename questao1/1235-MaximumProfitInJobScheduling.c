#include <stdlib.h>

typedef struct Job {
    int start;
    int end;
    int profit;
} Job;

int compareJobs(const void* a, const void* b) {
    return ((Job*)a)->end - ((Job*)b)->end;
}

int findLastNonConflictingJob(Job* jobs, int index) {
    int low = 0, high = index - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (jobs[mid].end <= jobs[index].start) {
            if (jobs[mid + 1].end <= jobs[index].start) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize) {
    int n = startTimeSize;
    Job jobs[n];
    for (int i = 0; i < n; i++) {
        jobs[i].start = startTime[i];
        jobs[i].end = endTime[i];
        jobs[i].profit = profit[i];
    }

    qsort(jobs, n, sizeof(Job), compareJobs);

    int dp[n];
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int inclProfit = jobs[i].profit;
        int lastNonConflicting = findLastNonConflictingJob(jobs, i);
        if (lastNonConflicting != -1) {
            inclProfit += dp[lastNonConflicting];
        }
        dp[i] = (inclProfit > dp[i - 1]) ? inclProfit : dp[i - 1];
    }

    return dp[n - 1];
}

