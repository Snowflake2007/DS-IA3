
/*
 * DS Internal Activity 3 - Q2
 * PRN: 202501100071
 * S = 71
 * Scenario: Student Marks
 * Hash Function: Mid-Square
 * Collision Handling: Separate Chaining
 * Hash Table Size (M): 13
 */

#include <iostream>
using namespace std;

const int M = 13;
const int N = 20;

int midSquareHash(int key) {
    int sq = key * key;
    int mid = (sq / 10) % 100;
    return mid % M;
}

int main() {
    const int S = 71;

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
