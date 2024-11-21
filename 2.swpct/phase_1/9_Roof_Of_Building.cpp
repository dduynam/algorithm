#include <bits/stdc++.h>
using namespace std;

int N;//Number of buildings
vector <int> H;//Height of buildings
vector <int> blocked;
vector <int> seen;
long long ans = 0;

void Input_Data(void){
	cin >> N;
    H.resize(N+1);
	for (int i = 0; i < N; i++)
		cin >> H[i];
}

void Solve()
{
    H[N] = INT_MAX;
    blocked.resize(N, 0);
    seen.resize(N, 0); 
    for (int i = N-1; i >= 0; i--)
    {
        int idx = i + 1;
        while (H[i] > H[idx])
        {
            seen[i] += 1 + seen[idx];
            idx = blocked[idx];
        }
        blocked[i] = idx;
    }

    for (auto &&x : seen)
        ans += x;
}

int main(){
	Input_Data();		//	Input function
    Solve();
	cout << ans << endl;	//	Output right answer
	return 0;
}
