Base256 Encoding in Unicode (base256U)
======================================
This repo contains a C++ sample implementation to represent binary data in base256 encoding by using Unicode characters. Typical use cases are safe passwords, digital keys, file checksums, identifiers, hashes and very big numbers.

What is base256U?
-----------------
Each byte is represented by exactly one Unicode character and vice versa each Unicode character represents exactly one byte. The mapping of Byte vs Unicode is quite simple:

| Byte   | Unicode             | Description           |
|--------|---------------------|-----------------------|
|    0-9 | '0'-'9'             | 10 digits             |
|  10-35 | 'A'-'Z'             | 26 uppercase letters  |
|  36-61 | 'a'-'z'             | 26 lowercase letters  |
| 62-255 | 'À', 'Á', 'Â', ...  | 194 umlaut characters |

✔️ Advantages of base256U
-------------------------
* **Ultra compact**, e.g. just 16 characters like `5iŗ3īÛźUKĺŰÑÞbŒŜ` can encode 128-bit of data.
* **Easy to recognize** due to the umlaut characters.
* **Safe to use:** nearly impossible to remember, so people are forced to copy & paste it.
* **Supports double-clicking** for comfortable copy & paste (all Unicode characters are non-terminal ones).
* **Supports all Unicode versions** due to highest code point 385 (requires Unicode 1.0 or higher).
* **Easy to implement:** see the [source code in base256U.cpp](base256U.cpp)

🔧 Installation
----------------
Requires **cmake** and a **C++ compiler**. Then execute in a terminal window: 
```
> git clone https://github.com/fleschutz/base256U  # or download und unzip the ZIP file (click the green button)
> cd base256U
> cmake .
> make
> ./base256U
```


Examples of base256U
--------------------
* 64 bits: `ŖÔńĪ07ėñ`, `RŧáÃĆĶ2Õ`
* 128 bits: `ĺËĀ8Ę3ĩŔá0VzœĹŀî`, `ŽTĭŊõł3ÐÑęGųĢÛąĶ`, `5iŗ3īÛźUKĺŰÑÞbŒŜ`, `ņĨqvLŀŠsůØŸÙGCŰƀ`
* 256 bits: `ħŅŹĬšÝŋţĀĸĻňőċqâĮŹúŪßWPŞÓā8æťÁüċ`, `Ě2ħŤRŧáÃĆĶ2ÕŀSŜöĄPŞÜbŰ06lŔùö9ĬŒģ`


Other Encoding Standards
------------------------

| Base | Name        | Alphabet                      | Overhead | Example |
|------|-------------|-------------------------------|----------|---------|
|    2 | Bit         | 0 or 1                        |          | 0101101 |
|    8 | Octal       | 0-7                           |          | 7734124 |
|   10 | Decimal     | 0-9                           |          | 3849834 |
|   16 | [Hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal) | 0-9,a-f (case insensitive)    |          | 7a9ff34 |
|   36 | [Base36](https://en.wikipedia.org/wiki/Base36)           | 0-9,A-Z                       |          | 7RT99XQ |
|   45 | Base45                                                   | 0-9,A-Z,space,$,%,*,+,-,.,/,: |          | 8X%/9:A |
|   64 | [Base64](https://en.wikipedia.org/wiki/Base64)           | A-Z,a-z,0-9,+,-               | 33%-37%  | zA8r+8q |


How long does it take to break a random key or password?
--------------------------------------------------------
Trying every possible key or password (called a 'brute force attack') at one billion attempts per second:

| Key Size | Key Example                        | Maximum Time Needed                       | 
|----------|------------------------------------|-------------------------------------------|
|  40-bit  | `ŞŰÀ8Œ`                            | about 9 minutes                           |
|  56-bit  | `ŖÔńĪ7ėñ`                          | about a year                              |
| 128-bit  | `ĤŗwĹĦñŧīĳēaqöĜĖŅ`                 | about 5,783,128,169,837,158,197,871 years |
| 256-bit  | `ÿőMêŽĖiĘśŃäŞŰÀ8ŒŽĎäPfSŖÔńiĪ7ėëŷò` | never, for all practical purposes         |

📧 Feedback
------------
Send your email feedback to: markus.fleschutz [at] gmail.com

🤝 License & Copyright
-----------------------
This open source project is licensed under the CC0 license. All trademarks are the property of their respective owners.
