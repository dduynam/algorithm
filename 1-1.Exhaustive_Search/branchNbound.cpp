/* BESTCONFIG --> Branch and Bound */

#include <bits/stdc++.h>

class Solution
{

public:
    void init_original()
    {
        /* Initialize a random BEST_CONFIG */
    }
    void try_original(int i, int k)
    {
        std::vector<int> arr(10, 0);
        std::vector<int> ret(10, 0);
        std::vector<bool> mark(10, 0);
        for (auto v : arr)
        {
            ret[i] = v;

            if (1 /* condition */)
            { // expectation with finding out the configuration better BEST_CONFIG

                if (i == k)
                {
                    /* update BEST_CONFIG */
                }
                else
                {
                    mark[v] = true; // Remember ret[i] receiving value v if need
                    try_original(i + 1, k);
                    mark[v] = false; // Unmark
                }
            }
        }
    }
};

int main()
{
    std::cout << "Branch n Bound" << std::endl;
    return 0;
}