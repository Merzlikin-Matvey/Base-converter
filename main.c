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

// Перевод из десятичной системы счисления в систему счисления с основанием base
char* base_convert(int n, int base){
    char* alphabet = get_alphabet(base);
    int len = 1;
    int tmp = n;
    while (tmp >= base) {
        tmp /= base;
        len++;
    }

    char* result = malloc((len + 1) * sizeof(char));
    result[len] = '\0';

    for (int i = len - 1; i >= 0; i--) {
        result[i] = alphabet[n % base];
        n /= base;
    }

    return result;
}



