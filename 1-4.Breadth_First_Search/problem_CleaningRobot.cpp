#include <bits/stdc++.h>

/* https://www.spoj.com/problems/CLEANRBT/ */

#define BRUTEFORCE 1
#define BFS 0

/* Input

7 5
3
.......
.o...*.
.......
.*...*.
.......
*/

/* Information
    * 'x' robot ko di qua duoc, '.' robot di qua duoc 
    * robot di chuyen nhieu lan qua 1 o
    * vi tri ban dau cua robot danh dau la 'o'. Vi tri vien gach ban danh day '*'
    * Robot di chuyen tren, duoi, trai, phai
    * Tim so buoc di chuyen nho nhat cua robot de lam sach het cac o gach bi ban, hoac in ra -1 neu khong the lam sach het cac o gach nay
*/


int bruteforceCleaning(int  r, int c, char** floor, int W, int H, int K, int removed, int cost)
{
    static int ans = INT_MAX;
    if (r < 0 || r >= H || c < 0 || c >= W || floor[r][c] == 'x')
        return 0;

    if (removed == K)
    {    
        ans = std::min(ans, cost);
    }

    if (cost > W*H)
        return 0;
    
    bool removedFlag = false;
    if (floor[r][c] == '*')
    {
        removedFlag = true;
        removed++;
        floor[r][c] = '.';
        std::cout << removed << "***";
    }
    bruteforceCleaning(r-1, c, floor, W, H, K, removed, cost+1);
    bruteforceCleaning(r+1, c, floor, W, H, K, removed, cost+1);
    bruteforceCleaning(r, c+1, floor, W, H, K, removed, cost+1);
    bruteforceCleaning(r, c-1, floor, W, H, K, removed, cost+1);

    if (removedFlag)
    {
        floor[r][c] = '*'; // backtracking
    }    

    return 0; 
}

void displayFloor(char** floor, int W, int H)
{
    std::cout << H << "x" << W << std::endl;
    for (char i = 0; i < H; i++)
    {
        for (char j = 0; j < W; j++)
        {
            std::cout << floor[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << "End" << std::endl;
}

#if 0

int main()
{
    int W, H; /* san nha W*H va W,H <= 20 */
    int K; /* o gach bi ban K <= 10 */

    std::cin >> W >> H;
    std::cin >> K;
    char** floor;
    floor = new char*[H];
    for (char i = 0; i < H; i++)
    {
        floor[i] = new char[W];
        for (char j = 0; j < W; j++)
        {
            std::cin >> floor[i][j];
        }
    }
    
    // Display the floor before cleaning
    displayFloor(floor, W, H);

    bruteforceCleaning(1, 1, floor, W, H, K, 0, 0);

    return 0;

}

#else 

const int dr[4] = {-1, 0, 0, 1};
const int dc[4] = {0, -1, 1, 0};
const int MAX = 20, STATE = 1 << 10;
int dist[STATE][MAX][MAX];
int H, W, total;
char A[MAX][MAX+5];

int bfs(int r, int c)
{
    int ans = INT_MAX;
    std::queue<int> q;
    dist[0][r][c] = 0;
    q.push(r), q.push(c), q.push(0);

    while(!q.empty())
    {
        r = q.front(); q.pop();
        c = q.front(); q.pop();
        int mask = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int vi = r + dr[i];
            int vj = c + dc[i];
            int vm = mask;
            if (vi >= 0 && vi < H && vj < W && A[vi][vj]!='x')
            {
                if (A[vi][vj] < total)
                {
                    vm |= 1 << A[vi][vj];
                }
                if (dist[vm][vi][vj] > dist[mask][r][c]+1)
                {
                    dist[vm][vi][vj] = dist[mask][r][c] + 1;
                    if (vm == (1 << total) -1)
                        ans = std::min(ans, dist[vm][vi][vj]);
                    q.push(vi), q.push(vj), q.push(vm);
                }
            }
        }
    }
    return ((ans < INT_MAX)?ans:-1);
}

int main()
{
    int W, H; /* san nha W*H va W,H <= 20 */
    int K; /* o gach bi ban K <= 10 */

    std::cin >> W >> H;
    std::cin >> K;
    char** floor;
    floor = new char*[H];
    for (char i = 0; i < H; i++)
    {
        floor[i] = new char[W];
        for (char j = 0; j < W; j++)
        {
            std::cin >> floor[i][j];
        }
    }
    
    // Display the floor before cleaning
    displayFloor(floor, W, H);


    return 0;

}
#endif