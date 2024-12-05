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
typedef std::vector<vs> vvs;
typedef std::vector<ll> vll;
typedef std::vector<std::pair<ll, ll>> vp;
typedef std::vector<std::vector<long long>> matriz;

int main() {
  // Example of reading
  auto input = readInput();
  vs rules_s;
  vvs list_order, good_list,bad_list;
  bool is_rules = true;
  std::unordered_multimap<std::string, std::string> danger_list;
  std::unordered_multimap<std::string, std::string> check_list;
  for (auto i : input) {
    if (is_rules && i != "") {
      auto aux = split(i, '|');
      danger_list.insert(std::make_pair(aux[1], aux[0]));
      check_list.insert(std::make_pair(aux[1], aux[0]));
    } else if (i == "") {
      is_rules = false;
    } else {
      list_order.push_back(split(i, ','));
    }
  }
  for (auto list : list_order) {
    std::unordered_set<std::string> danger_pages;
    std::set<std::string> set_elements;  // posibles changes if can repeat values
    bool is_good = true;
    for (auto page : list) {
      auto not_range = danger_pages.find(page);
      if (not_range != danger_pages.end()) {  // have the page
        is_good = false;
        break;
      }
      auto range = danger_list.equal_range(page);
      for (auto it = range.first; it != range.second; it++) {
        danger_pages.insert(it->second);
      }
    }
    // need to list is good respect values pair
    if (is_good) {
      bool must_be_use = true;
      for (auto page : set_elements) {
        auto range = check_list.equal_range(page);
        bool have_value = false;
        for (auto it = range.first; it != range.second; it++) {
          auto finder = set_elements.find(it->second);
          if (finder != set_elements.end()) {  // is find
            have_value = true;
            break;
          }
        }
        if (!have_value) {
          must_be_use = false;
        }
      }
      if (must_be_use) {
        good_list.push_back(list);
      }else {
        bad_list.push_back(list);
      }
    }
  }
  vs output;
  for (auto i : bad_list) {
    output.push_back(i[i.size() / 2]);
  }
  ll sum = 0;
  for (auto i : output) {
    std::cout << i << " ";
    sum += stoi(i);
  }
  std::cout << sum << "\n";

  return 0;
}