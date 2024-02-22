#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Получаем алфавит длины n
char* get_alphabet(int n) {
    char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    if (n > 62) n = 62;

    char* result = malloc((n + 1) * sizeof(char));
    strncpy(result, alphabet, n);
    result[n] = '\0';

    return result;
}

// Перевод из системы счисления с основанием base в десятичную систему счисления
int convert_to_dec(char* number, int base){
    if (base > 62){
        return -1;
    }

    int len = strlen(number);
    char* alphabet = get_alphabet(base);
    int result = 0;
    int pow = 1;
    for (int i = len - 1; i >= 0; i--) {
        int index = 0;
        for (int j = 0; j < base; j++) {
            if (number[i] == alphabet[j]) {
                index = j;
                break;
            }
        }
        result += index * pow;
        pow *= base;
    }
    return result;
}

// Перевод из системы счисления с основанием base1 в систему с основанием base2
char* base_converter(char* number, int base1, int base2){
    if (base1 > 62 || base2 > 62){
        return NULL;
    }

    int dec = convert_to_dec(number, base1);
    char* alphabet = get_alphabet(base2);
    int len = 0;
    int tmp = dec;
    while (tmp > 0) {
        tmp /= base2;
        len++;
    }
    if (len == 0) len = 1;
    char* result = malloc((len + 1) * sizeof(char));
    result[len] = '\0';
    for (int i = len - 1; i >= 0; i--) {
        result[i] = alphabet[dec % base2];
        dec /= base2;
    }
    return result;
}





