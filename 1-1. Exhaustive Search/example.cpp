// List a binary chain created from n numbers  

#include <bits/stdc++.h>
std::string num = "000";

int length = num.length(); 

class Solution
{
public:
    void displayArr(std::vector<int> &);
    void convertIntToArray(std::string&, std::vector<int> &);
    void listBinaryChain(int, std::vector<int> &);
};

void Solution::displayArr(std::vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
    }
    std::cout << " ------" << std::endl;
}

void Solution::convertIntToArray(std::string& num, std::vector<int> &arr)
{
    int numb = std::stoi(num);
    for (int i = 0; i < length; i++)
    {
        arr[length - i - 1] = numb % 10;
        numb = numb / 10;
    }

    displayArr(arr);
}

void Solution::listBinaryChain(int i, std::vector<int> &_arr){
    i = length - 1;
    while ((i >= 0) && (_arr[i] == 1)){
        --i;
    }

    if (i >= 0)
    {
        _arr[i] = 1;

        for (int j = i + 1; j <= length; ++j)
            _arr[j] = 0;
        
        displayArr(_arr);
        listBinaryChain(i, _arr);
    }


}

int main()
{

    int i = length - 1;
    std::vector<int> _arr(length);
    Solution sol;
    sol.convertIntToArray(num, _arr);
    sol.displayArr(_arr);
    sol.listBinaryChain(i, _arr);
    return 0;
}
