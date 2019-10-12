# Vigenere Cipher
<p align="center">
<!-- replace image by project Image -->
<img height="128" src="https://cryptools.github.io/img/vigenere.svg">
</p>
<p align="center">
<img src="https://cryptools.github.io/img/status/in-review.svg">
<!-- replace `cryptools.github.io` by the project repo name-->
<img src="https://img.shields.io/github/license/Cryptools/cryptolls.github.io.svg">
<img src="https://img.shields.io/github/contributors/Cryptools/cryptools.github.io.svg">
</p>

Secure cipher but now breakable

## How it works

At its core, the vigenere cipher is several Caesar ciphers, with a different shift value depending on the key. It can be computed simply by hand, through the use of a vigenere table. In code, it can be done using modulo arithmetic.

### Encoding

To encode, we first convert every letter to a number between 0 and 25, where A is 0, and Z is 25. If the key is shorter than the message, it is repeated until they are the same length, i.e. if the message is `cryptography`, and the key is `secretkey`:

```txt
msg = cryptography
key = secretkeysec
```

The ith character of the output O, can be computed from the message M, and key K using the follwing formula:

```txt
O[i] = (M[i] + K[i]) mod 26
```

### Decoding

Decoding the output O, into the message M knowing the key K, is just as simple:

```txt
M[i] = (O[i] - K[i]) mod 26
```

## Implementations

|  Language  |           Encrypt           |           Decrypt           |
|------------|-----------------------------|-----------------------------|
| Javascript | [encrypt.js](js/encrypt.js) | [decrypt.js](js/decrypt.js) |
|   Python   | [encrypt.py](py/encrypt.py) | [decrypt.py](py/decrypt.py) |
|      C     | [vigenere.c](c/vigenere.c)  | [vigenere.c](c/vigenere.c)  |

## Running the tests

Tests are automatically handled by [Travis CI](https://travis-ci.org).

## Contributing

Please read [CONTRIBUTING.md](https://github.com/CrypTools/cryptools.github.io/blob/master/CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/CrypTools/cipher/tags).

## Authors

* **Luka Lafaye** - *Initial work* - [@lukalafaye](https://github.com/lukalafaye)
* **Arthur Guiot** - *Wrote JS Implementation* - [@arguoit](https://github.com/arguiot)
* **Lucas Gruwez** - *Clean up work* - [@lucasgruwez](https://github.com/lucasgruwez)

See also the list of [contributors](https://github.com/CrypTools/cipher/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
