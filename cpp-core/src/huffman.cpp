#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
int HuffmanEncoding(string input)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        freq[ch] = freq[ch] + 1;
    }
    priority_queue<int, vector<int>, greater<int> > heap;
    unordered_map<char, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        heap.push(it->second);
    }
    int totalBits = 0;
    while (heap.size() > 1)
    {
        int first = heap.top();
        heap.pop();
        int second = heap.top();
        heap.pop();
        int sum = first + second;
        totalBits = totalBits + sum;
        heap.push(sum);
    }
    return totalBits;
}