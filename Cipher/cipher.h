#ifndef __CIPHER_H__
#define __CIPHER_H__

#define PLAIN_SIZE    100
#define ENC_SIZE      150

char plain_text[PLAIN_SIZE];
char enc_text[ENC_SIZE];
char dec_text[PLAIN_SIZE];

void init_plain();
void init_enc();
void init_dec();

void enc_caesar(char plain[], int key);
void dec_caesar(char enc[], int key);

#endif