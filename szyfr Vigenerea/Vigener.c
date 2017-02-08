#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    
int opcja;
    
printf("Wybierz opcje: (1 lub 2)\n\n1. zaszyfruj\n2. odszyfruj\n\n");
scanf("%d", &opcja);
printf("\n");
switch(opcja)
{
case 1:
{
char kod[3000];     // tablica do której pobieram tekst z pliku 

	FILE *wi;  // plik z wiadomoœci¹ 
    FILE *fp;  // plik wyjsciowy, z zakodowan¹ wiadomoœci¹.
	
	if ((wi=fopen("wiadomosc.txt", "r"))== NULL) {
    printf ("Nie moge otworzyc wiadomosc.txt .\n");
    exit(1);
    }
fscanf (wi, "%s", kod);   // pobieranie tekstu z pliku 
fclose (wi);
	
int i, j;
j=0;

char haslo[200];
int haslo2[200];


int kod2[3000];     // zmienna pomocnicza do zamiany liter na ASCI
int szyfr[3000];    // zaszyfrowana wiadomosc

/*
printf("PODAJ WIADOMOSC DO ZAKODOWANIA, WIELKIMI LITERAMI, BEZ SPACJI, ZNAKOW I CYFR\n");	
scanf("%s", kod); */       // wpisywa³em tekst do zakodowania rêcznie zanim pobiera³em go z pliku

printf("PODAJ HASLO WIELKIMI LITERAMI, BEZ SPACJI, ZNAKOW I CYFR\n");	
	scanf("%s", haslo);
	
	printf ("Wiadomosc do zaszyfrowania posiada %i znakow.\n",strlen(kod));
	printf ("Haslo szyfrujace posiada %i.\n\n",strlen(haslo));
	
	printf("\n");
   	for(i=0;i<strlen(kod);i++)
   	{
	printf("%c ",kod[i]);     // wyœwietlenie wiadomosci z pliku
	}
	
	printf("\n");
	
   for(i=0;i<strlen(kod);i++)
   	{
	kod2[i]=kod[i]-65;       // tu chary przypisuje do tablicy int (zamieniam na ASCI)
                             // i odejmujê 65 dla u³atwienia (wtedy A=0, bo w ASCI A=65)
	}
	
	printf("\n");
	
 for(i=0;i<strlen(haslo);i++)
   	{
	haslo2[i]=haslo[i]-65;    // to samo co wyzej
   	}
	
	printf("\n\n");
	
 for(i=0;i<strlen(kod);i++)
   	{
	szyfr[i]=(kod2[i]+haslo2[j])%26;   // do wartoœci liczbowej wiadomosci dodaje wartosc hasla
	                                   // mod26 dzia³a gdy wyjedziemy poza alfabet
	++j;
		if(j>=strlen(haslo)) j=0;		// gdy has³o siê skoñczy, jest dopisywane od nowa
	}
	
	printf("\n");
	
	 if ((fp=fopen("zaszyfrowany.txt", "w"))==NULL) {
     printf ("Nie moge otworzyc szyfr.txt .\n");
     exit(1);
     }
	
	
	for(i=0;i<strlen(kod);i++)
   	{	
	fprintf(fp, "%C",szyfr[i]+65); // zaszyfrowana wiadomosc zapisana do pliku
	                               // 65 dodane, bo wczesniej bylo odjête od kodu ASCI.
	}
	
	printf("\nTekst zostal zaszyfrowany\n\n");
	
		printf("\n");
	fclose (fp);     
     
break;     
}
                                          /*koniec czêœci odpowiedzialnej za szyfrowanie*/
/*------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------*/

case 2:
{

char zaszyfrowany[3000];
 
const double czestotliwosc[] = {
	0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015,
    0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749,
    0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758,
    0.00978, 0.02360, 0.00150, 0.01974, 0.00074
};
 
int naj_zgranie(const double *a, const double *b) {
    double suma = 0, dopasowanie, d, naj_dopasowanie = 1e100;
    int i, obrot, naj_obrot = 0;
    for (i = 0; i < 26; i++)
        suma += a[i];
    for (obrot = 0; obrot < 26; obrot++) {
        dopasowanie = 0;
        for (i = 0; i < 26; i++) {
            d = a[(i + obrot) % 26] / suma - b[i];
            dopasowanie += d * d / b[i];
        }
 
        if (dopasowanie < naj_dopasowanie) {
            naj_dopasowanie = dopasowanie;
            naj_obrot = obrot;
        }
    }
 
    return naj_obrot;
}
 
double czest_kazd_nast(const int *msg, int dlugosc, int odstep, char *haslo) {
    double suma, d, zwr;
    double wyjscie[26], dokladnosc[26] = {0};
    int i, j, obr;
 
    for (j = 0; j < odstep; j++) {
        for (i = 0; i < 26; i++)
            wyjscie[i] = 0;
        for (i = j; i < dlugosc; i += odstep)
            wyjscie[msg[i]]++;
        haslo[j] = obr = naj_zgranie(wyjscie, czestotliwosc);
        haslo[j] += 'A';
        for (i = 0; i < 26; i++)
            dokladnosc[i] += wyjscie[(i + obr) % 26];
    }
 
    for (i = 0, suma = 0; i < 26; i++)
        suma += dokladnosc[i];
 
    for (i = 0, zwr = 0; i < 26; i++) {
        d = dokladnosc[i] / suma - czestotliwosc[i];
        zwr += d * d / czestotliwosc[i];
    }
 
    haslo[odstep] = '\0';
    return zwr;
}
    
    FILE *plik;
    if((plik=fopen("zaszyfrowany.txt","r"))!=NULL)
    {
    while(fgets(zaszyfrowany,sizeof(zaszyfrowany),plik)!=NULL);
    }
    else
    return -1;
    fclose(plik);
    
    
    int txt[sizeof(zaszyfrowany)];
    int dlugosc = 0, j;
    char klucz[100];
    double dopasowanie, naj_dopasowanie = 1e100;
 
    for (j = 0; zaszyfrowany[j] != '\0'; j++)
        if (isupper(zaszyfrowany[j]))
            txt[dlugosc++] = zaszyfrowany[j] - 'A';
    
    getchar();       
    printf("Nacisnij ENTER aby zlamac haslo\n");
    getchar();
            
    for (j=1; j<=30; j++)
    {
    dopasowanie = czest_kazd_nast(txt, dlugosc, j, klucz);   
    if (dopasowanie < naj_dopasowanie)
    {
    naj_dopasowanie = dopasowanie;
    printf("Trafnosc: %.2f%%, dlugosc klucza: %2d, haslo: %s", 100-(((naj_dopasowanie*100)*100)/1000), j, klucz);
    if(dopasowanie<=0.36)
    printf(" - szukane haslo");
    printf("\n");
    }
    }
    printf("\n");
    
                                              /* koniec czêœci odpowiedzialnej za ³amanie klucza */
/*------------------------------------------------------------------------------------------------------------------------------------------*/
    
    FILE *we, *wy;
int i, licznik;
int tablica_ASCII[1000];        //przechowywane beda w niej wartosci liter odpowiadajace poszczegolnym literom w hasle
char znak;                     //znak odczytany z pliku
char haslo[200];               //tablica, w ktorej przechowywane bedzie haslo 
//Przed uruchomieniem programu nalezy utworzyc 2 pliki - 1. z tekstem zaszyfrowanym, 2. pusty na t.jawny
for (i=0; i<1000; i++)         //wypelnienie tablicy pustymi znakami
    haslo[i]=42;

printf("Wpisz haslo (drukowanymi literami):\n");
scanf("%s",&haslo);

int pozycja=0;
for (i=0; i<1000; i++)
   if (haslo[pozycja]!=42)
      {
      	tablica_ASCII[i]=haslo[pozycja];      //wypelnienie tablicy_ASCII wartosciami
	pozycja++;
      }
   else
       {
	pozycja=0;                           //haslo wpisywane jest cyklicznie
        i--;
      	tablica_ASCII[i]=haslo[pozycja];
	pozycja++;
      }

for (i=0; i<1000; i++)                       //po odjeciu wartosci 64 otrzymujemy wartosc przesuniecia
     tablica_ASCII[i]-=65;


licznik=0;

if((we=fopen("zaszyfrowany.txt","r"))!=NULL)    //otwieranie pliku 1. do odczytu - oba pliki musza istniec
{
if((wy=fopen("odszyfrowany.txt","w"))!=NULL)  //otwieranie pliku 2. do zapisu
{
   while((znak=getc(we))!=EOF)   //pobieranie znaku z pliku 1. tak dlugo az nie nastapi znak konca pliku
   //Kazdy odczytywany znak wg kodow ASCII jest przydzielany do 2 grup duze litery, male litery
	   {
		if ((znak>=65)&&(znak<=90))
		     {
			znak-=65;
			znak-=tablica_ASCII[licznik];   //przesuniecie w lewo wedlug znaku hasla
			if(licznik==1000)                //w przypadku gdyby tekst byl dluzszy niz 200 liter wtedy haslo bedzie pobierane od poczatku
			   licznik=0;
                        else
			   licznik++;
			if (znak<0)                     
			     znak=26-fabs(znak);
			znak+=65;
			putc(znak,wy);
		     }
		 else if ((znak>=97)&&(znak<=122))
		     {
			znak-=97;
			znak-=tablica_ASCII[licznik];
			if(licznik==1000)
			   licznik=0;
                        else
			   licznik++;
			if (znak<0)
			     znak=26-fabs(znak);
			znak+=97;
			putc(znak,wy);
		     }
	}
      
fclose(wy);
 }
fclose(we);
 }
printf("\n");
printf("Tekst zostal odszyfrowany\n\n");
break;
}
                                             /* koniec czêœci odpowiedzialnej za deszyfrowanie */
/*------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------*/
}
	system("pause");
    return 0;
}
