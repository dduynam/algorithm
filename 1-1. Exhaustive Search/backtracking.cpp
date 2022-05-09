#include <bits/stdc++.h>

class Solution {
    public:
        void try_1(int, int); // List binary list with length at n
        void try_2(int, int, int); // List a sorted child list with k elements
        void try_3(int, int, int); // Chinh hop ko lap chap K phan tu
        void try_4(int, int); // Hoan vi: Chinh hop ko lap chap K phan tu voi k = n
        void print(std::vector<int> &);
    
};

void Solution::print(std::vector<int> &_arr){
    int size = _arr.size();
    for (int i = 1; i < size; i++)
    {
        std::cout << _arr[i];
    }
    std::cout << " ";
}

void Solution::try_1(int i, int length){
    static std::vector<int> arr(length, 0);

    for (int j = 0; j <= 1; j++)
    {
        arr[i-1] = j;
        if (i == length){
            print(arr);
        }
        else {
            try_1(i+1, length);
        }
    }
}

void Solution::try_2(int idx, int n, int length){
    static std::vector<int> arr(length+1, 0);

    for (int i = arr[idx-1]+1; i <= n-length+idx; i++){
        arr[idx] = i;

        if (idx == length){
            print(arr);
        }
        else
            try_2(idx+1, n, length);
    }
}

void Solution::try_3(int idx, int length, int k){
    static std::vector<bool> c(length+1, false);
    static std::vector<int> arr(k+1, 0);

    for (int i = 1; i < length+1; i++)
    {
        if (!c[i]){
            arr[idx] = i;
            if (idx == k)
                print(arr);
            else{
                c[i] = true; // Mark this number is used 
                try_3(idx+1, length, k);
                c[i] = false; // Free this number 
            }
        }
    }
}

void Solution::try_4(int idx, int length){
    static std::vector<bool> c(length+1, false);
    static std::vector<int> arr(length+1, 0);

    for (int i = 1; i < length+1; i++)
    {
        if (!c[i]){
            arr[idx] = i;
            if (idx == length)
                print(arr);
            else {
                c[i] = true;
                try_4(idx+1, length);
                c[i] = false;              
            }
        }
    }
}



int main(){
    Solution sol; 
    int n = 3;
    int arr[]= {1,3,4,2,4,5,5};

    //sol.try_1(1, 3);
    //sol.try_2(1, 9, 5);
    //sol.try_3(1, 9, 5);
    sol.try_4(1, 5);
    
    return 0;
}