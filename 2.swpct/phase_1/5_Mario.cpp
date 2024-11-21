#include <bits/stdc++.h>
using namespace std;

int N; //Number of mushrooms
vector <int> P(150010, 0); //Mushroom value
int ret = 0;

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

void Solve()
{
    int max_val = P[0];
    int min_val = 9999;
    for (int i = 1; i < N; i++) {
        if (max_val != 0) {
            if (max_val <= P[i]) max_val = P[i];
            else {
                ret += max_val;
                max_val = 0;
                min_val = P[i];
            }
        }
        
        if (min_val != 0) {
            if (min_val >= P[i]) min_val = P[i];
            else {
                ret -= min_val;
                min_val = 0;
                max_val = P[i];
            }            
        }
    }
    
    if (max_val != 0) ret += max_val;

	cout << ret << endl;	//	Output answer
}

int main(){
	InputData();			//	Input function
	Solve();
	return 0;
}
