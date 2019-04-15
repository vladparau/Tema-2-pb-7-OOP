#include <iostream>
#include <fstream>
using namespace std;
class matrice;
class matrice_oarecare;
class matrice_patratica;
istream &operator >>(istream &in,matrice_oarecare &a);
ostream &operator <<(ostream &out,matrice_oarecare &a);
istream &operator >>(istream &in,matrice_patratica &a);
ostream& operator << (ostream &out, matrice_patratica &a);

class complex
{

    float re,im;
    friend class matrice;
    friend class matrice_oarecare;
    friend class matrice_patratica;
    friend istream &operator >>(istream &in,matrice_oarecare &a);
    friend ostream &operator <<(ostream &out,matrice_oarecare &a);
    friend istream &operator >>(istream &in,matrice_patratica &a);
    friend ostream &operator <<(ostream &out,matrice_patratica &a);

};
class matrice
{
protected:
    complex **v;
    int lin,col;
public:
    matrice ()
    {
        v=new complex*[100];
        for (int i=0; i<100; i++)
            v[i]=new complex[100];
        lin=col=100;
    }
    matrice(int l,int c)
    {
        v=new complex*[l];
        for (int i=0; i<l; i++)
            v[i]=new complex[c];



    }
    virtual ~matrice ()
    {
        for (int i=0; i<col; i++)
            delete[] v[i];
        delete []v;

    }


};
class matrice_oarecare: public matrice
{
public:
    matrice_oarecare(int l,int c):matrice(l,c) {}
    friend istream &operator >>(istream &in,matrice_oarecare &a)
    {
        in>>a.lin>>a.col;
        int i,j;
        for (i=0; i<a.lin; i++)
            for (j=0; j<a.col; j++)
                in>>a.v[i][j].re>>a.v[i][j].im;
        return in;
    }
    friend ostream &operator <<(ostream &out,matrice_oarecare &a)
    {
        int i,j;
        for (i=0; i<a.lin; i++)
        {
            for (j=0; j<a.col; j++)
                if (a.v[i][j].im>=0)
                    out<<a.v[i][j].re<<"+"<<a.v[i][j].im<<"*i ";
                else
                    out<<a.v[i][j].re<<a.v[i][j].im<<"*i ";
            out<<endl;
        }
        return out;
    }




