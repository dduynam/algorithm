#include <bits/stdc++.h>
using namespace std;

int N;//the number of test cases
int B;//number system
string S;//first integer
string D;//second integer
bool sign_flag = false; 

int convertToInt(char x)
{
    if (x <= '9' && x >= '0')
        return x - '0';
    if (x >= 'A' && x <= 'Z')
        return x - 'A' + 10;
}

char convertToChar(int x)
{
    if (x <= 9)
        return x + '0';
    else
        return x + 'A' - 10;
}

void InputData(){
	cin >> B >> S >> D;
    sign_flag = false;
}

void Solve()
{
    if (S[0] == '0' || D[0] == '0')
    {
        cout << "0" << endl;
        return;
    }

    if (S[0] == '-')
    {
        sign_flag = !sign_flag;
        S.erase(0,1);
    }
    
    if (D[0] == '-')
    {
        sign_flag = !sign_flag;
        D.erase(0,1);
    }
    
    reverse(D.begin(), D.end());
    reverse(S.begin(), S.end());

    int ret_size = S.size() + D.size(); 
    vector <int> mul_val(ret_size, 0);
     
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; j < D.size(); j++)
        {
            mul_val[i+j] += convertToInt(S[i])*convertToInt(D[j]);
            mul_val[i+j+1] += mul_val[i+j]/B;
            mul_val[i+j] %= B;
        }
        
    }

    if (sign_flag)
        cout << "-";

    int idx;
    for (idx = mul_val.size()-1; idx >= 0; idx--)
    {
        if (mul_val[idx] != 0)
        {
            break;
        }
    }

    for (; idx >= 0; idx--)
    {
        cout << convertToChar(mul_val[idx]);
    }

    cout << endl;
    
}

int main(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		InputData();
        Solve();
	}
	return 0;
}