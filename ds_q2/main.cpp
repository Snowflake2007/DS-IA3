
/*
 * DS Internal Activity 3 - Q2
 * PRN: 202501100071
 * S = 71
 * Scenario: Student Marks
 * Hash Function: Mid-Square
 * Collision Handling: Separate Chaining
 * Hash Table Size: M = 13
 */

#include <iostream>
using namespace std;

const int M = 13;
const int N = 20;

// Node structure for the hash table
struct Node {
    int marks;
    Node* next;
};

// Hash table array
Node* table[M];

// Mid-square hash function
int midSquareHash(int key) {
    int sq = key * key;
    int mid = (sq / 10) % 100;
    return mid % M;
}

int main() {
    const int S = 71;

    // Initialize all hash table slots
    for (int i = 0; i < M; i++) {
        table[i] = nullptr;
    }

    cout << "Student Marks Dataset with Mid-Square Hashing\n";

    for (int i = 0; i < N; i++) {
        int v = (S + 13 * i) % 100;

        cout << v
             << " -> square " << v * v
             << " -> slot " << midSquareHash(v)
             << endl;
    }

    return 0;
}
