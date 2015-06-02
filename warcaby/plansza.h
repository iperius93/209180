#ifndef PLANSZA_H_
#define PLANSZA_H_

#include <iostream>
#include <string>

using namespace std;

struct XY
{
		int x;
		int y;
};

enum TypGracza { Czlowiek, Komputer, Siec };

struct Gracz
{
		string Nazwa;
		TypGracza typ;
};

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
    //pole temp_ustawienie[32];
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

    void Testuj_Szybkosc_Komputera(int jakie_h);
    pole* wskaz(char kierunek, pole* ptr);
    enum pionek czyja_figura(enum pionek figura);
    najlepszy evaluate(char h, pionek CzyjRuch);
	najlepszy bestmove(char h, int alfa, int beta,  pionek CzyjRuch);
	void Ruch_Komputera(pionek CzyjRuch);
	enum pionek przeciwny(enum pionek czemu);
    void odtworz();
	void zapamietaj();
    void Przesun(int skad, int dokad);
    void Przesun_na_kopi(int skad, int dokad);
    int XYtoI(int x, int y);
	XY ItoXY(int i);

	void wyswietl_plansze();

	bool takie_same(int ktora)
	{
        for(int i=0;i<32;i++)
        {
            if(tmp_ustawienie[i] != valid_moves[ktora].pola[i]) return 0;
        }
	    return 1;
	}


};


#endif
