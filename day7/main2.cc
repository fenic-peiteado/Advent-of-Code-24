#include <gmp.h>

#include <iostream>

#include "utils.cc"

int main() {
  auto input = readInput();
  vvs list_e;
  for (auto& i : input) {
    list_e.push_back(split(i, ':'));
  }

  matriz number_sequence;
  vi aux;
  for (auto& list_simple : list_e) {
    aux.push_back(stoll(list_simple[0]));
    auto correction = split(
        stripSpace(join_s(vs(list_simple.begin() + 1, list_simple.end()))),
        ' ');
    for (long long i = 0; i < correction.size(); i++) {
      aux.push_back(stoll(correction[i]));
    }
    number_sequence.push_back(aux);
    aux.clear();
  }

  mpz_t result_final;
  mpz_init(result_final);

  for (long long i = 0; i < number_sequence.size(); i++) {
    long long number_to_find = number_sequence[i][0];
    long long num_elements = number_sequence[i].size() - 1;
    long long limit = pow(2, num_elements - 1);
    bool flag = false;

    for (long long k = 0; k < limit; k++) {
      std::bitset<64> mask_bits(k);

      for (long long t = 0; t < limit; t++) {
        std::bitset<64> mask_bits_2(t);
        mpz_t result;
        mpz_init_set_si(result, number_sequence[i][1]);

        for (long long l = 0; l < num_elements - 1; l++) {
          if (mask_bits_2[l] == 0) {
            if (mask_bits[l] == 0) {
              mpz_add_ui(result, result, number_sequence[i][l + 2]);  // 0 0 = +
            } else {
              mpz_mul_ui(result, result, number_sequence[i][l + 2]);  // 0 1 = *
            }
          } else {
            if (mask_bits[l] == 0) {
              std::string result_str = mpz_get_str(NULL, 10, result);
              std::string number_str =
                  std::to_string(number_sequence[i][l + 2]);
              std::string concatenated_str = result_str + number_str;

              // Convertir de nuevo a mpz_t
              mpz_set_str(result, concatenated_str.c_str(), 10);
            } else {
              break;  // 1 1 = break
            }
          }
        }

        if (mpz_cmp_ui(result, number_to_find) == 0) {
          mpz_add(result_final, result_final, result);
          // std::cout << "Encontrado: ";
          // mpz_out_str(stdout, 10, result);
          // std::cout << std::endl;
          flag = true;
          mpz_clear(result);
          break;
        }

        mpz_clear(result);
        if (flag) {
          break;
        }
      }

      if (flag) {
        break;
      }
    }
  }

  std::cout << "Resultado final: ";
  mpz_out_str(stdout, 10, result_final);
  std::cout << std::endl;
  mpz_clear(result_final);

  return 0;
}
