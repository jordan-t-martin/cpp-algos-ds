// this is incomplete
// Checks if there is an anagram of the pattern inside of the text provided.
#include <iostream>
#include <string.h>
#define MAX 256

using namespace std;

// Are the two character arrays the same?
bool compare (char arr1[], char arr2[])
{
    for(int i = 0; i < MAX; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

// 
void anagram (char* pattern, char* text)
{
    int patternLen = strLen(pattern), textLen = strlen(text);
    char freqPattern [MAX] = {0}, freqWindow = [MAX] = {0}; // 256 Charachters for each array?
    for(int i = 0; i < patternLen; i++)
    {
        freqPat[(int)pattern[i]]++; // +1 for the int number for that character
        freqWindow[(int)pattern[i]]++;
    }

    for(int i = patternLen; i < textLen; i++)
    {
        if(compare(freqPattern, freqWindow))
            cout << "Found at index: " << (i - patternLen) << endl;

        freqWindow[(int)text[i]]++;
        frewWindow[(int)text[i-patternLen]]--;
    }

    if(compare(freqPattern, freqWindow))
        cout << "Found at Index: " << (textLen - patternLen) << endl;
}

int main()
{
    char str1[] = "dep", str2[] = "encyclopedia";
    anagram(str1, str2);
    return 0;
}