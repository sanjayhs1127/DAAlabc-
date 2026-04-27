#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int start, finish, profit;
};

bool compare(Job a, Job b) {
    return a.finish < b.finish;
}

int main() {
    Job jobs[] = {
        {1, 3, 50},
        {2, 5, 20},
        {4, 6, 70},
        {6, 7, 60}
    };

    int n = 4;
    sort(jobs, jobs + n, compare);

    int dp[4];
    dp[0] = jobs[0].profit;

    for(int i = 1; i < n; i++) {
        dp[i] = jobs[i].profit;

        for(int j = 0; j < i; j++) {
            if(jobs[j].finish <= jobs[i].start) {
                if(dp[j] + jobs[i].profit > dp[i]) {
                    dp[i] = dp[j] + jobs[i].profit;
                }
            }
        }
    }

    int result = dp[0];
    for(int i = 1; i < n; i++) {
        if(dp[i] > result)
            result = dp[i];
    }

    cout << "Maximum Profit: " << result << endl;
    return 0;
}