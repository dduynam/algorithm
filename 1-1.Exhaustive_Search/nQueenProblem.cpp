#include <bits/stdc++.h>

/* Description: Calculating the number of ways N queens can be planed on an NxN chessboard so that no two queens attack
each other 
With:
    • y: row
    • Recursive based on row, and numbered from 0 to n-1.
    * It's not allowed to add another queen to column or diagonal that already contains a queen
*/

#define N_SIZE 4
int column[N_SIZE]; // keep track a columns that contain a queen.
int diag1[N_SIZE*N_SIZE], diag2[N_SIZE*N_SIZE]; // diag1, diag2 keep track of diagonals

static int count = 0;
void search(int y)
{
    if (y == N_SIZE) {
        count++; // a solution has been found and the variable count is increased by one.
        return;
    }

    for (int x = 0; x < N_SIZE; x++)
    {
        if (column[x] || diag1[x+y] || diag2[x-y+N_SIZE-1]) continue;
        column[x] = diag1[x+y] = diag2[x-y+N_SIZE-1] = 1;
        // call itself with parameter y+1
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+N_SIZE-1] = 0;
    }
}

int main ()
{
    search(0);
    std::cout << count << std::endl;
    return 0;
}