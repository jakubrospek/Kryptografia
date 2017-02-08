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

main()
{
      int n, mniejsza_o_1=0, b=0, granica_zakresu, nowa_postac, i=1, j, k, pierwsza_reszta, potega, temp, zastepczo, licznik=0, licznik2=0;
      double potega_dwojki=0, krotnosc_dwojki=0, prawdopodobienstwo;
      int *tablica;
 
      cout << "Podaj liczbe nieparzysta:" << endl;
      cin >> n;
 
      mniejsza_o_1 = n - 1;
      zastepczo = n - 1;
      granica_zakresu = n - 2;
      
      cout << "Testy dla losowych wartosci z zakresu od 1 do " << n - 2 << endl;
      //cout << "Podaj wartosc b z zakresu od 1 do " << n - 2 << endl;
      //cin >> b;
      
for( k=1; k<=10; k++)
{

b = rand() % (granica_zakresu) + 1;

cout << endl;
cout << "-------------------------------------------------------------" << endl;
cout << "Test dla b rownego: " << b << endl;
 
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
                                  licznik2 += 1;
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
                             licznik2 += 1;
                            }
                            else
                            {
                                continue;
                            }
                   }
                   if(licznik == 0)
                   {
                    cout << "liczba " << n << " moze byc liczba zlozona" << endl;
                   }
               }
}

prawdopodobienstwo = 1 - (pow(0.25,10));

cout << "--------------------------------------------------------------------------------" << endl;
cout << "Liczba testow pozytywnych: " << licznik2 << "/10" << endl;

if(licznik2 >= 0.25*10)
{
cout << endl;
cout << "Liczba " << n << " jest liczba silnie pseudopierwsza." << endl;
cout << endl;
cout << "Prawdopodobienstwo wynosi: " << prawdopodobienstwo * 100 << "%" << endl;
cout << endl;

}
else
{

cout << endl;
cout << "Liczba " << n << " nie jest liczba silnie pseudopierwsza." << endl;
cout << endl;

}
system("pause");
return 0;
}
