#include <iostream>
#include <fstream>   // for file reading
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
    int choice;
    string filename;
    string input;
    cout << "Choose Sample File:\n";
    cout << "1. Repetitive Data\n";
    cout << "2. Random Data\n";
    cout << "3. Skewed Data\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
        filename = "../samples/repetitive.txt";
    else if (choice == 2)
        filename = "../samples/random.txt";
    else
        filename = "../samples/skewed.txt";

    ifstream file(filename);

    if (!file)
    {
        cout << "Error: Cannot open file!\n";
        return 1;
    }

    file >> input;
    cout << "\nInput Read From File: " << input << endl;

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

    return 0;
}
