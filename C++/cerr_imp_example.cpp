#include <iostream>
using namespace std;

int main() {
    int x;

    cout << "Enter a number: ";
    
    if (!(cin >> x)) {
        cerr << "Error: Invalid input!\n";
        return 1;
    }

    cout << "Square = " << x * x << "\n";
    return 0;
}
//./program > output.txt 2> error.txt
