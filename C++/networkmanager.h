#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <cstdio>
#include <stdexcept>
#include <string>

class NetworkManager{
  public :
    std::string command,result,url;
    char buffer[256];
    std::string res(){
      return result;
    }
    void get(std::string url){
      this->url = url;
      command = "curl -sS " + url;
      FILE *pipe = popen(command.c_str(), "r");
      if (!pipe)
        throw std::runtime_error("PIPING FAILED");
      while (fgets(buffer,sizeof(buffer),pipe)!=nullptr)
        result += buffer;
      pclose(pipe);
    }
};

#endif // !NETWORKMANAER_H
