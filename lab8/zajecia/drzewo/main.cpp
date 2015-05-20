#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
using namespace std;

//definicja wezla
struct wezel
{
    int wartosc;           //wartosc przechowywana w wezle
    wezel *rodzic;  //wskaznik na rodzica
    wezel *lewy_syn;   //wskaznik na lewe dziecko
    wezel *prawy_syn;   //wskaznik na prawe dziecko
};

class drzewo
{
    public:
    wezel *korzen;
    int licznik;

    drzewo();
    ~drzewo();
    bool dodaj(wezel *nowy);
    wezel* szukaj(int key);
    wezel* min_wezel(wezel* x);
    wezel* max_wezel(wezel* x);
    wezel* poprzednik(wezel *x);
    wezel* nastepca(wezel *x);
    wezel* usun(wezel *x);
    wezel* preorder(wezel *x);
    wezel* inorder(wezel *x);
    wezel* postorder(wezel *x);
    int liczba_wezlow()
    {
        return licznik;
    }
};

drzewo::drzewo()
{
    korzen = NULL;
    licznik = 0;
}

drzewo::~drzewo()
{
    while(korzen) delete(usun(korzen));
}

bool drzewo::dodaj(wezel *nowy)
{
    wezel *y, *x = korzen;

    y = nowy->lewy_syn = nowy->prawy_syn = NULL;

    while(x)
    {
        if(nowy->wartosc == x->wartosc)
        {
            delete nowy;
            return false;
        }
        y = x;
        x = (nowy->wartosc < x->wartosc) ? x->lewy_syn : x->prawy_syn;
    }
    nowy->rodzic = y;

    if(!y) korzen = nowy;
    else if (nowy->wartosc < y->wartosc) y->lewy_syn = nowy;
    else y->prawy_syn = nowy;

    licznik++;
    return true;
}

wezel* drzewo::szukaj(int key)
{
    wezel *x = korzen;

    while((x) && (x->wartosc != key))
        x = (key < x->wartosc) ? x->lewy_syn : x->prawy_syn;

    return x;
}

wezel* drzewo::min_wezel(wezel* x)
{
    while(x->lewy_syn) x = x->lewy_syn;
    return x;
}
wezel* drzewo::max_wezel(wezel* x)
{
    while(x->prawy_syn) x = x->prawy_syn;
    return x;
}

wezel* drzewo::poprzednik(wezel *x)
{
    if(x->lewy_syn) return max_wezel(x->lewy_syn);

    wezel *y;

    do
    {
        y = x;
        x = x->rodzic;
    } while(x && (x->prawy_syn != y));

    return x;
}

wezel* drzewo::nastepca(wezel *x)
{
    if(x->prawy_syn) return min_wezel(x->prawy_syn);

    wezel *y;

    do
    {
        y = x;
        x = x->rodzic;
    } while(x && (x->lewy_syn != y));

    return x;
}

wezel* drzewo::usun(wezel *x)
{
    wezel *y = x->rodzic, *z;

    if((x->lewy_syn) && (x->prawy_syn))
    {
        z = (rand() % 2) ? usun(poprzednik(x)) : usun(nastepca(x));
        z->lewy_syn = x->lewy_syn;
        if(z->lewy_syn) z->lewy_syn->rodzic = z;
        z->prawy_syn = x->prawy_syn;
        if(z->prawy_syn) z->prawy_syn->rodzic = z;
        licznik++;
    }
    else z = (x->lewy_syn) ? x->lewy_syn : x->prawy_syn;

    if(z) z->rodzic = y;

    if(!y) korzen = z;
    else if(y->lewy_syn == x) y->lewy_syn = z;
    else y->prawy_syn = z;

    licznik--;
    return x;
}

wezel* drzewo::preorder(wezel *x)
{
    if(x)
    {
        cout << x->wartosc <<endl;
        preorder(x->lewy_syn);
        preorder(x->prawy_syn);
    }
}

