#include <bits/stdc++.h>
using namespace std;

int N, M;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector <vector<int>> mp;
queue <pair<int, int>> q;
queue <pair<int, int>> _q;
pair<int, int> start;

void Input()
{
    cin >> N >> M;
    mp.resize(N);
    for (int i = 0; i < N; i++)
    {   
        mp[i].resize(M);
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 1)
            {
                start.first = i;
                start.second = j;
            }
        }
    }

    // for (int i = 0; i < N; i++)
    // {   
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void bfs_1()
{
    q.push({start.first, start.second});
    _q.push({start.first, start.second});
    mp[start.first][start.second] = 2;
    vector <vector<bool>> visited(N, vector<bool> (M, 0));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;

        for (int i = 0; i <= 3; i++)
        {
            int _x = x + dx[i];
            int _y = y + dy[i];

            if (_x < 0 || _x >= N) continue;
            if (_y < 0 || _y >= M) continue;

            if (!visited[_x][_y] && mp[_x][_y] == 1)
            {
                q.push({_x, _y});
                _q.push({_x, _y});
                mp[_x][_y] = 2;
            }
        }
    }
}

void bfs_2()
{
    vector <vector<bool>> visited(N, vector<bool> (M, 0));

    while (!_q.empty())
    {
        int x = _q.front().first;
        int y = _q.front().second;
        _q.pop();
        visited[x][y] = true;

        for (int i = 0; i <= 3; i++)
        {
            int _x = x + dx[i];
            int _y = y + dy[i];

            if (_x < 0 || _x >= N) continue;
            if (_y < 0 || _y >= M) continue;

            if (mp[_x][_y] == 1)
            {
                cout << mp[x][y] - 2 << endl;
                return;
            }

            if (!visited[_x][_y] && mp[_x][_y] == 0)
            {
                _q.push({_x, _y});
                mp[_x][_y] = mp[x][y] + 1;
            }
        }
    }
}

void Solve()
{
    bfs_1();
    bfs_2();
}

int main() {
    Input();
    Solve();
	return 0;
}