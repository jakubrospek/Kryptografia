#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
 
    int dzielnik, n, i;
    int tablica[20]={0};
    int krotnosc[20]={0};
    int temp=0;
    cout << "Podaj liczbe:\n";
    cin >> n;
    temp = n;
    dzielnik = 2;
    
    while(n>1)
    {
              for(i=0; i<20; i++)
              {
                       while(n % dzielnik == 0)
                       {
                               tablica[i]=dzielnik;
                               n = n/dzielnik;
                       }
                       dzielnik = dzielnik + 1;                  
              }
    }
               
    cout << "pierwsze podzielniki:" << endl;
    
    for(i=0; i<20; i++)
    {
             if(tablica[i]!=0)
             {
                              cout << tablica[i] << " ";
             }
    }
    
    cout << "\n";

    for(i=0; i<20; i++)
    {
             if(tablica[i]!=0)
             {
                              while((temp%tablica[i])==0)
                              {
                                                         krotnosc[i] += 1;
                                                         temp /= tablica[i];
                              }
             }          
    }
    
    cout << "krotnosci:" << endl;
    
    for(i=0; i<20; i++)
    {
             if(krotnosc[i]!=0)
             {
                               cout << krotnosc[i] << " ";
             }    
    }
    
    cout << endl << endl;
     
    

    system("pause");
    return 0;
}
