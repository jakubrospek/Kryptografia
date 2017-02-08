#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int power_modulo_fast(int a, int b, int m)  //  funkcja obliczaj¹ca resztê z dzielenia du¿ej potêgi przez modulo m.
{
       int i;
       int result = 1;
       while (b > 0)
       {
             if(b % 2 == 1)
                  result = (result * a) % m;
                  b = b >> 1;
                  a = (a*a) % m;
             
       }
 
       return result;
}
/*
long long int potega(long long int n)
{
    long long int j,p=1;
    for(j=0; j<n; j++)
    {
    p*=2;
    }
    return p;
}
*/

int potegowanie_binarne(int b, int n)
{
    
    int i,x,z; 

x=1; 
 
z=b; 
i=n; 

while (i>0) 
{ 
if (i%2==1) 
x=x*z; 

z=z*z; 
i=(i/2); 
} 

return x;
}

main()
{
      
      unsigned szukane_s, i; 
      unsigned Mp=0, p, S0 = 4, S;
      cout << "Podaj indeks dla liczby Mersenne'a:" << endl;
      cin >> p;
      
      Mp = potegowanie_binarne(2,p) - 1;
      cout << endl;
      cout << "Rozpatrywana liczba Mersenne'a to: " << Mp << endl;
      szukane_s = p - 2;
      cout << endl;
      
      for(i=0; i<szukane_s; i++)
      {
               S0 = power_modulo_fast(S0, 1, Mp);
               S0 = power_modulo_fast( S0, 2, Mp ) - power_modulo_fast(2, 1, Mp);
      }
      

      
      if(S0 == 0 || szukane_s == 0)
      {
            cout << "Liczba " << Mp << " jest pierwsza" << endl;
      }
      else
      {
          cout << "Liczba " << Mp << " jest zlozona" << endl;
      }
      cout << endl;
      
      
system("pause");
return 0;
}
