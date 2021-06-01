#include <string>
#include <cstring>
#include <iostream>
#include <time.h>
using namespace std;
typedef uint32_t Unicode;

Unicode alphabetB256U[256] =
{
'0','1','2','3','4','5','6','7','8','9',								 // ASCII digits
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', // ASCII upper
'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', // ASCII lower
192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,					 // Latin 1
208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,					 // Umlauts ...
224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,
256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,
272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,
288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,
304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,
320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,
336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,
352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,
368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,
384,385
};

string encodeB256U(const uint8_t *dataPtr, size_t dataSize)
{
	string result = {};
	for (size_t i = 0; i < dataSize; i++)
	{	
		Unicode character = alphabetB256U[dataPtr[i]];
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

void decodeB256U(const string& string, uint8_t *dataPtr)
{
	for (size_t i = 0; i < string.size(); i++)
	{
		Unicode unicode = (unsigned char)string[i];
		if (unicode >= 128)
			unicode = (unicode - 192) << 6 | ((unsigned char)string[++i] - 128) & 63;
		for (unsigned int j = 0; j < 256; j++)
		{
			if (unicode == alphabetB256U[j])
			{
				*dataPtr++ = (uint8_t)j;
				break;
			}
		}
	}
}

void randomize(uint8_t *dataPtr, size_t dataSize)
{
	srand(time(nullptr));
	for (size_t i = 0; i < dataSize; i++)
		dataPtr[i] = rand();
}

int main(int argc, char *argv[])
{
	uint8_t binaryData[128 / 8] = {};
	randomize(binaryData, sizeof(binaryData));

	string text = encodeB256U(binaryData, sizeof(binaryData));
	cout << "pseudorandom 128 bits encoded in B256U are <" << text;

	uint8_t decodedData[sizeof(binaryData)] = {};
	decodeB256U(text, decodedData);

	if (memcmp(binaryData, decodedData, sizeof(binaryData)) == 0)
		cout << "> and decoding works!" << endl;
	return 0;
}
