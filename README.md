Base 256 Encoding using Unicode
===============================
This repo contains a simple C++ program to represent binary data in base 256 encoding by using Unicode characters (B256U).  Typical use cases for B256U are safe passwords, digital keys, file checksums, identifiers and hashes.

What is B256U?
---------------
Each byte is represented by exactly one Unicode character and vice versa each Unicode character represents exactly one byte. The mapping from byte to Unicode is quite simple:

| Byte     | Unicode                                    | 
|----------|--------------------------------------------|
| 0...9    | '0'...'9' (10 digits)                      |  
| 10...35  | 'A'...'Z' (26 uppercase letters)           |
| 36...61  | 'a'...'z' (26 lowercase letters)           | 
| 62...255 | 'À', 'Á', 'Â', ... (194 umlaut characters) |

Advantages
----------
* **It's short**: just 16 Unicode characters represent 128-bit of data, 32 characters represent 256-bit of data
* **It's safe**: people are forced to copy & paste it 
* **It's easy to implement**: see the [source code](base256.cpp)
* **It's easy to recognize**: lots of umlauts (see the examples below)
* **It supports double-click** for copy & paste (no terminal characters in B256U) 
* **It's backward compatible**: B256U uses Unicode 1.0 only (highest code point used is 385)

Build Requirements
------------------
Just cmake and a C++ compiler are required.

Installation
------------
Execute in a terminal window: 
```
> git clone https://github.com/fleschutz/base256unicode  # Or download und unzip the ZIP file (click green button)
> cd base256unicode
> cmake .
> make
> ./base256
```

Examples
--------
128-bit of random data in base 256: `ĺËĀ8Ę3ĩŔá0VzœĹŀî`, `ŽTĭŊõł3ÐÑęGųĢÛąĶ`, `5iŗ3īÛźUKĺŰÑÞbŒŜ`, `ņĨqvLŀŠsůØŸÙGCŰƀ`, `ŋôBĉOÍŬįēĳmōįUĞÜ`, `Sőś6ŬŹŠęűöìÇthTK`.

256-bit of random data in base 256: `ħŅŹĬšÝŋţĀĸĻňőċqâĮŹúŪßWPŞÓā8æťÁüċ`, `Ě2ħŤRŧáÃĆĶ2ÕŀSŜöĄPŞÜbŰ06lŔùö9ĬŒģ`, `āLë2lÏäöĥųŧpğĨķŇHĺ4LăsŸđĵ_űLeYhĩ`, `ÂŚÔJàįŶļcvàPĈčĲċĉĲĂūęŻÉĢJĸķ3ğPĭŠ`

How long does it take to break a random key or password?
--------------------------------------------------------
Trying every possible key or password (called a 'brute force attack') at one billion attempts per second:

| Key size | Time needed                               | Key example                        |
|----------|-------------------------------------------|------------------------------------|
|  40-bit  | about 9 minutes                           |                                    |
|  56-bit  | about a year                              |                                    |
| 128-bit  | about 5,783,128,169,837,158,197,871 years | `ĤŗwĹĦñŧīĳēaqöĜĖŅ`                 |
| 256-bit  | never, for all practical purposes         | `ÿőMêŽĖiĘśŃäŞŰÀ8ŒŽĎäPfSŖÔń÷Ī7ėëŷò` |

📧 Feedback
------------
Send your email feedback to: markus.fleschutz [at] gmail.com

🤝 License & Copyright
-----------------------
This open source project is licensed under the CC0 license. All trademarks are the property of their respective owners.
