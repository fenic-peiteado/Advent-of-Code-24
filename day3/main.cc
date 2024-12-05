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

typedef long long int ll;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<ll> vll;
typedef std::vector<std::pair<ll, ll>> vp;

vp extrac_mult(std::string linex) {
  std::regex pattern1("(.*?)(don't\\(\\).*?)(do\\(\\).*?)");  
  std::string line = std::regex_replace(linex, pattern1, "$1$3");
  std::string line1 = line;
  bool posibly_change = true;
  while (posibly_change) {
    line = std::regex_replace(line, pattern1, "$1$3");
    if (line != line1) {
      line1 = line;
    } else {
      posibly_change = false;
    }
  }
  std::regex pattern("(mul)\\((\\d?\\d?\\d?),(\\d?\\d?\\d?)\\)");
  auto search = std::regex_search(line, pattern);
  std::smatch coincidencia;
  auto words_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
  auto words_ends = std::sregex_iterator();

  vp result;
  for (auto i = words_begin; i != words_ends; ++i) {
    std::smatch match = *i;
    auto element = std::make_pair(stoi(match[2].str()), stoi(match[3].str()));
    result.push_back(element);
  }
  return result;
}

int main() {
  // Ejemplo de lectura
  auto input = readInput();
  std::vector<long> actual;
  std::map<int, int> right_list;
  int counts = 0;
  ll sum = 0;
  std::string line = "";
  for (auto i : input) {
    // auto spli_r = split(reduceSpaces(i), ' ');
    line += i;
  }
  auto result = extrac_mult(line);
  for (auto i : result) {
    sum += (i.first * i.second);
  }
  // ordenadr salida
  std::cout << sum << "\n";
  return 0;
}