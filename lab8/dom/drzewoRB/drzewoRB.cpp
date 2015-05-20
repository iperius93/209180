#include "drzewoRB.h"

/*!
 *   \file
 *   \brief Definicja metod klasy drzewoRB
 *
 *
 *
 *
*/

/*!

 */
drzewoRB::drzewoRB()
{
    cr = cl = cp = "  ";
    straznik.kolor = 'B';
    straznik.rodzic = &straznik;
    straznik.lewy_syn = &straznik;
    straznik.prawy_syn = &straznik;
    korzen = &straznik;
}
/*!

 */
drzewoRB::~drzewoRB()
{
    zniszcz(korzen);
}
/*!

 */
void drzewoRB::zniszcz(wezelRB *p)
{
    if(p != &straznik)
    {
        zniszcz(p->lewy_syn);
        zniszcz(p->prawy_syn);
        delete p;
    }
}
/*!

 */
void drzewoRB::wyswietlRB(string sp, string sn, wezelRB *p)
{
    string t;

    if(p != &straznik)
    {
        t = sp;
        if(sn == cr) t[t.length() - 2] = ' ';
        wyswietlRB(t+cp,cr,p->prawy_syn);

        t = t.substr(0,sp.length()-2);
        cout << t << sn << p->kolor << ":" << p->wartosc<<endl;

        t = sp;
        if(sn == cl) t[t.length() - 2] = ' ';
        wyswietlRB(t+cp,cl,p->lewy_syn);
    }
}
/*!

 */
void drzewoRB::print()
{
    wyswietlRB("","",korzen);
}
/*!

 */
wezelRB* drzewoRB::szukaj(int k)
{
    wezelRB *p;

    p = korzen;
    while((p != &straznik) && (p->wartosc != k))
        if(k < p->wartosc) p = p->lewy_syn;
        else p = p->prawy_syn;
    if(p == &straznik) return NULL;
    return p;
}
/*!

 */
wezelRB* drzewoRB::min_wezel(wezelRB *p)
{
    if(p != &straznik)
        while(p->lewy_syn != &straznik) p = p->lewy_syn;
    return p;
}
/*!

 */
wezelRB* drzewoRB::nastepca(wezelRB *p)
{
    wezelRB *r;

    if(p != &straznik)
    {
        if(p->prawy_syn != &straznik) return min_wezel(p->prawy_syn);
        else
        {
            r = p->rodzic;
            while((r != &straznik) && (p == r->prawy_syn))
            {
                p = r;
                r = r->rodzic;
            }
            return r;
        }
    }
    return &straznik;
}
/*!

 */
void drzewoRB::rot_L(wezelRB *A)
{
    wezelRB *B, *p;

    B = A->prawy_syn;
    if(B != &straznik)
    {
        p = A->rodzic;
        A->prawy_syn = B->lewy_syn;
        if(A->prawy_syn != &straznik) A->prawy_syn->rodzic = A;

        B->lewy_syn = A;
        B->rodzic = p;
        A->rodzic = B;

        if(p != &straznik)
        {
            if(p->lewy_syn == A) p->lewy_syn = B;
            else p->prawy_syn = B;
        }
        else korzen = B;
    }
}
/*!

 */
void drzewoRB::rot_R(wezelRB *A)
{
    wezelRB *B, *p;

    B = A->lewy_syn;
    if(B != &straznik)
    {
        p = A->rodzic;
        A->lewy_syn = B->prawy_syn;
        if(A->lewy_syn != &straznik) A->lewy_syn->rodzic = A;

        B->prawy_syn = A;
        B->rodzic = p;
        A->rodzic = B;

        if(p != &straznik)
        {
            if(p->lewy_syn == A) p->lewy_syn = B;
            else p->prawy_syn = B;
        }
        else korzen = B;
    }
}
/*!

 */
