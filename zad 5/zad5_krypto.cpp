#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
int fermat(){
	
	
}
int main(int argc, char *argv[])
{
 
    int dzielnik, n, i,p;
    int tablica[20]={0};
    int krotnosc[20]={0};
    int temp=0;
    cout << "Podaj liczbe:\n";
    cin >> n;
    p = n;
    temp = n;
    dzielnik = 2;
    int size = 0;
    while(n>1)
    {
     for(i=0; i<20; i++)
     {
      while(n % dzielnik == 0)
      {
       tablica[i]=dzielnik;
       n = n/dzielnik;
       }
       dzielnik = dzielnik + 1;                  
     }
    }
               
    cout << "pierwsze podzielniki:" << endl;
    
    for(i=0; i<20; i++)
    {
     if(tablica[i]!=0)
     {
      cout << tablica[i] << " ";
      size++;
     }
    }
    
    cout << "\n";

    for(i=0; i<20; i++)
    {
     if(tablica[i]!=0)
     {
      while((temp%tablica[i])==0)
      {
       krotnosc[i] += 1;
       temp /= tablica[i];
      }
     }          
    }
    
    cout << "krotnosci:" << endl;
    
    for(i=0; i<20; i++)
    {
     if(krotnosc[i]!=0)
     {
      cout << krotnosc[i] << " ";
     }    
    }
    
    cout << endl << endl;
    cout<<"Test lucasa \n";
    cout<<"podaj b \n";
    int b;
    cin>>b;
    long long int s = pow(b,p-1);
    long long int s1;
    int wyj;
    int tmp;
    wyj = 0;
    if(s%p == 1){
    	for(i = 0;i<20;i++){
    		if(tablica[i] != 0){
    			tmp = tablica[i];
    			tmp =ceil((float)(p-1)/(float)temp);
    			s1 = pow(b,tmp);
    			if(s1%p != 1){
    				cout<<"Liczba pierwsza\n";
    			}
    		}
    		
    	}
    	if(wyj == 1){
    		cout<<"Liczba zlozona\n";
    	}
    }else{
    	cout<<"liczba zlozona\n";
    }
    

    system("pause");
    return 0;
}
