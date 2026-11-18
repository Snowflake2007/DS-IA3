

//  DS Internal Activity 3 - Q2
//  PRN: 202501100071
//  S = 71
//  Scenario: Student Marks
//  Hash Function: Mid-Square
//  Collision Handling: Separate Chaining
//  Hash Table Size: M = 13
 

#include <iostream>
using namespace std;

const int M = 13;
const int N = 20;

// Node structure
struct Node {
    int marks;
    Node* next;
};

// Hash table
Node* table[M];

// Mid-square hash function
int midSquareHash(int key) {
    int sq = key * key;
    int mid = (sq / 10) % 100;
    return mid % M;
}

// Insert using separate chaining (append at end)
void insertKey(int key) {
    int h = midSquareHash(key);

    Node* n = new Node{key, nullptr};

    // If slot is empty
    if (table[h] == nullptr) {
        table[h] = n;
        cout << "Inserted " << key
             << " at slot " << h << endl;
        return;
    }

    // Traverse to the last node
    Node* cur = table[h];

    while (cur->next != nullptr) {
        cur = cur->next;
    }

    // Attach new node at the end
    cur->next = n;

    cout << "Inserted " << key
         << " at slot " << h << endl;
}

// Display hash table
void displayTable() {
    cout << "\nFinal Hash Table\n";
    cout << "--------------------------\n";

    for (int i = 0; i < M; i++) {
        cout << "Slot " << i << ": ";

        Node* cur = table[i];

        if (cur == nullptr) {
            cout << "empty";
        }

        while (cur != nullptr) {
            cout << cur->marks << " ";
            cur = cur->next;
        }

        cout << endl;
    }
}

int main() {
    const int S = 71;

    // Initialize hash table
    for (int i = 0; i < M; i++) {
        table[i] = nullptr;
    }

    cout << "Student Marks Hash Table\n";
    cout << "--------------------------\n";

    // Generate dataset and insert values
    for (int i = 0; i < N; i++) {
        int v = (S + 13 * i) % 100;
        insertKey(v);
    }

    // Display final hash table
    displayTable();

    return 0;
}
