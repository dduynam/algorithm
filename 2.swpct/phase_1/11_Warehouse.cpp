#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> warehouse;
vector<vector<int>> dist;
typedef pair<int, int> ii;
auto comparator = [](const ii &a, const ii &b)
{
    return a.first > b.first;
};

int N, M;

void Input()
{
    cin >> N >> M;

    warehouse.resize(N + 1);
    dist.resize(N + 1, vector<int>(N + 1, INT_MAX));
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        warehouse[a].push_back({b, c});
        warehouse[b].push_back({a, c});
        dist[a][b] = c;
        dist[b][a] = c;
    }
}

void djikstras(int start, int end)
{
    // priority_queue<ii, vector<ii>, decltype(comparator)> pq(comparator);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<bool> visited(N + 1, 0);
    pq.push({0, start});

    while (!pq.empty())
    {
        int dx = pq.top().first;
        int x = pq.top().second;

        pq.pop();
        visited[x] = true;

        if (x == end)
        {
            dist[end][start] = dx;
            return;
        }

        for (auto &it : warehouse[x])
        {
            int y = it.first;
            int dxy = it.second;
            if (!visited[y] && dist[start][y] >= dx + dxy)
            {

                dist[start][y] = dx + dxy;
                pq.push({dist[start][y], y});
            }
        }
    }
}

void Solve()
{
    for (int i = 1; i < N + 1; i++)
    {
        dist[i][i] = 0;
        for (int j = 1; j < N + 1; j++)
            if (i != j)
                djikstras(i, j);
    }

    int minVal = INT_MAX;
    for (int i = 1; i < N + 1; i++)
    {
        int maxVal = 0;
        for (int j = 1; j < N + 1; j++)
            maxVal = max(maxVal, dist[i][j]);
        minVal = min(minVal, maxVal);
    }

    cout << minVal << endl;
}

int main()
{
    Input();
    Solve();
    return 0;
}