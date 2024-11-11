#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the maximum value for the 0/1 Knapsack
int knapsack_01(const vector<int>& values, const vector<int>& weights, int capacity) {
    int n = values.size();
    // Create a 2D DP array initialized with 0
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    // The maximum value that can be achieved with the given capacity
    return dp[n][capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n);
    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the value for item " << i + 1 << ": ";
        cin >> values[i];
        cout << "Enter the weight for item " << i + 1 << ": ";
        cin >> weights[i];
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int max_value = knapsack_01(values, weights, capacity);
    cout << "Maximum value in knapsack = " << max_value << endl;

    return 0;
}
