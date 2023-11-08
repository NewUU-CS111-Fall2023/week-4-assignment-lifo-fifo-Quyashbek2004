#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        cout << "Move disk 1 from " << from_peg << " to " << to_peg << endl;
        return;
    }
    towerOfHanoi(n-1, from_peg, aux_peg, to_peg);
    cout << "Move disk " << n << " from " << from_peg << " to " << to_peg << endl;
    towerOfHanoi(n-1, aux_peg, to_peg, from_peg);
}

int main() {
    int n = 8;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
