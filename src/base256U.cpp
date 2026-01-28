#include <string>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <time.h>
using namespace std;
typedef uint32_t Unicode;

Unicode alphabet[256] =
{
'0','1','2','3','4','5','6','7','8','9',                          // 10 digits
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',  // 26 uppercase letters
'Q','R','S','T','U','V','W','X','Y','Z',
'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',  // 26 lowercase letters
'q','r','s','t','u','v','w','x','y','z',
192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,  // 194 accent letters
208,209,210,211,212,213,214,216,217,218,219,220,221,222,223,224,
225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,
241,242,243,244,245,246,248,249,250,251,252,253,254,255,256,257,
258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,
274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,
290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,
306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,
322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,
338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,
354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,
370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,
386,387 // NOTE: × (=215) and ÷ (=247) have been skipped: both are math operators, not letters
}; 

string encodeToBase256U(const uint8_t *dataPtr, size_t dataSize)
{
	string result = {};
	for (size_t i = 0; i < dataSize; i++)
	{	
		Unicode character = alphabet[dataPtr[i]];
		if (character >= 128)
		{
			result.push_back(192 + (character >> 6));
			result.push_back(128 + (character & 63));
		}
		else
			result.push_back(character);
	}
	return result;
}

void decodeFromBase256U(const string& string, uint8_t *dataPtr)
{
	for (size_t i = 0; i < string.size(); i++)
	{
		Unicode unicode = (unsigned char)string[i];
		if (unicode >= 128)
			unicode = (unicode - 192) << 6 | ((unsigned char)string[++i] - 128) & 63;
		for (unsigned int j = 0; j < 256; j++)
		{
			if (unicode == alphabet[j])
			{
				*dataPtr++ = (uint8_t)j;
				break;
			}
		}
	}
}

void generateRandomData(uint8_t *dataPtr, size_t dataSize)
{
	for (size_t i = 0; i < dataSize; i++)
		dataPtr[i] ^= rand();
}

int main(int argc, char *argv[])
{
	// shuffle a good random seed
	unsigned int seed = rand() + (unsigned int)strlen(argv[0]) * (unsigned int)time(nullptr) ^ rand();
	srand(seed);

	cout << endl;
	cout << "Choose Your Safe Password       (random 128 bits in base256U encoding, use double-click to copy & paste)" << endl;
	cout << "-------------------------" << endl;
	
	for (int i = 0; i < 120; i++)
	{
		uint8_t binaryData[128 / 8];
		generateRandomData(binaryData, sizeof(binaryData));

		// encode and print it:
		string text = encodeToBase256U(binaryData, sizeof(binaryData));
		cout << "[" << text << "]\t ";

		// decode and check it:
		uint8_t decodedData[sizeof(binaryData)] = {};
		decodeFromBase256U(text, decodedData);
		if (memcmp(binaryData, decodedData, sizeof(binaryData)) != 0)
			return 1; // check failed
	}
	return 0;
}

