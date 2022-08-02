/* Issue: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/ */
#include<bits/stdc++.h>

/* Input
1
5 3
2 1 7 4 2
*/

#define BRUTEFORCE 1
#define BFS 0

#if BRUTEFORCE
/* Time complexity: N*K */
int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        int N, K;
        std::cin >> N >> K;
        std::vector<long long> a(N);
        for (int i = 0; i < N; i++)
        {
            std::cin >> a[i];
        }
        long long ans = 0;

        for (int i = 0; i < K; i++)
        {
            // dung max element de tim phan tu lon nhat cua day
            std::vector<long long>::iterator bigCandyPosition = std::max_element(a.begin(), a.end());
            ans += *bigCandyPosition;
            *bigCandyPosition /= 2;
        }
        
        std::cout << ans << '\n';
        
    }

    return 0;
}

#else // BFS
/* Time complexity: K*log(N) */
int main()
{    
    int N, K;
    std::cin >> N >> K;

    long long ans = 0; 
    std::priority_queue<long long> qu;

    for (int i = 0; i < N; i++)
    {
        long long candy;
        std::cin >> candy; 
        qu.push(candy);
    }
    
    while(K--)
    {
        long long consume = qu.top();
        qu.pop();
        ans += consume;
        qu.push(consume/2);
    }

    std::cout << ans << "\n";
    return 0;
}

#endif