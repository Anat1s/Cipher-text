#include <stdio.h>
#include <string.h>
#include "cipher.h"

void init_enc()
{
    memset(enc_text, 0, ENC_SIZE);
}

void init_dec()
{
    memset(dec_text, 0, PLAIN_SIZE);
}

void enc_caesar(char plain[], int key)
{
    int i;

    init_enc();

    for(i = 0; i < PLAIN_SIZE; i++) {
        if(plain[i] >= 'a' && plain[i] <= 'z') {
            enc_text[i] = plain[i] + key;
            if(enc_text[i] > 'z')
                enc_text[i] -= 26;
        }

        if(plain[i] >= 'A' && plain[i] <= 'Z') {
            enc_text[i] =  plain[i] + key;
            if(enc_text[i] > 'Z')
                enc_text[i] -= 26;
        }

        if(enc_text[i] == '\0')
            break;
    }

    printf("Encryption text : %s\n", enc_text);
}

void dec_caesar(char enc[], int key)
{
    int i;

    init_dec();

    for(i = 0; i < ENC_SIZE; i++) {
        if(enc_text[i] >= 'a' && enc_text[i] <= 'z') {
            dec_text[i] = enc_text[i] - key;
            if(dec_text[i] < 'a')
                dec_text[i] += 26;
        }

        if(enc_text[i] >= 'A' && enc_text[i] <= 'Z') {
            dec_text[i] = enc_text[i] - key;
            if(dec_text[i] < 'A')
                dec_text[i] += 26;
        }

        if(dec_text[i] == '\0')
            break;
    }

    printf("Decryption text : %s\n", dec_text);
}