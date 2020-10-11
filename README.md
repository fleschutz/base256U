Base 256 Encoding using Unicode (B256U)
=======================================

This is a simple C++ sample to represent binary data in B256U encoding. Typical use cases for B256U encodings are passwords, file checksums, identifiers and hashes.

Advantages of B256U
-------------------
* it's short: 128 bit require 16 characters only, 256 bit require 32 characters only
* it's safe: people are forced to copy&paste it 
* it's simple: one byte is represented by one Unicode character
* it's fast and easy to implement: see the source code
* it supports double-click for copy&paste (no terminal characters in B256U) 
* it simply works: B256U uses Unicode 1.0 only (highest code point used is 333)

Samples of 128 bit in B256U encoding
------------------------------------
* à°J¥ÜņĉĺŠrgġ6¯ēñ
* 4ðaŜTīċQÐĶĎagÅw¡
* sTÊłÓÀÇ6Ĝ¦ĪĜt£ăd
* ©UªåĕÏëńōĝ®0ÛJ5Ü

Samples of 256 bit in B256U encoding
------------------------------------
* XéĚK5Ĥù7ăÈËŞĆfŚcŚ«ĭüvĀª´¶ŀŔİYX®¥
* 6öĮ¢ùCŉŖŝĂęWİąŢözôìOµñäĤ8ÕØĘFĩÂM
* 2ũĈĻĆÝăġËĶĕÉöĽĆŝ1Ń6őuuĄËĜĺŪĖÉďĺË
* ñeħvĀČq«ßÉćĴöĒĤxéĜŒĤChFĥÚbĀŉĉŤfa
