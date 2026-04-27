[![CMake on multiple platforms](https://github.com/fleschutz/base256U/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/base256U/actions/workflows/cmake-multi-platform.yml)

Base256 Encoding in Unicode (base256U)
======================================
This repo contains a C++ sample implementation to represent binary data in base256 encoding by using Unicode characters. Typical use cases are representing safe passwords, digital keys, file checksums, identifiers, hashes, extremely big numbers, or data in character-limited messengers.

What is base256U?
-----------------
Each byte is represented by exactly one Unicode character (and vice versa). The mapping of byte to Unicode is dead simple:

| Byte   | Unicode Character                  | Comment                   |
|--------|------------------------------------|---------------------------|
|    0-9 | '0'-'9'                            | the 10 digits             |
|  10-35 | 'A'-'Z'                            | the 26 uppercase letters  |
|  36-61 | 'a'-'z'                            | the 26 lowercase letters  |
| 62-255 | 'À', 'Á', 'Â', 'Ã', 'Ä', ...       | the 194 accent letters    |

✔️ Advantages
--------------
* **Ultra compact**, e.g. 16 characters like `5iŗ3īÛźUKĺŰÑÞbŒŜ` can encode 128-bit of data!
* **Easy to recognize** due to the accent letters.
* **Safe to use:** can't be remembered, so people are forced to copy & paste it (no need to hide it).
* **Supports double-clicking** for comfortable copy & paste (all Unicode characters are non-terminal ones).
* **Supports all Unicode versions:** highest code point is 387 which requires Unicode 1.0 only.
* **Easy to implement:** see [base256U.cpp](src/base256U.cpp).

🔧 Installation
----------------
Execute in a terminal window:  (*C++ compiler* and *cmake* required) 
```
> git clone https://github.com/fleschutz/base256U  # or download & unzip the ZIP file (click the green button)
> cd base256U/src
> cmake .
> make
> ./base256U
```

🎉 Examples
------------
* 64-bit encoding: `ŖÔńĪ07ėñ`, or `RŧáÃĆĶ2Õ`
* 128-bit encoding: `ĺËĀ8Ę3ĩŔá0VzœĹŀî`, `ŽTĭŊõł3ÐÑęGųĢÛąĶ`, `5iŗ3īÛźUKĺŰÑÞbŒŜ`, or `ņĨqvLŀŠsůØŸÙGCŰƀ`
* 256-bit encoding: `ħŅŹĬšÝŋţĀĸĻňőċqâĮŹúŪßWPŞÓā8æťÁüċ`, or `Ě2ħŤRŧáÃĆĶ2ÕŀSŜöĄPŞÜbŰ06lŔùö9ĬŒģ`
* [zeichensalat](https://karme.de/zeichensalat/): a tool to make compressed executables for copy & paste using less than 500 unicode characters. It is intended to be used on the fediverse (or in chats).


⚖️ Comparison of Encoding Standards
------------------------------------

| Base | Name                                                     | Alphabet                      | Example | Byte Overhead |
|------|----------------------------------------------------------|-------------------------------|---------|---------------|
|    2 | Binary                                                   | 0 or 1                        | 0101101 | 800%          |
|    8 | Octal                                                    | 0-7                           | 7734124 |               |
|   10 | Decimal                                                  | 0-9                           | 3849834 |               |
|   16 | [Hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal) | 0-9,a-f (case insensitive)    | 7a9ff34 | 100%          |
|   32 | [Base32](https://en.wikipedia.org/wiki/Base32)           | A-Z,2-7                       | S7FFQZB | 60%           |
|   36 | [Base36](https://en.wikipedia.org/wiki/Base36)           | 0-9,A-Z                       | 7RT99XQ |               |
|   45 | Base45                                                   | 0-9,A-Z,space,$,%,*,+,-,.,/,: | 8X%/9:A |               |
|   64 | [Base64](https://en.wikipedia.org/wiki/Base64)           | A-Z,a-z,0-9,+,-               | zA8r+8q | 33%/37%       |
|   85 | [Base85](https://en.wikipedia.org/wiki/Ascii85)          | !,",#,...,z                   | 9jqo    | 25%           |
|  256 | Base256U                                                 | 0-9,A-Z,a-z,accent letters    | ĘśŃäŞŰÀ | ~75%          |


Strength of Password/Key
------------------------
Required is a really random password or a random key (to rule out dictionary attacks). Then trying every possible key or
password (called a 'brute force attack') at one billion attempts per second:

| Key Size | Key Example                        | Max Time Needed @ 1B attempts/sec         | 
|----------|------------------------------------|-------------------------------------------|
|  40-bit  | `ŞŰÀ8Œ`                            | about 9 minutes                           |
|  56-bit  | `ŖÔńĪ7ėñ`                          | about a year                              |
| 128-bit  | `ĤŗwĹĦñŧīĳēaqöĜĖŅ`                 | about 5,783,128,169,837,158,197,871 years |
| 256-bit  | `ÿőMêŽĖiĘśŃäŞŰÀ8ŒŽĎäPfSŖÔńiĪ7ėëŷò` | never, for all practical purposes         |

🤝 Contributing
----------------
* Contributions, suggestions, and improvements are always welcome!
* Open an Issue if you encounter bugs or have feature ideas.
* Create a Pull Request if you'd like to improve something.

📜 License & Copyright
-----------------------
This open source project is licensed under the CC0 license. All trademarks are the property of their respective owners.
