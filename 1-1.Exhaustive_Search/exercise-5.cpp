/* Solution for https://www.spoj.com/problems/BURGLARY/ */

#include <bits/stdc++.h>

const std::string input = "input.txt";
const std::string output = "output.txt";

class Solution{
public: 
    int burglary_original(std::vector<int> &_arr, int num, int flag, int _sum, int k, int *res){
        //static std::vector<int> ret; 

        int sum = _sum; 
        int ret = 0;
        int s = 1;
        int size = _arr.size();
        int count = 1; 

        for (int j = num; j < size; j++){
            if (sum + _arr[j] > k)
                continue;
            else if (sum + _arr[j] < k){
                count++;
                sum = sum + _arr[j];
                ret = burglary_original(_arr, ++j, -1, sum, k, res);
            }
            else {
                count++;
                ret++;            
            }
        }

        if (flag != -1 && num < size)
            ret = ret + burglary_original(_arr, ++num, flag, _arr[num], k, res);
        
        if (num = size){
            if (ret == 1)
                *res = count; 
            else if (ret > 1)
                *res = 1;
            else if (ret == 0)
                *res = 0;
        }
        return ret;
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

    std::ofstream outfile; 
    outfile.open(output);

    int lp = 0;

    infile >> lp;

    while (lp--){
    int num, k; 

    infile >> num >> k; 

    std::vector<int> arr(num, 0);
    for (int i = 0; i < num; i++)
    {
        infile >> arr[i];
    }
    
    for (auto i : arr)
        std::cout << i << " "; 

    std::cout << std::endl;
    std::cout << num << "------" << k << std::endl;

    int res = 0;
    std::cout << sol.burglary_original(arr, 1, 1, arr[0], k, &res) << " " << res << std::endl;

    
    if (res == 0)
        outfile << "IMPOSSIBLE" << std::endl;
    else if (res == 1) 
        outfile << "AMBIGIOUS" << std::endl;
    else
        outfile << res << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}