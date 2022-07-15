#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cipher.h"

void init()
{
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
}

void banner()
{
    printf("========================================================================================\n");
    printf("+      $ $ $ $   $ $ $ $ $ $   $ $ $ $ $     $         $   $ $ $ $ $ $   $ $ $ $ $     +\n");
    printf("+    $               $         $       $     $         $   $             $        $    +\n");
    printf("+   $                $         $       $     $         $   $             $ $ $ $ $     +\n");
    printf("+  $                 $         $ $ $ $ $     $ $ $ $ $ $   $ $ $ $ $ $   $ $ $ $ $     +\n");
    printf("+   $                $         $             $         $   $             $ $  $  $     +\n");
    printf("+    $               $         $             $         $   $             $ $   $  $    +\n");
    printf("+      $ $ $ $   $ $ $ $ $ $   $             $         $   $ $ $ $ $ $   $ $   $ $ $   +\n");
    printf("========================================================================================\n");
    printf("\n");
}

void menu()
{
    printf("Choose an encryption method\n");
    printf("1. Caesar Cipher\n");
    printf("4. Exit\n");
    printf(">> ");
}

void enc_or_dec()
{
    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf(">> ");
}

void init_plain()
{
    memset(plain_text, 0, PLAIN_SIZE);
}

int main()
{
    int choice, key;
    int sel;

    init();
    banner();

    while(1) {
        menu();
        scanf("%d", &choice);
        system("clear");

        switch(choice) {
            case 1:
                enc_or_dec();
                scanf("%d", &sel);
                printf("\n");
                
                init_plain();

                if(sel == 1) { 
                    printf("Enter plain text : ");
                    read(0, plain_text, sizeof(plain_text) - 1);

                    printf("Key : ");
                    scanf("%d", &key);

                    if(key <= 0 || key > 26) {
                        printf("key range from 1 to 26...\n");
                        break;
                    }

                    enc_caesar(plain_text, key);
                }
                else if(sel == 2) {
                    if(enc_text[0] == '\0') {
                        printf("No encrypted text...\n");
                        break;
                    }

                    dec_caesar(enc_text, key);
                }
                break;

            case 4:
                printf("Bye~!\n");
                return 0;

            default:
                break;
        }
        printf("\n");
    }
}