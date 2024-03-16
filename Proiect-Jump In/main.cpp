#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <stdio.h>
#include "Menu.h"
#include "Nivele.h"
#include <mmsystem.h>
//#include "Tablaa.h"
//#include "MutariPiese.h"
// 0 - viziuna goala
// 1 - spatiu normal liber
// 2 - ciuperca
// 3 - iepure alb
// 4 - iepure gri
// 5 - iepure maro
/// 6 - cap vulpe in sus
///-1 - spate vulpe in sus
// 7 - iepure alb in vizuina
// 8 - iepure gri in vizuina
// 9 - iepure maro in vizuina
/// 10- cap vulpe la dreapta
/// 11- coada vulpe la dreapta
/// 12- cap vulpe in jos
/// 13- coada vulpe in jos
/// 14 - cap vulpe la stanga
/// 15 - coada vulpe la stanga

using namespace std;
int pagina;
int nivel;
int k=1;
int initial_x, initial_y, final_x, final_y;
int ok;
bool gata;
POINT cursor_poz;
void Verficare()
{
    int i,j;
    for(i=1; i <= 5; i++)
        for(j = 1; j <=5; j++)

            if(cursor_poz.x >= 90*j && cursor_poz.x <= 90*(j+1)-2 && cursor_poz.y >= 90+90*i && cursor_poz.y <= 90+90*(i+1)-2)
            {
                final_x=i;
                final_y=j;
                break;
            }

}
void Initializare_Tabla()
{
    int i,j;
    for(i = 1; i <= 5; i++)
        for(j = 1; j <= 5; j++)
            Tabla[i][j] = 1;

    Tabla[1][1] = 0;
    Tabla[1][5] = 0;
    Tabla[3][3] = 0;
    Tabla[5][1] = 0;
    Tabla[5][5] = 0;

}
void Desenez_piesa(int p, int l, int c) //citesc imaginile
{
    char numeFisier[30];
    switch(p)
    {
    case 0:
        strcpy(numeFisier,"Vizuina.bmp");
        break;

    case 1:
        strcpy(numeFisier,"Spatiu verde.bmp");
        break;
    case 2:
        strcpy(numeFisier,"Ciuperca.bmp");
        break;

    case 3:
        strcpy(numeFisier,"Iepure alb.bmp");
        break;
    case 4:
        strcpy(numeFisier,"Iepure gri.bmp");
        break;

    case 5:
        strcpy(numeFisier,"Iepure maro.bmp");
        break;
    case 6:
        strcpy(numeFisier,"Cap vulpe in sus.bmp");
        break;
    case -1:
        strcpy(numeFisier,"Coada vulpe in sus.bmp");
        break;
    case 7:
        strcpy(numeFisier,"Iepure alb in vizuina.bmp");
        break;
    case 8:
        strcpy(numeFisier,"Iepure gri in vizuina.bmp");
        break;

    case 9:
        strcpy(numeFisier,"Iepure maro in vizuina.bmp");
        break;
    case 10:
        strcpy(numeFisier,"Cap vulpe spre dreapta.bmp");
        break;
    case 11:
        strcpy(numeFisier,"Coada vulpe spre dreapta.bmp");
        break;
    case 12:
        strcpy(numeFisier,"Cap vulpe in jos.bmp");
        break;
    case 13:
        strcpy(numeFisier,"Coada vulpe in jos.bmp");
        break;
    case 14:
        strcpy(numeFisier,"Cap vulpe spre stanga.bmp");
        break;
    case 15:
        strcpy(numeFisier,"Coada vulpe spre stanga.bmp");
        break;
    }
    readimagefile(numeFisier, 90*c,90+90*l, 90*(c+1)-2, 90+90*(l+1)-2);
}
void Desenez_Tabla()
{
    int i,j,p;
    readimagefile("JumpINback.bmp", 0, 0, 655, 755);
    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= 5; j++)
        {
            p = Tabla[i][j];// ce cifra am in matrice
            Desenez_piesa(p,i,j); // apelez functia si pun in matrice imaginea piesei pe care o am pe linia i si coloana j
        }
    }
    setbkcolor(RGB(173, 241, 253));
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(55, 70, "BACK");

}
void afisare_tabla()
{
    int i,j;
    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= 5; j++)
            cout<< Tabla[i][j] <<" ";
        cout<<endl;
    }
}

int VerfCastig()
{
    int i,j,NUAmIepPeTabla;
    NUAmIepPeTabla=1;
    for(i=1; i <=5; i++)
        for(j=1; j <=5; j++)
            if(Tabla[i][j] == 3 || Tabla[i][j] == 4 || Tabla[i][j] == 5)
                NUAmIepPeTabla=0;
    if(NUAmIepPeTabla == 1)
        return 1;
    else
        return 0;

}

