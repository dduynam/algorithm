#include <bits/stdc++.h>
using namespace std;

int N; //The number of candidates
vector <int> A; //Temperament value
pair <int, int> ret;
int minVal = 9999;

void InputData(){
    cin >> N;
    A.resize(N, 0);
    for (int i = 0; i < N; i++) 
        cin >> A[i];
}

void Solve()
{
    if (N == 2)
        cout << "0 1" << endl;

    int leftIdx = 0;
    int rightIdx = N-1;
    do {
        int tmp = abs(A[leftIdx] + A[rightIdx]);
        if (minVal > tmp)
        {
            minVal = tmp;
            ret.first = leftIdx;
            ret.second = rightIdx;
        }
        if (abs(A[leftIdx]) > abs(A[rightIdx]))
            leftIdx++;
        else
            rightIdx--;
    } while (leftIdx != rightIdx);

    cout << ret.first << " " << ret.second << endl;
}

int main(){
    InputData();
	Solve();
    return 0;
}
