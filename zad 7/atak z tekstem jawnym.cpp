#include<iostream>
#include<string>
#include<cmath>

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

      return x;
}

using namespace std;

main()
{
      char litery[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
                'q','r','s','t','u','v','w','x','y','z'};
                
      string st1;
      string st2;
      
      cout << "Podaj tekst" << endl;
      cin >> st1;
      int i=0, j, k, t, wyznacznik, x;
 
      //ile_wektorow=int(ceil(st.length()/2));
 
      int tab1[2][2];
      int wynik[2][2];
      int tab2[2][2];
  
      while (st1[i])
      {
           st1[i]=tolower(st1[i]);
           i++;
      }
 
      k=0;
 
      for(i=0; i<2; ++i)
      {
              if(k == st1.length())
              break;
                              for(j=0; j<2; ++j)
                              {
                                              for(t=0; t<26; ++t)
                                              {
                                                               if(st1[k] == litery[t])
                                                               {
                                                                        tab1[i][j] = t;
                                                                        k++;
                                                                        break;
                                                               }
                                              }
                              }
      }
     
      cout << endl;
      cout << "Liczby odpowiadajace pierwszym 4 literom tekstu jawnego:\n";
      cout << endl;
     
      for(i=0; i<2; ++i)
      {
                                for(j=0; j<2; ++j)
                                {
                                                cout << tab1[i][j] << " ";
                                }
     
                                cout << "\n";
     }
     cout << endl;
     
//--------------------------------------------------------------------------------------------------------------------------------------------
     cout << "Podaj tekst zaszyfrowany" << endl;
     cin >> st2;
     
     while (st2[i])
      {
           st2[i]=tolower(st2[i]);
           i++;
      }
 
      k=0;
 
      for(i=0; i<2; ++i)
      {
              if(k == st2.length())
              break;
                              for(j=0; j<2; ++j)
                              {
                                              for(t=0; t<26; ++t)
                                              {
                                                               if(st2[k] == litery[t])
                                                               {
                                                                        tab2[i][j] = t;
                                                                        k++;
                                                                        break;
                                                               }
                                              }
                              }
      }
     
      cout << endl;
      cout << "Liczby odpowiadajace pierwszym 4 literom tekstu zaszyfrowanego:\n";
      cout << endl;
     
      for(i=0; i<2; ++i)
      {
                                for(j=0; j<2; ++j)
                                {
                                                cout << tab2[i][j] << " ";
                                }
     
                                cout << "\n";
     }
     
     cout << endl;
     
     int temp00 = tab1[0][0];
     int temp01 = tab1[0][1];
     int temp10 = tab1[1][0];
     int temp11 = tab1[1][1];
     
     wyznacznik = ( temp00 * temp11 ) - ( temp01 * temp10 );
     cout << "--------------------------------------------------------------------------------" << endl;
     
     cout << "Wyznacznik pierwszej macierzy: " << wyznacznik << endl;
     cout << endl;
     
     x = NWD(wyznacznik,26);
     cout << "x z euklidesa: " << x << endl;
     
     tab1[0][0] = temp11;              // zamiana na macierz dope³nieñ, wstawienie minusów
     tab1[0][1] = -temp01;             //        i transponowanie za jednym zamachem
     tab1[1][0] = -temp10;
     tab1[1][1] = temp00;
     
     //cout << tab1[0][1] << endl;
     //cout << tab1[1][0] << endl;
     
     cout << endl;
     
     cout << "Macierz odwrotna do macierzy tekstu jawnego:" << endl;
     
     cout << endl;
     
     for(i=0; i<2; ++i)
     {
                                for(j=0; j<2; ++j)
                                {
                                         if(tab1[i][j]<0)
                                         {
                                                         tab1[i][j] = tab1[i][j] * x;
                                                         while(tab1[i][j]<0)
                                                         {
                                                                tab1[i][j] = tab1[i][j] + 26;
                                                         }
                                                         
                                         }
                                         else
                                         {
                                                         tab1[i][j] = (tab1[i][j] * x)%26;
                                         }
                                         
                                         cout << tab1[i][j] << " ";
                                }
     
                                cout << "\n";
     }
     
     cout << endl;
     cout << "Szukany klucz ma postac:" << endl;
     cout << endl;
     
     for(i=0; i<2; ++i)
     {
                                for(j=0; j<2; ++j)
                                {
                                                if(i==0) // j olreœla kolumne
                                                {
                                                        wynik[i][j]=(tab1[0][0]*tab2[i][j]+tab1[0][1]*tab2[1][j])%26;
                                                }
                                                else // i=1
                                                {
                                                        wynik[i][j]=(tab1[1][0]*tab2[0][j]+tab1[1][1]*tab2[i][j])%26;
                                                }
                                                cout << wynik[i][j] << " ";
                                }
                                cout << "\n";
     }
     
     
      
      cout << endl;
system("pause");
return 0;
}
