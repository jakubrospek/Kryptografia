#include <iostream>
#include <string>
#include <math.h>

using namespace std;

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

      return x;
}



 
int main()
{
    
int Wybor;
string st;
int szyfr[2][2]={1,1,1,1}, wyznacznik, najwiekszy_wspolny_dzielnik,x;
    
    cout << "Podaj klucz" << endl;
    cout << "Wartosc elementu 11:" << endl;
    cin >> szyfr[0][0];
    cout << "Wartosc elementu 12:" << endl;
    cin >> szyfr[1][0];
    cout << "Wartosc elementu 21:" << endl;
    cin >> szyfr[0][1];
    cout << "Wartosc elementu 22:" << endl;
    cin >> szyfr[1][1];
    
    cout << endl;
    
    wyznacznik = (szyfr[0][0] * szyfr[1][1]) - (szyfr[1][0] * szyfr[0][1]);
    cout <<"Wyznacznik wynosi: "<< wyznacznik << endl;
    
    cout << endl;
    
    najwiekszy_wspolny_dzielnik = NWD(wyznacznik,26);
    
    x = NWD2(wyznacznik,26);
    cout <<"x z roz. Euklidesa wynosi: "<< x << endl;
    
    if(najwiekszy_wspolny_dzielnik != 1)
    {
                                   cout << "Podany klucz jest bledny!" << endl;
                                   cout << endl;
                                   cout << "NWD(" << wyznacznik << "," << 26 << ") = " << najwiekszy_wspolny_dzielnik << " (jest rozny od 1)" << endl;
                                   cout << endl;
                                   system("pause");
                                   return 0;
    }
    else
    {
                                   cout << "NWD(" << wyznacznik << "," << 26 << ") = " << najwiekszy_wspolny_dzielnik << endl;
    }
    
    cout << endl;
    
    int temp00 = szyfr[0][0];
    int temp01 = szyfr[0][1];
    int temp10 = szyfr[1][0];
    int temp11 = szyfr[1][1];
    
    cout << "Co chcesz zrobic?" << endl;
    cout << endl;
    cout << "1 - Zaszyfrowac" << endl;
    cout << "2 - Odszyfrowac" << endl;
    cout << endl;
    cin>>Wybor;
    
    if(Wybor == 1)
    {
             cout << endl;
             cout << "Wybrales operacje szyfrowania" << endl;
    }
    else
    {
         temp00 = szyfr[1][1] * x;
         temp01 = -szyfr[1][0] * x;
         temp10 = -szyfr[0][1] * x;
         temp11 = szyfr[0][0] * x;
         
    
     
         szyfr[0][0] = temp00;
         while(temp10<0)
         {
                 temp10 = temp10 + 26;
         }
         szyfr[0][1] = temp10;
     
     
         while(temp01<0)
         {
                 temp01 = temp01 + 26;
         }
         szyfr[1][0] = temp01;
         szyfr[1][1] = temp11;
     
         cout << endl;
         cout << "Wybrales operacje deszyfrowania" << endl;
     }
 
 
     char litery[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
                'q','r','s','t','u','v','w','x','y','z'};
     
     cout << endl;
     cout << "Podaj tekst" << endl;
     cin >> st;
     int i=0, ile_wektorow, j, k, t;
 
     ile_wektorow=int(ceil(st.length()/2));
 
     int tab[ile_wektorow][2];
     int wynik[ile_wektorow][2];
  
     while (st[i])
     {
           st[i]=tolower(st[i]);
           i++;
     }
 
     k=0;
 
     for(i=0; i<ile_wektorow; ++i)
     {
              if(k == st.length())
              break;
                              for(j=0; j<2; ++j)
                              {
                                              for(t=0; t<26; ++t)
                                              {
                                                               if(st[k] == litery[t])
                                                               {
                                                                        tab[i][j] = t;
                                                                        k++;
                                                                        break;
                                                               }
                                              }
                              }
     }
     
     if(Wybor == 1)
     {
     cout << endl;
     cout << "Liczby odpowiadajace literom tekstu przed zaszyfrowaniem:" << endl;
     cout << endl;
     }
     else
     {
     cout << endl;
     cout << "Liczby odpowiadajace literom tekstu przed odszyfrowaniem:" << endl;
     cout << endl;
     }
     
     for(i=0; i<ile_wektorow; ++i)
     {
                                for(j=0; j<2; ++j)
                                {
                                                cout << tab[i][j] << " ";
                                }
     
                                cout << endl;
     }
     
     if(Wybor == 1)
     {
     cout << endl;
     cout << "Liczby odpowiadajace literom tekstu po zaszyfrowaniu:" << endl;
     cout << endl;
     }
     else
     {
     cout << endl;
     cout << "Liczby odpowiadajace literom tekstu po odszyfrowaniu:" << endl;
     cout << endl;
     }
     
     for(i=0; i<ile_wektorow; ++i)
     {
                                for(j=0; j<2; ++j)
                                {
                                                if(j==0)
                                                {
                                                        wynik[i][j]=(szyfr[0][0]*tab[i][j]+szyfr[0][1]*tab[i][1])%26;
                                                        while(wynik[i][j]<0)
                                                        {
                                                                            wynik[i][j] = wynik[i][j] + 26;
                                                        }
                                                }
                                                else
                                                {
                                                        wynik[i][j]=(szyfr[1][0]*tab[i][0]+szyfr[1][1]*tab[i][1])%26;
                                                        while(wynik[i][j]<0)
                                                        {
                                                                            wynik[i][j] = wynik[i][j] + 26;
                                                        }
                                                }
                                                cout << wynik[i][j] << " ";
                                }
                                cout << endl;
     }
     
     if(Wybor == 1)
     {
     cout << endl;
     cout << "Tekst zaszyfrowany" << endl;
     cout << endl;
     }
     else
     {
     cout << endl;
     cout << "Tekst odszyfrowany" << endl;
     cout << endl;
     }
      
     for(i=0; i<ile_wektorow; ++i)
     for(j=0; j<2; ++j)
     cout << litery[wynik[i][j]];
     cout << endl << endl;
 
system("pause");
return 0;
}
