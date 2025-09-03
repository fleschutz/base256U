Base256 Encoding in Unicode (base256U)
======================================
This repo contains a C++ sample implementation to represent binary data in base256 encoding by using Unicode characters. Typical use cases are representing safe passwords, digital keys, file checksums, identifiers, hashes, extremely big numbers, or data in character-limited messengers.

What is base256U?
-----------------
Each byte is represented by exactly one Unicode character (and vice versa). The mapping of byte to Unicode is dead simple:

| Byte   | Unicode Character                  | Description           |
|--------|------------------------------------|-----------------------|
|    0-9 | '0'-'9'                            | 10 digits             |
|  10-35 | 'A'-'Z'                            | 26 uppercase letters  |
|  36-61 | 'a'-'z'                            | 26 lowercase letters  |
| 62-255 | 'À', 'Á', 'Â', 'Ã', 'Ä', ...       | 194 accent letters    |

✔️ Advantages
--------------
* **Ultra compact**, e.g. 16 characters like `5iŗ3īÛźUKĺŰÑÞbŒŜ` encode 128-bit of data!
* **Easy to recognize** due to the accent letters.
* **Safe to use:** can't be remembered (no need to hide it), so people are forced to copy & paste it.
* **Supports double-clicking** for comfortable copy & paste (all Unicode characters are non-terminal ones).
* **Supports all Unicode versions** due to highest code point 387 (requires Unicode 1.0 or higher).
* **Easy to implement**, see [base256U.cpp](base256U.cpp) for a C++ implementation.

🔧 Installation
----------------
Requires a **C++ compiler** and **cmake**. Then execute in a terminal window: 
```
> git clone https://github.com/fleschutz/base256U  # or download und unzip the ZIP file (click the green button)
> cd base256U
> cmake .
> make
> ./base256U
```

🎉 Examples
------------
* 64-bit keys: `ŖÔńĪ07ėñ`, `RŧáÃĆĶ2Õ`
* 128-bit keys: `ĺËĀ8Ę3ĩŔá0VzœĹŀî`, `ŽTĭŊõł3ÐÑęGųĢÛąĶ`, `5iŗ3īÛźUKĺŰÑÞbŒŜ`, `ņĨqvLŀŠsůØŸÙGCŰƀ`
* 256-bit keys: `ħŅŹĬšÝŋţĀĸĻňőċqâĮŹúŪßWPŞÓā8æťÁüċ`, `Ě2ħŤRŧáÃĆĶ2ÕŀSŜöĄPŞÜbŰ06lŔùö9ĬŒģ`
* [zeichensalat](https://karme.de/zeichensalat/): a tool to make/run compressed executables copy/pastes using less than 500 unicode characters. It is intended to be used on the fediverse (or in  chats).


⚖️ Other Encoding Standards
----------------------------

| Base | Name                                                     | Alphabet                      | Example | Overhead |
|------|----------------------------------------------------------|-------------------------------|---------|----------|
|    2 | Binary                                                   | 0 or 1                        | 0101101 | +800%    |
|    8 | Octal                                                    | 0-7                           | 7734124 |          |
|   10 | Decimal                                                  | 0-9                           | 3849834 |          |
|   16 | [Hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal) | 0-9,a-f (case insensitive)    | 7a9ff34 | +100%    |
|   32 | [Base32](https://en.wikipedia.org/wiki/Base32)           | A-Z,2-7                       | S7FFQZB | +60%     |
|   36 | [Base36](https://en.wikipedia.org/wiki/Base36)           | 0-9,A-Z                       | 7RT99XQ |          |
|   45 | Base45                                                   | 0-9,A-Z,space,$,%,*,+,-,.,/,: | 8X%/9:A |          |
|   64 | [Base64](https://en.wikipedia.org/wiki/Base64)           | A-Z,a-z,0-9,+,-               | zA8r+8q | +33%/37% |
|   85 | [Base85](https://en.wikipedia.org/wiki/Ascii85)          | !,",#,...,z                   | 9jqo    | +25%     |
|  256 | Base256U                                                 | 0-9,A-Z,a-z,accent letters    | ĘśŃäŞŰÀ | +~75%    |


How long does it take to break a random key or password?
--------------------------------------------------------
Trying every possible key or password (called a 'brute force attack') at one billion attempts per second:

| Key Size | Key Example                        | Maximum Time Needed                     | 
|----------|------------------------------------|-----------------------------------------|
|  40-bit  | `ŞŰÀ8Œ`                            | ~9 minutes                              |
|  56-bit  | `ŖÔńĪ7ėñ`                          | ~1 year                                 |
| 128-bit  | `ĤŗwĹĦñŧīĳēaqöĜĖŅ`                 | ~5,783,128,169,837,158,197,871 years    |
| 256-bit  | `ÿőMêŽĖiĘśŃäŞŰÀ8ŒŽĎäPfSŖÔńiĪ7ėëŷò` | never, for all practical purposes       |

🤝 Contributing
----------------
* Contributions, suggestions, and improvements are always welcome!
* Open an Issue if you encounter bugs or have feature ideas.
* Create a Pull Request if you'd like to improve something.
* Or just send your feedback to: markus.fleschutz [at] gmail.com

📜 License & Copyright
-----------------------
This open source project is licensed under the CC0 license. All trademarks are the property of their respective owners.