void drzewoRB::dodaj(int k)
{
    wezelRB *X, *Y;

    X = new wezelRB;
    X->lewy_syn = &straznik;
    X->prawy_syn = &straznik;
    X->rodzic = korzen;
    X->wartosc = k;
    if(X->rodzic == &straznik) korzen = X;
    else
    {
        while(true)
        {
            if(k < X->rodzic->wartosc)
            {
                if(X->rodzic->lewy_syn == &straznik)
                {
                    X->rodzic->lewy_syn = X;
                    break;
                }
                X->rodzic = X->rodzic->lewy_syn;
            }
            else
            {
                if(X->rodzic->prawy_syn == &straznik)
                {
                    X->rodzic->prawy_syn = X;
                    break;
                }
                X->rodzic = X->rodzic->prawy_syn;
            }
        }
        X->kolor = 'R';
        while((X != korzen) && (X->rodzic->kolor == 'R'))
        {
            if(X->rodzic == X->rodzic->rodzic->lewy_syn)
            {
                Y = X->rodzic->rodzic->prawy_syn;

                if(Y->kolor == 'R')
                {
                    X->rodzic->kolor = 'B';
                    Y->kolor = 'B';
                    X->rodzic->rodzic->kolor = 'R';
                    X = X->rodzic->rodzic;
                    continue;
                }

                if(X == X->rodzic->prawy_syn)
                {
                    X = X->rodzic;
                    rot_L(X);
                }

                X->rodzic->kolor = 'B';
                X->rodzic->rodzic->kolor = 'R';
                rot_R(X->rodzic->rodzic);
                break;
            }
            else
            {
                Y = X->rodzic->rodzic->lewy_syn;

                if(Y->kolor == 'R')
                {
                    X->rodzic->kolor = 'B';
                    Y->kolor = 'B';
                    X->rodzic->rodzic->kolor = 'R';
                    X = X->rodzic->rodzic;
                    continue;
                }

                if(X == X->rodzic->lewy_syn) // Przypadek 2
                {
                    X = X->rodzic;
                    rot_R(X);
                }

                X->rodzic->kolor = 'B'; // Przypadek 3
                X->rodzic->rodzic->kolor = 'R';
                rot_L(X->rodzic->rodzic);
                break;
            }
            korzen->kolor = 'B';
        }
    }
}
/*!

 */
void drzewoRB::usun(wezelRB *X)
{
    wezelRB *W, *Y, *Z;

    if((X->lewy_syn == &straznik) || (X->prawy_syn == &straznik)) Y = X;
    else Y = nastepca(X);

    if(Y->lewy_syn != &straznik) Z = Y->lewy_syn;
    else Z = Y->prawy_syn;

    Z->rodzic = Y->rodzic;

    if(Y->rodzic == &straznik) korzen = Z;
    else if(Y == Y->rodzic->lewy_syn) Y->rodzic->lewy_syn = Z;
    else Y->rodzic->prawy_syn = Z;

    if(Y != X) X->wartosc = Y->wartosc;

    if(Y->kolor == 'B')
    {
        while((Z != korzen) && (Z->kolor == 'B'))
        {
            if(Z == Z->rodzic->lewy_syn)
            {
                W = Z->rodzic->prawy_syn;

                if(W->kolor == 'R')
                {
                    W->kolor = 'B';
                    Z->rodzic->kolor = 'R';
                    rot_L(Z->rodzic);
                    W = Z->rodzic->prawy_syn;
                }

                if((W->lewy_syn->kolor) && (W->prawy_syn->kolor == 'B'))
                {
                    W->kolor = 'R';
                    Z = Z->rodzic;
                    continue;
                }

                if(W->prawy_syn->kolor == 'B')
                {
                    W->lewy_syn->kolor = 'B';
                    W->kolor = 'R';
                    rot_R(W);
                    W = Z->rodzic->prawy_syn;
                }

                W->kolor = Z->rodzic->kolor;
                Z->rodzic->kolor = 'B';
                W->prawy_syn->kolor = 'B';
                rot_L(Z->rodzic);
                Z = korzen;
            }
            else
            {
                W = Z->rodzic->lewy_syn;

                if(W->kolor == 'R')
                {
                    W->kolor = 'B';
                    Z->rodzic->kolor = 'R';
                    rot_R(Z->rodzic);
                    W = Z->rodzic->lewy_syn;
                }

                if((W->lewy_syn->kolor) && (W->prawy_syn->kolor == 'B'))
                {
                    W->kolor = 'R';
                    Z = Z->rodzic;
                    continue;
                }

                if(W->lewy_syn->kolor == 'B')
                {
                    W->prawy_syn->kolor = 'R';
                    W->kolor = 'R';
                    rot_L(W);
                    W = Z->rodzic->lewy_syn;
                }

                W->kolor = Z->rodzic->kolor;
                Z->rodzic->kolor = 'B';
                W->lewy_syn->kolor = 'B';
                rot_R(Z->rodzic);
                Z = korzen;
            }

            Z->kolor = 'B';
        }
    }

    delete Y;
}