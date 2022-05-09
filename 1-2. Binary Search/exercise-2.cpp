/* This solution for "https://www.spoj.com/problems/ABCDEF/" */

#include <bits/stdc++.h> 

const std::string input = "input.txt";
const std::string output = "output.txt";

class Solution {
public:
    int abcdef_bruteforce(std::vector<int> &_arr)
    {
        int size = _arr.size();
        int ret = 0;
        for (int a = 0; a < size; a++)
        {
            for (int b = 0; b < size; b++)
            {
                for (int c = 0; c < size; c++)
                {
                    for (int d = 0; d < size; d++)
                    {
                        if (!_arr[d])
                            continue;
                        for (int e = 0; e < size; e++)
                        {
                            for (int f = 0; f < size; f++)
                            {
                                long long s = (_arr[a]*_arr[b]+_arr[c])/_arr[d] - _arr[e]; 
                                if (s == _arr[f])
                                    ret++;
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }

        return ret;
        
    }

    int abcdef_binarySearch(std::vector<int> &_arr){
        // Decrease search scope a*b+c  = (f+e)*d 
        int size = _arr.size();
        std::vector<int> leftArray; 
        std::vector<int> rightArray;
        for (int i = 0; i < size; i++) {
            for (int i1 = 0; i1 < size; i1++) {
                for (int i2 = 0; i2 < size; i2++)
                {
                    leftArray.push_back(_arr[i]*_arr[i1] + _arr[i2]);
                    if (_arr[i2] != 0)
                        rightArray.push_back((_arr[i]+_arr[i1])*_arr[i2]);
                }
            }
        }
        
        // sort --> number of appearance of any number is the last position - 1st position + 1
        std::sort(leftArray.begin(), leftArray.end());
        std::sort(rightArray.begin(), rightArray.begin());
        int ans = 0; 

        // Examine based on the size of leftArray (because in every cases, leftArray size is always higher than rightArray)
        for (size_t i = 0; i < leftArray.size(); i++)
        {
            auto lo = std::lower_bound(rightArray.begin(), rightArray.end(), leftArray[i]); // 1st position appearing
            auto hi = std::upper_bound(rightArray.begin(), rightArray.end(), leftArray[i]); // last position appearing
            ans += hi-lo+1;
        }
        
        return ans;
    }
};

int main(){
    Solution sol;

    std::ifstream infile; 
    infile.open(input);
    if (!infile){
        std::cout << "Unable to open this file " << input << std::endl;
        exit(-1);
    }

    int N; 

    infile >> N; 

    std::vector<int> arr(N, 0);

    for (int i = 0; i < N; i++)
    {
        infile >> arr[i]; 
    }
    
    for (auto i : arr)
        std::cout << i << " "; 
    
    std::cout << std::endl;

    std::cout << "Result:" << sol.abcdef_bruteforce(arr) << std::endl;

    std::cout << "Just a test" << std::endl;

    std::vector<int> test = {1,2,1,2};
    std::sort(test.begin(), test.end());
    auto lo = std::lower_bound(test.begin(), test.end(), 1);
    auto hi = std::upper_bound(test.begin(), test.end(), 1);
    
    std::cout << hi-lo << std::endl;


    return 0;
}
