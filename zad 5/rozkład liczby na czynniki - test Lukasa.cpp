#include <cstdlib>
#include <iostream>


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


int main(int argc, char *argv[])
{
 
    int dzielnik, n, i;
    int tablica[20]={0};        //  tablica przechowujaca podzielniki
    int krotnosc[20]={0};       //  tablica przechowuj¹ca krotnoœci
    int temp=0;                 //  wartosæ tymczasowa
    int temp2=0;
    
    cout << "Podaj nieparzysta liczbe:\n";
    cin >> n;
    int mniejsza_o_1 = n-1;    //         wartoœæ n-1 do testu Lucasa
    int b;                     //         wartoœæ b do testu Lucasa
    temp = mniejsza_o_1;
    temp2 = mniejsza_o_1;
    dzielnik = 2;
    
    
    while(mniejsza_o_1>1)                                                //  póki wartosæ dla której szukamy podzielników jest wiêksza od 1
    {
                         for(i=0; i<20; i++)                             //  dla kolejnych elementów tablicy
                         {
                                  while(mniejsza_o_1 % dzielnik == 0)    //  jesli reszta z dzielenia modulo wynosi 0
                                  {                                      
                                   tablica[i]=dzielnik;                  //  to przypisz elementowi tablicy dzielnik
                                   mniejsza_o_1 = mniejsza_o_1/dzielnik; //  nastêpnie zmieñ na wartoœæ bêd¹c¹ wynikiem dzielenia przez dzielnik
                                  }
                         dzielnik = dzielnik + 1;                        //  zwiêksz dzielnik o 1
                         }
    }
               
    cout << "pierwsze podzielniki liczby mniejszej o 1 - czyli " << n-1 << ":" << endl;
    
    for(i=0; i<20; i++)                            //  wyœwietlaj wszystkie
    {                                              //  wartoœci tablicy
             if(tablica[i]!=0)                     //  nie bêd¹ce zerami
             {
             cout << tablica[i] << " ";
             }
    }
    
    cout << "\n";

    for(i=0; i<20; i++)
    {
             if(tablica[i]!=0)
             {
                              while((temp%tablica[i])==0)       //      tak d³ugo jak reszta z dzielenia wartoœci przez okreœlony podzielnik
                              {                                 //      równa siê 0, w odpowiadajacym mu elemencie tablicy 'krotnoœæ' naliczana
                              krotnosc[i] += 1;                 //      jest wartosæ jego powtórzeñ.
                              temp /= tablica[i];               //      Wartoœæ sukcesywnie jest dzielona przez podzielnik
                              }
             }          
    }
    
    cout << "krotnosci:" << endl;
    
    for(i=0; i<20; i++)
    {
             if(krotnosc[i]!=0)                                 //      wyœwietlanie krotnoœci
             {                                                  //      czyli ka¿dego nie zerowego
             cout << krotnosc[i] << " ";                        //      elementu tablicy krotnoœæ
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
