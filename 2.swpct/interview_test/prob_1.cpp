#include <bits/stdc++.h>

using namespace std;

vector<int> inp = {-2, 0, 1, 1};

void display(vector<int> ret)
{
    cout << "Value of array(" << ret.size() << "): ";
    for (auto x : ret)
        cout << x << " ";
    cout << endl;
}

void permutation (int idx, int sum, vector<int> ret)
{
    if (idx == inp.size())
        return;

    for (int i = 0; i <= 1; i++)
    {
        if (i == 1)
        {
            ret.push_back(inp[idx]);
            if (sum + inp[idx] == 0)
            {
                display(ret);
            }
            permutation(idx+1, sum+inp[idx], ret);
            ret.pop_back();
        }
        else
            permutation(idx+1, sum, ret);
    }
}

int main()
{  
    int idx = 0;
    int sum = 0;
    vector <int> ret;
    permutation(idx, sum, ret);
}