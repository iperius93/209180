#include <iostream>

using namespace std;

/*!
 *   \file
 *   \brief Plik glowny programu
*/

/*
    !!!!!!!!!!!!!!!  UWAGA UWAGA  !!!!!!!!!!!!!!!!!!!!!!!!!
    Jesli chcemy mape typu <string,int> ustawiamy w pliku element.h
    #define ZERO ""
    #define STRING_KEY 1
    Jesli chcemy mape typu <int,int> ustawiamy w pliku element.h
    #define ZERO 0
    #define STRING_KEY 0
*/

#include "map.h"

unsigned int hf_global(string key)
{
   
    unsigned int klucz_haszujacy = 0;

    for(int i = 0; i<key.length();i++)
    {
        klucz_haszujacy += key[i]*i;          //suma znakow klucza
    }

    klucz_haszujacy %= 400;    //modula = reszta z dzialenia

    return klucz_haszujacy;
}

int main()
{
    map<string,int> nowy(400);
    nowy["marzec"] = 30;
    cout <<"Indeks:"<<hf_global("marzec")<<" Liczba dni w marcu: "<< nowy["marzec"]<<"."<<endl;

    cout << "Znaleziono" << nowy.find("marzec")<<endl;
    
    nowy["styczen"] = 31;
    cout <<"Indeks: "<<hf_global("styczen")<<" Liczba dni w styczniu: "<< nowy["styczen"]<<"."<<endl;
    cout << "Znaleziono " << nowy.find("marzec")<<endl;
    nowy["luty"] = 28;
    cout <<"Indeks: "<<hf_global("luty")<<" Liczba dni w lutym: "<< nowy["luty"]<<"."<<endl;
    cout << "Znaleziono " << nowy.find("marzec")<<endl;
    cout << "Ostatni numer to: "<<nowy.end()<<endl;

    cout << "Znaleziono " << nowy.find("luty")<<endl;
    cout << "Znaleziono " << nowy.find("styczen")<<endl;

    nowy.erase(nowy.find("luty"));
    nowy.erase(nowy.find("styczen"));
    cout << "Znaleziono " << nowy.find("marzec")<<endl;

    /*
    cout <<"Liczba dni w styczniu: "<< nowy["styczen"]<<"."<<endl;
    cout << "liczba dni w lutym: "<< nowy["luty"]<<"."<<endl;
    nowy.erase("luty");
    cout << "liczba dni w lutym: "<< nowy["luty"]<<"."<<endl;
    nowy["luty"]=29;;
    cout << "liczba dni w lutym: "<< nowy["luty"]<<"."<<endl;*/


    return 0;
}
