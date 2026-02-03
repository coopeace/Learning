#include <iostream>
using namespace std;

void factorial(int n, int b = 2) {
    if (b == 2) cout << "Called with default b" << endl;
    else cout << "Called with provided b" << endl;
}

int main() {
    factorial(1);
    factorial(2,1);
    return 0;
}
