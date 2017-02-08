#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int main()
{

	int liczba, i, j, temp=0, temp2=0;
	int *tablica, *tablica2;
      
	cout << "Podaj liczbe: ";
	cin >> liczba;
      
	tablica = (int*)malloc((liczba+1)*sizeof(int));
	tablica2 = (int*)malloc((liczba+1)*sizeof(int));
	
      
	for(i=1; i<=liczba; i++)
	{
		tablica[i] = i;
	}
      
	for(j=1; j<=liczba; j++)
	{
		tablica2[j] = j;
	}
      
	for(j=2; j<=liczba; j++)
	{
		for(i=2; i<=liczba; i++)
		{
			temp2 = tablica2[j];
			temp = tablica[i];
			if(temp % temp2 == 0 && temp != temp2)
			{
				tablica[i] = 0;
			}
			else
			{
				tablica[i] = i;
			}
		}
	}
      

	      cout << "Liczby pierwsze z zakresu od 2 do " << liczba << ":" << endl;

      
	for(i=2; i<=liczba; i++)
	{         
		
			if(tablica[i] != 0)
			{
				cout << tablica[i] << "\n";
			}
	}


	cout << "\n";
system("pause");
return 0;
}
