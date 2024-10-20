#include <bits/stdc++.h>
using namespace std;

int N;//The number of goods to send 
int ans = 0;
vector <int> box_number(10, 0);//The number of BOXes(in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
vector <int> boxes {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
vector <int> ret(10, 0);//The number of boxes to send

void InputData(){
	int i;
	cin >> N;
	for(i = 0; i < 10; i++){
		cin >> box_number[i];
	}
}

pair <int, int> Solve_1()
{
    pair <int, int> out;
    out.first = 0;
    out.second = 0;
    int i;
    for (i = 0; i < box_number.size(); i++)
    {
        int num = box_number[i];
        for (int j = 0; j < num; j++)
        {
            out.first += boxes[i];
            ret[i]++;
            ans++;
            if (out.first >= N)
            {
                out.second = i;
                return out;
            }
        }
    }

    out.second = i - 1;
    return out;
}

void Solve_2(pair <int, int> tmp)
{
    if (tmp.first == N)
        return;

    int cmp = tmp.first - N;
    int sum = 0;
    
    for (int i = tmp.second - 1; i >= 0; i--)
    {
        int num = ret[i];
        for (int j = 0; j < num; j++)
        {
            if (sum + boxes[i] <= cmp)
            {
                ret[i]--;
                sum += boxes[i];
                ans--;
            }
            else
            {
                break;
            }

            if (sum == N)
            {
                return;
            }
        }
    }
}

void OutputData(){
	int i;
	cout << ans << endl;
	for(i = 0; i < 10; i++){
		cout << ret[i] << " ";
	}
	cout << endl;
}

int main(){
	InputData(); //	Input function
	Solve_2(Solve_1());
	OutputData(); // Output function
	return 0;
}