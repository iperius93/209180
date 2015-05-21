#include <iostream>

const int MAXINT = 2147483647;

using namespace std;

// Typy danych

struct slistEl
{
  slistEl * next;
  int v,w;                        // numer węzła docelowego i waga krawędzi
};

class graf
{
    public:
    int i,j,m,n,v,u,w,x,y,sptr,*d,*p,*S;
    slistEl **sasiedztwo;                 // Tablica list sąsiedztwa
    slistEl *pw,*rw;
    bool *QS;//

    graf(int wierzcholki, int krawedzie)
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

    ~graf()
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

    void inicjalizuj();
    void find_min_sciezke(int poczatek, int X);

};

void graf::inicjalizuj()
{
    cout << "INICJALIZACJA GRAF'U.\n";
    cout <<"Musisz podać "<<m<<" krawedzi\n";
    cout <<"Krawedz dotyczy dwoch wierzcholkow, sposob podawania danych\n";

    for(i = 0; i < m; i++)
    {
        cout << "Wierzcholek1 Wierzcholek2 ";
        cin >> x >> y;           // Odczytujemy krawędź z wagą
        pw = new slistEl;             // Tworzymy element listy sąsiedztwa
        pw->v = y;                    // Wierzchołek docelowy krawędzi
        pw->w = 1;                    // Waga krawędzi
        pw->next = sasiedztwo[x];
        sasiedztwo[x] = pw;                 // Element dołączamy do listy
    }
    cout << endl;
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

}
// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main()
{
    int liczba_wierszy,liczba_krawedzi;
    int szukany;
    cout << "Podaj liczbe wierzcholków: ";
    cin >> liczba_wierszy;
    cout << "Podaj liczbe krawedzi: ";
    cin >> liczba_krawedzi;
    graf test(liczba_wierszy,liczba_krawedzi);
    test.inicjalizuj();
    cout<<"Ktorego wezla mam podac sciezke: ";
    cin >> szukany;
    test.find_min_sciezke(0,szukany);

    return 0;
}
