#include <bits/stdc++.h>

using namespace std;

const int TAM = 100;

void LU(int A[][TAM], int n)
{
    int L[n][n], U[n][n];
    memset(L, 0, sizeof(L));
    memset(U, 0, sizeof(U));

    for (int i = 0; i < n; i++)
    {
        for (int k = i; k < n; k++)
        {

            int soma = 0;
            for (int j = 0; j < i; j++)
                soma += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - soma;
        }

        for (int k = i; k < n; k++)
        {
            if (i == k)
                L[i][i] = 1;
            else
            {

                int soma = 0;
                for (int j = 0; j < i; j++)
                    soma += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - soma) / U[i][i];
            }
        }
    }

    cout << "L" << endl;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    cout << "U" << endl;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout << U[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int A[][TAM] =
    {
        { 3, 0, 0 },
        { 0, 6, 0 },
        { 0, 0, 9 }
    };

    LU(A, 3);
    return 0;
}
