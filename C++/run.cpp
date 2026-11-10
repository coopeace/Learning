#include <iostream>
#include "networkmanager.h"
#include <string>

int main(){
  NetworkManager manager;
  manager.get("https://simplescraper.io/");
  std::string result = manager.res();
  std::cout << result;
  return 0;
}
