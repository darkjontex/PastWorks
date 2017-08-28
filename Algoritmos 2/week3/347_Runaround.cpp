#include <cstdio>
#include <cstring>
using namespace std;
/* IURY DOS SANTOS*/

//PREPROCESSAMENTO
int sols[9999999];//LIMITE 

//PREPROCESSAMENTO
void preProcessamento () {
   for(int i = 9876543; i > 9; i--) {
      if (passThrough(i))
         sols[i] = i;
      else
         sols[i] = sols[i + 1];
   }
}

//PERCORRE TODOS OS N�S
bool passThrough(int n) {
   char lin[100];
   sprintf(lin, "%d", n);

   int t = strlen(lin);
   if (!check(lin, N)) return (false);

   int idx = 0, m[10] = { 0 };
   int cur = (int) (lin[0] - '0');

   for (int i = 0; i < N; i++) {
      idx = (idx + cur) % N; //VAI PARA O PR�XIMO ITEM     

      if (m[cur]){
		  return (false);
	  }	  
      m[cur] = 1;
      cur = (int) (lin[idx] - '0');
   }

   if (cur == (lin[0] - 48)){
	   return (true);
   }
   return (false);
}

//REALIZA A VERIFICA��O
bool check(char * nb, int N) {
   int m[10] = { 0 };

   for (int i=0; i < N; i++) {//LA�O PARA SABER SE JA FOI VISITADO
      if (m[nb[i]-'1']){
         return (false);
	  }
      m[nb[i]-'1'] = 1;
   }
   return (true);//CONFIRMA
}

//FUN��O DE CHAMADA DE M�TODOS
int main() {
   int numb, cases = 1;

   preProcessamento();

   while (1) {
      scanf("%d",&numb);
      if (!numb)
         break;
     printf("Case %d: %d\n", cases++, sols[numb]);
   }
   return (0);
}
