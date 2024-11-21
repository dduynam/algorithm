#include <bits/stdc++.h>

using namespace std;

int N, M;
unordered_map <string, pair<int, int>> mp;
typedef pair<string, pair<int, int>> ii;
auto comparator = [](const ii& a, const ii& b)
{
    return a.second.first == b.second.first ? a.second.second > b.second.second : a.second.first < b.second.first;
};
priority_queue<ii, vector<ii>, decltype(comparator)> pq(comparator);

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        mp[name].first = i;
        mp[name].second = 0;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string name;
        int score;
        cin >> name >> score;
        if (mp.find(name) != mp.end())
            mp[name].second += score;
    }    
}

void Solve()
{
    for (auto &x : mp)
    {
        string name = x.first; 
        int score = x.second.second;
        int number = x.second.first;
        pq.push({name, {score, number}});
    }

    for (int i = 0; i < 3; i++)
    {
        cout << pq.top().first << " " << pq.top().second.first << endl;
        pq.pop();
    }
}

int main() {
    Input();
    Solve();
}