wezel* drzewo::inorder(wezel *x)
{
    if(x)
    {
        inorder(x->lewy_syn);
        cout << x->wartosc <<endl;
        inorder(x->prawy_syn);
    }
}

wezel* drzewo::postorder(wezel *x)
{
    if(x)
    {
        postorder(x->lewy_syn);
        postorder(x->prawy_syn);
        cout << x->wartosc <<endl;
    }
}

int main()
{
    int rozmiar=0, liczba =0;
    cout << "Ile bedzie liczb: ";
    cin >> rozmiar;
    cout << endl;
    drzewo test;
    wezel *nowy;
    for(int i = 0; i<rozmiar; i++)
    {
        nowy = new wezel;
        cin >> nowy->wartosc;
        test.dodaj(nowy);
    }
    test.preorder(test.korzen);
    //int *tablica_danych = new int [rozmiar];
/*
    fstream plik_danych;
    plik_danych.open("dane.txt",std::ios::in);
    if( plik_danych.good() == true )
	{
        int i=0;
		while(!plik_danych.eof())
		{
            plik_danych >> tablica_danych[i];
            i++;
		}
	} else cout << "Dostep do pliku zostal zabroniony!" << endl;*/
    //quicksort(tablica_danych,0,rozmiar-1);

    //int index_mediany_calego = mediana(tablica_danych,0,rozmiar);
    //dodaj_wezel(tablica_danych[mediana(tablica_danych,0,rozmiar)],root);    // dodaj korzen mediana calego zbioru

    //for(int a=0;a<rozmiar;a++)
    //{
    //    dodaj_wezel(tablica_danych[index_mediany_calego],root);
    //}
    //cout << endl <<tablica_danych[mediana(tablica_danych,0,rozmiar-1)];

    //cout << root->l_syn->wartosc << endl<<endl;


	//plik_danych.close();
    return 0;
}
/*
//przejdz drzewo w kolejnosci zaczynajac od wezla start
void in_order_tree_walk(struct wezel *start)
{
    if(start->l_syn != NULL) in_order_tree_walk(start->l_syn); //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie

    cout << start->wartosc<<endl;

   // if(start->p_syn != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
    //in_order_tree_walk(start->p_syn);
}

void dodaj_wezel(int value, wezel *start)
{
    if(root == NULL)  // jesli korzen wstaw wartosc
    {
        root = new wezel();
        root->wartosc = value;
        root->rodzic = NULL;
        root->l_syn = NULL;
        root->p_syn = NULL;
    }
    else if (value < start->wartosc)    //jezeli zadana wartosc jest mniejsza od korzenia idz do lewego poddrzewa
    {
        if(start->l_syn != NULL)        //jezeli lewe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
        {
            dodaj_wezel(value,start->l_syn);
        }
        else        //jezeli lewe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
        {
            wezel *nowy = new wezel();
            nowy->wartosc = value;
            nowy->l_syn = NULL;
            nowy->p_syn = NULL;
            nowy->rodzic = start;
            start->l_syn=nowy;
        }
    }
    else    //jezeli zadana wartosc jest wieksza lub rowna korzeniowi idz do prawego poddrzewa
    {
        if(start->p_syn!=NULL)
        {
            dodaj_wezel(value,start->p_syn);
        }
        else    //jezeli prawe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
        {
            wezel *nowy = new wezel();
            nowy->wartosc = value;
            nowy->l_syn = NULL;
            nowy->p_syn = NULL;
            nowy->rodzic = start;
            start->p_syn=nowy;
        }
    }
}
void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v) i++;
        while (tablica[j]>v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++; j--;
        }
    } while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j);
    if(i<prawy) quicksort(tablica, i, prawy);
}

int mediana(int *tablica,int lewy, int prawy)
{
    if((prawy + lewy + 1) % 2 == 0)     // parzysta liczba elementów
    {
        return (prawy + lewy + 1)/2 - 1;    // zwroc indeks/adres mediany
    }
    else                     // nieparzysta liczba elementow
    {
        return (prawy + lewy - 1)/2;        // zwroc indeks/adres mediany
    }
}

*/
