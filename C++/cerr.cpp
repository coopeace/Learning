#include <iostream>
using namespace std;

int main() {
    cout << "cout before";   // no newline
    clog << "clog before";   // no newline
    cerr << "cerr before";   // no newline

    int* p = nullptr;
    *p = 10;  // crash

    return 0;
}
