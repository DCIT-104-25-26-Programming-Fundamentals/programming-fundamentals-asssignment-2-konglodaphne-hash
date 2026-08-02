// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be greater than 0." << endl;
        return;
    }

    long long first = 0;
    long long second = 1;

    cout << "Fibonacci sequence: ";

    for (int i = 1; i <= n; i++) {
        cout << first << " ";

    
        long long next = first + second;
        
        first = second;
        second = next;
    }
    cout << endl;
}


bool isFibonacci(long long num) {
    if (num < 0) {
        return false;
    }

    long long first = 0;
    long long second = 1;
    while (first < num) {
        long long next = first + second;
        first = second;
        second = next;
    }
    return (first == num);
}

int main() {
    // --- PART A ---
    cout << "=== PART A: PRINT N TERMS ===" << endl;
    int n;
    cout << "How many terms? ";
    cin >> n;

    printFibonacci(n);

    // --- PART B ---
    cout << "=== PART B: CHECK FIBONACCI NUMBER ===" << endl;
    long long checkNum;
    cout << "Enter a number to check: ";
    cin >> checkNum;

    if (isFibonacci(checkNum)) {
        cout << checkNum << " is a Fibonacci number." << endl;
    } else {
        cout << checkNum << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
