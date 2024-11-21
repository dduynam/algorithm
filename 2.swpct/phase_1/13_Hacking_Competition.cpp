#include <bits/stdc++.h>

using namespace std;

string C, S;

int main()
{
    cin >> C >> S;
    long long idx = C.size();
    for (long long i = 0; i < S.size(); i++)
    {
        if (S[i] == 'L' && idx > 0)
        {
            idx--;
        }
        else if (S[i] == 'R' && idx < C.size())
        {
            idx++;
        }
        else if (S[i] == 'B' && idx > 0)
        {
            C.erase(idx - 1, 1);
            idx--;
        }
        else if (S[i] >= 'a' && S[i] <= 'z')
        {
            C.insert(C.begin() + idx, S[i]);
            idx++;
        }
    }

    cout << C << endl;
    return 0;
}
