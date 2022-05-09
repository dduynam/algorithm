/* Solution is deployed as below for this issue "https://www.spoj.com/problems/REPROAD/" */

#include <bits/stdc++.h>

class IOhandler {
    const std::string input = "input.txt";
    const std::string output = "output.txt";

public:
    void Ihandler (){
        std::ifstream myfile;   
        myfile.open(input); 
        if (!myfile){
            std::cout << "Unable to open file";
            exit(1); 
        }

        int num, mark;

        myfile >> num >> mark; 

        std::vector<int> arr(num, 0);

        for (int i = 0; i < num; i++)
        {
            myfile >> arr[i]; 
        }

        for (auto i : arr){
            std::cout << i << " ";
        }

        std::cout << std::endl;
        std::cout << num << "_____" << mark << std::endl;

        myfile.close();
        Ohandler();
    }

    void Ohandler(){
        std::ofstream ret; 
        ret.open(output);
        ret << 10 << std::endl;
        ret.close();

    }

};

class Solution {
    public: 
        int repRoad(std::vector<int> _arr, int i, int k){
            int size = _arr.size();
            static int ret = 0;
            int max = 0;
            int cost = 0; 

            int temp = i;

            if (temp == size - 1)
                return _arr[temp]?std::max(1, ret): ret;

            for (temp; temp < size; temp++)
            { 
                if (_arr[temp] == 0)
                {
                    if (cost < k){
                        cost++;
                        max++;
                    }
                    else {
                        break;
                    }
                }
                else
                    max++;
            }
            ret = std::max(ret, max);
            
            return repRoad(_arr, ++i, k);
        }

        int repRoadUsingStack(std::vector<int> _arr, int k){
            int ans = -1; 
            std::list<int> q; 
            int len = 0; 
            int cost = 0; 
            int size = _arr.size();
            for (int i = 0; i < size; i++)
            {
                if (_arr[i] == 0){
                    if (cost < k){
                        cost++;
                        len++;
                    }
                    else {
                        len = i - q.front();
                        q.pop_front();
                    }
                    q.push_back(i);
                } else {
                    len++;
                }
                ans = std::max(ans, len);
            }
            return ans;
        }
};

int main(){
    Solution sol; 

    const std::string input = "input.txt";
    const std::string output = "output.txt";

    std::ifstream myfile;   
    myfile.open(input); 
    if (!myfile){
        std::cout << "Unable to open file";
        exit(1); 
    }

    int num, mark;

    myfile >> num >> mark; 

    std::vector<int> arr(num, 0);

    for (int i = 0; i < num; i++)
    {
        myfile >> arr[i]; 
    }

    for (auto i : arr){
        std::cout << i << " ";
    }

    std::cout << std::endl;
    std::cout << num << "___" << mark << std::endl;

    myfile.close();

    int ret = sol.repRoad(arr, 0, mark);

    std::ofstream outfile; 
    outfile.open(output);
    outfile << "Result: " << ret << std::endl;
    outfile.close();

    std::cout << "Result: ";
    std::cout << ret << std::endl;
    return 0;
}