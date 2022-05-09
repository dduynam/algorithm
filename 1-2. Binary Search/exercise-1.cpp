#include <bits/stdc++.h>

int arr[] = {1, 3, 4, 5, 6, 7};

int solution(int* arr, int num, int length){
    int ret = 1;
    int start = 0, end = length - 1;
    std::cout << start << " " << end << std::endl;

    if (num < arr[start]) return start;
    if (num > arr[end]) return end+1; 

    while (start <= end){
        int mid = (start + end)/2;
        if (arr[mid] > num)
            end = mid - 1;
        else if (arr[mid] < num)
            start = mid + 1;
        else {
            std::cout << "number is found" << std::endl; 
            return mid;
        }
        std::cout << start << " " << end << std::endl;
    }

    std::cout << "number is not found" << std::endl;
    return end+1;
}

int main(){
    int length = sizeof(arr)/sizeof(int);
    std::cout << solution(arr, 2, length) << std::endl;    
    return 0;
}