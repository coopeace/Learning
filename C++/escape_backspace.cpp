#include <iostream>
#include <thread>  // Needed for sleeping
#include <chrono>  // Needed for time units

using namespace std;

int main() {
    cout << "Loading..." << flush;
    
    // Wait for 1 second so you can see the dots
    this_thread::sleep_for(chrono::milliseconds(1000));

    // Move back one space and overwrite the last dot with a space
    cout << "\b \b" << flush;
    this_thread::sleep_for(chrono::milliseconds(500));

    // Move back another space and overwrite
    cout << "\b \b" << flush;
    this_thread::sleep_for(chrono::milliseconds(500));

    // Move back the last space and overwrite
    cout << "\b \b" << flush;
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << " Done!" << endl;

    return 0;
}
