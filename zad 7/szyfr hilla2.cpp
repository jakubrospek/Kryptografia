#include<iostream>
#include<string>
#include<cmath>

using namespace std;

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

      return x;
}

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

main()
{
   char alfabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
                'q','r','s','t','u','v','w','x','y','z'};
                
   char tekst[1000],tekst2[1000];
   int i,j,k,l,m,n=0, rozmiar, wyznacznik, Klucz[4],Klucz2[4], liczby_pierwotnego_tekstu[1000], *liczby_po_przemnozeniu_przez_klucz, *liczby_po_odszyfrowaniu_przez_klucz2;
   int temp1,temp2,*szyfr, *liczby_tekstu_do_odszyfrowania;
   
   cout << 113 % 26 << endl;
   
   cout << "Podaj klucz(4 cyfry):" << "\n";
      
      for(i=0; i<4; i++)
      {
                     cin >> Klucz[i];
      }
      
      cout << endl;
      
      cout << "Klucz ma nastepujaca postac:" << "\n";
      
      cout << endl;
      
      for(i=0; i<4; i++)
      {
                     cout << Klucz[i] << "\n";
      }
      
      cout << endl;
      
      cout << "podaj tekst:" << endl;
      cin >> tekst;
      
      cout << endl;
      
      rozmiar = strlen(tekst);
      
      liczby_po_przemnozeniu_przez_klucz = (int*)malloc(rozmiar*sizeof(int));
      liczby_po_odszyfrowaniu_przez_klucz2 = (int*)malloc(rozmiar*sizeof(int));
      szyfr = (int*)malloc(rozmiar+1*sizeof(int));
      liczby_tekstu_do_odszyfrowania = (int*)malloc(rozmiar*sizeof(int));
      
      for(n=0; n<rozmiar; n++)
      {
               szyfr[n]=0;
      }
      
      for(k=0; k<26; k++)
      {
               for(l=0; l<rozmiar; l++)
               {
                                 if(alfabet[k]==tekst[l])
                                 {
                                 //   cout << k << endl;
                                 liczby_pierwotnego_tekstu[l] = k;
                                 }
               }
      }
      
      for(l=0; l<rozmiar; l++)
      {
               cout << liczby_pierwotnego_tekstu[l] << endl;
      }
      
      cout << endl;
      
      for(int l=0; l<rozmiar; l=l+2)
      {
              for(i=0; i<rozmiar; i=i+2)
              {
                       
                       liczby_po_przemnozeniu_przez_klucz[i] = (liczby_pierwotnego_tekstu[l] * Klucz[i]) + (liczby_pierwotnego_tekstu[l+1] * Klucz[i+1]);
                       liczby_po_przemnozeniu_przez_klucz[i] = liczby_po_przemnozeniu_przez_klucz[i] % 26;
                       cout << liczby_po_przemnozeniu_przez_klucz[i] << endl;
                       //cout << liczby_pierwotnego_tekstu[l] << endl;
                       //cout << liczby_pierwotnego_tekstu[l+1] << endl;
                       //dzia³anie na l; dzia³anie na l+1;
              }
      }

//--------------------------------------------------------------------------------------------------------------------------------------------     

cout << endl;
cout << "Tekst zaszyfrowany:" << endl;
cout << endl;

for(k=0; k<26; k++)
{
         for(int l=0; l<rozmiar; l=l+2)
         {
              for(i=0; i<rozmiar; i=i+2)
              {
                       
                       liczby_po_przemnozeniu_przez_klucz[i] = (liczby_pierwotnego_tekstu[l] * Klucz[i]) + (liczby_pierwotnego_tekstu[l+1] * Klucz[i+1]);
                       liczby_po_przemnozeniu_przez_klucz[i] = liczby_po_przemnozeniu_przez_klucz[i] % 26;
                       if(liczby_po_przemnozeniu_przez_klucz[i]==k)
                       {
                        cout << alfabet[k];
                        n=0;
                        szyfr[n] = k;
                             if(szyfr[n]==0)
                             {
                                            szyfr[n] = k;
                             }
                             else
                             {
                                 while(szyfr[n]!=0 && n<rozmiar)
                                 {
                                  n++;
                                 }
                                 szyfr[n] = k;
                                 
                             }
                       }
              }
         }
}

      
//--------------------------------------------------------------------------------------------------------------------------------------------      
      cout << endl;
      wyznacznik = (Klucz[0]*Klucz[3])-(Klucz[1]*Klucz[2]);
      
      cout << endl;
      cout << "Wyznacznik macierzy utworzonej z 'klucza' wynosi: " << wyznacznik << endl;
      cout << endl;
      cout << "NWD(" << wyznacznik << "," << 26 << ") = " << NWD3(wyznacznik,26) << endl;
      cout << endl;
      
      Klucz2[0] = Klucz[3];
      temp1 = -Klucz[1];
      while(temp1<0)
      {
                    temp1 = temp1 + 26;
      }
      Klucz2[1] = temp1;
      temp2 = -Klucz[2];
      while(temp2<0)
      {
                    temp2 = temp2 + 26;
      }
      Klucz2[2] = temp2;
      Klucz2[3] = Klucz[0];
      
      cout << "Odwrocony klucz:" << endl;
      for(i=0; i<4; i++)
      {
               cout << Klucz2[i] << endl;
      }
      
      cout << endl;
      
      for(n=1; n<rozmiar+1; n++)
      {
               liczby_tekstu_do_odszyfrowania[n-1] = szyfr[n];
      }
      
      cout << "Wartosci liczbowe tekstu do odszyfrowania:" << endl;
      
      for(n=0; n<rozmiar; n++)
      {
             cout << liczby_tekstu_do_odszyfrowania[n] << " ";
      }
      
      cout << endl;
      cout << "Wartosci liczbowe tekstu odszyfrowanego:" << endl;
      cout << endl;
     
      for(int l=0; l<rozmiar; l=l+2)
      {
              for(i=0; i<rozmiar; i=i+2)
              {
                       
                       liczby_po_odszyfrowaniu_przez_klucz2[i] = (liczby_tekstu_do_odszyfrowania[l] * Klucz2[i]) + (liczby_tekstu_do_odszyfrowania[l+1] * Klucz2[i+1]);
                       liczby_po_odszyfrowaniu_przez_klucz2[i] = liczby_po_odszyfrowaniu_przez_klucz2[i] % 26;
                       cout << liczby_po_odszyfrowaniu_przez_klucz2[i] << " ";
                       
              }
      }
      cout << endl;
      
      cout << "Przypisanie wartosciom liter:" << endl;

for(k=0; k<26; k++)
{      
      for(int l=0; l<rozmiar; l=l+2)
      {
              for(i=0; i<rozmiar; i=i+2)
              {
                       
                       liczby_po_odszyfrowaniu_przez_klucz2[i] = (liczby_tekstu_do_odszyfrowania[l] * Klucz2[i]) + (liczby_tekstu_do_odszyfrowania[l+1] * Klucz2[i+1]);
                       liczby_po_odszyfrowaniu_przez_klucz2[i] = liczby_po_odszyfrowaniu_przez_klucz2[i] % 26;
                       //cout << liczby_po_odszyfrowaniu_przez_klucz2[i] << endl;
                       if(liczby_po_odszyfrowaniu_przez_klucz2[i]==k)
                       {
                        cout << alfabet[k] << endl;
                       }
                       
              }
      }
}
      
      
      cout << endl;
system("pause");
return 0;
}

