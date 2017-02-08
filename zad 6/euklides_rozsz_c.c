//
// Rozszerzony algorytm Euklidesa
// www.algorytm.org
// (c)2006 Tomasz Lubinski
//


#include "stdio.h"

int main()
{
   int r, nwd, a, q, b;
   int x, x1, x2;
   int y, y1, y2;
   int nwd_a, nwd_b;

   //get all data
   printf("Podaj pierwsza liczbe\n");
   scanf("%d", &nwd_a);
   
   printf("Podaj druga liczbe\n");
   scanf("%d", &nwd_b);
   
   // a must be greater than b
   if (nwd_b > nwd_a)
   {
      nwd = nwd_b;
      nwd_b = nwd_a;
      nwd_a = nwd;
   }

   
   //initialize a and b
   a = nwd_a;
   b = nwd_b;

   //initialize r and nwd
   q = a/b;
   r = a - q*b;
   nwd = b;
   
   //initialize x and y
   x2 = 1;
   x1 = 0;
   y2 = 0;
   y1 = 1;
   x = 1;
   y = y2 - (q-1)*y1;
   
   while (r != 0)
   {
      a = b;
      b = r;
      
      x = x2 - q*x1;
      x2 = x1;
      x1 = x;

      y = y2 - q*y1;
      y2 = y1;
      y1 = y;      

      nwd = r;
      q = a/b;
      r = a - q*b; 
   }
   
   //present results
   printf("NWD(%d, %d) = %d = %d * %d + %d * %d\n", nwd_a, nwd_b, nwd, x, nwd_a, y, nwd_b);
   
   if (nwd == 1)
     printf("%d * %d mod %d = 1\n", nwd_b, y, nwd_a);
   
   system("pause");
   return 0;
}
