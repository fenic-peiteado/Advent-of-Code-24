/**
 * @file main.cc
 * @author Jose Fenic Peiteado Padilla (alu0101227023@ull.edu.es)
 * @brief The solution for advent of code 2024 day 1
 * @version 0.1
 * @date 2024-11-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <bits/stdc++.h>
#include "utils.cc"



int main() {

// Ejemplo de lectura
  auto input = readInput();
  std::vector<long long> left,right;
  std::map<int,int> right_list;
  for (auto i: input) {
    auto spli_r = split(i,' ');
    left.push_back(stoi(spli_r[0]));
    right.push_back(stoi(spli_r[3]));
    long long right = stoi(spli_r[3]);
    right_list[right] += 1;
 }
 //ordenadr salida
  std::sort(left.begin(),left.end());
  std::sort(right.begin(), right.end());
  size_t result = 0;
  for(long long i = 0; i< left.size();i++) {
    result += abs(left[i] * right[i]);
  }
  size_t result2 = 0;
  for(long i = 0; i < left.size();i++) {
    result2 += left[i]*right_list[left[i]];
  }
  std::cout << result << "\n";
  std::cout << result2 << "\n"; 
return 0;
}