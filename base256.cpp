#include <string>
#include <iostream>
using namespace std;

string base256alphabet[256] =
{
"0","1","2","3","4","5","6","7","8","9",								 // digits
"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z", // uppercase
"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z", // lowercase
"!","\"","#","$","%","&","'","(",")","*","+",",","-",".","/","<","=",">","?","@","[","\\","]","^","_",	 // misc
"`","{","|","}","~","\u00A1","\u00A2","\u00A3","\u00A4","\u00A5","§","\u00A9","\u00AA","\u00AB",
"\u00AC","\u00AE","\u00AF","\u00B0","\u00B1","\u00B2","\u00B3","\u00B4","\u00B5","\u00B6","\u00BB",
"\u00BF","\u00F7",
"À","Á","Â","Ã","Ä","Å","Æ",										 // A variations
"à","á","â","ã","ä","å","ā","ă","æ",									 // a variations
"ć","ĉ","ċ","č",											 // c variations
"è","é","ê","ë","ē","ĕ","ė","ę","ě",									 // o variations
"ĝ","ğ","ġ","ģ",											 // g variations
"ì","í","î","ï","ĩ","ī","ĭ","į","ı",									 // i variations
"ð","ò","ó","ô","õ","ö",										 // o variations
"ń","ņ","ň",												 // n variations
"ù","ú","û","ü",											 // u variations
"ý","ÿ",												 // y variations
u8"Γ",u8"Δ",u8"Θ",u8"Λ",u8"Ξ",u8"Π",u8"Σ",u8"Φ",u8"Ψ",u8"Ω",u8"α",u8"β",u8"ε",u8"λ",u8"μ",u8"π",u8"ω",	 // greek
"\u00BC","\u00BD","\u00BE","\u2150","\u2151","\u2152","\u2153","\u2154","\u2155","\u2156","\u2157",	 // fractions
	"\u2158","\u2159","\u215A","\u215B","\u215C","\u215D","\u215E",
"\u2600","\u2601","\u2602","\u2603","\u26A1",								 // weather
"\u2669","\u266A","\u266B","\u266C","\u266D","\u266E","\u266F",						 // music
"\u2648","\u2649","\u264A","\u264B","\u264C","\u264D","\u264E","\u264F","\u2650","\u2651","\u2652","\u2653",// star sign

"0","1","2","3","4","5","6","7","8","9",
"A","B","C","D","E","F","G","H","I","J","K","L","M",
};

string encodeInB256U(uint8_t *dataPtr, size_t dataSize)
{
	string result = {};
	for (size_t i = 0; i < dataSize; i++)
		result += base256alphabet[dataPtr[i]];
	return result;
}

int main(int argc, char *argv[])
{
	srand(time(nullptr));
	uint8_t binaryData[128 / 8] = {};
	for (int i = 0; i < sizeof(binaryData); i++)
		binaryData[i] = rand();

	cout << "random 128 bit encoded in B256U: " << encodeInB256U(binaryData, sizeof(binaryData)) << endl;
	return 0;
}
