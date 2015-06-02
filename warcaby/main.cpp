#include <iostream>

#include "plansza.h"
using namespace std;

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
            cout << "\n!!!!!!!!!!! Zwyciestwo Białych !!!!!!!!!!!!\n\n";
            return 1;
        }
    else return 0;
}

void warcaby::gramy()
{
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
}
int main()
{
    cout << "GRA WARCABY \n";

    warcaby test;
    test.gramy();

    return 0;
}
