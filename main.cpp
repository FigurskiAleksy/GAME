#include <iostream>
#define cap 1000

using namespace std;

//Struktury zawierajace dane o pracownikach

struct inzynier
{
  char imie[20];
  char wydzial[20];
  double placa=8000;
};

struct magazynier
{
  char imie[20];
  string wozek;
  double placa=5000;
};

struct marketer
{
  char imie[20];
  int follow;
  double placa=6000;
};

struct robotnik
{
  char imie[20];
  int rozmiar;
  double placa=4000;
};

//Struktura przechowujaca dane o kredytach

struct kredyt
{
  double wielkosc;
  int okres;
  double ratka;
};

//Struktury do zatrudniania pracownikow i umieszczania ich w bazie danych

void zinzynier (struct inzynier baza [], int i)
{
  cout << "\n ID Inzyniera : " << i << endl;

  cout << "Imie : ";
  cin >> baza[ i ].imie;

  cout << "Wydzial : ";
  cin >> baza[ i ].wydzial;
}

void zmagazynier (struct magazynier baza [], int i)
{
  cout << "\n ID Magazyniera : " << i << endl;
  
  cout << "Imie : ";
  cin >> baza[ i ].imie;

  cout << " Umie obslugiwac wozek widlowy? (tak/nie) : \n";
  cin >> baza[ i ].wozek;

  while(baza[ i ].wozek!="tak" && baza[ i ].wozek!="tak")
  {
    cout << " Powtorz \n";
    cin >> baza[ i ].wozek;
  }
}

void zmarketer (struct marketer baza [], int i)
{
  cout << "\n ID Marketera : " << i << endl;

  cout << "Imie : ";
  cin >> baza[ i ].imie;

  cout << "Followersi : ";
  cin >> baza[ i ].follow;
}

void zrobotnik (struct robotnik baza [], int i)
{
  cout << "\n ID Robotnika : " << i << endl;

  cout << "Imie : ";
  cin >> baza[ i ].imie;

  cout << "Rozmiar buta : ";
  cin >> baza[ i ].rozmiar;
}

//Struktura do zaciagania kredytow

void zkredyt (struct kredyt baza [], int i, double w1)
{
  cout << "\n ID Kredytu : " << i << endl;

  cout << "Kwota : ";
  cin >> baza[ i ].wielkosc;
  while(baza[ i ].wielkosc>w1)
  {
    cout << "Podaj nizsza kwotę \n";
    cin >> baza[ i ].wielkosc;
  }

  cout << "Okres kredytowania : ";
  cin >> baza[ i ].okres;
  while(baza[ i ].okres>50)
  {
    cout << "Podaj krótszy okres splaty (nie może byc dluzszy niz 50 tur) \n";
    cin >> baza[ i ].okres;
  }
  baza[ i ].ratka=baza[ i ].wielkosc/baza[ i ].okres;
}

//Struktura do listowania pracownikow kazdego typu

void listuj_inz (struct inzynier baza[], int n )
{
  int i;
   
    for( i = 0; i < n; i++ )
    //if( baza[ i ].imie[ 0 ] != 0 )
    {
        cout << "ID Inzyniera : " << i << endl;
       
        cout << "Imie : ";
        cout << baza[ i ].imie << endl;

        cout << "Wydzial : ";
        cout << baza[ i ].wydzial << endl;
    }
}

void listuj_mag (struct magazynier baza[], int n )
{
  int i;
   
    for( i = 0; i < n; i++ )
    //if( baza[ i ].imie[ 0 ] != 0 )
    {
        cout << "ID Magazyniera : " << i << endl;
       
        cout << "Imie : ";
        cout << baza[ i ].imie << endl;

        cout << "Umie obslugiwac wozek widlowy : ";
        if(baza[ i ].wozek=="tak")
        {
        cout << "Tak" << endl;
        }
        else
        cout << "Nie" << endl;
    }
}

