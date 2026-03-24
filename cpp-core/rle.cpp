#include <iostream>
#include <string>

using namespace std;
struct RLEResult 
{
    string encoded;
    int totalBits;
};
RLEResult RunLengthEncode(string input) 
{
    string encoded = "";
    int totalBits = 0;
    
    int n = input.length();

    for (int i = 0; i < n; i++) 
    {
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) 
        {
            count++;
            i++;
        }
        encoded += input[i];
        encoded += to_string(count);
        totalBits += 16;
    }
    RLEResult result;
    result.encoded = encoded;
    result.totalBits = totalBits;
    return result;
}