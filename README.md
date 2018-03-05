# VigenereCipher

## History and usage

The ***Vigenere cipher*** was named after **Blaise de Vigenère**. This **substitutiom cipher** was invented by Giovan Battista Bellaso in 1553, however, the scheme was later ameliorated by Blaise de Vigenère in the 19th century, and therefore acquired its present name. The Vigenere cipher is similar to the **Caesar cipher**, but is harder to break (it resisted all attempts for around three centuries).

## Detailed Explanations : How it works?

#### 1. Firstly, we'll "draw" the Vigenere Table:
<img align="center" width="500" src="https://upload.wikimedia.org/wikipedia/commons/9/9a/Vigenère_square_shading.svg"/>

#### 2. After, we'll repeat the key:
If our message has a length of 12 for example, and our key is `CRYPTOOLS`, then we just repeat it until the new key length is superior to the message length:

```
CRYPTOOLSCRYPTOOLS
```
And we take the first `x` characters of this string, where `x` is our message length:
```
CRYPTOOLSCRY
```

#### 3. We encrypt the message using the Vigenere Table:
```
CRYPTOGRAPHY
     |
     v
CRYPTOOLSCRY
------------
EIWEMCUCSRYW
```
#### 4. We output the word
```
return "EIWEMCUCSRYW"
```
## Weaknesses
- Repeating key
- Cryptanalysis can determine the key length

## Implementations

| **Language** | Encrypt                        | Decrypt                        |
| ------------ | ------------------------------ | ------------------------------ |
| C            | [c/vigenere.c](c/vigenere.c)   | [c/vigenere.c](c/vigenere.c)   |
| Python       | [py/encrypt.py](py/encrypt.py) | [py/decrypt.py](py/decrypt.py) |
| JavaScript   | [js/encrypt.js](js/encrypt.js) | [js/decrypt.js](js/decrypt.js) |
