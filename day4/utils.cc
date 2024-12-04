
#include <bits/stdc++.h>


std::vector<std::string> split(std::string line, char separator) {
  std::vector<std::string> result;
  std::istringstream ss(line);
  std::string token;
  while(std::getline(ss, token,separator)){
    result.push_back(token);
  }
  return result;
}

std::string reduceChar(std::string line, std::string separator, char replace) {
  std::regex reg(separator);
  return std::regex_replace(line, reg, std::string(1, replace));
} 

std::string reduceSpaces(const std::string& line) {
    std::regex reg("\\s+"); // Coincide con uno o más espacios consecutivos
    return std::regex_replace(line, reg, " "); // Reemplaza con un único espacio
}

std::string join_s(std::vector<std::string> aux) {
  std::string result;
  for(auto i : aux){
    result.append(i);
  }
  return result;
}

// read for input and return a vector of strings
std::vector<std::string> readInput() {
  std::string line;
  std::vector<std::string> result;
  while (std::getline(std::cin, line)) {
    result.push_back(line);
  }
  return result;
}

template <typename T>
void printVector(std::vector<T> vec) {
  for (auto i : vec) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}