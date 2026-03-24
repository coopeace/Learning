#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> data = {1, 2, 3, 4, 5};

    clog << "Program started\n";

    for (int x : data) {
        clog << "Processing value: " << x << "\n";
    }

    clog << "Processing complete\n";

    cout << "Done!\n";
    return 0;
}
// run ./program > output.txt 2> log.txt
