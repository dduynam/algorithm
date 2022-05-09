#include <bits/stdc++.h>

#define KRUSKAL 1
#define PRIM 1
#define DIJKSTRA 1

#if KRUSKAL
bool kruskalMST() {
    int V = 5; 
    int parent[V]; // chua co dinh nao nam trong MST 
    int count[V]; // count[i] la so luong nut con neu coi nut i la goc

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1; // Tat ca la cay mot nut
        count[i] = 1;
    }

    qsort(E); // Sap xep lai cac canh cua do thi theo thu tu tang dan

    while (mst.size() < V - 1 && E.size() > 0)
    {
        e = E.front(); //Lay dinh e co trong so nho nhat 
        E.pop();

        if (!makeUnion(e, parent, count)) // Neu khong the them canh e vao cay khung nho nhat
            continue;

        mst.push(e); // Them canh e vao trong MST
    }
    return mst.size() == V - 1; // Thong bao ket qua cua viec tiem cay khung nho nhat
}

bool makeUnion(Edge e, int parent[], int count[]) {
    int parentStart = e.start;
    while (parent[parentStart] != -1) parentStart = parent[parentStart]; // tim goc cua cay start
    int parentEnd = e.end;
    while (parent[parentEnd] != -1) parentEnd = parent[parentEnd]; // tim goc cua cay end

    if (parentStart == parentEnd) return false; // Neu hai dinh co cung goc >> them canh e se tao ra chu trinh >> loai bo e

    if (count[parentStart] > count[parentEnd]) {
        parent[parentEnd] = parentStart;
        count[parentStart] += count[parentEnd]; //tang so luong nut cua cay nut start
    } else {
        parent[parentStart] = parentEnd;
        count[parentEnd] += count[parentStart]; //tang so luong nut cua cay nut start
    }
    return true;
}
#endif

#if PRIM

bool  primMST() {
    int V = 5; // size of graph 
    int parent[V]; // Cay khung duoc luu tren mang parent, voi cha cua not i trong cay khung la parent[i]
    int key[V]; // Mang luu tru khoang cach voi y nghia key[i] la khoang cach tu cac dinh i den cay khung hien tai
    bool mstSet[V]; // mang kiem tra y nghia dinh thu i co mstSet[i] == true nghia la dinh i dang nam trong cay khung va nguoc lai

    // Initilization
    for (int i = 0; i <  V; i++)
    {
        key[i] = INT_MAX; // Initially chua co dinh nao duoc chon, tat ca khoang cach la vo cung
        mstSet[i] = false;
    }
    
    key[0] = 0; // Chon dinh bat dau la 0, khoang cach tu 0 den khug hien tai la 0
    parent[0] = -1; // Vi 0 la root, nen no ko co cha

    for (int i = 0; i < V-1; i++)
    {
        int u = minKey(key, mstSet); // Lay ra dinh u co khoang cach nho nhat den cay khung hien tai

        if (u == -1) return false; // Khong tim duoc dinh nao --> Do thi khong lien thong nen khong tim duoc MST

        mstSet[u] = true; // Danh dau dinh u da duoc chon vao cay khung

        for (int v = 0; v < V; v++)
        {
            /* Tu dinh u da chon vao cay, kiem tra tat ca cac canh noi voi dinh u.
            Neu khoang cach tu dinh vua duoc chon vao cay u den dinh v khong thuoc cay ma nho hon key[v].
            Key[v] hien tai la khoang cach nho nhat tu dinh v den cay khi dinh u chua duoc them vao cay.
            Thi cap nhat lai gia tri cho key[v]. */
            if (mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u; // cap nhat lai parent cua dinh v la dinh u
                key[v] = graph[u][v]; 
            }
        }
    }
    return true;
}

int minKey(int key[], int mstSet[]){
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

#endif

#if DIJKSTRA
int V =  5; 
/* Tim duong di ngan nhat tu diem s den cac diem con lai torng do thi */
void dijkstra(int graph[5][5], int s) // graph[V][V]
{
    int d[V]; // mang luu tru khoang cach tu dinh s den cac dinh con lai tren do thi
    int pre[V]; // mang truy vet duong ngan nhat
    bool unvisited[V]; // mang kiem tra diem da duoc tham hay chua
    
    /* Initialization */
    for (int i = 0; i < V; i++)
    {
        d[i] = INT_MAX; // Chua biet duong di
        unvisited[i] = true;
        pre[i] = s; 
    }

    d[s] = 0; // Duong di tu s den chinh no luon bang 0
    pre[s] = -1; // s la diem dau tien, truoc no khong co dinh nao

    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(d, unvisited); // tim dinh chua tham ma co khoang cach tu s den ngan nhat

        if (d[u] == INT_MAX) break; // dung lai neu khong co duong di

        unvisited[u] = false; // danh dau da tham

        for (int v = 0; v < V; v++)
        {
            if (unvisited[v] == true && graph[u][v] != INT_MAX && d[u] + graph[u][v] < d[v])
            {
                d[v] = d[u] + graph[u][v];
                pre[v] = u; // luu vet duong di
            }
        }
    }
    printSolution(d);
}

int minDistance(int dist[], int unvisited[])
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
    {
        if (unvisited[v] == true && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int pre[])
{
    for (int i = 0; i < V; i++)
    {
        printf("Distance from source to %d is %d", i, dist[i]);
    }
    
}
#endif

int main() { 


    return 0;
}