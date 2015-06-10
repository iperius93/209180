#include <ctime>
#include <stdio.h>
#include <string.h>
#include "plansza.h"

plansza::plansza()
{
    zeruj_plansze();
    int x=0;
	for(x=0;x<32;x++)ustawienie[x].lp=x;


	// tworzenie pwowiazan na planszy (miedzy polami)
	for(x=0;x<4;x++)
	{
		ustawienie[x].lewy=&ustawienie[x+4];
		ustawienie[x+8].lewy=&ustawienie[x+4+8];
		ustawienie[x+16].lewy=&ustawienie[x+4+16];
		ustawienie[x+24].lewy=&ustawienie[x+4+24];

		ustawienie[4+x].prawy=&ustawienie[x+8];
		ustawienie[12+x].prawy=&ustawienie[x+16];
		ustawienie[20+x].prawy=&ustawienie[x+24];
	}

	for(x=0;x<3;x++)
	{
		ustawienie[x].prawy=&ustawienie[5+x];
		ustawienie[8+x].prawy=&ustawienie[13+x];
		ustawienie[16+x].prawy=&ustawienie[21+x];
		ustawienie[24+x].prawy=&ustawienie[29+x];

		ustawienie[5+x].lewy=&ustawienie[8+x];
		ustawienie[13+x].lewy=&ustawienie[16+x];
		ustawienie[21+x].lewy=&ustawienie[24+x];
	}
	ustawienie[4].lewy=NULL;
	ustawienie[12].lewy=NULL;
	ustawienie[20].lewy=NULL;
	ustawienie[28].lewy=NULL;

	ustawienie[29].lewy=NULL;
	ustawienie[30].lewy=NULL;
	ustawienie[31].lewy=NULL;

	ustawienie[29].prawy=NULL;
	ustawienie[30].prawy=NULL;
	ustawienie[31].prawy=NULL;

	ustawienie[3].prawy=NULL;
	ustawienie[11].prawy=NULL;
	ustawienie[19].prawy=NULL;
    ustawienie[27].prawy=NULL;

	for(x=0;x<32;x++)
	{
		ustawienie[x].tlewy=NULL;
		ustawienie[x].tprawy=NULL;
	};

	for(x=0;x<32;x++)
	{
		if(ustawienie[x].lewy!=NULL)
				ustawienie[ustawienie[x].lewy->lp].tprawy=&ustawienie[x];
		if(ustawienie[x].prawy!=NULL)
				ustawienie[ustawienie[x].prawy->lp].tlewy=&ustawienie[x];
	};
}

plansza::~plansza()
{

}

void plansza::zeruj_plansze()
{
    valid_moves_count=0;
	MAX_H=8;

	for(int x=0;x<12;x++)
	{
		ustawienie[x].typ=Bialy;
		ustawienie[20+x].typ=Czarny;
	}
	for(int x=12;x<20;x++)
        ustawienie[x].typ=Pusty;
}

