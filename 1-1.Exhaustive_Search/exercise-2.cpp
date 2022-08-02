/*  Longest Palindromic Substring
    A palindrome string is a string where both forward and reverse 
    are the same, for example: “aba” , “tnt”

    Find the longest palindrome string inside a given string  
*/

#include <bits/stdc++.h>

class Solution {
    public:
        std::string longestPalindrome(std::string);
};

std::string Solution::longestPalindrome(std::string s){
    int maxIndex = s.length() - 1;
    int halfLength = 0;
    std::string palindrome = s.substr(0,1);

    // for odd length string
    for (int i = 0; i < maxIndex; i++)
    {
        int j;
        // extend palindrome to left and right
        for (j = 0; j <= std::min(i, maxIndex - i); j++){
            if (s[i-j] != s[i+j]) break;
        }

        if (j - 1 > halfLength){
            halfLength = j - 1;
            palindrome = s.substr(i - halfLength, i + halfLength + 1);
        }

        // skip if maxIndex - 1 < current halfLength
        if (maxIndex - i < halfLength) break;
    }

    // for even length string
    for (int i = 0; i < maxIndex; i++)
    {
        int j; 
        // extend palindrome to left and right
        for (j = 0; j <= std::min(i, maxIndex - i - 1); j++)
        {
            if (s[i-j] != s[i+j+1]) break;
        }

        if (j - 1 >= halfLength){
            halfLength = j - 1;
            palindrome = s.substr(i - halfLength, i + halfLength + 2);
        }
        
        // skip if maxIndex - i < current halfLength
        if (maxIndex - i < halfLength) break;
    }
    
    return palindrome;
}

int main(){
    std::string s = "asvsr"; //"asndadsdasds";
    std::string ret = ""; 

    Solution sol; 
    std::cout << sol.longestPalindrome(s);

    return 0;
}