#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const int n=5,m=3,folgas=2;

void imprimir(double tabela[][n]);
void Simplex(double tabela[][n]);

void imprimir(double tabela[][n])
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout.precision(2);
            cout << tabela[i][j] << "\t";
            //printf("%.2lf\t",tabela[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}


int colunaMin(double tabela[][n])
{
    double minimo = 10000000;
    int c = -1;

    for (int i = 0; i < n - folgas - 1; i++)
    {
        if (tabela[0][i] < minimo && tabela[0][i] > 0)
        {
            minimo = tabela[0][i];
            c = i;

        }
    }

    return c;
}


int findLines(int c,double tabela[][n])
{

    double minimo = tabela[1][n - 1] / tabela[1][c];

    int l = 1;
    for (int j = 2; j < m; j++)
    {
        if (tabela[j][c] > 0)
            if ((tabela[j][n - 1] / tabela[j][c]) < minimo && (tabela[j][n - 1] / tabela[j][c]) > 0)
            {
                minimo = tabela[j][n - 1] / tabela[j][c];
                l = j;
            }
    }
    return l;
}

void calcular_linha(int linha, int colunaPiv,double tabela[][n])
{
    if (tabela[linha][colunaPiv] != 0)
    {
        double piv = tabela[linha][colunaPiv];
        for (int i = 0; i < n; i++)
            tabela[linha][i] /= piv;
    }
}

void buildTable(int linha, int colunaPiv,double tabela[][n])
{

    double p2 = tabela[linha][colunaPiv];
    for (int l = 0; l < m; l++)
    {
        double p1 = tabela[l][colunaPiv];
        double p3 = fabs(p1);

        if (l != linha)
        {
            for (int c = 0; c < n; c++)
            {
                if (p1 > 0 && p2 > 0)
                    tabela[l][c] = (tabela[l][c] * p2) - (tabela[linha][c] * p3);
                else if (p1 > 0 && p2 < 0)
                    tabela[l][c] = (tabela[l][c] * p2) + (tabela[linha][c] * p3);
                else if (p1 < 0 && p2 > 0)
                    tabela[l][c] = (tabela[l][c] * p2) + (tabela[linha][c] * p3);
                else
                    tabela[l][c] = (tabela[l][c] * p2) - (tabela[linha][c] * p3);
            }
        }

    }
}

void Simplex(double tabela[][n])
{
    while(colunaMin(tabela)!=-1)
    {
        int coluna_piv = colunaMin(tabela);
        int linha = findLines(coluna_piv,tabela);
        calcular_linha(linha,coluna_piv,tabela);
        buildTable(linha,coluna_piv,tabela);
    }
    cout << endl;
    imprimir(tabela);
}

int main()
{
    double tabela[m][n] =
    {
        { 2, 4, 0, 0, 0}, { 1, 1, 1, 0, 5 }, { 0, 1, 0, 1, 4}
    };

    cout << "\tModelo Simplex\n" << endl;
    Simplex(tabela);

    return 0;
}
