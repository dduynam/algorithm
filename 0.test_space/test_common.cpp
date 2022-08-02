#include <bits/stdc++.h>

// All denominations of Indian Currency
int deno[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
int n = sizeof(deno) / sizeof(deno[0]);

void greedy (std::vector<int> &ans, int v)
{
    for (int i = n-1; i >= 0; i--)
    {
        while (v >= deno[i])
        {
            ans.push_back(deno[i]);
            v -= deno[i];
        }
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    
}

int main() {

    std::vector<int> ans;
    greedy(ans, 70);

    return 0;
}