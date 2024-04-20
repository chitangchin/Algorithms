#include <stdio.h>

int isSafe(int row, int col, int sol[], int N)
{
    if (sol[col] != -1)
    {
        return 0;
    }
    else
    {
        int left_diagonal = row - col;
        int right_diagonal = row + col;
        for (int i = 0; i < N; i++)
        {
            if (sol[i] != -1)
            {
                if (sol[i] + i == right_diagonal || sol[i] - i == left_diagonal)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
}

// display solution
void display(int sol[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("Q%d is placed in row %d, column %d\n", sol[i], sol[i], i);
    }
    printf("\n");
}

// State Space Tree
void solve(int N, int sol[], int pos)
{
    // Recursive function

    // base condition
    if (pos == N)
    {
        display(sol, N);
    }
    else
    {
        // Solution is not complete
        for (int i = 0; i < N; i++)
        {
            if (isSafe(pos, i, sol, N) == 1)
            {
                sol[i] = pos;
                solve(N, sol, pos + 1);
                sol[i] = -1;
            }
        }
    }
}

// Input getting function
int main(void)
{
    int N;
    scanf("%d", &N);
    int sol[N];
    for (int i = 0; i < N; i++)
    {
        sol[i] = -1;
    }
    solve(N, sol, 0);
}