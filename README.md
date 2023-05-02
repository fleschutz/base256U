Base 256 Unicode (B256U) Encoding
=================================
This repo contains a simple C++ program to represent binary data in B256U encoding. 

What is B256U Encoding?
-----------------------
Each Unicode character represents exactly one byte (and vice versa: each byte is represented by one Unicode character) - dead simple. The B256U alphabet of 256 possible Unicode characters consists of:

1. the **10 digits** (0...9)
2. the **26 uppercase letters** (A...Z) and the **26 lowercase letters** (a...z)
3. the **194 umlaut characters** (À, Á, Â, Ã, Ä, Å, ...)

Typical use cases for B256U encoding are safe passwords, file checksums, identifiers and hashes.

Advantages of B256U Encoding
----------------------------
* **it's short**: just 16 Unicode characters represent 128-bit of data, 32 characters represent 256-bit of data
* **it's safe**: people are forced to copy & paste it 
* **it's easy to implement**: see the [source code](base256.cpp)
* **it's easy to recognize**: lots of umlauts (see the examples below)
* **it supports double-click** for copy & paste (no terminal characters in B256U) 
* **it's backward compatible**: B256U uses Unicode 1.0 only (highest code point used is 385)

Installation
------------
Execute in a terminal window: (requires git, cmake, and a C++ compiler)

```
> git clone https://github.com/fleschutz/base256unicode; cd base256unicode
> cmake .
> make
> ./base256
```

Examples of 128-bit of data in B256U Encoding
---------------------------------------------
* `ĺËĀ8Ę3ĩŔá0VzœĹŀî`
* `ŽTĭŊõł3ÐÑęGųĢÛąĶ`
* `5iŗ3īÛźUKĺŰÑÞbŒŜ`
* `ņĨqvLŀŠsůØŸÙGCŰƀ`
* `ŋôBĉOÍŬįēĳmōįUĞÜ`
* `Sőś6ŬŹŠęűöìÇthTK`

Examples of 256-bit of data in B256U Encoding
---------------------------------------------
* `ħŅŹĬšÝŋţĀĸĻňőċqâĮŹúŪßWPŞÓā8æťÁüċ`
* `Ě2ħŤRŧáÃĆĶ2ÕŀSŜöĄPŞÜbŰ06lŔùö9ĬŒģ`
* `āLë2lÏäöĥųŧpğĨķŇHĺ4LăsŸđĵ_űLeYhĩ`
* `ÂŚÔJàįŶļcvàPĈčĲċĉĲĂūęŻÉĢJĸķ3ğPĭŠ`

How long does it take to break a random key or password?
--------------------------------------------------------
Trying every possible key or password (called a 'brute force attack') at one billion attempts per second:

--------------------------------------------------------
| Key size | Time to break                             |
| -------- | ----------------------------------------- |
|  40-bit  | about 9 minutes                           |
|  56-bit  | about a year                              |
| 128-bit  | about 5,783,128,169,837,158,197,871 years |
| 256-bit  | never, for all practical purposes         |
--------------------------------------------------------

Feedback
--------
Send your email feedback to: markus.fleschutz [at] gmail.com

License & Copyright
-------------------
This open source project is licensed under the CC0 license. All trademarks are the property of their respective owners.
