#include <iostream>

using namespace std;

int main()
{
    int i,j,n;
    float xbarra,Produtorio,Pn;

    cout << "Digite a quantidade de pontos: ";
    cin >> n;

    pair<float,float> pontos[n];

    for(i=0; i<n; i++)
    {
        cin >> pontos[i].first;
        cin >> pontos[i].second;
    }

    cout << "X = ";
    cin >> xbarra;

    Pn=0;
    for (j = 0; j < n; j++)
    {
        Produtorio=1;
        for (i=0; i < n; i++)
        {
            if (i!=j)
            {
                Produtorio *= ((xbarra-pontos[i].first)/(pontos[j].first-pontos[i].first));
            }
        }
        Pn+=Produtorio*pontos[j].second;
    }

    cout << "f(" << xbarra << ") = " << Pn << endl;

    return 0;
}