void listuj_mkt (struct marketer baza[], int n )
{
  int i;
   
    for( i = 0; i < n; i++ )
    //if( baza[ i ].imie[ 0 ] != 0 )
    {
        cout << "ID Marketera : " << i << endl;
       
        cout << "Imie : ";
        cout << baza[ i ].imie << endl;

        cout << "Followersi : ";
        cout << baza[ i ].follow << endl;
    }
}

void listuj_rob (struct robotnik baza[], int n )
{
  int i;
   
    for( i = 0; i < n; i++ )
    //if( baza[ i ].imie[ 0 ] != 0 )
    {
        cout << "ID Robotnika : " << i << endl;
       
        cout << "Imie : ";
        cout << baza[ i ].imie << endl;

        cout << "Rozmiar buta : ";
        cout << baza[ i ].rozmiar << endl;
    }
}

int main() 
{
  
   
    int n = 0, a = 0, b = 0, c = 0, d = 0, k=0; //Zmienne liczace rozne rzeczy
    string wybor;
    double piniadz = 100000.0;                  //Wartosci startowe
    double pojemnosc_bazowa=100.0;
    double pojemnosc;
    double produkt = 0;
    double cena_bazowa=1000.0;
    double cena;
    double wydatki;
    double CMag=50.0; 
    double CR=15.0;  
    double CI=0.25;
    double CMkt=0.5;
    double sprzedaz_bazowa=15.0;
    double sprzedaz;
    double zysk;
    double W[5];                                //Tabela do przechowywania wartosci firmy z ostatnich pieciu tur - zerowana ponizej
    double kredyt=0;
    int m=4;                                    //Wielokrotnosc wartosci firmy do zdolnosci kredytowej
    int raty;
    double rata=0;
    int nr=0;
    double wartosc=piniadz-kredyt;
    double zdolnosc_kredytowa=wartosc*m;

    for(int a=0; a<5; a++)
    {
      W[a]=0;
    }

    //Tworzenie struktur (baz)

    struct inzynier BazaInz[ cap ];
    struct robotnik BazaRob[ cap ];
    struct magazynier BazaMag[ cap ];
    struct marketer BazaMkt[ cap ];
    struct kredyt BazaKred[ cap ];

      cout << "Witaj w utopijnym symulatorze firmy. Nie ma tu podatkow, ani odsetek od zaciagnietych kredytow. Twoim jedynym celem jest nie zbankrutowac. Uzyj ponizszych komend, aby zdobyc fortune. \n";
      cout << "\n";
      cout << "zinz - Zatrudnij inzyniera \n";
      cout << "zmag - Zatrudnij magazyniera \n";
      cout << "zrob - Zatrudnij robotnika \n";
      cout << "zmkt - Zatrudnij marketera \n";
      cout << "lp - Listuj pracownikow \n";
      cout << "kt - Koncz ture \n";
      cout << "kred - Zaciagnij kredyt\n";
      cout << "help - Wyswietl komendy jeszcze raz\n";
      cout << "\n";
      cout << "Zaczynasz z 100000 i czterema pracownikami. Nadaj teraz im imiona i cechy.\n";
      
      zinzynier( BazaInz, a );
      a++;
      zmagazynier( BazaMag, b );
      b++;
      zrobotnik( BazaRob, c );
      c++;
      zmarketer( BazaMkt, d );
      d++;
      
      //Chcialem, żeby poczatkowi pracownicy rowniez pokazywali sie przy komendzie lp, a nie zeby tylko ich liczba zaczynala sie od 1, a nie od 0.

      cout << "Podaj komende \n";
    
    do
    {
      
      cin >> wybor;

      
            if(wybor == "zinz")
            {
                zinzynier( BazaInz, a );
                a++;
                
            }

            if(wybor == "zmag")
            {
                zmagazynier( BazaMag, b );
                b++;
                
            } 
            
              
            if(wybor == "zrob")
            {
                zrobotnik( BazaRob, c );
                c++;
                
            }  


            if(wybor == "zmkt")
            {
                zmarketer( BazaMkt, d );
                d++;
            }


            if(wybor == "lp")
            {
                listuj_inz( BazaInz, a);
                listuj_mag( BazaMag, b);
                listuj_rob( BazaRob, c);
                listuj_mkt( BazaMkt, d);  
            }

            if(wybor == "kred")
            {
              zkredyt( BazaKred, k, zdolnosc_kredytowa);
              piniadz=piniadz+BazaKred[k].wielkosc;
              kredyt=kredyt+BazaKred[k].wielkosc;
              k++;
            
              cout << "Kredyt zaciagniety. Pierwsza rata platna od kolejnej tury \n";
            }
            if(wybor == "kt")
            {   
                nr++;

                wydatki=a*BazaInz[0].placa+b*BazaMag[0].placa+c*BazaRob[0].placa+d*BazaMkt[0].placa;
                pojemnosc=pojemnosc_bazowa+b*CMag;

                if(produkt+CR*c<=pojemnosc)
                {
                  produkt=produkt+CR*c;
                }
                else
                produkt=pojemnosc;

                cena=cena_bazowa*(1+a*CI);

                sprzedaz=sprzedaz_bazowa*(1+d*CMkt);


                if(sprzedaz<=produkt)
                {
                  zysk=sprzedaz*cena;
                  produkt=produkt-sprzedaz;
                }
                else
                {
                  zysk=produkt*cena;
                  produkt=0;
                  sprzedaz=produkt;
                }

                piniadz=piniadz+zysk-wydatki;
                W[4]=W[3];
                W[3]=W[2];
                W[2]=W[1];
                W[1]=W[0];
                W[0]=piniadz;
          
                wartosc=(W[0]+W[1]+W[2]+W[3]+W[4])/5-kredyt;

                cout << "Tura: " << nr << "\n";
                cout << "Bilans: " << piniadz << "\n";
                cout << "Wydatki: " << wydatki << "\n";
                cout << "Wplywy: " << zysk << "\n";
                cout << "Cena produktu: " << cena << "\n";
                cout << "Pojemnosc magazynu: " << pojemnosc << "\n";
                cout << "Sprzedany towar: " << sprzedaz << "\n";
                cout << "Zalegajacy towar: " << produkt << "\n";
                cout << "Wartosc firmy: " << wartosc << "\n";
                cout << "Zalegly kredyt: " << kredyt << "\n";
                cout << "Zaplacona rata kredytu: " << rata << "\n";

                
                kredyt=0;   
                rata=0;

                for(int i=0; i<k; i++)
                {
                  if(BazaKred[i].wielkosc>0)
                  {
                    BazaKred[i].wielkosc=BazaKred[i].wielkosc-BazaKred[i].ratka;
                    kredyt=kredyt+BazaKred[i].wielkosc;
                    rata=rata+BazaKred[i].ratka;
                  }
                  else
                  BazaKred[i].ratka=0;     
                }
                //Kredyt uznaje za swojego rodzaju oddziely wydatek i jest on uwzgledniany przy drukowaniu bilansu
                
                piniadz=piniadz-rata;
            }

            if(wybor == "help")
            {
              cout << "zinz - Zatrudnij inzyniera \n";
              cout << "zmag - Zatrudnij magazyniera \n";
              cout << "zrob - Zatrudnij robotnika \n";
              cout << "zmkt - Zatrudnij marketera \n";
              cout << "lp - Listuj pracownikow \n";
              cout << "kt - Koncz ture \n";
              cout << "kred - Zaciagnij kredyt\n";
              cout << "help - Wyswietl komendy jeszcze raz\n";
              cout << "Podaj komende \n";
                
            }
            else
            {
              cout << "Podaj komende \n";
            }

           


    }while(piniadz>=0);
    
  
  cout << "Zbankrutowales \n";


}