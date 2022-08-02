#include <bits/stdc++.h>

std::vector<std::vector<int>> in{{1,4}, {3,6}, {2,7}, {1,2}, {3, 8}};
int size = in.size();

int bruteforce(std::vector<std::vector<int>> &in)
{
    int ret = size;
    std::vector<std::vector<int>> temp(size, std::vector<int>(2, 0));
    for (int i = 0; i < size; i++)
    {
        temp[i][0] = in[i][0];
        temp[i][1] = i;
    }
    
    sort(temp.begin(), temp.end());
    
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (in[temp[j][1]][1] - in[temp[i][1]][1] >= 0)
            {
                size--;
                in[temp[i][1]][1] = INT_MAX;
            }
        }
    }

    return size;
}

int bruteforce_2(std::vector<std::vector<int>> &in)
{
    int ret = 0;
    std::vector<bool> check(in.size(), true);
    for (int i = 0; i < in.size(); i++)
    {
        for (int j = 0; j < in.size(); j++)
        {
            if (i==j) continue;
            if (in[j][0] <= in[i][0] && in[i][1] <= in[j][1])
            {
                check[i] = false;
                break;
            }
        }
    }

    for (int i = 0; i < in.size(); i++)
    {
        if (check[i])
            ret++;
    }
    
    return ret;
}

// greedy

static bool com(std::vector<int> &a, std::vector<int> &b)
{
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int greedy(std::vector<std::vector<int>> &intervals)
{
    int max = -1;
    int count = 0;

    // neu bang nhau thi khoang nao co phan tu ket thuc lon hon xep len truoc
    std::sort(intervals.begin(), intervals.end(), com);

    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][1] > max)
        {
            max = intervals[i][1];
            count++;
        }
        return count;
    }
    
}
int main()
{
    std::cout << bruteforce_2(in) << std::endl;
}