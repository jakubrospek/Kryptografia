#include<stdio.h>
#include<stdlib.h>

int main()
{
      int liczba, i,sumowanie=0;
      scanf("%d", &liczba);
      
      for(i=2; i<liczba; i++)
      {
               if(liczba%i!=0)
               {
                  sumowanie += 1;            
               }
      }
      
      
      if(sumowanie == liczba-2)
      {
                   printf("%d jest liczba pierwsza.\n",liczba);
      }
      else
      {
          printf("%d nie jest liczba pierwsza.",liczba);
      }
       
system("pause");
return 0;
}
