#include <iostream>
using namespace std;

union Color {
    unsigned int hexValue; // The whole 32-bit "package"
    
    struct {
        unsigned char r; // 1 byte (8 bits)
        unsigned char g; // 1 byte (8 bits)
        unsigned char b; // 1 byte (8 bits)
        unsigned char a; // 1 byte (8 bits)
    } rgba; // This struct lets us access each bucket by name
};

int main() {
    Color myColor;

    // Setting individual colors
    myColor.rgba.r = 255; // Max Red
    myColor.rgba.g = 128; // Half Green
    myColor.rgba.b = 0;   // No Blue
    myColor.rgba.a = 255; // Fully Opaque (Visible)

    // Now look at the "Magic Number" it created
    cout << "The 32-bit HEX value is: " << hex << myColor.hexValue << endl;

    return 0;
}
