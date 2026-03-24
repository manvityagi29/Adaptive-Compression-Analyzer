#include <iostream>
#include <string>

using namespace std;
int CalculateFixedSize(const string &input);
struct RLEResult
{
    string encoded;
    int totalBits;
};
RLEResult RunLengthEncode(string input);
int HuffmanEncoding(string input);
int main()
{
    string input;
    cout << "Enter text to analyze: ";
    cin >> input;
    int fixedBits = CalculateFixedSize(input);
    RLEResult rleResult = RunLengthEncode(input);
    int huffmanBits = HuffmanEncoding(input);
    cout << "\n===== Compression Results =====\n";
    cout << "Fixed Encoding Bits : " << fixedBits << endl;
    cout << "RLE Encoded Output  : " << rleResult.encoded << endl;
    cout << "RLE Bits Used       : " << rleResult.totalBits << endl;
    cout << "Huffman Bits Used   : " << huffmanBits << endl;

    int minBits = fixedBits;
    string bestAlgo = "Fixed Encoding";
    if (rleResult.totalBits < minBits)
    {
        minBits = rleResult.totalBits;
        bestAlgo = "Run Length Encoding (RLE)";
    }
    if (huffmanBits < minBits)
    {
        minBits = huffmanBits;
        bestAlgo = "Huffman Encoding";
    }
    cout << "\n>>> Best Algorithm: " << bestAlgo << endl;
    cout << ">>> Minimum Bits Used: " << minBits << endl;
}