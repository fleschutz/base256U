Base 256 Unicode (B256U) Encoding
=================================
This repository contains a simple C++ sample program to represent binary data in B256U encoding. Typical use cases are passwords, file checksums, identifiers and hashes.

What is B256U Encoding?
-----------------------
Dead simple: each Unicode character represents exactly one byte (and vice versa each byte is represented by one Unicode character).

The 256 possible Unicode characters consist of the **10 digits** (0...9), the **26 uppercase letters** (A...Z), the **26 lowercase letters** (a...z) and **194 umlaut characters**.

Advantages of B256U Encoding
----------------------------
* **it's short**: 128 bit data are represented by 16 characters only, 256 bit data require 32 characters only
* **it's safe**: people are forced to copy & paste it 
* **it's easy to implement**: see the [source code](base256.cpp)
* **it's easy to recognize**: lots of umlauts (see the samples below)
* **it supports double-click** for copy & paste (no terminal characters in B256U) 
* **it's backward compatible**: B256U uses Unicode 1.0 only (highest code point used is 385)

Installation & Compilation
--------------------------
```
> git clone https://github.com/fleschutz/base256unicode
> cd base256unicode
> cmake .
> make
> ./base256
```

Samples of pseudo-random 128 bits encoded in B256U
--------------------------------------------------
* `ĺËĀ8Ę3ĩŔá0VzœĹŀî`
* `ŽTĭŊõł3ÐÑęGųĢÛąĶ`
* `5iŗ3īÛźUKĺŰÑÞbŒŜ`
* `ņĨqvLŀŠsůØŸÙGCŰƀ`

Samples of pseudo-random 256 bits encoded in B256U
--------------------------------------------------
* `ħŅŹĬšÝŋţĀĸĻňőċqâĮŹúŪßWPŞÓā8æťÁüċ`
* `Ě2ħŤRŧáÃĆĶ2ÕŀSŜöĄPŞÜbŰ06lŔùö9ĬŒģ`
* `āLë2lÏäöĥųŧpğĨķŇHĺ4LăsŸđĵ_űLeYhĩ`
* `ÂŚÔJàįŶļcvàPĈčĲċĉĲĂūęŻÉĢJĸķ3ğPĭŠ`

Feedback
--------
Send your email feedback to: markus.fleschutz [at] gmail.com

License & Copyright
-------------------
This open source project is licensed under the CC0 license. All trademarks are the property of their respective owners.
