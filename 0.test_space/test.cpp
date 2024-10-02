#include <bits/stdc++.h>
using namespace std;

int N;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string seed;
		vector<vector<bool>> check(3, vector<bool>(3, false));
		unordered_map <char, pair<int,int>> toaDo;
		vector <int> ret(seed.size(), 0);

		cin >> seed;
		for (int a = 0; a < 3; a++)
		{
			string val;
			cin >> val;
			for (int b = 0; b < 3; b++)
			{
				toaDo[val[b]] = pair<int,int> (a,b);
			}
		}

		for (int a = 0; a < seed.length(); a++)
		{
			if (toaDo.find(seed[a]) == toaDo.end())
			{
				ret[a] = 0;
				continue;
			}

			int temp = 0;
			int x = toaDo[seed[a]].first;
			int y = toaDo[seed[a]].second;
			check[x][y] = true;
			bool checkVal = true;

			for (int b = 0; b < 3; b++)
			{
				checkVal *= check[x][b];
			}

			if (checkVal)
				temp++;

			checkVal = true;
			for (int b = 0; b < 3; b++)
			{
				checkVal *= check[a][x];
			}

			if (checkVal)
				temp++;

			checkVal = true;
			if (x == 1 && y == 1 || x == 2 && y == 2 || x == 3 && y == 3)
				checkVal = check[1][1]*check[2][2]*check[3][3];

			if (checkVal)
				temp++;

			checkVal = true;
			if (x == 1 && y == 3 || x == 2 && y == 2 || x == 3 && y == 1)
				checkVal = check[1][3]*check[2][2]*check[3][1];

			if (checkVal)
				temp++;			

			ret[a] = temp;
		}
	}

	return 0;
}