void mutare_iepuri()
{
    //x=linie, y=coloana
    if(final_x == initial_x)
    {
        if(final_y == initial_y+2) //daca sar peste un obstacol care este la dreapta de pozitia initiala
        {
            if(Tabla[initial_x][initial_y+1] == 2 || Tabla[initial_x][initial_y+1] == 3 || Tabla[initial_x][initial_y+1] == 4 || Tabla[initial_x][initial_y+1] == 5 || Tabla[initial_x][initial_y+1] == 6 || Tabla[initial_x][initial_y+1] == 7 || Tabla[initial_x][initial_y+1] == 8 || Tabla[initial_x][initial_y+1] == 9 || Tabla[initial_x][initial_y+1] == 10 || Tabla[initial_x][initial_y+1] == 11 || Tabla[initial_x][initial_y+1] == 12 || Tabla[initial_x][initial_y+1] == 13 || Tabla[initial_x][initial_y+1] == 14 || Tabla[initial_x][initial_y+1] == 15 || Tabla[initial_x][initial_y+1] == -1 )
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<<" la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y-1,90+90*initial_x-1, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;

                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y-1,90+90*initial_x-1, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;


                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y-1,90+90*initial_x-1, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 9;

                }
                 else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 3;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 4;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 5;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 3;

                }
                else
                 if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 4;

                }
                else
                 if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 5;
                }



            }
        }


        else if(final_y == initial_y-2) // daca sar peste un obstacol care este la stanga de pozitia initiala
        {
            if(Tabla[initial_x][initial_y-1] == 2 || Tabla[initial_x][initial_y-1] == 3 || Tabla[initial_x][initial_y-1] == 4 || Tabla[initial_x][initial_y-1] == 5 || Tabla[initial_x][initial_y-1] == 6 || Tabla[initial_x][initial_y-1] == 7 || Tabla[initial_x][initial_y-1] == 8 || Tabla[initial_x][initial_y-1] == 9 || Tabla[initial_x][initial_y-1] == 10 || Tabla[initial_x][initial_y-1] == 11 || Tabla[initial_x][initial_y-1] == 12 || Tabla[initial_x][initial_y-1] == 13 || Tabla[initial_x][initial_y-1] == 14 || Tabla[initial_x][initial_y-1] == 15 || Tabla[initial_x][initial_y-1] == -1 )
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// daca a ajuns la vizuina si initial era pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;

                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4 ) // daca a ajuns la vizuina si initial era pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;

                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5) // daca a ajuns la vizuina si initial era pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 9;

                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 3;
                    Tabla[initial_x][initial_y] =0;

                }
                else
                 if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 4;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 5;
                    Tabla[initial_x][initial_y] = 0;

                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 3;
                }
                else
                 if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 4;

                }
                else
                 if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 5;
                }
            }

        }
        else if(final_y == initial_y+3) //daca sar peste 2 obstacole
        {
            if((Tabla[initial_x][initial_y+1] == 2 || Tabla[initial_x][initial_y+1] == 3 || Tabla[initial_x][initial_y+1] == 4 || Tabla[initial_x][initial_y+1] == 5 || Tabla[initial_x][initial_y+1] == 6 || Tabla[initial_x][initial_y+1] == 7 || Tabla[initial_x][initial_y+1] == 8 || Tabla[initial_x][initial_y+1] == 9 || Tabla[initial_x][initial_y+1] == 10 ||Tabla[initial_x][initial_y+1] == 11 || Tabla[initial_x][initial_y+1] == 12 || Tabla[initial_x][initial_y+1] == 13 || Tabla[initial_x][initial_y+1] == 14 || Tabla[initial_x][initial_y+1] == 15 || Tabla[initial_x][initial_y+1] == -1 ) && (Tabla[initial_x][initial_y+2] == 2 || Tabla[initial_x][initial_y+2] == 3 || Tabla[initial_x][initial_y+2] == 4 || Tabla[initial_x][initial_y+2] == 5 || Tabla[initial_x][initial_y+2] == 6 || Tabla[initial_x][initial_y+2] == 7 || Tabla[initial_x][initial_y+2] == 8 || Tabla[initial_x][initial_y+2] == 9 || Tabla[initial_x][initial_y+2] == 10 || Tabla[initial_x][initial_y+2] == 11 || Tabla[initial_x][initial_y+2] == 12 || Tabla[initial_x][initial_y+2] == 13 || Tabla[initial_x][initial_y+2] == 14 || Tabla[initial_x][initial_y+2] == 15 || Tabla[initial_x][initial_y+2] == -1 ))
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;

                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;


                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 9;

                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 3;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 4;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 5;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 3;

                }
                else
                 if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 4;

                }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 5;
                }

            }
        }



        else if(final_y == initial_y-3) //sar peste 2 obstacole
        {
            if((Tabla[initial_x][initial_y-1] == 2 || Tabla[initial_x][initial_y-1] == 3 || Tabla[initial_x][initial_y-1] == 4 || Tabla[initial_x][initial_y-1] == 5 || Tabla[initial_x][initial_y-1] == 6 || Tabla[initial_x][initial_y-1] == 7 || Tabla[initial_x][initial_y-1] == 8 || Tabla[initial_x][initial_y-1] == 9 || Tabla[initial_x][initial_y-1] == 10 || Tabla[initial_x][initial_y-1] == 11 || Tabla[initial_x][initial_y-1] == 12 || Tabla[initial_x][initial_y-1] == 13 || Tabla[initial_x][initial_y-1] == 14 || Tabla[initial_x][initial_y-1] == 15 || Tabla[initial_x][initial_y-1] == -1 ) && (Tabla[initial_x][initial_y-2] == 2 || Tabla[initial_x][initial_y-2] == 3 || Tabla[initial_x][initial_y-2] == 4 || Tabla[initial_x][initial_y-2] == 5 || Tabla[initial_x][initial_y-2] == 6 ||Tabla[initial_x][initial_y-2] == 7 || Tabla[initial_x][initial_y-2] == 8 || Tabla[initial_x][initial_y-2] == 9 || Tabla[initial_x][initial_y-2] == 10 || Tabla[initial_x][initial_y-2] == 11 || Tabla[initial_x][initial_y-2] == 12 || Tabla[initial_x][initial_y-2] == 13 || Tabla[initial_x][initial_y-2] == 14 || Tabla[initial_x][initial_y-2] == 15 || Tabla[initial_x][initial_y-2] == -1))
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;
                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;
                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 9;


                }
                else
                if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 3;
                    Tabla[initial_x][initial_y] =0;

                }
                else
                 if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 4;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 5;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 3;

                }
                else
                 if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 4;

                }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 5;
                }

            }
        }
        else if(final_y == initial_y+4) //daca sar peste 3 obstacole
        {
            if((Tabla[initial_x][initial_y+1] == 2 || Tabla[initial_x][initial_y+1] == 3 || Tabla[initial_x][initial_y+1] == 4 || Tabla[initial_x][initial_y+1] == 5 || Tabla[initial_x][initial_y+1] == 6 || Tabla[initial_x][initial_y+1] == 7 || Tabla[initial_x][initial_y+1] == 8 || Tabla[initial_x][initial_y+1] == 9 || Tabla[initial_x][initial_y+1] == 10 ||Tabla[initial_x][initial_y+1] == 11 || Tabla[initial_x][initial_y+1] == 12 || Tabla[initial_x][initial_y+1] == 13 || Tabla[initial_x][initial_y+1] == 14 || Tabla[initial_x][initial_y+1] == 15 || Tabla[initial_x][initial_y+1] == -1 ) && (Tabla[initial_x][initial_y+2] == 2 || Tabla[initial_x][initial_y+2] == 3 || Tabla[initial_x][initial_y+2] == 4 || Tabla[initial_x][initial_y+2] == 5 || Tabla[initial_x][initial_y+2] == 6 || Tabla[initial_x][initial_y+2] == 7 || Tabla[initial_x][initial_y+2] == 8 || Tabla[initial_x][initial_y+2] == 9 || Tabla[initial_x][initial_y+2] == 10 || Tabla[initial_x][initial_y+2] == 11 || Tabla[initial_x][initial_y+2] == 12 || Tabla[initial_x][initial_y+2] == 13 || Tabla[initial_x][initial_y+2] == 14 || Tabla[initial_x][initial_y+2] == 15 || Tabla[initial_x][initial_y+2] == -1 ) &&(Tabla[initial_x][initial_y+3] == 2 || Tabla[initial_x][initial_y+3] == 3 || Tabla[initial_x][initial_y+3] == 4 || Tabla[initial_x][initial_y+3] == 5 || Tabla[initial_x][initial_y+3] == 6 || Tabla[initial_x][initial_y+3] == 7 || Tabla[initial_x][initial_y+3] == 8 || Tabla[initial_x][initial_y+3] == 9 || Tabla[initial_x][initial_y+3] == 10 ||Tabla[initial_x][initial_y+3] == 11 || Tabla[initial_x][initial_y+3] == 12 || Tabla[initial_x][initial_y+3] == 13 || Tabla[initial_x][initial_y+3] == 14 || Tabla[initial_x][initial_y+3] == 15 || Tabla[initial_x][initial_y+3] == -1 ))
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;

                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;


                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 9;

                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 3;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 4;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 5;
                    Tabla[initial_x][initial_y] = 0;
                }
                else

                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 3;

                }
                else
                 if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 4;

                }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 5;
                }

            }
        }



        else if(final_y == initial_y-4) //sar peste 3 obstacole
        {
            if((Tabla[initial_x][initial_y-1] == 2 || Tabla[initial_x][initial_y-1] == 3 || Tabla[initial_x][initial_y-1] == 4 || Tabla[initial_x][initial_y-1] == 5 || Tabla[initial_x][initial_y-1] == 6 || Tabla[initial_x][initial_y-1] == 7 || Tabla[initial_x][initial_y-1] == 8 || Tabla[initial_x][initial_y-1] == 9 || Tabla[initial_x][initial_y-1] == 10 || Tabla[initial_x][initial_y-1] == 11 || Tabla[initial_x][initial_y-1] == 12 || Tabla[initial_x][initial_y-1] == 13 || Tabla[initial_x][initial_y-1] == 14 || Tabla[initial_x][initial_y-1] == 15 || Tabla[initial_x][initial_y-1] == -1 ) && (Tabla[initial_x][initial_y-2] == 2 || Tabla[initial_x][initial_y-2] == 3 || Tabla[initial_x][initial_y-2] == 4 || Tabla[initial_x][initial_y-2] == 5 || Tabla[initial_x][initial_y-2] == 6 ||Tabla[initial_x][initial_y-2] == 7 || Tabla[initial_x][initial_y-2] == 8 || Tabla[initial_x][initial_y-2] == 9 || Tabla[initial_x][initial_y-2] == 10 || Tabla[initial_x][initial_y-2] == 11 || Tabla[initial_x][initial_y-2] == 12 || Tabla[initial_x][initial_y-2] == 13 || Tabla[initial_x][initial_y-2] == 14 || Tabla[initial_x][initial_y-2] == 15 || Tabla[initial_x][initial_y-2] == -1) && (Tabla[initial_x][initial_y-3] == 2 || Tabla[initial_x][initial_y-3] == 3 || Tabla[initial_x][initial_y-3] == 4 || Tabla[initial_x][initial_y-3] == 5 || Tabla[initial_x][initial_y-3] == 6 || Tabla[initial_x][initial_y-3] == 7 || Tabla[initial_x][initial_y-3] == 8 || Tabla[initial_x][initial_y-3] == 9 || Tabla[initial_x][initial_y-3] == 10 || Tabla[initial_x][initial_y-3] == 11 || Tabla[initial_x][initial_y-3] == 12 || Tabla[initial_x][initial_y-3] == 13 || Tabla[initial_x][initial_y-3] == 14 || Tabla[initial_x][initial_y-3] == 15 || Tabla[initial_x][initial_y-3] == -1 ))
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;
                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;
                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 9;


                }
                else
                if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 3;
                    Tabla[initial_x][initial_y] =0;

                }
                else
                 if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 4;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 5;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 3;

                }
                else
                 if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 4;

                }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 5;
                }

            }
        }

        if(VerfCastig() == 1)
        {
            cout<<"Ai castigat!"<< endl;
            gata=true;
            WinMenu();
            pagina=6;
        }

    }
    else if(final_y == initial_y)
    {
        if(final_x == initial_x+2)// sar peste un obstacol
        {
            if(Tabla[initial_x+1][initial_y] == 2 || Tabla[initial_x+1][initial_y] == 3 || Tabla[initial_x+1][initial_y] == 4 || Tabla[initial_x+1][initial_y] == 5 || Tabla[initial_x+1][initial_y] == 6 || Tabla[initial_x+1][initial_y] == 7 || Tabla[initial_x+1][initial_y] == 8 || Tabla[initial_x+1][initial_y] == 9 || Tabla[initial_x+1][initial_y] == 10 || Tabla[initial_x+1][initial_y] == 11 || Tabla[initial_x+1][initial_y] == 12 || Tabla[initial_x+1][initial_y] == 13 || Tabla[initial_x+1][initial_y] == 14 || Tabla[initial_x+1][initial_y] == 15 || Tabla[initial_x+1][initial_y] == -1)
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;
                }
                else
                 if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;
                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                    {
                        cout<<"Iepurele a ajuns in vizuina."<<endl;
                        readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 9;
                    }
                else
                if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                    {
                        cout<<"Iepurele a iesit din vizuina."<<endl;
                        readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                        ok=1;
                        Tabla[final_x][final_y] = 3;
                        Tabla[initial_x][initial_y] = 0;
                    }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                    {
                        cout<<"Iepurele a iesit din vizuina."<<endl;
                        readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                        ok=1;
                        Tabla[final_x][final_y] = 4;
                        Tabla[initial_x][initial_y] = 0;
                    }
                else
                if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                    {
                        cout<<"Iepurele a iesit din vizuina."<<endl;
                        readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                        ok=1;
                        Tabla[final_x][final_y] = 5;
                        Tabla[initial_x][initial_y] = 0;

                    }
                    else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                 else
                 if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 3;
                    }
                else
                if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 4;

                    }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 5;
                    }

            }

        }


        else
        if(final_x == initial_x-2) //sar peste un obstacol mai sus
        {
            if(Tabla[initial_x-1][initial_y] == 2 || Tabla[initial_x-1][initial_y] == 3 || Tabla[initial_x-1][initial_y] == 4 || Tabla[initial_x-1][initial_y] == 5 || Tabla[initial_x-1][initial_y] == 6 || Tabla[initial_x-1][initial_y] == 7 ||Tabla[initial_x-1][initial_y] == 8 || Tabla[initial_x-1][initial_y] == 9 || Tabla[initial_x-1][initial_y] == 10 || Tabla[initial_x-1][initial_y] == 11 || Tabla[initial_x-1][initial_y] == 12 || Tabla[initial_x-1][initial_y] == 13 || Tabla[initial_x-1][initial_y] == 14 || Tabla[initial_x-1][initial_y] == 15 || Tabla[initial_x-1][initial_y] == -1)
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;
                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;
                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 9;
                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 3;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 4;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 5;
                    Tabla[initial_x][initial_y] = 0;
                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 3;
                }
                else
                if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 4;
                    }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 5;
                    }

            }
        }

        else
        if(final_x == initial_x+3) // sar peste 2 obstacole
        {
            if(( Tabla[initial_x+1][initial_y] == 2 || Tabla[initial_x+1][initial_y] == 3 || Tabla[initial_x+1][initial_y] == 4 || Tabla[initial_x+1][initial_y] == 5 || Tabla[initial_x+1][initial_y] == 6 || Tabla[initial_x+1][initial_y] == 7 || Tabla[initial_x+1][initial_y] == 8 || Tabla[initial_x+1][initial_y] == 9 || Tabla[initial_x+1][initial_y] == 10 || Tabla[initial_x+1][initial_y] == 11 || Tabla[initial_x+1][initial_y] == 12 || Tabla[initial_x+1][initial_y] == 13 || Tabla[initial_x+1][initial_y] == 14 || Tabla[initial_x+1][initial_y] == 15 || Tabla[initial_x+1][initial_y] == -1) && (Tabla[initial_x+2][initial_y] == 2 || Tabla[initial_x+2][initial_y] == 3 || Tabla[initial_x+2][initial_y] == 4 || Tabla[initial_x+2][initial_y] == 5 || Tabla[initial_x+2][initial_y] == 6 || Tabla[initial_x+2][initial_y] == 7 || Tabla[initial_x+2][initial_y] == 8 || Tabla[initial_x+2][initial_y] == 9 ||Tabla[initial_x+2][initial_y] == 10 || Tabla[initial_x+2][initial_y] == 11 || Tabla[initial_x+2][initial_y] == 12 || Tabla[initial_x+2][initial_y] == 13 || Tabla[initial_x+2][initial_y] == 14 || Tabla[initial_x+2][initial_y] == 15 || Tabla[initial_x+2][initial_y] == -1 ))
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;
                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;

                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                    {
                        cout<<"Iepurele a ajuns in vizuina."<<endl;
                        readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 9;

                    }
                else
                if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                    {
                        cout<<"Iepurele a iesit din vizuina."<<endl;
                        readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                        ok=1;
                        Tabla[final_x][final_y] = 3;
                        Tabla[initial_x][initial_y] = 0;

                    }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                    {
                        cout<<"Iepurele a iesit din vizuina."<<endl;
                        readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                        ok=1;
                        Tabla[final_x][final_y] = 4;
                        Tabla[initial_x][initial_y] = 0;
                    }
                else
                if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                    {
                        cout<<"Iepurele a iesit din vizuina."<<endl;
                        readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                        ok=1;
                        Tabla[final_x][final_y] = 5;
                        Tabla[initial_x][initial_y] = 0;


                    }
                    else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 3;
                    }
                else
                    if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 4;

                    }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 5;

                    }

            }
        }


        else
        if(final_x == initial_x-3) // sar peste 2 obstacole
        {
            if((Tabla[initial_x-1][initial_y] == 2 || Tabla[initial_x-1][initial_y] == 3 || Tabla[initial_x-1][initial_y] == 4 || Tabla[initial_x-1][initial_y] == 5 || Tabla[initial_x-1][initial_y] == 6 || Tabla[initial_x-1][initial_y] == 7 || Tabla[initial_x-1][initial_y] == 8 || Tabla[initial_x-1][initial_y] == 9 || Tabla[initial_x-1][initial_y] == 10 || Tabla[initial_x-1][initial_y] == 11 || Tabla[initial_x-1][initial_y] == 12 || Tabla[initial_x-1][initial_y] == 13 || Tabla[initial_x-1][initial_y] == 14 || Tabla[initial_x-1][initial_y] == 15 || Tabla[initial_x-1][initial_y] == -1) && (Tabla[initial_x-2][initial_y] == 2 || Tabla[initial_x-2][initial_y] == 3 || Tabla[initial_x-2][initial_y] == 4 || Tabla[initial_x-2][initial_y] == 5 || Tabla[initial_x-2][initial_y] == 6 || Tabla[initial_x-2][initial_y] == 7 ||Tabla[initial_x-2][initial_y] == 8 || Tabla[initial_x-2][initial_y] == 9 ||Tabla[initial_x-2][initial_y] == 10 || Tabla[initial_x-2][initial_y] == 11 || Tabla[initial_x-2][initial_y] == 12 || Tabla[initial_x-2][initial_y] == 13 || Tabla[initial_x-2][initial_y] == 14 || Tabla[initial_x-2][initial_y] == 15 || Tabla[initial_x-2][initial_y] == -1 ))
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;

                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;


                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 9;

                }
                else
                if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 3;
                    Tabla[initial_x][initial_y] = 0;

                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 4;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 5;
                    Tabla[initial_x][initial_y] = 0;

                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 3;

                }
                else
                if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 4;

                }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 5;

                }

            }
        }
 else
        if(final_x == initial_x+4) // sar peste 3 obstacole
        {
            if(( Tabla[initial_x+1][initial_y] == 2 || Tabla[initial_x+1][initial_y] == 3 || Tabla[initial_x+1][initial_y] == 4 || Tabla[initial_x+1][initial_y] == 5 || Tabla[initial_x+1][initial_y] == 6 || Tabla[initial_x+1][initial_y] == 7 || Tabla[initial_x+1][initial_y] == 8 || Tabla[initial_x+1][initial_y] == 9 || Tabla[initial_x+1][initial_y] == 10 || Tabla[initial_x+1][initial_y] == 11 || Tabla[initial_x+1][initial_y] == 12 || Tabla[initial_x+1][initial_y] == 13 || Tabla[initial_x+1][initial_y] == 14 || Tabla[initial_x+1][initial_y] == 15 || Tabla[initial_x+1][initial_y] == -1) && (Tabla[initial_x+2][initial_y] == 2 || Tabla[initial_x+2][initial_y] == 3 || Tabla[initial_x+2][initial_y] == 4 || Tabla[initial_x+2][initial_y] == 5 || Tabla[initial_x+2][initial_y] == 6 || Tabla[initial_x+2][initial_y] == 7 || Tabla[initial_x+2][initial_y] == 8 || Tabla[initial_x+2][initial_y] == 9 ||Tabla[initial_x+2][initial_y] == 10 || Tabla[initial_x+2][initial_y] == 11 || Tabla[initial_x+2][initial_y] == 12 || Tabla[initial_x+2][initial_y] == 13 || Tabla[initial_x+2][initial_y] == 14 || Tabla[initial_x+2][initial_y] == 15 || Tabla[initial_x+2][initial_y] == -1 ) && ( Tabla[initial_x+3][initial_y] == 2 || Tabla[initial_x+3][initial_y] == 3 || Tabla[initial_x+3][initial_y] == 4 || Tabla[initial_x+3][initial_y] == 5 || Tabla[initial_x+3][initial_y] == 6 || Tabla[initial_x+3][initial_y] == 7 || Tabla[initial_x+3][initial_y] == 8 || Tabla[initial_x+3][initial_y] == 9 || Tabla[initial_x+3][initial_y] == 10 || Tabla[initial_x+3][initial_y] == 11 || Tabla[initial_x+3][initial_y] == 12 || Tabla[initial_x+3][initial_y] == 13 || Tabla[initial_x+3][initial_y] == 14 || Tabla[initial_x+3][initial_y] == 15 || Tabla[initial_x+3][initial_y] == -1))
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;
                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;

                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                    {
                        cout<<"Iepurele a ajuns in vizuina."<<endl;
                        readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 9;

                    }
                else
                if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                    {
                        cout<<"Iepurele a iesit din vizuina."<<endl;
                        readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                        ok=1;
                        Tabla[final_x][final_y] = 3;
                        Tabla[initial_x][initial_y] = 0;

                    }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                    {
                        cout<<"Iepurele a iesit din vizuina."<<endl;
                        readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                        ok=1;
                        Tabla[final_x][final_y] = 4;
                        Tabla[initial_x][initial_y] = 0;
                    }
                else
                if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                    {
                        cout<<"Iepurele a iesit din vizuina."<<endl;
                        readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                        ok=1;
                        Tabla[final_x][final_y] = 5;
                        Tabla[initial_x][initial_y] = 0;


                    }
                    else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 3;
                    }
                else
                    if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 4;

                    }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                    {
                        cout<<"Iepurele nu este inca in vizuina."<<endl;
                        readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                        readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                        ok=1;
                        Tabla[initial_x][initial_y] = 1;
                        Tabla[final_x][final_y] = 5;

                    }

            }
        }


        else
        if(final_x == initial_x-3) // sar peste 3 obstacole
        {
            if((Tabla[initial_x-1][initial_y] == 2 || Tabla[initial_x-1][initial_y] == 3 || Tabla[initial_x-1][initial_y] == 4 || Tabla[initial_x-1][initial_y] == 5 || Tabla[initial_x-1][initial_y] == 6 || Tabla[initial_x-1][initial_y] == 7 || Tabla[initial_x-1][initial_y] == 8 || Tabla[initial_x-1][initial_y] == 9 || Tabla[initial_x-1][initial_y] == 10 || Tabla[initial_x-1][initial_y] == 11 || Tabla[initial_x-1][initial_y] == 12 || Tabla[initial_x-1][initial_y] == 13 || Tabla[initial_x-1][initial_y] == 14 || Tabla[initial_x-1][initial_y] == 15 || Tabla[initial_x-1][initial_y] == -1) && (Tabla[initial_x-2][initial_y] == 2 || Tabla[initial_x-2][initial_y] == 3 || Tabla[initial_x-2][initial_y] == 4 || Tabla[initial_x-2][initial_y] == 5 || Tabla[initial_x-2][initial_y] == 6 || Tabla[initial_x-2][initial_y] == 7 ||Tabla[initial_x-2][initial_y] == 8 || Tabla[initial_x-2][initial_y] == 9 ||Tabla[initial_x-2][initial_y] == 10 || Tabla[initial_x-2][initial_y] == 11 || Tabla[initial_x-2][initial_y] == 12 || Tabla[initial_x-2][initial_y] == 13 || Tabla[initial_x-2][initial_y] == 14 || Tabla[initial_x-2][initial_y] == 15 || Tabla[initial_x-2][initial_y] == -1 ) && (Tabla[initial_x-3][initial_y] == 2 || Tabla[initial_x-3][initial_y] == 3 || Tabla[initial_x-3][initial_y] == 4 || Tabla[initial_x-3][initial_y] == 5 || Tabla[initial_x-3][initial_y] == 6 || Tabla[initial_x-3][initial_y] == 7 || Tabla[initial_x-3][initial_y] == 8 || Tabla[initial_x-3][initial_y] == 9 || Tabla[initial_x-3][initial_y] == 10 || Tabla[initial_x-3][initial_y] == 11 || Tabla[initial_x-3][initial_y] == 12 || Tabla[initial_x-3][initial_y] == 13 || Tabla[initial_x-3][initial_y] == 14 || Tabla[initial_x-3][initial_y] == 15 || Tabla[initial_x-3][initial_y] == -1))
            {
                cout<<"Ai mutat iepurele de la pozitia "<<initial_x<<" "<<initial_y<< "la pozitia "<<final_x<<" "<<final_y<<"."<<endl;

                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 3)// verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 7;

                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 4) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 8;


                }
                else
                if(Tabla[final_x][final_y] == 0 && Tabla[initial_x][initial_y] == 5) // verific daca a ajuns in vizuina si initial este pe un spatiu verde
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp", 90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 9;

                }
                else
                if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 3;
                    Tabla[initial_x][initial_y] = 0;

                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 4;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 1 ) //daca iepurele era in vizuina si il mut intr-un spatiu liber
                {
                    cout<<"Iepurele a iesit din vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 5;
                    Tabla[initial_x][initial_y] = 0;

                }
                else
                 if(Tabla[initial_x][initial_y] == 7 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure alb in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 7;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                if(Tabla[initial_x][initial_y] == 8 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure gri in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 8;
                    Tabla[initial_x][initial_y] =0;


                }
                else
                 if(Tabla[initial_x][initial_y] == 9 && Tabla[final_x][final_y] == 0 ) //daca iepurele era in vizuina si il mut in alta vizuina
                {
                    cout<<"Iepurele a ajuns in vizuina."<<endl;
                    readimagefile("Iepure maro in vizuina.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Vizuina.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2 );
                    ok=1;
                    Tabla[final_x][final_y] = 9;
                    Tabla[initial_x][initial_y] = 0;


                }
                else
                if(Tabla[initial_x][initial_y] == 3 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure alb.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 3;

                }
                else
                if(Tabla[initial_x][initial_y] == 4 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure gri.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 4;

                }
                else
                if(Tabla[initial_x][initial_y] == 5 && Tabla [final_x][final_y] == 1) //daca mut iepurele pe un spatiu verde liber  de pe un spatiu verde
                {
                    cout<<"Iepurele nu este inca in vizuina."<<endl;
                    readimagefile("Iepure maro.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2 );
                    readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                    ok=1;
                    Tabla[initial_x][initial_y] = 1;
                    Tabla[final_x][final_y] = 5;

                }

            }
        }
        if(VerfCastig() == 1)
        {
            WinMenu();
            cout<<"Ai castigat!"<< endl;
            gata=true;
            pagina=6;
        }



    }


}

