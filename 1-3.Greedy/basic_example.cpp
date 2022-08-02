#include <bits/stdc++.h>

// To change of an amount using the smallest posible numbers of coins

int value[] = {5,2,1};
int size = sizeof(value)/sizeof(value[0]);

void changeGreedyBased(int cash)
{
    // Step 1 - Empty solution set
    std::vector<int> ans;

    for (int i = 0; i < size; i++)
    {
        // Step 2 - Examine the feasibility
        while(cash>=value[i])
        {
            // Step 3 - Save the local optiomal option 
            ans.push_back(value[i]);
            cash -= value[i];    
        }

        // Step 4 - Ignore the unsastisfied item
    }

    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
}

int main () {
    changeGreedyBased(18);
    return 0;
}