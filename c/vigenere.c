// CrypTools - GitHub
// Tuesday, 14 August 2018
// Vignerere Cipher to encrypt text

/*****
Compile:
$ make
Use:
$ ./vigenere KEYARRAY < file.txt
Note that the KEYARRAY should only be composed of alphabetical lowercase and uppercase letters.
*****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINCAP 65
#define MAXCAP 90

#define MINLOW 97
#define MAXLOW 122

void encode (int shiftNumber, char letter);
int getFirstLetter (char letter);

// Takes an int and a file containing text to encrypt
int main (int argc, char *argv[]) {
    int shift = 0;
    int c = 0;
    // set key
    char *key = argv[1];
    int keyLength = strlen(key);
    int keyIndex = 0;
    int currentLetter = 0;
    while ((c = getchar()) != EOF) {
        currentLetter = key[keyIndex % keyLength];
        shift = (currentLetter - getFirstLetter(currentLetter));
        keyIndex++;
        encode(shift, c);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

/* takes a character and increments it by shift */
void encode (int shift, char letter) {
    int numAscii = letter;
    int firstLetter = getFirstLetter(letter);
    if ((firstLetter == 65) || (firstLetter == 97)) {
        numAscii -= (firstLetter - shift);
        numAscii = (numAscii % 26);
        numAscii += firstLetter;
        putchar(numAscii);
    }
}

int getFirstLetter (char letter) {
    int numAscii = letter;
    int firstLetter;
    if (numAscii >= MINCAP && numAscii <= MAXCAP) {
        firstLetter = MINCAP;
    } else if (numAscii >= MINLOW && numAscii <= MAXLOW) {
        firstLetter = MINLOW;
    } else {
        putchar(letter);
        firstLetter = 1;
    }
    return firstLetter;
}
