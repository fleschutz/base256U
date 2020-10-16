Base 256 Encoding using Unicode (B256U)
=======================================

This is a simple C++ sample to represent binary data in B256U encoding. Typical use cases for B256U encodings are passwords, file checksums, identifiers and hashes.

Advantages of B256U
-------------------
* it's **short**: 128 bit require 16 characters only, 256 bit require 32 characters only
* it's **simple** to grasp: one byte is represented by one Unicode character
* it's **safe**: people are forced to copy&paste it 
* it's **easy to implement**: see the source code
* it **supports double-click** for copy&paste (no terminal characters in B256U) 
* it **backwards compatible**: B256U uses Unicode 1.0 only (highest code point used is 385)

Samples of 128 bit in B256U encoding
------------------------------------
* `<ĺËĀ8Ę3ĩŔá0VzœĹŀî>`
* `<ŽTĭŊõł3ÐÑęGųĢÛąĶ>`
* `<5iŗ3īÛźUKĺŰÑÞbŒŜ>`
* `<ņĨqvLŀŠsůØŸÙGCŰƀ>`

Samples of 256 bit in B256U encoding
------------------------------------
* `<ħŅŹĬšÝŋţĀĸĻňőċqâĮŹúŪßWPŞÓā8æťÁüċ>`
* `<Ě2ħŤRŧáÃĆĶ2ÕŀSŜöĄPŞÜbŰ06lŔùö9ĬŒģ>`
* `<āLë2lÏäöĥųŧpğĨķŇHĺ4LăsŸđĵ_űLeYhĩ>`
* `<ÂŚÔJàįŶļcvàPĈčĲċĉĲĂūęŻÉĢJĸķ3ğPĭŠ>`
