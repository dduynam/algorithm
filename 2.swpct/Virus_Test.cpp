#include <bits/stdc++.h>
using namespace std;

int N; // Number of executable code data
int M; // Number of virus data
int A[20000 + 10]; // Executable code data
vector <int> B; // Virus data

int sol; // Correct answer

void InputData(void)
{
	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	B.resize(M, 0);
	for (i = 0; i < M; i++) {
		cin >> B[i];

	}
}

void OutputData(void)
{

	cout << sol;
}

int Find(int start)
{
	int i;
	vector <int> C(M, 0);
	for (int j = 0; j < M; j++)
	{
		C[j] = A[start + j];
	}
	
	sort(C.begin(), C.end());
	sort(B.begin(), B.end());
	int cmp_val = B[0] - C[0];

	for (i = 0; i < M; i++) {
		if (B[i] != C[i] + cmp_val) return 0;
	}
	return 1;
}

void Solve(void)
{
	int i;

	for (i = 0; i <= N - M; i++) {
		sol += Find(i);
	}
}

int main(void)
{
	InputData(); // Input

	Solve(); // Problem solving

	OutputData(); // Output

	return 0;
}
