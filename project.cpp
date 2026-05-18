#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 🎨 Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

// ⏱️ Delay (no thread issues)
void delay() {
    for (volatile int i = 0; i < 100000000; i++);
}

// Function to display rods
void display(vector<stack<int>> &rods, int n) {
    cout << CYAN << "\nCurrent State:\n" << RESET;

    vector<stack<int>> temp = rods;

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 3; j++) {
            if (temp[j].size() >= i) {
                stack<int> t = temp[j];
                vector<int> v;

                while (!t.empty()) {
                    v.push_back(t.top());
                    t.pop();
                }

                cout << GREEN << "  " << v[i-1] << "  " << RESET;
            } else {
                cout << "  |  ";
            }
        }
        cout << endl;
    }

    cout << YELLOW << "----- ----- -----\n";
    cout << "  A     B     C  \n" << RESET;

    delay(); // animation
}

// Move disk
void moveDisk(vector<stack<int>> &rods, int from, int to,
              char s, char d, int &moves, int n) {

    int disk = rods[from].top();
    rods[from].pop();
    rods[to].push(disk);

    moves++;

    cout << RED << "Move disk " << disk << " from "
         << s << " to " << d << RESET << endl;

    display(rods, n);
}

// Recursive function
void towerOfHanoi(int n, vector<stack<int>> &rods, int from, int aux, int to,
                  char s, char a, char d, int &moves, int totalDisks) {

    if (n == 1) {
        moveDisk(rods, from, to, s, d, moves, totalDisks);
        return;
    }

    towerOfHanoi(n - 1, rods, from, to, aux, s, d, a, moves, totalDisks);

    moveDisk(rods, from, to, s, d, moves, totalDisks);

    towerOfHanoi(n - 1, rods, aux, from, to, a, s, d, moves, totalDisks);
}

// Reset rods (important for menu reuse)
void initialize(vector<stack<int>> &rods, int n) {
    for (int i = 0; i < 3; i++) {
        while (!rods[i].empty()) rods[i].pop();
    }

    for (int i = n; i >= 1; i--) {
        rods[0].push(i);
    }
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    vector<stack<int>> rods(3);
    int choice;

    do {
        cout << CYAN << "\n===== MENU =====\n" << RESET;
        cout << "1. Start Simulation\n";
        cout << "2. Show Expected Moves\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int moves = 0;
            initialize(rods, n);

            display(rods, n);

            towerOfHanoi(n, rods, 0, 1, 2,
                         'A', 'B', 'C', moves, n);

            cout << GREEN << "\nTotal moves: " << moves << RESET << endl;
            break;
        }

        case 2:
            cout << YELLOW << "Expected moves (2^n - 1): "
                 << (1 << n) - 1 << RESET << endl;
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}