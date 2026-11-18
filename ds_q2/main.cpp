

//  DS Internal Activity 3 - Q2
//  PRN: 202501100071
//  S = 71
//  Scenario: Student Marks
//  Hash Function: Mid-Square
//  Collision Handling: Separate Chaining
//  Hash Table Size: 13
 

#include <iostream>
using namespace std;

const int M = 13;
const int N = 20;

struct Node {
    int marks;
    Node* next;
};

Node* table[M];

// Mid-Square Hash Function
int midSquareHash(int key) {
    int sq = key * key;
    int mid = (sq / 10) % 100;
    return mid % M;
}

// Insert with duplicate checking
bool insertKey(int key) {
    int h = midSquareHash(key);

    Node* cur = table[h];

    // Check duplicate
    while (cur != nullptr) {
        if (cur->marks == key) {
            cout << "Duplicate key " << key
                 << " skipped at slot " << h << endl;
            return false;
        }
        cur = cur->next;
    }

    // Create new node
    Node* n = new Node{key, nullptr};

    // Insert at beginning if slot is empty
    if (table[h] == nullptr) {
        table[h] = n;
    }
    else {
        // Append at end of chain
        cur = table[h];

        while (cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = n;
    }

    cout << "Inserted " << key
         << " at slot " << h << endl;

    return true;
}

// Display hash table
void displayTable() {
    cout << "\nFinal Hash Table:\n";

    for (int i = 0; i < M; i++) {
        cout << "Slot " << i << ": ";

        Node* cur = table[i];

        if (cur == nullptr) {
            cout << "empty";
        }

        while (cur != nullptr) {
            cout << cur->marks;

            cur = cur->next;

            if (cur != nullptr) {
                cout << " -> ";
            }
        }

        cout << endl;
    }
}

// Free dynamically allocated memory
void freeMemory() {
    for (int i = 0; i < M; i++) {
        Node* cur = table[i];

        while (cur != nullptr) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }

        table[i] = nullptr;
    }
}

int main() {
    const int S = 71;

    // Initialize hash table
    for (int i = 0; i < M; i++) {
        table[i] = nullptr;
    }

    cout << "Generated Dataset:\n";

    // Insert 20 generated values
    for (int i = 0; i < N; i++) {
        int v = (S + 13 * i) % 100;

        cout << v << " ";
        insertKey(v);
    }

    // Duplicate test: 71 was already inserted above
    cout << "\nDuplicate Test:\n";
    insertKey(71);

    // Display final hash table
    displayTable();

    // Release allocated memory
    freeMemory();

    cout << "\nMemory cleaned successfully.\n";

    return 0;
}
