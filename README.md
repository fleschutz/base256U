Base 256 Encoding using Unicode (B256U)
=======================================

This is a simple C++ sample to represent binary data in B256U. Typical use cases for B256U are passwords, file checksums, identifiers and hashes.

Advantages of B256U
-------------------
* it's short: 128 bit require 16 characters only, 256 bit require 32 characters only
* it's safe: people are forced to copy&paste it 
* it's simple: one byte is represented by one Unicode character
* it's fast and easy to implement: see the source code
* it supports double-click for copy&paste (no terminal characters in B256U) 
* it simply works: B256U uses Unicode 1.0 only (highest code point used is 333)

128 bit Samples in B256U
------------------------
* ġ7¢K#ĈÝ¢ØĵOĦQ®ðğ
* ¬üYęÎpMľ6Mĺ±Ùìň9
* $ÀňåıAęü'p»äńYĘĝ
* ¶»Ń'ÊKêuĉ_àj÷òa4

256 bit Samples in B256U
------------------------
* ,ÈEÂ³'ċ`ÝÂđħÁ¶~/üċ]JyãÊu£ùēOÜÑbĥ
* hwčĽ¶ĚB%đĘŌàú«n³tyÉdÝİ§ÿ9Ô°ķ«ĤBÞ
* Cł[&¢ņÐôĽąë4pçI(ĜÂÁAČćģŋêzüÄáĢAí
