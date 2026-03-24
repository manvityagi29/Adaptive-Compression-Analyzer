#include <string>
using namespace std;
int CalculateFixedSize(const string &input)
{
    int length=input.length();
    int BitsPerCharacter = 8;
    int totalSize = length*BitsPerCharacter;
    return totalSize;
}