void Mutare_Vulpe()
{
    int i,AmSpatiuLiber;
        if(initial_x == final_x) // vulpea e pe orizontala
        {   //vulpea e spre stanga
            if(Tabla[final_x][final_y] == 1 && Tabla[final_x][final_y+1] == 14 )
            {
                if(final_y+1 == initial_y)
                { cout<<"Ai mutat vulpea de la pozitia "<<initial_x<<" "<<initial_y<<" la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                  readimagefile("Cap vulpe spre stanga.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                  readimagefile("Coada vulpe spre stanga.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                  readimagefile("Spatiu verde.bmp",90*(initial_y+1),90+90*initial_x, 90*((initial_y+1)-1)-2, 90+90*(initial_x-1)-2);
                  Tabla[final_x][final_y] = 14;
                  Tabla[initial_x][initial_y] = 15;
                  Tabla[initial_x][initial_y+1] = 1;
                  ok=1;

                }
            }
        else
           if(final_y == initial_y+1 && Tabla[final_x][final_y+1] == 1 && Tabla[final_x][final_y] == 15)
           {
            if( final_y+1 >=1 && final_y+1 <= 5)//daca sunt in matrice
            {
                cout<<"Ai mutat vulpea de la pozitia "<<initial_x<<" "<<initial_y<<" la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                  readimagefile("Cap vulpe spre stanga.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                  readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                  readimagefile("Coada vulpe spre stanga.bmp",90*(final_y+1),90+90*final_x, 90*((final_y+1)-1)-2, 90+90*(final_x-1)-2);
                  Tabla[initial_x][initial_y] = 1;
                  Tabla[final_x][final_y] = 14;
                  Tabla[final_x][final_y+1] = 15;
                  ok=1;
            }
           }
        else
        //vulpea spre dreapta
        if(Tabla[final_x][final_y] == 1 && Tabla[initial_x][initial_y] == 10 )
            {
                if(final_y-1 == initial_y)
                { cout<<"Ai mutat vulpea de la pozitia "<<initial_x<<" "<<initial_y<<" la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                  readimagefile("Cap vulpe spre dreapta.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                  readimagefile("Coada vulpe spre dreapta.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                  readimagefile("Spatiu verde.bmp",90*(initial_y-1),90+90*initial_x, 90*((initial_y-1)-1)-2, 90+90*(initial_x-1)-2);
                  Tabla[final_x][final_y] = 10;
                  Tabla[final_x][final_y-1] = 11;
                  Tabla[final_x][final_y-2] = 1;
                  ok=1;

                }
            }
        else
           if(final_y == initial_y-1 && Tabla[final_x][final_y] == 11 && Tabla[final_x][final_y-1] == 1)
           {
            if(final_y-1 >=1 && final_y-1 <= 5)//daca sunt in matrice
            {
                cout<<"Ai mutat vulpea de la pozitia "<<initial_x<<" "<<initial_y<<" la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                  readimagefile("Cap vulpe spre dreapta.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                  readimagefile("Spatiu verde.bmp",90*initial_y,90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                  readimagefile("Coada vulpe spre dreapta.bmp",90*(final_y-1),90+90*final_x, 90*((final_y-1)-1)-2, 90+90*(final_x-1)-2);
                  Tabla[final_x][final_y] = 10;
                  Tabla[final_x][final_y-1] = 11;
                  Tabla[initial_x][initial_y] = 1;
                  ok=1;
            }
           }

        }

    else
           if(final_y == initial_y) // vulpea e pe verticala
           {// vulpea e cu capul in sus
               if(Tabla[final_x][final_y] == 1 && Tabla[final_x+1][final_y] == 6)
               {
                   if(final_x+1 == initial_x)// mut cu o pozitie in sus
                   {
                       cout<<"Ai mutat vulpea de la pozitia "<<initial_x<<" "<<initial_y<<" la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                       readimagefile("Cap vulpe in sus.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                       readimagefile("COada vulpe in sus.bmp", 90*initial_y, 90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                       readimagefile("Spatiu verde.bmp", 90*initial_y, 90+90*(initial_x+1), 90*(initial_y-1)-2, 90+90*((initial_x+1)-1)-2);
                       Tabla[final_x][final_y] = 6;
                       Tabla[initial_x][initial_y] = -1;
                       Tabla[initial_x+1][initial_y] = 1;
                       ok=1;
                   }
               }
               else
                if(Tabla[final_x][final_y] == -1 && final_x == initial_x+1 && Tabla[final_x+1][final_y] == 1)// mut cu o pozitie in jos
               {
                   if(final_x+1>= 1 && final_x+1 <= 5)// daca sunt in matrice
                   {
                       cout<<"Ai mutat vulpea de la pozitia "<<initial_x<<" "<<initial_y<<" la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                       readimagefile("Spatiu verde.bmp", 90*initial_y, 90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                       readimagefile("Cap vulpe in sus.bmp", 90*final_y, 90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                       readimagefile("Coada vulpe in sus.bmp", 90*final_y, 90+90*(final_x+1), 90*(final_y-1)-2, 90+90*((final_x+1)-1)-2);
                       Tabla[final_x][final_y] = 6;
                       Tabla[final_x+1][final_y] = -1;
                       Tabla[initial_x][initial_y] = 1;
                       ok=1;
                   }
               }
               else
               // vulpea e cu capul in jos
               if(Tabla[final_x][final_y] == 1 && Tabla[initial_x][initial_y] == 12)

               {
                   if(final_x-1 == initial_x)// mut cu o pozitie in jos
                   {
                       cout<<"Ai mutat vulpea de la pozitia "<<initial_x<<" "<<initial_y<<" la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                       readimagefile("Cap vulpe in jos.bmp",90*final_y,90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                       readimagefile("Coada vulpe in jos.bmp", 90*initial_y, 90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                       readimagefile("Spatiu verde.bmp", 90*initial_y, 90+90*(initial_x-1), 90*(initial_y-1)-2, 90+90*((initial_x-1)-1)-2);
                       Tabla[final_x][final_y] = 12;
                       Tabla[final_x-1][final_y] = 13;
                       Tabla[initial_x-1][initial_y] = 1;
                       ok=1;
                   }
               }
               else
                if(Tabla[final_x][final_y] == 13 && final_x == initial_x-1 && Tabla[final_x-1][final_y] == 1)
               {
                   if(final_x-1>= 1 && final_x-1 <= 5)// daca sunt in matrice
                   {
                       cout<<"Ai mutat vulpea de la pozitia "<<initial_x<<" "<<initial_y<<" la pozitia "<<final_x<<" "<<final_y<<"."<<endl;
                       readimagefile("Spatiu verde.bmp", 90*initial_y, 90+90*initial_x, 90*(initial_y-1)-2, 90+90*(initial_x-1)-2);
                       readimagefile("Cap vulpe in jos.bmp", 90*final_y, 90+90*final_x, 90*(final_y-1)-2, 90+90*(final_x-1)-2);
                       readimagefile("Coada vulpe in jos.bmp", 90*initial_y, 90+90*(initial_x-2), 90*(initial_y-1)-2, 90+90*((initial_x-2)-1)-2);
                       Tabla[final_x][final_y] = 12;
                       Tabla[final_x-1][final_y] = 13;
                       Tabla[initial_x][initial_y] = 1;
                       ok=1;
                   }
               }
           }


}
void Mutare_Piese()
{
    gata=false;
    bool click;
    int i,j,y,z;
    ok=1;
    while(!gata)
    {
        click=false;
        while(!click)
        {
            cursor_poz.x=mousex();
            cursor_poz.y=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
                click=true;
        }
        final_x=1;
        final_y=1;
        clearmouseclick(WM_LBUTTONDOWN);
        if(cursor_poz.x >= 50 && cursor_poz.x <= 150 && cursor_poz.y >=50 && cursor_poz.y <= 100)//daca apas pe butonul de back
            {   gata=true;
                LoseMenu();
                pagina=5;
                cout<<"Ai pierdut."<<endl;

            }
            else
                Verficare();
            if(ok==1)
            {
                if((Tabla[final_x][final_y] == 3 || Tabla[final_x][final_y] == 7))
                {
                    cout<<"Ai selectat un iepure alb."<<endl;
                    ok=2;
                    initial_x=final_x;
                    initial_y=final_y;

                }


                if(Tabla[final_x][final_y] == 4 || Tabla[final_x][final_y] == 8)
                {
                    cout<<"Ai selectat un iepure gri."<<endl;
                    ok=2;
                    initial_x=final_x;
                    initial_y=final_y;
                }

                    if(Tabla[final_x][final_y] == 5 || Tabla[final_x][final_y] == 9)
                {
                    cout<<"Ai selectat un iepure maro."<<endl;
                    ok=2;
                    initial_x=final_x;
                    initial_y=final_y;

                }
                if(Tabla[final_x][final_y] == 6)
                {
                    cout<<"Ai selectat o vulpe."<<endl;
                    ok=3;
                    initial_x=final_x;
                    initial_y=final_y;
                }
                if(Tabla[final_x][final_y] == 10)
                {
                    cout<<"Ai selectat o vulpe."<<endl;
                    ok=3;
                    initial_x=final_x;
                    initial_y=final_y;
                }
                if(Tabla[final_x][final_y] == 12)
                {
                    cout<<"Ai selectat o vulpe."<<endl;
                    ok=3;
                    initial_x=final_x;
                    initial_y=final_y;
                }
                if(Tabla[final_x][final_y] == 14)
                {
                    cout<<"Ai selectat o vulpe."<<endl;
                    ok=3;
                    initial_x=final_x;
                    initial_y=final_y;
                }


            }
            else

                if(ok==2)
                 {
                 if(Tabla[final_x][final_y]== 1 || Tabla[final_x][final_y] == 0)
                   {
                       mutare_iepuri();
                       afisare_tabla();
                       clearmouseclick(WM_LBUTTONDOWN);
                   }


                else
                  ok=1;
                }
            else
                if(ok==3)
                  {
                   Mutare_Vulpe();
                   afisare_tabla();
                  }
    }
}
void play_music(int m)
{
    if(m % 2 != 0)
    PlaySound("muzicaJoc.wav", NULL, SND_FILENAME || SND_ASYNC || SND_LOOP);
    else
    PlaySound(NULL, NULL, SND_ASYNC);

}
int main()
{
    int i,j;
    initwindow(655,755,"Jump In");
    PlaySound("muzicaJoc.wav", NULL, SND_FILENAME || SND_ASYNC || SND_LOOP);
    DeseneazaMenu();
    pagina=1;
    while(true)
    {
        if(pagina==1)// pagina principala cu play si instructiunile
        {
            GetCursorPos(&cursor_poz);
            ScreenToClient(GetForegroundWindow(),&cursor_poz);
            if((cursor_poz.x >= 200 && cursor_poz.x <= 400 && cursor_poz.y >=100 && cursor_poz.y <= 150 ) && ismouseclick(WM_LBUTTONDOWN))
            {
                DeseneazaNivele();
                pagina=2;
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if((cursor_poz.x >= 150 && cursor_poz.x <= 450 && cursor_poz.y >=200 && cursor_poz.y <= 350 ) && ismouseclick(WM_LBUTTONDOWN))
            {
                instructiuni();
                pagina=3;
                clearmouseclick(WM_LBUTTONDOWN);
            }
             if((cursor_poz.x >= 500 && cursor_poz.x <= 650 && cursor_poz.y >=650 && cursor_poz.y <= 700 ) && ismouseclick(WM_LBUTTONDOWN))
            {
               play_music(++k);
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        if(pagina == 2)//pagina cu nivele
        {
            GetCursorPos(&cursor_poz);
            ScreenToClient(GetForegroundWindow(),&cursor_poz);
            if((cursor_poz.x >= 50 && cursor_poz.x <= 150 && cursor_poz.y >=50 && cursor_poz.y <= 100 ) && ismouseclick(WM_LBUTTONDOWN))
            {
                DeseneazaMenu();
                pagina=1;
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if((cursor_poz.x >= 500 && cursor_poz.x <= 650 && cursor_poz.y >=650 && cursor_poz.y <= 700 ) && ismouseclick(WM_LBUTTONDOWN))
            {
               play_music(++k);
            }
           if((cursor_poz.x >= 100 && cursor_poz.x <= 130 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {
               Initializare_Tabla();
               Nivelul_1();
               Desenez_Tabla();
               pagina=4;
               nivel=1;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 150 && cursor_poz.x <= 180 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_2();
               Desenez_Tabla();
               pagina=4;
               nivel=2;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 200 && cursor_poz.x <= 230 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_3();
               Desenez_Tabla();
               pagina=4;
               nivel=3;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 250 && cursor_poz.x <= 280 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_4();
               Desenez_Tabla();
               pagina=4;
               nivel=4;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 300 && cursor_poz.x <= 330 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_5();
               Desenez_Tabla();
               pagina=4;
               nivel=5;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 350 && cursor_poz.x <= 380 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_6();
               Desenez_Tabla();
               pagina=4;
               nivel=6;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 400 && cursor_poz.x <= 430 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_7();
               Desenez_Tabla();
               pagina=4;
               nivel=7;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 450 && cursor_poz.x <= 480 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_8();
               Desenez_Tabla();
               pagina=4;
               nivel=8;
               clearmouseclick(WM_LBUTTONDOWN);
           }
            if((cursor_poz.x >= 500 && cursor_poz.x <= 530 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_9();
               Desenez_Tabla();
               pagina=4;
               nivel=9;
               clearmouseclick(WM_LBUTTONDOWN);
           }
            if((cursor_poz.x >= 555 && cursor_poz.x <= 595 && cursor_poz.y >=100 && cursor_poz.y <= 130 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_10();
               Desenez_Tabla();
               pagina=4;
               nivel=10;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 100 && cursor_poz.x <= 140 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_11();
               Desenez_Tabla();
               pagina=4;
               nivel=11;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 155 && cursor_poz.x <= 195 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_12();
               Desenez_Tabla();
               pagina=4;
               nivel=12;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 210 && cursor_poz.x <= 250 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_13();
               Desenez_Tabla();
               pagina=4;
               nivel=13;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 265 && cursor_poz.x <= 305 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_14();
               Desenez_Tabla();
               pagina=4;
               nivel=14;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 320 && cursor_poz.x <= 360 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_15();
               Desenez_Tabla();
               pagina=4;
               nivel=15;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 375 && cursor_poz.x <= 415 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_16();
               Desenez_Tabla();
               pagina=4;
               nivel=16;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 430 && cursor_poz.x <= 470 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_17();
               Desenez_Tabla();
               pagina=4;
               nivel=17;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 485 && cursor_poz.x <= 525 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_18();
               Desenez_Tabla();
               pagina=4;
               nivel=18;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 540 && cursor_poz.x <= 580 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_19();
               Desenez_Tabla();
               pagina=4;
               nivel=19;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 595 && cursor_poz.x <= 635 && cursor_poz.y >=200 && cursor_poz.y <= 230 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_20();
               Desenez_Tabla();
               pagina=4;
               nivel=20;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 100 && cursor_poz.x <= 140 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_21();
               Desenez_Tabla();
               pagina=4;
               nivel=21;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 155 && cursor_poz.x <= 195 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_22();
               Desenez_Tabla();
               pagina=4;
               nivel=22;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 210 && cursor_poz.x <= 250 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_23();
               Desenez_Tabla();
               pagina=4;
               nivel=23;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 265 && cursor_poz.x <= 305 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_24();
               Desenez_Tabla();
               pagina=4;
               nivel=24;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 320 && cursor_poz.x <= 360 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_25();
               Desenez_Tabla();
               pagina=4;
               nivel=25;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 375 && cursor_poz.x <= 415 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_26();
               Desenez_Tabla();
               pagina=4;
               nivel=26;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 430 && cursor_poz.x <= 470 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_27();
               Desenez_Tabla();
               pagina=4;
               nivel=27;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 485 && cursor_poz.x <= 525 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_28();
               Desenez_Tabla();
               pagina=4;
               nivel=28;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 540 && cursor_poz.x <= 580 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_29();
               Desenez_Tabla();
               pagina=4;
               nivel=29;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 595 && cursor_poz.x <= 635 && cursor_poz.y >=300 && cursor_poz.y <= 330 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_30();
               Desenez_Tabla();
               pagina=4;
               nivel=30;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 100 && cursor_poz.x <= 140 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_31();
               Desenez_Tabla();
               pagina=4;
               nivel=31;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 155 && cursor_poz.x <= 195 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_32();
               Desenez_Tabla();
               pagina=4;
               nivel=32;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 210 && cursor_poz.x <= 250 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_33();
               Desenez_Tabla();
               pagina=4;
               nivel=33;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 265 && cursor_poz.x <= 305 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_34();
               Desenez_Tabla();
               pagina=4;
               nivel=34;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 320 && cursor_poz.x <= 360 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_35();
               Desenez_Tabla();
               pagina=4;
               nivel=35;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 375 && cursor_poz.x <= 415 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_36();
               Desenez_Tabla();
               pagina=4;
               nivel=36;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 430 && cursor_poz.x <= 470 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_37();
               Desenez_Tabla();
               pagina=4;
               nivel=37;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 485 && cursor_poz.x <= 525 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_38();
               Desenez_Tabla();
               pagina=4;
               nivel=38;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 540 && cursor_poz.x <= 580 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_39();
               Desenez_Tabla();
               pagina=4;
               nivel=39;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 595 && cursor_poz.x <= 635 && cursor_poz.y >=400 && cursor_poz.y <= 430 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_40();
               Desenez_Tabla();
               pagina=4;
               nivel=40;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 100 && cursor_poz.x <= 140 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_41();
               Desenez_Tabla();
               pagina=4;
               nivel=41;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 155 && cursor_poz.x <= 195 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_42();
               Desenez_Tabla();
               pagina=4;
               nivel=42;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 210 && cursor_poz.x <= 250 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_43();
               Desenez_Tabla();
               pagina=4;
               nivel=43;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 265 && cursor_poz.x <= 305 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_44();
               Desenez_Tabla();
               pagina=4;
               nivel=44;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 320 && cursor_poz.x <= 360 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_45();
               Desenez_Tabla();
               pagina=4;
               nivel=45;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 375 && cursor_poz.x <= 415 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_46();
               Desenez_Tabla();
               pagina=4;
               nivel=46;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 430 && cursor_poz.x <= 470 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_47();
               Desenez_Tabla();
               pagina=4;
               nivel=47;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 485 && cursor_poz.x <= 525 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_18();
               Desenez_Tabla();
               pagina=4;
               nivel=48;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 540 && cursor_poz.x <= 580 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_49();
               Desenez_Tabla();
               pagina=4;
               nivel=49;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 595 && cursor_poz.x <= 635 && cursor_poz.y >=500 && cursor_poz.y <= 530 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_50();
               Desenez_Tabla();
               pagina=4;
               nivel=50;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 100 && cursor_poz.x <= 140 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_51();
               Desenez_Tabla();
               pagina=4;
               nivel=51;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 155 && cursor_poz.x <= 195 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_52();
               Desenez_Tabla();
               pagina=4;
               nivel=52;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 210 && cursor_poz.x <= 250 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_53();
               Desenez_Tabla();
               pagina=4;
               nivel=53;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 265 && cursor_poz.x <= 305 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_54();
               Desenez_Tabla();
               pagina=4;
               nivel=54;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 320 && cursor_poz.x <= 360 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_55();
               Desenez_Tabla();
               pagina=4;
               nivel=55;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 375 && cursor_poz.x <= 415 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_56();
               Desenez_Tabla();
               pagina=4;
               nivel=56;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 430 && cursor_poz.x <= 470 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_57();
               Desenez_Tabla();
               pagina=4;
               nivel=57;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 485 && cursor_poz.x <= 525 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_58();
               Desenez_Tabla();
               pagina=4;
               nivel=58;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 540 && cursor_poz.x <= 580 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_59();
               Desenez_Tabla();
               pagina=4;
               nivel=59;
               clearmouseclick(WM_LBUTTONDOWN);
           }
           if((cursor_poz.x >= 595 && cursor_poz.x <= 635 && cursor_poz.y >=600 && cursor_poz.y <= 630 )&& ismouseclick(WM_LBUTTONDOWN))
           {   Initializare_Tabla();
               Nivelul_60();
               Desenez_Tabla();
               pagina=4;
               nivel=60;
               clearmouseclick(WM_LBUTTONDOWN);
           }


        }
        if(pagina == 3)// pagina de instructiuni
        {
            GetCursorPos(&cursor_poz);
            ScreenToClient(GetForegroundWindow(),&cursor_poz);
            if((cursor_poz.x >= 50 && cursor_poz.x <= 150 && cursor_poz.y >=50 && cursor_poz.y <= 100 ) && ismouseclick(WM_LBUTTONDOWN))
            {
                DeseneazaMenu();
                pagina=1;
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if((cursor_poz.x >= 500 && cursor_poz.x <= 650 && cursor_poz.y >=650 && cursor_poz.y <= 700 ) && ismouseclick(WM_LBUTTONDOWN))
            {
               play_music(++k);
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        if(pagina == 4)//tabla de joc
        {   clearmouseclick(WM_LBUTTONDOWN);
            GetCursorPos(&cursor_poz);
            ScreenToClient(GetForegroundWindow(),&cursor_poz);
            if((cursor_poz.x >= 50 && cursor_poz.x <= 150 && cursor_poz.y >=50 && cursor_poz.y <= 100 ) && ismouseclick(WM_LBUTTONDOWN))
             {
                 DeseneazaMenu();
                 pagina=1;
                 clearmouseclick(WM_LBUTTONDOWN);
             }
            cout<<"Ai selectat nivelul "<<nivel<<"."<<endl;
            Mutare_Piese();

        }
        if(pagina == 5)// loseMenu
        {
          clearmouseclick(WM_LBUTTONDOWN);
            GetCursorPos(&cursor_poz);
            ScreenToClient(GetForegroundWindow(),&cursor_poz);
            if((cursor_poz.x >= 50 && cursor_poz.x <= 150 && cursor_poz.y >=50 && cursor_poz.y <= 100 ) && ismouseclick(WM_LBUTTONDOWN))
             {
                 DeseneazaNivele();
                 pagina=2;
                 clearmouseclick(WM_LBUTTONDOWN);
             }
             clearmouseclick(WM_LBUTTONDOWN);
        }
         if(pagina == 6)// winMenu
        {
          clearmouseclick(WM_LBUTTONDOWN);
            GetCursorPos(&cursor_poz);
            ScreenToClient(GetForegroundWindow(),&cursor_poz);
            if((cursor_poz.x >= 50 && cursor_poz.x <= 150 && cursor_poz.y >=50 && cursor_poz.y <= 100 ) && ismouseclick(WM_LBUTTONDOWN))
             {
                 DeseneazaNivele();
                 pagina=2;
                 clearmouseclick(WM_LBUTTONDOWN);
             }
             clearmouseclick(WM_LBUTTONDOWN);

        }
    }


    getch();
    closegraph();


    return 0;
}
