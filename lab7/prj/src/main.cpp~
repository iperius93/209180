#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <list>

/*!
 *   \file
 *   \brief Plik główny
 *
*/

/*!
 *	\brief Modeluje interfejs Obserwator
 *
 *	Klasa modeluje interfejs dziedziczony miedzy innymi
	przez klase ObserwatorUser. Zawiera wirtualną metodę
	update. 
*/
class Obserwator
{
	public:
	/*!
	 *	\brief Metoda wirtualna .

	*/
	virtual void update() = 0;
};

/*!
 *	\brief Modeluje pojącie Obserwowany
 *
 *	Klasa modeluje pojącie Obserwowany. Jest to klasa która
	zawiera liste obserwatorów. Można dodawać oraz usuwać kolejnych 
	obserwatorów.
*/
class Obserwowany
{
	protected:
	/*!
	 *	\brief Lista obserwatorów.
	 *	
	 *	Lista przechowuje wszystkich obserwatorów. 
	*/
		std::list <Obserwator*> obserwatorzy;
	public:
	/*!
	 *	\brief Metoda za pomocą której możemy dodać nowy obserwator do listy.
	 *	
	 *	Dodaje nowy obserwator do listy obserwatorów.
	*/
    	void dodaj(Obserwator *o) {
        	obserwatorzy.push_back (o);
    	}
	/*!
	 *	\brief Metoda za pomocą której możemy usuną obserwator z listy.
	 *	
	 *	Usuwa obserwator z listy obserwatorów.
	*/
    	void usun(Obserwator *o) {
        	obserwatorzy.remove (o);
   	}
	/*!
	 *	\brief Metoda za pomocą której sprawdzamy czy nie zaszy zmiany w obserwowanych obiektach.
	 *	
	 *	Za jej pomocą sprawdzamy po kolei wszystkie obserwowane obiekty czy nie zaszła w nich zmiana.
	*/
	void powiadom () {
        	std::list<Obserwator *>::iterator it;
        	for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) {
        	    (*it)->update ();
        }
    }
};


#include "element.hh"
#include "single_list.hh"
#include "queue.hh"
#include "stack.hh"
#include "lista.hh"
#include "benchmark.hh"

/*!
 *	\brief Modeluje pojącie ObserwowanyBenchmark
 *
 *	Klasa modeluje pojącie ObserwowanyBenchmark. Jest to klasa która
	modeluje obiekt obserwowany konkretny z cehami Benchmarka. 
*/
class ObserwowanyBenchmark : public Obserwowany, public Benchmark
{
	/*!
	 *	\brief Przechowuje ciag znaków jako wiadomość o stanie obserwowanego obiektu.
	 *	
	 *	Przechowuje informacje o stanie obiektu obserwowanego.
	*/
	string stan;
	public:
 	/*!
	 *	\brief Metoda za pomocą której dosatjemy się do prywatnego pola.
	 *	
	 *	Za jej pomocą mamy dostęp do prywatnego pola klasy.
	*/
        std::string pobierzStan () {
        	return stan;
   	}

 	/*!
	 *	\brief Metoda za pomocą której zmieniamy stan naszego obiektu.
	 *	\param s - ciag znakow, informujacy o stanie obiektu.	

	 *	Za jej pomocą mamy zmieniamy stan naszego obiektu.
	*/
        void ustawStan (const std::string& s) {
        	stan = s;
        	std::cout << "Stan: " << stan << std::endl;
        	powiadom();
    	}
};

/*!
 *	\brief Modeluje pojącie ObserwatorUser
 *
 *	Klasa modeluje pojącie ObserwowanyUser. Jest to klasa która
	modeluje obiekt obserwujący konkretny obiekt (u nas obserwuje Benchmarka).
*/
class ObserwatorUser : public Obserwator
{
	/*!
	 *	\brief Zmienna przechowuje numer Obserwatora.

	 *	Przechowuje numer obserwatora, za pomocą którego identyfikujey obserwatory.
	*/
	int idBenchmarku;
	/*!
	 *	\brief Zmienna przechowuje numer obserwowany obiekt.

	 *	Przechowuje obiekt którego obserwujemy.
	*/
	ObserwowanyBenchmark *test;

