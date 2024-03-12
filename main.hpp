#ifndef MAIN_H
#define MAIN_H

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

// Получаем алфавит длины n
std::string get_alphabet(int n) {
    std::string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    if (n > 62) n = 62;
    return alphabet.substr(0, n);
}

// Перевод из системы счисления с основанием base в десятичную систему счисления
int convert_to_dec(const std::string& number, int base){
    if (base > 62){
        return -1;
    }

    int len = number.length();
    std::string alphabet = get_alphabet(base);
    int result = 0;
    int pow = 1;
    for (int i = len - 1; i >= 0; i--) {
        int index = alphabet.find(number[i]);
        result += index * pow;
        pow *= base;
    }
    return result;
}

// Перевод из системы счисления с основанием base1 в систему с основанием base2
std::string base_converter(const std::string& number, int base1, int base2){
    if (base1 > 62 || base2 > 62){
        return "";
    }

    int dec = convert_to_dec(number, base1);
    std::string alphabet = get_alphabet(base2);
    std::vector<char> result;
    do {
        result.push_back(alphabet[dec % base2]);
        dec /= base2;
    } while (dec > 0);
    return std::string(result.rbegin(), result.rend());
}

#endif //MAIN_H