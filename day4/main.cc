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

typedef long long ll;
typedef std::vector<long long> vi;
typedef std::vector<std::string> vs;
typedef std::vector<ll> vll;
typedef std::vector<std::pair<ll, ll>> vp;
typedef std::vector<std::vector<long long>> matrix;

std::string reverse_x(std::string r) {
  reverse(r.begin(), r.end());
  return r;
}

bool checkWord(std::string word) {
  if (word == "MAS") {
    return true;
  } else if (word == "SAM") {
    return true;
  }
  return false;
}

long long countSubWords(std::vector<std::string> element) {
  std::string aux_check = "";
  long long counts = 0;
  size_t SIZE_WORD = 3;
  size_t size_v = element.size();
  for (long long i = 0; i < element.size(); i++) {
    size_t size_h = element[0].size();
    for (long long j = 0; j < element[0].size(); j++) {
      // diagona principal
      if (i + SIZE_WORD - 1 < size_v && j + SIZE_WORD - 1 < size_h &&
          j - SIZE_WORD - 1 >= 0) {
        aux_check.clear();
        for (long long x = 0; x < SIZE_WORD; x++) {
          aux_check += element[i + x][j + x];
        }
        if (checkWord(aux_check)) {
        aux_check.clear();
          for (long long x = 0; x < SIZE_WORD; x++) {
            aux_check += element[i + x][j + 2 - x];
          }
          std::cout << aux_check << "\n";
          if (checkWord(aux_check)) {
            counts++;
          }
        }
      }
    }

    // horizontal
    //   if (j SIZE_WORD -1 < size_h) {
    //     aux_check = element[i].substr(j, SIZE_WORD);
    //     if (checkWord(aux_check)) {
    //       counts++;
    //     }
    //   }
    //   // vertical
    //   if (i SIZE_WORD -1 < size_v) {
    //     aux_check.clear();
    //     for (long long x = 0; x < SIZE_WORD; x++) {
    //       aux_check += element[i + x][j];
    //     }
    //     std::cout << aux_check << "\n";
    //     if (checkWord(aux_check)) {
    //       counts++;
    //     }
    //   }
    // diagonal first
    //  if (i + SIZE_WORD - 1 < size_v && j + SIZE_WORD - 1 < size_h) {
    //    aux_check.clear();
    //
    //    for (long long x = 0; x < SIZE_WORD; x++) {
    //      aux_check += element[i + x][j + x];
    //    }
    //
    //    if (checkWord(aux_check)) {
    //      counts++;
    //    }
    //  }
    //
    //  if (i + SIZE_WORD - 1 < size_v && j - SIZE_WORD - 1 >= 0) {
    //    aux_check.clear();
    //    for (long long x = 0; x < SIZE_WORD; x++) {
    //      aux_check += element[i + x][j - x];
    //    }
    //    if (checkWord(aux_check)) {
    //      counts++;
    //    }
    //  }
    //}
  }
  return counts;
}

int main() {
  // Example of reading
  auto input = readInput();
  long result = 0;
  int sum;
  result += countSubWords(input);
  // for (int i = 0; i < input.size(); i++) {
  //   for (int j = 0; j < input[0].size(); j++) {
  //     std::string aux = "";
  //     vs sub_m;
  //     if (i + 2 < input.size() && j + 2 < input[0].size()) {
  //       for (int x = 0; x < 3; x++) {
  //         for (int y = 0; y < 3; y++) {
  //           aux += input[i + x][j + y];
  //         }
  //         sub_m.push_back(aux);
  //         aux.clear();
  //       }
  //       result += countSubWords(sub_m);
  //     }
  //   }
  // }
  std::cout << result << "\n";
  return 0;
}