/*Note:
By default, the sequence is max-heap */

#include <iostream>
#include <queue>

void showpq(const std::priority_queue<int> &gq)
{
    std::priority_queue<int> g = gq;
    while (!g.empty())
    {
        std::cout << '\t' << g.top();
        g.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::priority_queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);

    std::cout << "The priority queue is: ";
    showpq(gquiz);

    std::cout << "\nTop: " << gquiz.top();
    std::cout << "\nSize: " << gquiz.size();

    std::cout << "\nAfter pop: " << gquiz.top();
    gquiz.pop();
    std::cout << "\n";
    std::cout << "The priority queue is: ";
    showpq(gquiz);

}

/* In case of max-heap - default */
std::priority_queue<int> maxHeap;

/* In case of min-heap */
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;