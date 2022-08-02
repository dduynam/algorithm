#include <bits/stdc++.h>

std::vector<int> in{2,3,1,1,0,1};

bool bruteforce(std::vector<int> &in, int index)
{
    static bool ret = false;

    for (int i = 1; i <= in[index]; i++)
    {
        if (index + i < in.size()-1)
            bruteforce(in, index+i);
        /* else if (index + i > in.size()-1)
            continue;
        else
            ret = true; 

        >>> Because equal or greater than the last index will satify the requirement of this issue    
        */
        else
        {
            ret = true;
            break;
        }
    }
    
    return ret;
}

/* greedy 
1. Define a value max which is the furthest index that all elements from 0 to max can jump to. Set max to 0 initially
2. For each in[i], find the furthest element you can jump to which is i+in[i],. If it is greater than max, then set it as max.
3. Repeat until i == max or i == N-1


*/

bool greedy(std::vector<int> &in)
{
    bool ret = false;
    int size = in.size();
    int maxIdx = 0; // Highes index that we can jump to. Set it to 0 initially
    for (int i = 0; i < size; i++)
    {
        // If max is already equal to or greater than the last index, then return true. 
        if (maxIdx >= size-1)
        {
            ret = true;
            break;
        }

        // if i > max then we have already checked all elements from i to max
        if (i > maxIdx)
        {
            ret = false;
            break;
        }

        //Update value of max
        maxIdx = (i+in[i]) > maxIdx? i+in[i] : maxIdx;
    }

    return ret;
}

int main()
{
    std::cout << std::boolalpha << bruteforce(in, 0) << std::endl;
    return 0;
}