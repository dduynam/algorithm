#include <bits/stdc++.h>
using namespace std;

int N;
vector <vector<int>> colors;
unordered_map <int, pair<pair<int,int>, pair<int,int>>> um;
vector <bool> check (10, 0);
vector <bool> exclude (10, 0);
int ans = 0;

void Input()
{
    cin >> N;
    colors.resize(N);
    for (int i = 0; i < N; i++)
    {
        string val;
        cin >> val;
        colors[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            int valInt = val[j] - '0';
            colors[i][j] = valInt;
            if (!check[valInt])
            {
                check[valInt] = true;
                um[valInt] = {{i,j},{i,j}};
            }
            else
            {
                um[valInt].second.first = max(um[valInt].second.first, i);
                um[valInt].second.second = max(um[valInt].second.second, j);
                um[valInt].first.first = min(um[valInt].first.first, i);
                um[valInt].first.second = min(um[valInt].first.second, j);
            }
        }
    }

    check[0] = false;
    for (int i = 1; i < 10; i++)
    {
        if (check[i])
        {
            int xMin = um[i].first.first;
            int yMin = um[i].first.second;
            int xMax = um[i].second.first;
            int yMax = um[i].second.second;
            // cout << i << " " << xMin << "_" << yMin << " " << xMax << "_" << yMax << endl;
            for (int x = xMin; x <= xMax; x++)
                for (int y = yMin; y <= yMax; y++)
                    if (colors[x][y] != i && colors[x][y] != 0)
                        // cout << colors[x][y] << endl;
                        exclude[colors[x][y]] = true;
        }
    }
    
    for (int i = 1; i < 10; i++)
        if (check[i] && exclude[i] != true) ans++;
    
    cout << ans << endl;    
}

int main() {
    Input();
	return 0;
}