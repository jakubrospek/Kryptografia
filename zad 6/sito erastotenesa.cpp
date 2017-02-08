#include<iostream>
#include<string>
#include<stdlib.h>
#include<cmath>

using namespace std;
//-------------------------------------------------------------------------------------------------------------------------------------------

long long NWD(long long a, long long b)
{
    long long temp_a, temp_b, x=1, y=0, i=0, j=1, reszta, zaokraglenie=0, i2, j2;
      

      temp_a = a;
      temp_b = b;
      
      while(b != 0)
      {
              reszta = a % b;
              zaokraglenie = lrint(floor(a/b));   // funkcja zaokr¹gla i zwraca typ ca³kowity long int
              a = b;
              b = reszta;
              i2 = x - (zaokraglenie * i);
              j2 = y - (zaokraglenie * j);
              x = i;
              y = j;
              i = i2;
              j = j2;                  
      }

      return ((x*temp_a) + (y*temp_b));
}

long long NWD2(long long a, long long b)
{
    long long temp_a, temp_b, x=1, y=0, i=0, j=1, reszta, zaokraglenie=0, i2, j2;
      

      temp_a = a;
      temp_b = b;
      
      cout << " r " << "   " << " q " << "    " << " x " << "   " << " y" << "\n";
      cout << "----------------------------------" << "\n";
      cout << temp_a << "    " << zaokraglenie << "     " << x << "      " << y << "\n";
      
      while(b != 0)
      {
              reszta = a % b;
              zaokraglenie = lrint(floor(a/b));   // funkcja zaokr¹gla i zwraca typ ca³kowity long int
              a = b;
              b = reszta;
              i2 = x - (zaokraglenie * i);
              j2 = y - (zaokraglenie * j);
              x = i;
              y = j;
              i = i2;
              j = j2;

      cout << a << "     " << zaokraglenie << "     " << x << "     " << y << "\n";                     
      }
      
      cout << "----------------------------------" << "\n";
      cout << "\n";
      cout << "NWD(" << temp_a << "," << temp_b << ") = x * a + y * b = " << ((x*temp_a) + (y*temp_b)) << "\n";
      cout << "\n";
      
      cout << "Gdzie:" << "\n";
      cout << "\n";
      cout << "x = " << x << "\n";
      cout << "a = " << temp_a << "\n";
      cout << "y = " << y << "\n";
      cout << "b = " << temp_b << "\n";
      cout << "\n";
      


      return y;
}

long long NWD3(long long a, long long b)
{
    long long temp_a, temp_b, x=1, y=0, i=0, j=1, reszta, zaokraglenie=0, i2, j2;
      

      temp_a = a;
      temp_b = b;
      
      while(b != 0)
      {
              reszta = a % b;
              zaokraglenie = lrint(floor(a/b));   // funkcja zaokr¹gla i zwraca typ ca³kowity long int
              a = b;
              b = reszta;
              i2 = x - (zaokraglenie * i);
              j2 = y - (zaokraglenie * j);
              x = i;
              y = j;
              i = i2;
              j = j2;                   
      }

      return y;
}

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

//-------------------------------------------------------------------------------------------------------------------------------------------
main()
{

      long long liczba, i, j, l, temp=0, temp2=0, losuj=0, P=0, Q=0, N=0, gamma_N=0, E=0, D=0, rozm_tekstu=0, m=0, c=0, odszyfrowana=0;
      int *tablica, *tablica2, *L_pierwsze;
      
      cout << "Podaj liczbe:" << "\n";
      cin >> liczba;
      
      tablica = (int*)malloc((liczba+1)*sizeof(int));
      tablica2 = (int*)malloc((liczba+1)*sizeof(int));
      
      for(i=1; i<=liczba; i++)
      {
              tablica[i] = i;
      }
      
      for(j=1; j<=liczba; j++)
      {
              tablica2[j] = j;
      }
      
      
      
      for(j=2; j<=liczba; j++)
      {
               for(i=2; i<=liczba; i++)
               {
                        temp2 = tablica2[j];
                        temp = tablica[i];
                        if(temp % temp2 == 0 && temp != temp2)
                        {
                                      tablica[i] = 0;
                        }
                        else
                        {
                            tablica[i] = i;
                        }
               }
      }
      
      cout << "\n";
      cout << "Liczby pierwsze z zakresu od 2 do " << liczba << ":" << "\n";
      cout << "\n";
      
      L_pierwsze = (int*)malloc(2*sizeof(int));
      
      for(i=2; i<=liczba; i++)
      {
               if(tablica[i] != 0)
               {
               cout << tablica[i] << "\n";
               }
               
      }
      cout << "\n";

      cout << "Losowanie 2 liczb pierwszych:" << "\n";
      cout << "\n";
      
      if(liczba < 100)                                              //losowanie 2 du¿ych liczb pierwszych z okreslonego zakresu
      {
                for(l=0; l<2; l++)
                {
                         losuj = rand() % liczba + 2;
                         start:
                         if(tablica[losuj]!=0)
                         {
                                              L_pierwsze[l] = tablica[losuj];
                         }
                         else
                         {
                                              losuj = rand() % liczba + 2;
                                              goto start;
                         }
                }
      }
      else
      {
                for(l=0; l<2; l++)
                {
                         losuj = rand() % liczba + 2;
                         start2:
                         if(tablica[losuj]!=0 && (tablica[losuj] > liczba/2))
                         {
                                              L_pierwsze[l] = tablica[losuj];
                         }
                         else
                         {
                                              losuj = rand() % liczba + 2;
                                              goto start2;
                         }
                }
      }
      
      P = L_pierwsze[0];
      Q = L_pierwsze[1];
      cout << "Wylosowana liczba P: " << P << "\n";
      cout << "Wylosowana liczba Q: " << Q << "\n";
      cout << "\n";
      
      N = P * Q;
      gamma_N = (P-1)*(Q-1);
      
      cout << "Wyznaczone N: " << N << "\n";
      cout << "Wyznaczone phi_N: " << gamma_N << "\n";
      cout << "\n";
      
      E = rand() % gamma_N + 1;
      
      while(NWD(gamma_N,E)!=1)
      {
                              E = 0;
                              E = rand() % gamma_N + 1;             
      }
      
      cout << "Wylosowana liczba E: " << E << "\n";
      cout << "\n";
      cout << "Wyznaczanie liczby D:" << "\n";
      cout << "\n";
      cout << "Liczba D wynosi: " << NWD2(gamma_N,E) << "\n";
      D = NWD3(gamma_N,E);
      cout << "\n";
      
      cout << "Klucz publiczny: (N,E) = (" << N << "," << E << ")" << "\n";
      cout << "Klucz prywatny: (N,D) = (" << N << "," << D << ")" << "\n";
      cout << "\n";
      
      cout << "Podaj liczbe do zaszyfrowania:" << "\n";
      cin >> m;
      cout << "\n";
      
      c = power_modulo_fast(m, E, N);
      
      cout << "Liczba po zaszyfrowaniu: " << c << "\n";
      cout << "\n";
      
      odszyfrowana = power_modulo_fast(c, D, N);
      
      cout << "Liczba odszyfrowana: " << odszyfrowana << "\n";
      
cout << "\n";
system("pause");
return 0;
}
