#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main () {
  std::string str;

  //country_name entry
  std::ofstream outfile;
  outfile.open("country_names.txt");
  {
    std::vector<std::string> countries;
    countries = {"USA","United Kingdom","South Korea"};
    for ( auto country : countries ){
      outfile << country << std::endl;
    }
  }
  outfile.close();

  //capital_name entry
  outfile.open("capital_name.txt");
  {
    std::vector<std::string> capitals;
    capitals = {"Washington","London","Seoul"};
    for ( auto capital : capitals ){
      outfile << capital << std::endl;
    }
  }
  outfile.close();

  //Reading Files
  std::ifstream infile;

  //Reading country_names.txt
  infile.open("country_names.txt");
  {
    std::cout << "Content of country_names.txt" << std::endl;
    while (infile) {
      getline(infile,str);
      std::cout << str << std::endl;
    }
  }

  infile.close();

  //Reading capital_name.txt
  infile.open("capital_name.txt");
  {
    std::cout << "Content of capital_name.txt" << std::endl;
    while (infile) {
      getline(infile,str);
      std::cout << str << std::endl;
    }
  }
  infile.close();

  return 0;
}
