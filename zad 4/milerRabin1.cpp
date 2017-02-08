#include<iostream>
#include<string>
#include<cmath>

using namespace std;


int power_modulo_fast(int a, int b, int m)  //  funkcja obliczaj¹ca resztê z dzielenia du¿ej potêgi przez modulo m.
{
       int i;
       int result = 1;
       long int x = a%m;
 
       for (i=1; i<=b; i<<=1)
       {
       x %= m;
       if ((b&i) != 0)
       {
       result *= x;
       result %= m;
       }
       x *= x;
       }
 
       return result;
}

main()
{
      int n, mniejsza_o_1=0, b, nowa_postac, i=1, j, pierwsza_reszta, potega, temp, zastepczo, licznik=0;
      double potega_dwojki=0, krotnosc_dwojki=0;
      int *tablica;
 
      cout << "Podaj liczbe nieparzysta:" << endl;
      cin >> n;
 
      mniejsza_o_1 = n - 1;
      zastepczo = n - 1;
 
      cout << "Podaj wartosc b z zakresu od 1 do " << n - 1 << endl;
      cin >> b;
 
      while( mniejsza_o_1 % 2 == 0)
      {
             mniejsza_o_1 /= 2;
             krotnosc_dwojki += 1;
      }
      nowa_postac = mniejsza_o_1;
      
      cout << endl;
      
      cout << "krotnosc dwojki: " << krotnosc_dwojki << endl;
      cout << "wartosc niepodzielna: " << nowa_postac << endl;
      cout << endl;
      
      tablica = (int*)malloc((krotnosc_dwojki)*sizeof(int));
      
      potega_dwojki = pow(2,krotnosc_dwojki);

               while(i <= potega_dwojki - 1)
               {
                       
                       for(j=0; j < krotnosc_dwojki; j++)
                       {
                                i *= 2;
                                tablica[j]=i;
                       }
                       //cout << i << endl; 
               }
               
               
               pierwsza_reszta = power_modulo_fast(b, nowa_postac, n);
               

               
               if(pierwsza_reszta == (1 % n))
               {
                                  cout << "liczba " << n << " moze byc liczba pierwsza" << endl;
               }
               else
               {
               
                   for(j=0; j < krotnosc_dwojki; j++)
                   {
                            
                            temp = 0;
                            potega = 0;
                            temp = tablica[j];
                            potega = temp * nowa_postac;
                            //cout << "potega " << power_modulo_fast(b, potega, n) << endl;
                            
                            if(power_modulo_fast(b, potega, n) == (zastepczo))
                            {
                             cout << "liczba " << n << " moze byc liczba pierwsza" << endl;
                             licznik += 1;
                            }
                            else
                            {
                                continue;
                            }
                   }
                   if(licznik == 0)
                   {
                    cout << "liczba " << n << " jest liczba zlozona" << endl;
                   }
               }
      
system("pause");
return 0;
}
