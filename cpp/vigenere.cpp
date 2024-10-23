#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class VigenereCipher {
public:
    // Encryption function to encrypt the plaintext using the key
    string encrypt(const string &plaintext, const string &key) {
        string ciphertext;
        int keyIndex = 0;
        int keyLength = key.length();

        for (char ch : plaintext) {
            if (isalpha(ch)) {
                char base = isupper(ch) ? 'A' : 'a';
                char keyChar = toupper(key[keyIndex % keyLength]) - 'A';
                char encryptedChar = (ch - base + keyChar) % 26 + base;
                ciphertext += encryptedChar;
                keyIndex++;
            } else {
                ciphertext += ch; // Non-albhabetic character will be added as is it
            }
        }
        return ciphertext;
    }

    // Decryption function the ciphertext using the key
    string decrypt(const string &ciphertext, const string &key) {
        string plaintext;
        int keyIndex = 0;
        int keyLength = key.length();

        for (char ch : ciphertext) {
            if (isalpha(ch)) {
                char base = isupper(ch) ? 'A' : 'a';
                char keyChar = toupper(key[keyIndex % keyLength]) - 'A';
                char decryptedChar = (ch - base - keyChar + 26) % 26 + base;
                plaintext += decryptedChar;
                keyIndex++;
            } else {
                plaintext += ch; // Non-alphabetic character will be added as it is.
            }
        }
        return plaintext;
    }
};

int main() {
    VigenereCipher vc;
    string plaintext, key;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter key: ";
    getline(cin, key);

    string encrypted = vc.encrypt(plaintext, key);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = vc.decrypt(encrypted, key);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