void plansza::znajdz_mozliwe_ruchy(enum pionek ktorych)
{

	int i;

	if(ktorych==Czarny) odwroc();

	//sprawdzamy po kolei ruchy naszych pionkow i dopisujemy do valid_moves;
	valid_moves_count=0;

	//jesli damki wogole sa na planszy ??? dsopisac
	//bicia damek
	pionek damka=czyja_damka(ktorych);


	ile_zbitych=0;
	max_zbitych=0;
	//najpierw bicia, bo po co nam zwykle ruchy skoro bicia sa przymusowe
	//we will find beats first (if there are beats, standard move is not allowed)
	for(i=0;i<32;i++)
	{

		//bicia zwyklych pionkow
		if(ustawienie[i].typ==ktorych)sprawdz_bicie(ktorych,i);
			else
		//bicia damek
			if(ustawienie[i].typ==damka)
				sprawdz_bicie_damki(ktorych,i);


	}
	//if any moves found at this moment, it means that there are no beats
   if(!valid_moves_count)
   {
	//ruchy bez bic damek
	enum pionek tmp;

	if(ktorych==Bialy)tmp=BialaDamka;
			else tmp=CzarnaDamka;


	for(i=0;i<32;i++)
		if(ustawienie[i].typ==tmp)
		{
			ustawienie[i].typ=Pusty;
			pole* ptr;
			//tyl-lewo
			ptr=ustawienie[i].tlewy;
			while((ptr!=NULL)&&(ptr->typ==Pusty))
			{
				ustawienie[ptr->lp].typ=tmp;
				dopisz_ruch(ktorych);
				ustawienie[ptr->lp].typ=Pusty;
				ptr=ptr->tlewy;
			};
			//tyl-prawo
			ptr=ustawienie[i].tprawy;
			while((ptr!=NULL)&&(ptr->typ==Pusty))
			{
				ustawienie[ptr->lp].typ=tmp;
				dopisz_ruch(ktorych);
				ustawienie[ptr->lp].typ=Pusty;
				ptr=ptr->tprawy;
			};
			//przod-lewo
			ptr=ustawienie[i].lewy;
			while((ptr!=NULL)&&(ptr->typ==Pusty))
			{
				ustawienie[ptr->lp].typ=tmp;
				dopisz_ruch(ktorych);
				ustawienie[ptr->lp].typ=Pusty;
				ptr=ptr->lewy;
			};
			//przod-prawo
			ptr=ustawienie[i].prawy;
			while((ptr!=NULL)&&(ptr->typ==Pusty))
			{
				ustawienie[ptr->lp].typ=tmp;
				dopisz_ruch(ktorych);
				ustawienie[ptr->lp].typ=Pusty;
				ptr=ptr->prawy;
			};

			ustawienie[i].typ=tmp;
		}


	//normalne ruchy
	//Moves without beats

	for(i=0;i<28;i++) //nie musi do konca przeciez na ostatniej lini nie zrobi sie ruchu do przodu dlatego jest 28
	{

		if(ustawienie[i].typ==ktorych)
		{
			if((ustawienie[i].lewy!=NULL)&&(ustawienie[i].lewy->typ==Pusty))
			{
				pionek tmp=ustawienie[i].typ;
				ustawienie[i].lewy->typ=tmp;
				ustawienie[i].typ=Pusty;

				dopisz_ruch(ktorych);

				ustawienie[i].lewy->typ=Pusty;
				ustawienie[i].typ=tmp;
			}

			if((ustawienie[i].prawy!=NULL)&&(ustawienie[i].prawy->typ==Pusty))
			{
				pionek tmp=ustawienie[i].typ;
				ustawienie[i].prawy->typ=tmp;
				ustawienie[i].typ=Pusty;

				dopisz_ruch(ktorych);

				ustawienie[i].prawy->typ=Pusty;
				ustawienie[i].typ=tmp;

			}
		}
	}
   }
   if(ktorych==Czarny) odwroc();
}

void plansza::odwroc()
{
	pionek tempor[32];
	for(int i=0;i<32;i++)
		tempor[i]=ustawienie[31-i].typ;

	for(int i=0;i<32;i++)
		ustawienie[i].typ=tempor[i];
}

enum pionek plansza::czyja_damka(enum pionek ktorych)
{
	if(ktorych==Bialy)return BialaDamka;
		else return CzarnaDamka;
}

bool plansza::sprawdz_bicie(enum pionek ktorych, int nr)
{
	bool czy_znalazl=false;

	//btw. nie potrzebnie sprawdze np. .lewy->lewy bo jesli na nr nie stoi nic to nie ma mowy o biciu
	if((ustawienie[nr].lewy!=NULL)&&(ustawienie[nr].lewy->lewy!=NULL))
		czy_znalazl=sprawdz_kierunek(ktorych, nr, ustawienie[nr].lewy->lp, ustawienie[nr].lewy->lewy->lp);

	if((ustawienie[nr].prawy!=NULL)&&(ustawienie[nr].prawy->prawy!=NULL))
		czy_znalazl=sprawdz_kierunek(ktorych, nr, ustawienie[nr].prawy->lp, ustawienie[nr].prawy->prawy->lp)||czy_znalazl;

	if((ustawienie[nr].tlewy!=NULL)&&(ustawienie[nr].tlewy->tlewy!=NULL))
		czy_znalazl=sprawdz_kierunek(ktorych, nr, ustawienie[nr].tlewy->lp, ustawienie[nr].tlewy->tlewy->lp)||czy_znalazl;

	if((ustawienie[nr].tprawy!=NULL)&&(ustawienie[nr].tprawy->tprawy!=NULL))
		czy_znalazl=sprawdz_kierunek(ktorych, nr, ustawienie[nr].tprawy->lp, ustawienie[nr].tprawy->tprawy->lp)||czy_znalazl;

	return czy_znalazl;
}

