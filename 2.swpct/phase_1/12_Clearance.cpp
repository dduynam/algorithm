#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> inp;
vector<vector<int>> mp;
vector<long long> sz;
vector<long long> num;
typedef pair<int, int> ii;
long long ans = 0;

auto comparator = [](const ii &a, const ii &b)
{
    return (a.second == b.second) ? num[a.first] < num[b.first] : a.second > b.second;
};

void Input()
{
    cin >> N >> M;
    mp.resize(M+1);
    sz.resize(M+1, 0);
    num.resize(M+1, 0);	
    inp.resize(N);
    cin >> inp[0];
    int pre = inp[0];
    int count = 1;

    for (int i = 1; i < N; i++)
    {
        cin >> inp[i];
        if (inp[i] == pre)
        {
            count++;
        }
        else
        {
            mp[pre].push_back(count);
            sz[pre]++;
						num[pre] += count;
            pre = inp[i];
            count = 1;
        }

        if (i == N-1)
        {
            mp[pre].push_back(count);
						num[pre] += count;
            sz[pre]++;
        }
    }

    // for (int i = 1; i <= M; i++)
    // {
    //     cout << i << ": ";
    //     for (auto &x : mp[i])
    //         cout << x << " ";
    //     cout << endl;
    // }
    priority_queue<ii, vector<ii>, decltype(comparator)> pq(comparator);
    
    for (int i = 1; i <= M; i++)
    {
        //cout << i << ": " << sz[i] << endl;
        pq.push({i, sz[i]});
    }

    while (!pq.empty()) {
        // cout << pq.top().first << ": " << pq.top().second;
        // pq.pop();
        // cout << endl;
        if (pq.size() == 1)
        {
            pq.pop();
            continue;
        }

        int x = pq.top().first;
        int sizeX = pq.top().second;
        pq.pop();
        priority_queue<int, vector<int>, greater<int>> _pq;
        for (int i = 0; i < sizeX; i++)
        {
            _pq.push(mp[x][i]);
        }
        while(_pq.size() != 1)
        {
            ans += _pq.top()*2;
            //cout << _pq.top() << endl;
            _pq.pop();
        }        
    }

    cout << ans;

}

void Solve()
{

}

int main() {
    freopen("input", "r", stdin);
    Input();
    Solve();
	return 0;
}


// 1 4 => 2
// 1 1 => 2 
// 1 1
// 1 1 1 1 3 2 3 2 1 

// 1 1 1 1 1 2 3 2 3  2

// 1 1 1 1 1 2 2 3 3  4 
	
// 1 4 => 2
// 1 1 1 => 
// 1 1 => 2
	
// 1 1 1 1 3 2 3 2 1 3

// 1 1 1 1 1 2 3 2 3 3
	
// 1 1 1 1 1 2 2 3 3 3
	