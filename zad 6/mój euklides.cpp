#include<iostream>
#include<cmath>
#include<string>

using namespace std;

main()
{
      int a, b, temp_a, temp_b, x=1, y=0, i=0, j=1, reszta, zaokraglenie=0, i2, j2;
      
      cout << "Podaj wartosc a:" << "\n";
      cin >> a;
      cout << "Podaj wartosc b:" << "\n";
      cin >> b;
      
      cout << "\n";
      temp_a = a;
      temp_b = b;
      
      cout << " r " << "   " << " q " << "    " << " x " << "   " << " y" << "\n";
      cout << "----------------------------------" << "\n";
      cout << temp_a << "    " << zaokraglenie << "     " << x << "      " << y << "\n";
      
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

      cout << a << "     " << zaokraglenie << "     " << x << "     " << y << "\n";                     
      }
      
      cout << "----------------------------------" << "\n";
      cout << "\n";
      cout << "NWD(" << temp_a << "," << temp_b << ") = x * a + y * b = " << ((x*temp_a) + (y*temp_b)) << "\n";
      cout << "\n";
      
      cout << "Gdzie:" << "\n";
      cout << "\n";
      cout << "x = " << x << "\n";
      cout << "a = " << temp_a << "\n";
      cout << "y = " << y << "\n";
      cout << "b = " << temp_b << "\n";
      cout << "\n";
      
system("pause");
return 0;
}
