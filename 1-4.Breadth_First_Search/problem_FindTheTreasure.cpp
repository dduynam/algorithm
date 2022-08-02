#include <bits/stdc++.h>

#define BRUTEFORCE 1
#define BFS 0
#define SOLUTION BFS

/* Example of input
1
5
1 4
1 5
1 5
2 2 3
*/

#if SOLUTION

std::vector<std::vector<int>> adj;
std::vector<int> ans;
int n;

// Ham kiem tra xem so hop can mo trong vector a co nho hon cach trong vector b hay khong

bool checkSmaller(std::vector<int> a, std::vector<int> b)
{
    // Neu co cung so phan tu, kiem tra tung phan tu 1. Neu co phan tu cua vector a nho hon phan tu b, tra ve true
    // Neu 2 vector co size khac nhau, kiem tra xem size cua a co nho hon size cua b khong

    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] < b[i])
                return true;
        }
        return false;
    }
    else
    {
        return a.size() < b.size();
    }
}

// duyet xem tu hop u mo duoc nhung hop nao
// neu mo toi hop cuoi cung, luu lai cach mo nho nhat
// vector used dung de danh dau hop duoc mo roi
// vector path dung de luu cach mo

void tryOpen(int u, std::vector<bool> used, std::vector<int> path)
{
    used[u] = true;
    if (u == n - 1)
    {
        if (ans.empty() || checkSmaller(path, ans))
        {
            ans = path;
        }
        return;
    }
    for (auto nextBox : adj[u])
    {
        if(!used[nextBox])
        {
            path.push_back(nextBox);
            tryOpen(nextBox, used, path);
            path.pop_back();
        }
    }
}

int main()
{

    /* Handle input */
    int T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        adj = std::vector<std::vector<int>>(n);
        ans.clear();

        for (int i = 0; i < n-1; i++)
        {
            int m;
            std::cin >> m;
            for (int j = 0; j < m; j++)
            {
                int nextBox;
                std::cin >> nextBox;
                // dung theo index-0 nen giam chi so cua hop di 1 truoc khi luu vao list
                --nextBox;
                adj[i].push_back(nextBox); 
            }
        }
        
        std::vector<bool> used(n);
        std::vector<int> path;
        path.push_back(0);
        tryOpen(0, used, path);
        if(ans.empty())
            std::cout << -1 << '\n';
        else
        {
            std::cout << ans.size() - 1 << '\n';
            for (int i = 0; i < ans.size() - 1; i++)
            {
                std::cout << ans[i] + 1 << " ";
            }
            std::cout << '\n';
        }
    }

    return 0;
}

#else // BFS
/* Keyword: Tim cac hop can mo la nho nhat
- Sap xep danh sach cac hop co the mo theo thu tu tang dan
- Dung BFS dam bao duoc hop co so nho se duoc duyet truoc
- Cach mo hop tim thay dau tien cung la cach co cac hop can mo la so nho nhat
Time complexity: O(N)
*/

// vector used dung de danh dau hop da duoc duyet
// vector previousBox dung de luu hop duoc mo truoc do
// hop previousBox[i] la hop co chua chia khoa de mo hop i

std::vector<bool> used;
std::vector<int> previousBox;
std::vector<std::vector<int>> adj;

void bfs()
{
    std::queue<int> qu;
    qu.push(0);
    used[0] = true;
    previousBox[0] = -1;
    while(!qu.empty())
    {
        int currentBox = qu.front();
        qu.pop();
        for (auto nextBox : adj[currentBox])
        {
            if(!used[nextBox])
            {
                used[nextBox] = true;
                qu.push(nextBox);
                previousBox[nextBox] = currentBox;
            }
        }
    }
}

int main() {

    int T; 
    std::cin >> T;
    while (T--)
    {
        int n;
        std::cin >> n;
        adj = std::vector<std::vector<int>>(n);
        used = std::vector<bool>(n);
        previousBox = std::vector<int>(n);
        for (int i = 0; i < n-1; i++)
        {
            int m;
            std::cin >> m;
            for (int j = 0; j < m; j++)
            {
                int nextBox;
                std::cin >> nextBox;
                --nextBox;
                adj[i].push_back(nextBox);
            }
            std::sort(adj[i].begin(), adj[i].end());
        }
        bfs();
        if (!used[n-1])
            std::cout << -1 << '\n';
        else
        {
            std::vector<int> path;
            // duyet lai cac hop mo duoc truoc do bang vector previousBox
            for (int i = n-1; i != -1; i = previousBox[i])
            {
                path.push_back(i);
            }

            std::reverse(path.begin(), path.end());
            
            std::cout << path.size() - 1 << "\n";
            for (int i = 0; i < path.size()-1; i++)
            {
                std::cout << path[i] + 1 << ' ';
            }
            std::cout << '\n';
            
        }
        
    }
    return 0;
}

#endif