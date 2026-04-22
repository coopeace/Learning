#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Inventory {
    char name[20];
    int code;
    float cost;
public:
    void get(){
        cout << "Enter Name:"; cin >> name;
        cout << "Enter code:"; cin >> code;
        cout << "Enter cost:"; cin >> cost;
    }
    void show(){
        cout << setw(10) << name
             << setw(10) << code 
             << fixed << setprecision(2) << setw(10) << cost
             << endl;
    }
};

int main () {
    Inventory tempItem; // Use a single object for I/O
    fstream iofile;

    iofile.open("STOCK.DAT", ios::in | ios::out | ios::binary | ios::ate);

    if (!iofile.is_open()) {
        // Create file if missing
        iofile.open("STOCK.DAT", ios::in | ios::out | ios::binary | ios::trunc);
    }

    // 1. Show ALL current contents
    int fileSize = iofile.tellg();
    int objectsInFile = fileSize / sizeof(Inventory);
    iofile.seekg(0, ios::beg);

    cout << "CURRENT CONTENTS (" << objectsInFile << " items):" << endl;
    while (iofile.read((char *)&tempItem, sizeof(tempItem)) && fileSize!=0) {
        tempItem.show();
    }

    // 2. Clear flags after reaching EOF
    iofile.clear();
    iofile.seekp(0, ios::end); // Move writing pointer to the end

    // 3. Add new items (Let's just add 3 new ones)
    cout << "\nAdding 3 new items..." << endl;
    for (int i = 0; i < 3; i++) {
        tempItem.get();
        iofile.write((char *)&tempItem, sizeof(tempItem));
    }

    iofile.close();
    return 0;
}
