#include <cstdlib>
#include <iostream>


using namespace std;

int power_modulo_fast(int a, int b, int m)  //  funkcja obliczaj�ca reszt� z dzielenia du�ej pot�gi przez modulo m.
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


int main(int argc, char *argv[])
{
 
    int dzielnik, n, i;
    int tablica[20]={0};        //  tablica przechowujaca podzielniki
    int krotnosc[20]={0};       //  tablica przechowuj�ca krotno�ci
    int temp=0;                 //  wartos� tymczasowa
    int temp2=0;
    
    cout << "Podaj nieparzysta liczbe:\n";
    cin >> n;
    int mniejsza_o_1 = n-1;    //         warto�� n-1 do testu Lucasa
    int b;                     //         warto�� b do testu Lucasa
    temp = mniejsza_o_1;
    temp2 = mniejsza_o_1;
    dzielnik = 2;
    
    
    while(mniejsza_o_1>1)                                                //  p�ki wartos� dla kt�rej szukamy podzielnik�w jest wi�ksza od 1
    {
                         for(i=0; i<20; i++)                             //  dla kolejnych element�w tablicy
                         {
                                  while(mniejsza_o_1 % dzielnik == 0)    //  jesli reszta z dzielenia modulo wynosi 0
                                  {                                      
                                   tablica[i]=dzielnik;                  //  to przypisz elementowi tablicy dzielnik
                                   mniejsza_o_1 = mniejsza_o_1/dzielnik; //  nast�pnie zmie� na warto�� b�d�c� wynikiem dzielenia przez dzielnik
                                  }
                         dzielnik = dzielnik + 1;                        //  zwi�ksz dzielnik o 1
                         }
    }
               
    cout << "pierwsze podzielniki liczby mniejszej o 1 - czyli " << n-1 << ":" << endl;
    
    for(i=0; i<20; i++)                            //  wy�wietlaj wszystkie
    {                                              //  warto�ci tablicy
             if(tablica[i]!=0)                     //  nie b�d�ce zerami
             {
             cout << tablica[i] << " ";
             }
    }
    
    cout << "\n";

    for(i=0; i<20; i++)
    {
             if(tablica[i]!=0)
             {
                              while((temp%tablica[i])==0)       //      tak d�ugo jak reszta z dzielenia warto�ci przez okre�lony podzielnik
                              {                                 //      r�wna si� 0, w odpowiadajacym mu elemencie tablicy 'krotno��' naliczana
                              krotnosc[i] += 1;                 //      jest wartos� jego powt�rze�.
                              temp /= tablica[i];               //      Warto�� sukcesywnie jest dzielona przez podzielnik
                              }
             }          
    }
    
    cout << "krotnosci:" << endl;
    
    for(i=0; i<20; i++)
    {
             if(krotnosc[i]!=0)                                 //      wy�wietlanie krotno�ci
             {                                                  //      czyli ka�dego nie zerowego
             cout << krotnosc[i] << " ";                        //      elementu tablicy krotno��
             }    
    }
    
    cout << endl << endl;
    
    cout << "Test Lucasa:" << endl;
    cout << "Podaj b:" << endl;
    cin >> b;
    
    if(power_modulo_fast(b, temp2, n)-power_modulo_fast(1, 1, n) == 0)
    {
                            for(i=0; i<20; i++)
                            {
                                     if(tablica[i]!=0)
                                     {
                                     cout << "dla pn rownego: " << tablica[i] << "\n\n";
                                                   /*------------------------------------------*/
                                                    if(power_modulo_fast(b, ((n-1)/tablica[i]), n)-power_modulo_fast(1, 1, n) != 0)
                                                    {
                                                    cout << n << " jest liczba pierwsza" << endl;
                                                    }
                                                    else
                                                    {
                                                    cout << n << " nie jest liczba pierwsza" << endl;
                                                    }
                                                    /*------------------------------------------*/
                                                    system("pause");
                                                    cout << endl;
                                     }
                            }
    }
    
    else
    {
        cout << n << " nie jest liczba pierwsza" << endl;
    }
    
    system("pause");
    return 0;
}
