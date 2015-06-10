#ifndef PLANSZA_H_
#define PLANSZA_H_

#include <iostream>
#include <string>

using namespace std;

enum pionek { Pusty, Bialy, Czarny, BialaDamka, CzarnaDamka, Zbity };

struct pole
{
		int lp;
		pionek typ;
		pole *lewy;
		pole *prawy;
		pole *tlewy;
		pole *tprawy;
};

struct ustawionko
{
	pionek pola[32];
};

struct najlepszy
{
	int wartosc;
	int numer;
};

class plansza
{
    public:
	pole ustawienie[32];
	int valid_moves_count;
	ustawionko valid_moves[250];
	unsigned long int stat_ile_kombinacji;  //statystyka
	unsigned int czas_ostatniego_ruchu_komp;
	int MAX_H;

    private:
	pionek	tmp_ustawienie[32];

    public:
	int ile_zbitych;
	int max_zbitych;

    public:

    plansza();
    ~plansza();

    void zeruj_plansze();
    void znajdz_mozliwe_ruchy(enum pionek ktorych);
    void odwroc();
    enum pionek czyja_damka(enum pionek ktorych);
    bool sprawdz_bicie(enum pionek ktorych, int nr);
    bool sprawdz_kierunek(enum pionek ktorych,int nr1, int nr2, int nr3);
    void dopisz_ruch(enum pionek ktorych);
    void sprawdz_plansze(bool czy_plansza_odwrocona);
    bool sprawdz_bicie_damki(enum pionek ktorych, int nr);
    bool sprawdz_kierunek_damki(enum pionek ktorych, char kierunek, int nr);

    //void Testuj_Szybkosc_Komputera(int jakie_h);
    pole* wskaz(char kierunek, pole* ptr);
    enum pionek czyja_figura(enum pionek figura);
    najlepszy evaluate(char h, pionek CzyjRuch);
	najlepszy bestmove(char h, int alfa, int beta,  pionek CzyjRuch);
	void Ruch_Komputera(pionek CzyjRuch, int trudnosc);
	enum pionek przeciwny(enum pionek czemu);
    void odtworz();
	void zapamietaj();

	void wyswietl_plansze();


};


#endif

