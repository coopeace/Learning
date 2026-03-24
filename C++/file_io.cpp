#include <fstream>
using namespace std;

int main() {
    ofstream file("data.txt");   // opens automatically

    file << "My name is Shishir Dev.";

} // file closes automatically here
