#include<iostream>
#include<string>

using namespace std;

main()
{
      int i, j, k, l, m, n, o=0, p=0, ilosc=0, dzielnik=0, rozmiar=0, k1=0, k2=0, k3=0, k4=0, wiersz=0, kolumna=0;
      char alfabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
                'q','r','s','t','u','v','w','x','y','z'};
      char **tekst;
      int **liczby_pierwotnego_tekstu, Klucz1[2], Klucz2[2], *liczby_tekstu_wyjscowego, **macierz;
      
      cout << "Podaj klucz(4 cyfry):" << "\n";
      
      for(i=0; i<2; i++)
      {
                     cin >> Klucz1[i];
      }
      
      for(j=0; j<2; j++)
      {
               cin >> Klucz2[j];
      }
      
      cout << "Klucz ma nastepujaca postac:" << "\n";
      
      for(i=0; i<2; i++)
      {
                     cout << Klucz1[i] << "\n";
      }
      
      for(j=0; j<2; j++)
      {
               cout << Klucz2[j] << "\n";
      }
      
      k1 = Klucz1[0];
      k2 = Klucz1[1];
      k3 = Klucz2[0];
      k4 = Klucz2[1];
      
      cout << "\n";
      
      //Klucz = (int*)malloc(ilosc*sizeof(int));
      
      
      
      cout << "Podaj ilosc liter w tekscie:" << "\n";
      cin >> ilosc;
      
      //tekst = (char*)malloc(ilosc*sizeof(char));
      //liczby_pierwotnego_tekstu = (int*)malloc(ilosc*sizeof(int));
      
      dzielnik = ilosc/2;
      rozmiar = ilosc/dzielnik;
      
      wiersz = dzielnik;
      kolumna = rozmiar;
      
      
      tekst = (char**)malloc(wiersz*sizeof(char*));
      for(o=0; o<wiersz; o++)
      {
               tekst[o] = (char*)malloc(kolumna*sizeof(char));
      }
      
      liczby_pierwotnego_tekstu = (int**)malloc(wiersz*sizeof(int*));
      for(o=0; o<wiersz; o++)
      {
               liczby_pierwotnego_tekstu[o] = (int*)malloc(kolumna*sizeof(int));
      }
      
      
      cout << "podaj tekst:" << endl;
      
      
      for(o=0; o<wiersz; o++)
      {
                        for(p=0; p<kolumna; p++)
                        {
                                scanf("%c", &tekst[o][p]); 
                        }
      }
      
      //cout << "Wpisany tekst: " << tekst[0][0] << endl;
      
      for(o=0; o<wiersz; o++)
      {
                        for(p=0; p<kolumna; p++)
                        {
                                liczby_pierwotnego_tekstu[o][p]=0;
                        }
      }
      
      
      for(k=0; k<26; k++)
      {
               //for(l=0; l<ilosc; l++)
               //{
               for(o=0; o<wiersz; o++)
               {
                        for(p=0; p<kolumna; p++)
                        {
                                 if(alfabet[k]==tekst[o][p])
                                 {
                                 //   cout << k << endl;
                                 liczby_pierwotnego_tekstu[o][p] = k;
                                 }
                                 
                        }
               }
      }
                        
               //}
               
      
      
      cout << endl;
      
      //cout << liczby_pierwotnego_tekstu[1][1] << endl;
      
      for(o=0; o<wiersz; o++)
      {
                        for(p=0; p<kolumna; p++)
                        {
                                cout << liczby_pierwotnego_tekstu[o][p] << endl;
                        }
      }
      
      cout << endl;

      /*
      //liczby_tekstu_wyjscowego = (int*)malloc(ilosc*sizeof(int));
      macierz = (int**)malloc(wiersz*sizeof(int*));
      for(o=0; o<wiersz; o++)
      macierz[o] = (int*)malloc(kolumna*sizeof(int));
      
      for(o=0; o<wiersz; o++)
      {
                        for(p=0; p<kolumna; p++)
                        {
                                 macierz[o][p] = 0;
                        }
      }
      
               for(o=0; o<wiersz; o++)
               {
                        for(m=0; m<ilosc; m++)
                        
                                 for(p=0; p<kolumna; p++)
                                 {
                                          macierz[o][p] = liczby_pierwotnego_tekstu[m];
                                 }
                        
               }
      
      
      for(o=0; o<wiersz; o++)
               {
                        for(p=0; p<kolumna; p++)
                        {
                                cout << macierz[o][p] << endl;
                        }
               }
      
      //or(n=0; n<ilosc; n++)
      //{
      //         for(o=0; o<wiersz; o++)
      //}
      
*/      
system("pause");
return 0;
}
