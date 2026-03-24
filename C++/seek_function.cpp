#include <iostream>
using namespace std;

int main() {
    while (cin.peek() != '\n') {
        char ch = cin.get();

        if (ch != ' ')
            cout << ch;
    }

    cout << endl;
}
//Input is buffered in bulk, but processed one character at a time
//Seek is used to look Reads next character, Does NOT remove it from stream, Next input operation will still read that character
//
//Use Case Checking next character before deciding what to do
// Parsing input (like skipping spaces, detecting symbols)
