#include <iostream>
#include <fstream>

#include "plansza.h"

using namespace std;

std::istream & operator >> (std::istream& strumien, plansza& pierwsza)
{
    int zmienna = 0;
    for(int i=1;i<=32;i++)
    {
        strumien >> zmienna;
        if(zmienna == 0) pierwsza.ustawienie[i-1].typ = Pusty;
        else if(zmienna == 1) pierwsza.ustawienie[i-1].typ = Bialy;
        else if(zmienna == 2) pierwsza.ustawienie[i-1].typ = Czarny;
        else if(zmienna == 3) pierwsza.ustawienie[i-1].typ = BialaDamka;
        else if(zmienna == 4) pierwsza.ustawienie[i-1].typ = CzarnaDamka;
        else if(zmienna == 5) pierwsza.ustawienie[i-1].typ = Zbity;
    }
    return strumien;
}

std::ostream & operator << (std::ostream& strumien, plansza& pierwsza)
{
    for(int i=1;i<=32;i++)
    {
        strumien<<pierwsza.ustawienie[i-1].typ<<" ";
        if(i%4 == 0) strumien << endl;
    }
    return strumien;
}
/*
class warcaby {

    public:
    plansza	plan;
    pionek CzyjaKolej;

    public:
    warcaby();
    void gramy();
    void pokaz_wygrana()
    {

    }
    bool jeszcze_raz();
    void ruch_czlowieka();
    void ruch_komputera();
    bool wygrana();
};

warcaby::warcaby()
{

}

bool warcaby::jeszcze_raz()
{
    cout << "Jeszcze raz? (T = TAK) : ";

    char klawisz;
    cin >> klawisz;
    return (klawisz == 'T') || (klawisz == 't');
}

bool warcaby::wygrana()
{
    plan.znajdz_mozliwe_ruchy(CzyjaKolej);
    if(!plan.valid_moves_count)
        if(CzyjaKolej == Bialy)
        {
            cout << "\n!!!!!!!!!!! Zwyciestwo Czarnych !!!!!!!!!!!!\n\n";
            return 1;
        }
        else
        {
            cout << "\n!!!!!!!!!!! Zwyciestwo Bia³ych !!!!!!!!!!!!\n\n";
            return 1;
        }
    else return 0;
}

void warcaby::gramy()
{
    plan.odwroc();
    for(int i=0;i<32;i++)
    {
        plan.ItoXY(i);
        cout <<" "<< plan.ustawienie[i].typ<<endl;
    }

    do
    {
        plan.zeruj_plansze();
        plan.wyswietl_plansze();
        do
        {
            ruch_czlowieka();
            plan.wyswietl_plansze();
            CzyjaKolej = Czarny;

            if(wygrana()) break;

            cout << "Ruch komputera \n";
            ruch_komputera();
            plan.wyswietl_plansze();
            CzyjaKolej = Bialy;

            if(wygrana()) break;

        }   while(true);

        pokaz_wygrana();

    }   while(jeszcze_raz());

}

void warcaby::ruch_komputera()
{
    plan.Ruch_Komputera(Czarny);
}

void warcaby::ruch_czlowieka()
{
    int ktory=0, gdzie=0;
    bool zly_ruch = false;

    plan.znajdz_mozliwe_ruchy(Bialy);

    cout << plan.valid_moves_count<<plan.max_zbitych;
    for(int i=0;i<32;i++)
    {
        cout << plan.valid_moves[0].pola[i];
    }

    if(plan.max_zbitych != 0)
    {
        cout << "Masz bicie!!! \n\n";
    }

    do
    {
        cout << "Ktory? :";
        cin >> ktory;
        cout <<endl;
        cout << "Gdzie? :";
        cin >> gdzie;
        cout <<endl;

        plan.zapamietaj();
        plan.Przesun_na_kopi(ktory,gdzie);

        for(int a=0; a<plan.valid_moves_count;a++)
        {
            if( plan.takie_same(a) )
            {
                zly_ruch = false;
                for(int i=0;i<32;i++)
                {
                    plan.ustawienie[i].typ = plan.valid_moves[a].pola[i];
                }
                break;
            }
            else
            {
                zly_ruch = true;
            }
        }
        plan.zapamietaj();
        if(zly_ruch) cout<<"Nieprawidlowy ruch\n\n";
    } while(zly_ruch);
} */
int main(int argc, char* argv[])
{
    fstream plik_wej,plik_wyj;
    plik_wej.open(argv[1],std::ifstream::in);
    if(plik_wej.is_open())
    {
        plansza test;
        plik_wej >> test;
        if(*argv[3] == '1') test.Ruch_Komputera(Czarny,2);
        else if(*argv[3] == '2') test.Ruch_Komputera(Czarny,3);
        else if(*argv[3] == '3') test.Ruch_Komputera(Czarny,7);
        plik_wyj.open(argv[2],std::ifstream::out);
        if(plik_wyj.is_open())
        {
            plik_wyj << test;
            plik_wyj.close();
        }
        else return 1;
        plik_wej.close();
    }
    else return 1;
/*
        warcaby pierwsze;
        pierwsze.gramy();*/

    return 0;
}
