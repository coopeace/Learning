#include <iostream>
#include <fstream>

int main () {
  std::string name;
  float cost;

  //Write to the single_file_output.txt
  {
    std::ofstream outfile("single_file_output.txt");

    std::cout << "Enter Item Name:";
    getline(std::cin >> std::ws,name);

    outfile << name << std::endl;

    std::cout << "Enter Item Cost:";
    std::cin >> cost;

    outfile << cost;

    outfile.close();
  }

  //Read the single_file_output.txt
  {
    std::ifstream infile("single_file_output.txt");
    infile >> name >> cost;

    std::cout << std::endl;
    std::cout << "ITEM Name : " << name << std::endl;
    std::cout << "ITEM Cost : " << cost << std::endl;

    infile.close();
  }
  return 0;
}
