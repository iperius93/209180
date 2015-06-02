#include "graf.hh"
#include <fstream>

/*!
 *   \file
 *   \brief Definicja metod klasy graf
 *
 *
 *
 *
*/

using namespace std;

graf::graf(int wierzcholki, int krawedzie)
{
    n = wierzcholki;
    m = krawedzie;
    d = new int [wierzcholki];                // Tablica kosztów dojścia
    p = new int [wierzcholki];                // Tablica poprzedników
    QS = new bool [wierzcholki];              // Zbiory Q i S
    sasiedztwo = new slistEl * [wierzcholki];       // Tablica list sąsiedztwa
    S = new int [wierzcholki];                // Stos
    sptr = 0;

    for(i = 0; i < n; i++)
    {
        d[i] = MAXINT;
        p[i] = -1;
        QS[i] = false;
        sasiedztwo[i] = NULL;
    }               // Wskaźnik stosu
}

graf::~graf()
{
    delete [] d;
    delete [] p;
    delete [] QS;
    delete [] S;

    for(i = 0; i < n; i++)
    {
        pw = sasiedztwo[i];
        while(pw)
        {
            rw = pw;
            pw = pw->next;
            delete rw;
        }
    }
}


void graf::inicjalizuj()
{
    //cout << "INICJALIZACJA GRAF'U.\n";
    //cout <<"Musisz podać "<<m<<" krawedzi\n";
    //cout <<"Krawedz dotyczy dwoch wierzcholkow, sposob podawania danych\n";
    fstream plik_danych;
    plik_danych.open("dane.txt",std::ios::in);
    if( plik_danych.good() == true )
    {
        for(i = 0; i < m; i++)
        {
            //cout << "Wierzcholek1 Wierzcholek2 "<<i<<endl;
            plik_danych >> x >> y;           // Odczytujemy krawędź z wagą
            //cout << x <<" "<< y<<endl<<endl;
            pw = new slistEl;             // Tworzymy element listy sąsiedztwa
            pw->v = y;                    // Wierzchołek docelowy krawędzi
            pw->w = 1;                    // Waga krawędzi
            pw->next = sasiedztwo[x];
            sasiedztwo[x] = pw;                 // Element dołączamy do listy
        }
        //cout << endl;
    }
    plik_danych.close();
}

void graf::find_min_sciezke(int poczatek, int X)
{
    v = poczatek;
    d[v] = 0;

    // Wyznaczamy ścieżki

    for(i = 0; i < n; i++)
    {
        // Szukamy wierzchołka w Q o najmniejszym koszcie d

        for(j = 0; QS[j]; j++);
        for(u = j++; j < n; j++)
            if(!QS[j] && (d[j] < d[u])) u = j;

        // Znaleziony wierzchołek przenosimy do S

        QS[u] = true;

        // Modyfikujemy odpowiednio wszystkich sąsiadów u, którzy są w Q

        for(pw = sasiedztwo[u]; pw; pw = pw->next)
        if(!QS[pw->v] && (d[pw->v] > d[u] + pw->w))
        {
            d[pw->v] = d[u] + pw->w;
            p[pw->v] = u;
        }
    }

    // Gotowe, wyświetlamy wyniki

    i = X;

    cout << i << ": ";

    // Ścieżkę przechodzimy od końca ku początkowi,
    // Zapisując na stosie kolejne wierzchołki

    for(j = i; j > -1; j = p[j]) S[sptr++] = j;

    // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu

    while(sptr) cout << S[--sptr] << " ";

    // Na końcu ścieżki wypisujemy jej koszt

    //cout << "$" << d[i] << endl;

    for(i = 0; i < n; i++)
    {
        d[i] = MAXINT;
        p[i] = -1;
        QS[i] = false;
    }

}

void graf::DFS(int poczatek)
{
    v = poczatek;
    slistEl * p;

    QS[v] = true;     // Zaznaczamy węzeł jako odwiedzony
    cout << setw(3) << v;  // Przetwarzamy węzeł (wypisujemy jego numer)

    // Rekurencyjnie odwiedzamy nieodwiedzonych sąsiadów

    for(p = sasiedztwo[v]; p; p = p->next)
        if(!QS[p->v]) DFS(p->v);
}
void graf::BFS(int poczatek)
{
    v = poczatek;
    slistEl *r,*q,*head,*tail; // Kolejka

    q = new slistEl;        // W kolejce umieszczamy v
    q->next = NULL;
    q->v = v;
    head = tail = q;

    QS[v] = true;      // Wierzchołek v oznaczamy jako odwiedzony

    while(head)
    {
        v = head->v;          // Odczytujemy v z kolejki

        q = head;             // Usuwamy z kolejki odczytane v
        head = head->next;
        if(!head) tail = NULL;
        delete q;

        cout << setw(3) << v;

        for(r = sasiedztwo[v]; r; r = r->next)
            if(!QS[r->v])
            {
                q = new slistEl; // W kolejce umieszczamy nieodwiedzonych sąsiadów
                q->next = NULL;
                q->v = r->v;
                if(!tail) head = q;
                else      tail->next = q;
                tail = q;
                QS[r->v] = true; // i oznaczamy ich jako odwiedzonych
            }
    }

    for(i = 0; i < n; i++)
    {
        d[i] = MAXINT;
        p[i] = -1;
        QS[i] = false;
    }

}
