#include <string>
#include <iostream>
using namespace std;

static string base256alphabet[256] =
{
"0","1","2","3","4","5","6","7","8","9", // digits
"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z", // uppercase
"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z", // lowercase
"!","#","$","%","&","(",")","*","+","-","/","<","=",">","?","@","[","]","\\","_",			 // misc
"§","\u00A9","\u00AE","\u00B6","\u00F7",
"à","á","â","ã","ä","å","ā","ă" // variations of a
"ć","ĉ","ċ","č",
"è","é","ê","ë","ē","ĕ","ė","ę","ě", // variations of e
"ĝ","ğ","ġ","ģ",
"ì","í","î","ï","ĩ","ī","ĭ","į","ı", // variations of i
"ð","ò","ó","ô","õ","ö", // variations of o
"ń","ņ","ň", // variations of n
"ù","ú","û","ü", // variations of u
"ý","ÿ", // variations of y
u8"Γ",u8"Δ",u8"Θ",u8"Λ",u8"Ξ",u8"Π",u8"Σ",u8"Φ",u8"Ψ",u8"Ω",u8"α",u8"β",u8"ε",u8"λ",u8"μ",u8"π",u8"ω", // greek letters


"\u00BC","\u00BD","\u00BE","\u2150","\u2151","\u2152","\u2153","\u2154","\u2155","\u2156","\u2157",
	"\u2158","\u2159","\u215A","\u215B","\u215C","\u215D","\u215E", // fractions
"\u2600","\u2601","\u2602","\u2603","\u26A1",//weather
"\u2669","\u266A","\u266B","\u266C","\u266D","\u266E","\u266F", // music
"\u2648","\u2649","\u264A","\u264B","\u264C","\u264D","\u264E","\u264F","\u2650","\u2651","\u2652","\u2653",// star sign

"0","1","2","3","4","5","6","7","8","9",
"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",

};

string base256encode(unsigned char *dataPtr, size_t dataSize)
{
	string result = {};
	for (size_t i = 0; i < dataSize; i++)
		result += base256alphabet[dataPtr[i]];
	return result;
}

int main(int argc, char *argv[])
{
	unsigned char binaryData[128 / 8] = {};

	srand(time(nullptr));
	for (int i = 0; i < sizeof(binaryData); i++)
		binaryData[i] = rand();

	string result = base256encode(binaryData, sizeof(binaryData));
	cout << "random 128 bit encoded in base256: " << result << endl;
	return 0;
}
