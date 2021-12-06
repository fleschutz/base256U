Base 256 Unicode (B256U) Encoding
=================================
This repository contains a simple C++ sample program to represent binary data in B256U encoding. Typical use cases for B256U encodings are passwords, file checksums, identifiers and hashes.

What is B256U Encoding?
-----------------------
Each byte is represented by one Unicode character - dead simple (and each Unicode character represents one byte). The 256 possible Unicode characters consist of:
* 10 digits (0...9)
* 26 uppercase letters (A...Z)
* 26 lowercase letters (a...z)
* 194 umlaut characters

Advantages of B256U Encoding
----------------------------
* **it's short**: 128 bit data are represented by 16 characters only, 256 bit data require 32 characters only
* **it's safe**: people are forced to copy & paste it 
* **it's easy to implement**: see the [source code](base256.cpp)
* **it's easy to recognize**: lots of umlauts (see the samples below)
* **it supports double-click** for copy & paste (no terminal characters in B256U) 
* **it's backward compatible**: B256U uses Unicode 1.0 only (highest code point used is 385)

Samples of 128 bit in B256U encoding
------------------------------------
* `ĺËĀ8Ę3ĩŔá0VzœĹŀî`
* `ŽTĭŊõł3ÐÑęGųĢÛąĶ`
* `5iŗ3īÛźUKĺŰÑÞbŒŜ`
* `ņĨqvLŀŠsůØŸÙGCŰƀ`

Samples of 256 bit in B256U encoding
------------------------------------
* `ħŅŹĬšÝŋţĀĸĻňőċqâĮŹúŪßWPŞÓā8æťÁüċ`
* `Ě2ħŤRŧáÃĆĶ2ÕŀSŜöĄPŞÜbŰ06lŔùö9ĬŒģ`
* `āLë2lÏäöĥųŧpğĨķŇHĺ4LăsŸđĵ_űLeYhĩ`
* `ÂŚÔJàįŶļcvàPĈčĲċĉĲĂūęŻÉĢJĸķ3ğPĭŠ`