bool plansza::sprawdz_kierunek(enum pionek ktorych,int nr1, int nr2, int nr3)
{
	pionek pdamka;
	if(ktorych==Bialy)pdamka=CzarnaDamka; else pdamka=BialaDamka;
	if (((ustawienie[nr2].typ==przeciwny(ktorych))||(ustawienie[nr2].typ==pdamka))
		&&(ustawienie[nr3].typ==Pusty))
			{
				ile_zbitych++;
				ustawienie[nr3].typ=ktorych;
				ustawienie[nr1].typ=Pusty;

				pionek tmp=ustawienie[nr2].typ;
				ustawienie[nr2].typ=Zbity;

				if(!sprawdz_bicie(ktorych, nr3))
						if(ile_zbitych>=max_zbitych)
								{
									if(ile_zbitych>max_zbitych)
										{
											max_zbitych=ile_zbitych;
											valid_moves_count=0;
										}
									dopisz_ruch(ktorych);
								}

				ustawienie[nr2].typ=tmp;
				ustawienie[nr3].typ=Pusty;
				ustawienie[nr1].typ=ktorych;

				ile_zbitych--;
				return true;

			} else return false;
}

void plansza::dopisz_ruch(enum pionek ktorych)
{
	if(valid_moves_count>150)return;
	int j;

	sprawdz_plansze(ktorych==Czarny);

	if(ktorych==Bialy)
		for(j=0;j<32;j++)
		{
			if(ustawienie[j].typ==Zbity)
				valid_moves[valid_moves_count].pola[j]=Pusty;
					else
			valid_moves[valid_moves_count].pola[j]=ustawienie[j].typ;

		}
	  else
		for(j=0;j<32;j++)
		{
			if(ustawienie[31-j].typ==Zbity)
				valid_moves[valid_moves_count].pola[j]=Pusty;
					else
			valid_moves[valid_moves_count].pola[j]=ustawienie[31-j].typ;
		};

	valid_moves_count++;
	return;
}

void plansza::sprawdz_plansze(bool czy_plansza_odwrocona)
// czy zamiana na damki
{
	if(czy_plansza_odwrocona)
	{
		for(int i=0;i<4;i++)
		{
			if(ustawienie[i+28].typ==Czarny)
				ustawienie[i+28].typ=CzarnaDamka;
			if(ustawienie[i].typ==Bialy)
				ustawienie[i].typ=BialaDamka;
		}
	} else
	{
		for(int i=0;i<4;i++)
		{
			if(ustawienie[i].typ==Czarny)
				ustawienie[i].typ=CzarnaDamka;
			if(ustawienie[i+28].typ==Bialy)
				ustawienie[i+28].typ=BialaDamka;
		}
	}

}

bool plansza::sprawdz_bicie_damki(enum pionek ktorych, int nr)
{

	ustawienie[nr].typ=Pusty;
	//tyl-lewo
	sprawdz_kierunek_damki(ktorych, 1, nr);
	sprawdz_kierunek_damki(ktorych, 2, nr);
	sprawdz_kierunek_damki(ktorych, 3, nr);
	sprawdz_kierunek_damki(ktorych, 4, nr);

	ustawienie[nr].typ=czyja_damka(ktorych);
	return false;
}

