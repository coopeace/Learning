#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 0) return; // Base Case: No disks to move

    // Step 1: Move n-1 disks to Auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Step 2: Move the nth disk
    cout << "Move disk " << n << " from " << source << " to "
    << destination << endl;

    // Step 3: Move n-1 disks from Auxiliary to Destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A=Source, B=Aux, C=Dest
    return 0;
}
