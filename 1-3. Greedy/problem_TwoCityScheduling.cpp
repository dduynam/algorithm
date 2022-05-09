#include <bits/stdc++.h>

std::vector<std::vector<int>> a{{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
int size = a.size();
int ret = INT_MAX;
void bruteforce_dfs(int index, int x, int y, int temp)
{
    if(index == size)
    {
        ret = std::min(ret,temp);
    }
    if (x < size/2)
    {
        bruteforce_dfs(index+1, x+1, y, temp+a[index][0]);
    }
    if (y < size/2)
    {
        bruteforce_dfs(index+1, x, y+1, temp+a[index][1]);
    }
}

/* greedy
sap xep chuoi tang dan theo X[0]-X[1] voi chi phi X{[0], [1]}
Tu do ta co X[0]-X[1] < Y[0]-Y[1] ===>>>> X0+Y1 < Y0+X1
*/

int greedy(std::vector<std::vector<int>> &cost)
{
    int size = cost.size();
    int ret = 0;
    std::vector<std::vector<int>> temp(size, std::vector<int>(2,0));

    for (int i = 0; i < size; i++)
    {
        temp[i][0] = cost[i][0] - cost[i][1];
        temp[i][1] = i;
    }

    std::sort(temp.begin(), temp.end());

    for (int i = 0; i < size/2; i++)
    {
        ret += cost[temp[i][1]][0];
    }

    for (int i = size/2; i < size; i++)
    {
        ret += cost[temp[i][1]][1];
    }

    return ret;    
}

int main()
{
    bruteforce_dfs(0,0,0,0);
    std::cout << ret << std::endl;
    std::cout << INT_MAX << std::endl;
    std::cout << greedy(a) << std::endl;   
    return 0;
}