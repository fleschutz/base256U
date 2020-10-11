Base 256 Encoding using Unicode (B256U)
=======================================

This is a simple C++ sample to represent binary data in B256U. Typical use cases for B256U are passwords, file checksums, identifiers and hashes.

Advantages of B256U
-------------------
* It's short: 128 bit require 16 characters only, 256 bit require 32 characters only
* It's safe: people are forced to copy&paste it 
* It's simple: one byte is represented by one Unicode character 
* It works: B256U uses Unicode 1.0 only (highest used code point is 333)