	/*!
	 *	\brief Zmienna skojarzona z plikiem.

	 *	Zmienna skojarzona z plikem w którym zapisujemy informacje o zmianach "logi"
	*/
	fstream plik_log;

	public:
	/*!
	 *	\brief Konstruktor klasy ObserwatorUser
		\param h - wskaznik na obserwowany obiekt 
		\param id - numer identifikacyjny obserwatora.

	 *	Inicjalizuje pola idBenchmarku oraz test.
	*/
	ObserwatorUser(ObserwowanyBenchmark *h, int id)    //konstruktor
	{
		idBenchmarku = id;
		test = h;
	} 

	/*!
	 *	\brief Uaktualnia informacje o tym w jakim stanie jest obserwowany obiekt.

	 *	Zapisuje do pliku informacje o stanie obserwowanego obiektu.
	*/
	void update()
	{
		string stan = test->pobierzStan();

		plik_log.open("log.txt",std::ios::out | std::ios::app);
		if( plik_log.good() == true )
		{
			if (!stan.compare ("Rozpoczynam generowanie liczb")) 
			{
           			plik_log <<"Benchmark " << idBenchmarku << ": Rozpoczął losowanie liczb.\n" << std::endl;
        		}
			else if (!stan.compare ("Liczby wygenerowane")) 
			{
           			plik_log << "Benchmark " << idBenchmarku << ": Wygenerowal losowe liczby.\n" << std::endl;
        		}
			else if (!stan.compare ("Rozpoczalem test")) 
			{
            			plik_log << "Benchmark " << idBenchmarku << ": Rozpoczal wykonywanie testu.\n" << std::endl;
			}
			else if (!stan.compare ("Zakonczyłem test")) 
			{
            			plik_log << "Benchmark" << idBenchmarku << ": Zakonczyl wykonywanie testu.\n" << std::endl;
			}

		} else cout << "Dostep do pliku zostal zabroniony!" << endl;
	
		plik_log.close();

		
		if (!stan.compare ("Rozpoczynam generowanie liczb")) 
		{
           		std::cout <<"Benchmark " << idBenchmarku << ": Rozpoczął losowanie liczb.\n" << std::endl;
        	}
		else if (!stan.compare ("Liczby wygenerowane")) 
		{
           		std::cout <<"Benchmark " << idBenchmarku << ": Wygenerowal losowe liczby.\n" << std::endl;
        	}
		else if (!stan.compare ("Rozpoczalem test")) {
            		std::cout << "Benchmark " << idBenchmarku << ": Rozpoczal wykonywanie testu.\n" << std::endl;
		}
		else if (!stan.compare ("Zakonczyłem test")) {
            		std::cout << "Benchmark" << idBenchmarku << ": Zakonczyl wykonywanie testu.\n" << std::endl;
		}
	}	
};


using namespace std;	

int main()
{

	ObserwowanyBenchmark test;
	Obserwator *user1 = new ObserwatorUser(&test,1);
	
	test.dodaj(user1);

	
	int ilosc = 10;
	int ilosc2 = 10000000; 
	Benchmark Test;
	Lista Testowana;

	test.ustawStan("Rozpoczynam generowanie liczb");
	Test.generuj_liczby(ilosc2,30);
	test.ustawStan("Liczby wygenerowane");
	
	// Lista jednokierunkowa 1
	// Kolejka 2
	// Stos 3
	for(ilosc=10;ilosc<=ilosc2;ilosc*=10)
	{
		test.ustawStan("Rozpoczalem test");
		test.testuj(Testowana,1,10,ilosc);
		test.ustawStan("Zakonczyłem test");
	}
	
	delete user1;
	
	

	
	return 0;

}
