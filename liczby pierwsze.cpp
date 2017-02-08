#include<iostream>
#include<string>

using namespace std;

main()
{
      int liczba, i,sumowanie=0;
      cin >> liczba;
      
      for(i=2; i<liczba; i++)
      {
               if(liczba%i!=0)
               {
                  sumowanie += 1;            
               }
      }
      
      
      if(sumowanie == liczba-2)
      {
                   cout << liczba << " jest liczba pierwsza." << endl;
      }
      else
      {
          cout << liczba << " nie jest liczba pierwsza." << endl;
      }
       
system("pause");
return 0;
}
