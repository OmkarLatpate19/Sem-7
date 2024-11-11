#include <iostream>
#include <vector>
using namespace std;

// Non-Recursive (Iterative) Method
int fibonacciIterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, fib;
    for (int i = 2; i <= n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

// Recursive Method
int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Iterative Method
    cout << "Fibonacci (Iterative) of " << n << " is: " << fibonacciIterative(n) << endl;

    // Recursive Method
    cout << "Fibonacci (Recursive) of " << n << " is: " << fibonacciRecursive(n) << endl;

    return 0;
}
