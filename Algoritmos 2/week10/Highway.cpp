// UVA Problema 10147 - Highways
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1088
//USANDO C++ COMO TREINAMENTO PARA O MERCADO DE TRABALHO Com VBS
#include <iostream>
#include <math.h>

using namespace std;

#define INF 1000000000
#define MAXN 755

int n, x[MAXN], y[MAXN], CorredorSpy[MAXN];
double a[MAXN][MAXN];

///CALCULO A DISTÂNCIA
void Distancia() {
    for (int i=1;i<=n;i++) {
	a[i][i] = 0;
	for (int j=i+1;j<=n;j++)
		a[i][j] = a[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
}

///Tentativas de Entrada com suas distâncias
void Enter() {
    int l,r,k,u;
    cin >> n;
    for (k=1;k<=n;k++) {
        cin >> x[k] >> y[k];
    }
    Distancia();
    cin >> r;
    for (k=1;k<=r;k++) {
        cin >> u >> l;
        a[u][l] = a[l][u] = -1.0;
    }
}

///Checagem por Primos
void Primo() {
    bool Libera[n+2];
    double d[n+2], min;
    int k, u, l;
    for (k=1;k<=n;k++) {
        Libera[k] = true; d[k] = INF;
    }
    d[1] = 0;
    for (k=1;k<=n;k++) {
		u = 0; min = INF;
		for (l=1;l<=n;l++)
		if (Libera[l] && d[l]<min) {
			u = l; min = d[l];
		}
		Libera[u] = false;
		for (l=1;l<=n;l++)
		if (Libera[l] && d[l]>a[u][l]) {
			d[l] = a[u][l];
			CorredorSpy[l] = u;
		}
    }
}
///PEGO OS VALORES QUE BUSCO E IMPRIMO
void Resultado() {
    bool non = true;
    for (int u=2;u<=n;u++)
        if (a[u][CorredorSpy[u]]>=0) {
            cout << u << " " << CorredorSpy[u] << endl;
            non = false;
        }
    if (non) cout << "Sem novas highways Necessarias" << endl;
}

///APENAS CHAMO AS FUNÇÕES NA MAIN
main() {
int caso;
cin >> caso;
while (caso--) {
	Enter();
	Primo();
	Resultado();
	if (caso) cout << endl;
}
}