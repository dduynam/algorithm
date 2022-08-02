#include <bits/stdc++.h>

#define     V   5

void printResult(bool visited[], int pre[], int s);

void BFS(int graph[V][V], int s)
{
    bool visited[V];
    std::fill(visited, visited+V, false);
    int pre[V];
    pre[s] = -1;

    std::queue<int> queue;
    queue.push(s);

    while (queue.size() > 0)
    {
        int u = queue.front();
        queue.pop();
        visited[u] = true;

        for (int v = 0; v < V; ++v)
        {
            if (visited[V] == false && graph[u][v] > 0)
            {
                queue.push(v);
                pre[v] = u;
                visited[v] = true;
            }
        }

    }

    printResult(visited, pre, s);
}

void printResult(bool visited[], int pre[], int s)
{
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            printf("Khong co duong di tu %d den %d \n", s, v);
        }
        else
        {
            printf("Duong di tu %d den %d \n", s, v);
            int f = v;
            while (pre[f] != -1)
            {
                printf("%d <- ", f);
                f = pre[f];
            }
            printf("%d \n", f); // print the source place
        }
    }
    
}

int r[] = {-1, 0, 1, 0};    // Gia tri hang(row) cua 4 thanh phan lan can
int c[] = {0, 1, 0, -1};    // Gia tri cot(column) cua 4 thanh phan lan can

struct Point{
    int x;
    int y;

    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
};

int color[100][100];
// To mau nhung diem bat dau tu startPoint nhung mau targetColor thanh mau replacementColor

int N, M = 5;
void floodFillBfs(Point* startPoint, int targetColor, int replacementColor)
{
    std::queue<Point*> queue;
    queue.push(startPoint);

    while (queue.size() > 0)
    {
        Point* p = queue.front();
        queue.pop();

        color[p->x][p->x] = replacementColor;

        for (int i = 0; i < 4; i++)
        {
            int newX = p->x + r[i];
            int newY = p->y + c[i];

            if (newX < 0 || newX >= N) continue; // Neu diem moi ngoai mang thi bo qua diem nay
            if (newY < 0 || newY >= M) continue; // Neu diem moi ngoai mang thi bo qua diem nay

            if (color[newX][newY] == targetColor)
                queue.push(new Point(newX, newY)); // Them diem co toa do (newX, newY) cung khu vuc voi startPoint vao danh sach cho
        }
        
    }

}

int main()
{


    return 0;
}