bool plansza::sprawdz_kierunek_damki(enum pionek ktorych, char kierunek, int nr)
{
	pole* ptr, *ptr_prev;
	pionek tmp;

	ptr=wskaz(kierunek, &ustawienie[nr]);
	while((ptr!=NULL)&&(ptr->typ==Pusty))	//idzie w lewy tyl az napotka jakis pionek lub koniec planszy
		ptr=wskaz(kierunek, ptr);
	if(ptr==NULL)return false;  //jesli koniec planszy
	if(ptr->typ==Zbity)return false;
	if((czyja_figura(ptr->typ)==przeciwny(ktorych)))	//i napotkalismy pionek przeciwnika
			{
				ile_zbitych++;

				tmp=ptr->typ;
				ptr->typ=Zbity;  //kasujemy bitego chwilowo
				ptr_prev=ptr;
				//to jesli pozycje za nim sa wolne dodsajemy wszystkie do mozliwych ruchow
				ptr=wskaz(kierunek, ptr);
				while((ptr!=NULL)&&(ptr->typ==Pusty))
				{
					ustawienie[ptr->lp].typ=czyja_damka(ktorych);
					if(ile_zbitych>=max_zbitych)
					{
						if(ile_zbitych>max_zbitych)
						{
							max_zbitych=ile_zbitych;
							valid_moves_count=0;
						}
						dopisz_ruch(ktorych);
					}
					sprawdz_bicie_damki(ktorych, ptr->lp);
					ustawienie[ptr->lp].typ=Pusty;
					ptr=wskaz(kierunek, ptr);
				}
				ptr=ptr_prev;
				ptr->typ=tmp;  //odtwarzamy zbitego pionka

				ile_zbitych--;
			}
	return false;
}

void plansza::zapamietaj()
{
	for(int i=0;i<32;i++)
		tmp_ustawienie[i]=ustawienie[i].typ;
}

void plansza::odtworz()
{
	for(int i=0;i<32;i++)
		ustawienie[i].typ=tmp_ustawienie[i];
}

enum pionek plansza::przeciwny(enum pionek czemu)
{
	if(czemu==Bialy)return Czarny;
	if(czemu==BialaDamka)return CzarnaDamka;
	if(czemu==Czarny)return Bialy;
	if(czemu==CzarnaDamka)return BialaDamka;
	return Pusty;
}

void plansza::Ruch_Komputera(pionek CzyjRuch, int trudnosc)
{
    MAX_H = trudnosc;
	stat_ile_kombinacji=0;  //dla statystyk ile kombinacji wykonal

	zapamietaj();

	najlepszy best;

    time_t CzasStart = 0;

    CzasStart = clock();

	best=bestmove(0, -16000, +16000, CzyjRuch);

	czas_ostatniego_ruchu_komp = clock() - CzasStart; //pomiar czasu wykonnia


	odtworz();
	//poprawki co do ilosci przewidzianych ruchow w nastepnym obliczaniu
	//if(czas_ostatniego_ruchu_komp>1000)MAX_H--;	//jesli wiekszy od 1s zwieksza glebokosc wnikania
		//else if(czas_ostatniego_ruchu_komp<300)MAX_H++;


//
	znajdz_mozliwe_ruchy(CzyjRuch);
//
	for(int j=0; j<32; j++)
	  ustawienie[j].typ=valid_moves[best.numer].pola[j];
}

najlepszy plansza::bestmove(char h, int alfa, int beta, pionek CzyjRuch)
{
  stat_ile_kombinacji++;
  if (h == MAX_H) return evaluate(h, CzyjRuch);

  najlepszy best;
  int j;
  int v;

  znajdz_mozliwe_ruchy(CzyjRuch);
  if(!valid_moves_count)
		{

			best.numer=-1;
			best.wartosc=-15000;


			return best;
		}


  int ile_mozliwych;
  ustawionko mozliwe_ruchy[150];	//nie zamieniac nic na liste!
									//bo z lista nie zrobie memcpy
  if(valid_moves_count>150)valid_moves_count=150;
  memcpy(&mozliwe_ruchy, &valid_moves, sizeof(ustawionko)*valid_moves_count);
  /*for(j=0;j<valid_moves_count;j++)
	  for(v=0;v<32;v++)
		  mozliwe_ruchy[j].pola[v]=valid_moves[j].pola[v];*/
	//jesli cos sie wykrzacza z pamiecia to pewnie tutaj

  ile_mozliwych=valid_moves_count;

  //pionek tymczas[32];

  //for(j=0; j<32; j++)
    //tymczas[j]=ustawienie[j].typ;
  //to tez wyw tylko przerobic ustawienie (po co ten typ?)

  best.wartosc = alfa;
  for (int i = 0; i < ile_mozliwych; i++)
     {
		for(j=0; j<32; j++)
			ustawienie[j].typ=mozliwe_ruchy[i].pola[j];

        v = -bestmove(h + 1, -beta, -best.wartosc, przeciwny(CzyjRuch)).wartosc;    /* ocen go z punktu widzenia bie¿¹cego gracza */

        if (v > best.wartosc)
           {
              best.numer = i;
              best.wartosc = v;
			  if(v>=beta)return best;
           }


     }
  return best;

}

