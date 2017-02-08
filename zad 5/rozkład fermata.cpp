#include<iostream>
#include<string>
#include<cmath>

using namespace std;

main()
{
      int q=0, krotnosc_dwojki=0,dwa=0, n;
      double x=0, y_kwadrat, podzielnik1, podzielnik2, pierwiastek_z_y_kwadrat, podloga_pirwiastka_z_y_kwadrat;
      cout << "Podaj liczbe" << endl;
      cin >> q;
      
      cout << endl;
      
      if(q % 2 == 0)
      {
           while(q % 2 == 0)
           {
              q /= 2;
              krotnosc_dwojki += 1;
           }
           n=q;
           dwa=2;
      }
      else
      {
          n=q;
          dwa=0;
      }
       cout << "n: " << n << endl;
       x = floor( pow(n,0.5) );
       cout << "x: " << x << endl;
       
       cout << endl;
       
       cout << "pierwiastek z n: " << pow(n,0.5) << endl;
       cout << "podloga z pierwiastka z n: " << floor(pow(n,0.5)) << endl;
       
       cout << endl;
       
       if( pow(n,0.5) == floor(pow(n,0.5)) )
       {
           if(2*x == 2)
           {
               cout << "dzielnik: " << 2*x << endl;
               cout << endl;
               cout << "krotnosc: " << krotnosc_dwojki << endl;
           }
           else
           {
               cout << "dzielnik: 2 " << x << endl;
               cout << endl;
               cout << "krotnosc: " << krotnosc_dwojki << " 2" << endl;
           }
     
       }
       else
       {
           x += 1;
     
           while( x <= ((n+1)/2) )
           {
                   y_kwadrat=0;
                   y_kwadrat=((x*x) - n);
                   
                   pierwiastek_z_y_kwadrat = pow(y_kwadrat,0.5);
                   podloga_pirwiastka_z_y_kwadrat = floor(pow(y_kwadrat,0.5));
                   
                   if( y_kwadrat > 0 && (podloga_pirwiastka_z_y_kwadrat == pierwiastek_z_y_kwadrat) )
                   {
                                podzielnik1 = x-pow(y_kwadrat,0.5);
                                podzielnik2 = pow(y_kwadrat,0.5)+x;
                                
                                if(dwa != 0)
                                {
                                 cout << "podzielniki: " << dwa << " " << podzielnik1 << " " << podzielnik2 << endl; 
                                     cout << endl;
                                     cout << "krotnosci:   " << krotnosc_dwojki << " " << 1 << " " << 1 << endl;
                                }
                                else
                                {
                                    cout << "podzielniki: " << podzielnik1 << " " << podzielnik2 << endl; 
                                    cout << endl;
                                    cout << "krotnosci:   " << 1 << " " << 1 << endl;
                                }
                                
                                podzielnik1=0;
                                podzielnik2=0;
                                break;

                   }
                   else
                   {
                       x += 1;
                   }
           }
       }

system("pause");
return 0;
}
