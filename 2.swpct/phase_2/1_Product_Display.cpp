#include <iostream>
using namespace std;
#define MAXN (1000)

int N;
int ID[MAXN + 10];

int CalLargestBlock(int id_ignore){
	int max_block_size = 0;
	int cur_size = 1;
	
	int i;
	for (i = 0; i < N; i++)
	{
		if (id_ignore == ID[i]) continue;
		break;
	}
	
	if (i == N) return 0;
	if (i == N-1) return 1;
	int pre = ID[i];
	
	for (i += 1; i < N; i++){
		if (ID[i] == id_ignore)		
			continue;
		
		if (ID[i] == pre) cur_size++;
		else 
		{
			cur_size = 1;
			pre = ID[i];
		}
		
		if (max_block_size < cur_size) {
			max_block_size = cur_size;
		}
	}
	return max_block_size;
}

int Solve(){
	int sol = (int)1e7, max_cnt = 0;
	for (int i = 0; i < N; i++){
		int ret = CalLargestBlock(ID[i]);
		if ((max_cnt < ret) || ((max_cnt == ret) && (sol < ID[i]))) {
			max_cnt = ret;
			sol = ID[i];
		}
	}
	return sol;
}

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> ID[i];
	}
}

int main(){
	int ans;
	InputData();

	ans = Solve();

	cout << ans << "\n";
	return 0;
}