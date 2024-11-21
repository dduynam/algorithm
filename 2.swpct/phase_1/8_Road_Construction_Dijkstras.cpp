#include <bits/stdc++.h>
using namespace std;

int N;//Map Size
vector <vector<int>> mp;//Map information
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
typedef pair<int, pair<int, int>> ii;

void Input_Data(){
	cin >> N;
    mp.resize(N);
	for (int i = 0; i < N; i++){
        mp[i].resize(N);
        string val;
        cin >> val;
        for (int j = 0; j < N; j++)
        {
            mp[i][j] = val[j] - '0';
        }
	}
}

void Solve()
{
    priority_queue <ii, vector<ii>,  greater<ii>> pq;
    vector <vector<bool>> visited(N, vector<bool> (N, 0));
    vector <vector<int>> dist(N, vector<int> (N, INT_MAX));
    dist[0][0] = 0;
    pq.push({dist[0][0], {0,0}});

    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int dxy = pq.top().first;
        visited[x][y] = true;
        pq.pop();

        for (int i = 0; i <= 3; i++)
        {
            int _x = x + dx[i];
            int _y = y + dy[i];

            if (_x < 0 || _x >= N) continue;
            if (_y < 0 || _y >= N) continue;

            if (!visited[_x][_y] && dist[_x][_y] > dist[x][y] + mp[_x][_y])
            {
                dist[_x][_y] = dist[x][y] + mp[_x][_y];
                pq.push({dist[_x][_y], {_x, _y}});
            }    
        }
    }

    cout << dist[N-1][N-1] << endl;
}

int main(){
	int ans = -1;
	Input_Data();		//	Input function
    Solve();
	return 0;
}