najlepszy plansza::evaluate(char h, pionek CzyjRuch)
{
	int ocena=0;
	const int waga_pionkow=50;
	const int waga_damek=150;

	pionek damka=czyja_damka(CzyjRuch);
	for(int i=0;i<32;i++)
	{
		//zwykle pionki za pionek waga_pionkow
		if(ustawienie[i].typ==CzyjRuch)ocena+=waga_pionkow;
		  else if(ustawienie[i].typ==przeciwny(CzyjRuch))ocena-=waga_pionkow;

		//damki za damke waga_damek
		if(ustawienie[i].typ==damka)ocena+=waga_damek;
		  else if(ustawienie[i].typ==przeciwny(damka))ocena-=waga_damek;
	}

	najlepszy temp;
	temp.numer=-1;
	temp.wartosc=ocena;
	return temp;
}

enum pionek plansza::czyja_figura(enum pionek figura)
{
	if((figura==Bialy)||(figura==BialaDamka))return Bialy;
	if((figura==Czarny)||(figura==CzarnaDamka))return Czarny;
	return Pusty;
}

pole* plansza::wskaz(char kierunek, pole* ptr)
{
	switch(kierunek)
	{
		case 1 : return ptr->tprawy;
		case 2 : return ptr->tlewy;
		case 3 : return ptr->lewy;
		case 4 : return ptr->prawy;
	};
	return ptr;
}
/*
void plansza::Testuj_Szybkosc_Komputera(int jakie_h)
{
    time_t CzasStart = 0;
    time_t CzasWykonywania = 0;
	//ustawienie planszy
	plansza test;
	test.MAX_H=jakie_h;

	//ustawia sobie figury na teestowej planszy
	for(int x=0;x<12;x++)
	{
		test.ustawienie[x].typ=Pusty;
		test.ustawienie[20+x].typ=Pusty;
	}
	for(int x=0;x<2;x++)
	{
		test.ustawienie[7+x].typ=CzarnaDamka;
		test.ustawienie[26+x].typ=BialaDamka;
	}


    CzasStart = clock();
	test.Ruch_Komputera(Bialy);
    CzasWykonywania = clock() - CzasStart;
}*/

void plansza::wyswietl_plansze()
{
    int j = 0;

   for(int i=1;i<=32;i++)
    {
        if(j%2==0)
        {
            if(ustawienie[i-1].typ == 1) cout <<"-X";
            if(ustawienie[i-1].typ == 0) cout <<"-_";
            if(ustawienie[i-1].typ == 2) cout <<"-0";
            if(ustawienie[i-1].typ == 3) cout <<"-B";
            if(ustawienie[i-1].typ == 4) cout <<"-C";
        }
        if(j%2==1)
        {
            if(ustawienie[i-1].typ == 1) cout <<"X-";
            if(ustawienie[i-1].typ == 0) cout <<"_-";
            if(ustawienie[i-1].typ == 2) cout <<"0-";
            if(ustawienie[i-1].typ == 3) cout <<"B-";
            if(ustawienie[i-1].typ == 4) cout <<"C-";
        }
        if(i%4 == 0)
        {
            if(j%2==0) cout <<"        "<<" "<< i-4 << " " << i-3 << " " << i-2 << " " <<i-1;
            if(j%2==1) cout <<"        "<< i-4 << " " << i-3 << " " << i-2 << " " <<i-1<<" ";
            cout<<endl;
            j++;
        }
    }
    cout << endl;
}