    ~matrice_oarecare() {}
};
class matrice_patratica: public matrice
{
public:
    matrice_patratica(int dim):matrice(dim,dim) {}
    friend istream &operator >> (istream &in,matrice_patratica &a)
    {
        in>>a.lin;
        a.col=a.lin;
        int i,j;
        for (i=0; i<a.lin; i++)
            for (j=0; j<a.col; j++)
                in>>a.v[i][j].re>>a.v[i][j].im;
        return in;
    }
    friend ostream& operator << (ostream &out, matrice_patratica &a)
    {
        int i,j;
        for (i=0; i<a.lin; i++)
        {
            for (j=0; j<a.col; j++)
                if (a.v[i][j].im>=0)
                    out<<a.v[i][j].re<<"+"<<a.v[i][j].im<<"*i ";
                else
                    out<<a.v[i][j].re<<a.v[i][j].im<<"*i ";
            out<<endl;
        }

        if (a.lin==1)
        {
            if (a.v[0][0].im>=0)
                cout<<"Determinantul este: "<<a.v[0][0].re<<"+"<<a.v[0][0].im<<"*i "<<endl;
            else if (a.v[0][0].im<0)
                cout<<"Determinantul este: "<<a.v[0][0].re<<a.v[0][0].im<<"*i "<<endl;
        }


        complex rez;
        if (a.lin==2)
        {

            rez.re=a.v[0][0].re * a.v[1][1].re - a.v[0][0].im * a.v[1][1].im - (a.v[0][1].re * a.v[1][0].re - a.v[0][1].im * a.v[1][0].im);
            rez.im=a.v[0][0].re * a.v[1][1].im + a.v[0][0].im * a.v[1][1].re - (a.v[0][1].re * a.v[1][0].im + a.v[0][1].im * a.v[1][0].re);
            if (rez.im>=0)
                cout<<"Determinantul este: "<<rez.re<<"+"<<rez.im<<"*i ";
            else
                cout<<"Determinantul este: "<<rez.re<<rez.im<<"*i ";


        }

        complex rez2;
        if (a.lin==3)
        {
            rez.re=a.v[0][0].re*a.v[1][1].re*a.v[2][2].re - a.v[0][0].re*a.v[1][1].im*a.v[2][2].im - a.v[0][0].im*a.v[1][1].re*a.v[2][2].im - a.v[0][0].im*a.v[1][1].im*a.v[2][2].re;
            rez.re+=a.v[1][0].re*a.v[2][1].re*a.v[0][2].re - a.v[1][0].re*a.v[2][1].im*a.v[0][2].im - a.v[1][0].im*a.v[2][1].re*a.v[0][2].im - a.v[1][0].im*a.v[2][1].im*a.v[0][2].re;
            rez.re+=a.v[0][1].re*a.v[1][2].re*a.v[2][0].re - a.v[0][1].re*a.v[1][2].im*a.v[2][0].im - a.v[0][1].im*a.v[1][2].re*a.v[2][0].im - a.v[0][1].im*a.v[1][2].im*a.v[2][0].re;


            rez2.re=a.v[0][2].re*a.v[1][1].re*a.v[2][0].re - a.v[0][2].re*a.v[1][1].im*a.v[2][0].im - a.v[0][2].im*a.v[1][1].re*a.v[2][0].im - a.v[0][2].im*a.v[1][1].im*a.v[2][0].re;
            rez2.re+=a.v[0][0].re*a.v[1][2].re*a.v[2][1].re - a.v[0][0].re*a.v[1][2].im*a.v[2][1].im - a.v[0][0].im*a.v[1][2].re*a.v[2][1].im - a.v[0][0].im*a.v[1][2].im*a.v[2][1].re;
            rez2.re+=a.v[1][0].re*a.v[0][1].re*a.v[2][2].re - a.v[1][0].re*a.v[0][1].im*a.v[2][2].im - a.v[1][0].im*a.v[0][1].re*a.v[2][2].im - a.v[1][0].im*a.v[0][1].im*a.v[2][2].re;

            rez.im=a.v[0][0].re*a.v[1][1].re*a.v[2][2].im + a.v[0][0].re*a.v[1][1].im*a.v[2][2].re + a.v[0][0].im*a.v[1][1].re*a.v[2][2].re - a.v[0][0].im*a.v[1][1].im*a.v[2][2].im;
            rez.im+=a.v[1][0].re*a.v[2][1].re*a.v[0][2].im + a.v[1][0].re*a.v[2][1].im*a.v[0][2].re + a.v[1][0].im*a.v[2][1].re*a.v[0][2].re - a.v[1][0].im*a.v[2][1].im*a.v[0][2].im;
            rez.im+=a.v[0][1].re*a.v[1][2].re*a.v[2][0].im + a.v[0][1].re*a.v[1][2].im*a.v[2][0].re + a.v[0][1].im*a.v[1][2].re*a.v[2][0].re - a.v[0][1].im*a.v[1][2].im*a.v[2][0].im;

            rez2.im=a.v[0][2].re*a.v[1][1].re*a.v[2][0].im + a.v[0][2].re*a.v[1][1].im*a.v[2][0].re + a.v[0][2].im*a.v[1][1].re*a.v[2][0].re - a.v[0][2].im*a.v[1][1].im*a.v[2][0].im;
            rez2.im+=a.v[0][0].re*a.v[1][2].re*a.v[2][1].im + a.v[0][0].re*a.v[1][2].im*a.v[2][1].re + a.v[0][0].im*a.v[1][2].re*a.v[2][1].re - a.v[0][0].im*a.v[1][2].im*a.v[2][1].im;
            rez2.im+=a.v[1][0].re*a.v[0][1].re*a.v[2][2].im + a.v[1][0].re*a.v[0][1].im*a.v[2][2].re + a.v[1][0].im*a.v[0][1].re*a.v[2][2].re - a.v[1][0].im*a.v[0][1].im*a.v[2][2].im;
            rez.re-=rez2.re;
            rez.im-=rez2.im;


            if (rez.im>=0)
                cout<<"Determinantul este: "<<rez.re<<"+"<<rez.im<<"*i "<<endl;
            else
                cout<<"Determinantul este: "<<rez.re<<rez.im<<"*i "<<endl;



        }


        return out;
    }
    void diagonala(matrice_patratica a)
    {
        int i,j,ok=1;;
        for (i=0; i<a.lin; i++)
            for (j=0; j<a.col; j++)
                if ((a.v[i][j].re!=0 || a.v[i][j].im!=0) && i!=j)
                    ok=0;
        if (ok)
            cout<<"matrice diagonala";
        else
            cout<<"nu e matrice diagonala";



    }




    ~matrice_patratica() {}
};
int main()
{
    ///matrice_oarecare a(2,3);
    ///cin>>a;
    ///cout<<a;
    matrice_patratica x(3);
    ifstream f("date.in");
    f>>x;
    cout<<x;
    ///x.diagonala(x);



    return 0;
}
