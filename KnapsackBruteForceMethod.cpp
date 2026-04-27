#include <iostream>
using namespace std;

// Function to find maximum of two values
int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

// Brute Force Knapsack (Recursive)
int knapsack(int wt[], int val[], int n, int W) {

    // Base case
    if(n == 0 || W == 0)
        return 0;

    // If weight of item > capacity, skip it
    if(wt[n-1] > W)
        return knapsack(wt, val, n-1, W);

    // Include or exclude item
    else {
        int include = val[n-1] +
                      knapsack(wt, val, n-1, W - wt[n-1]);

        int exclude = knapsack(wt, val, n-1, W);

        return maxVal(include, exclude);
    }
}

// Main function with fixed values
int main() {

    int wt[] = {2, 3, 4, 5};
    int val[] = {3, 4, 5, 6};

    int n = 4;   // number of items
    int W = 5;   // capacity

    cout << "Weights: ";
    for(int i = 0; i < n; i++)
        cout << wt[i] << " ";

    cout << "\nValues: ";
    for(int i = 0; i < n; i++)
        cout << val[i] << " ";

    cout << "\nCapacity: " << W << endl;

    int result = knapsack(wt, val, n, W);

    cout << "Maximum Profit (Brute Force): "
         << result << endl;

    return 0;
}