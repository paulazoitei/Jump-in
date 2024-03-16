#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void Background()
{
    setcolor(7);
    readimagefile("JumpINback.bmp", 0, 0, 655, 755);
}
void Butoane()
{  //Butonul de play
    setfillstyle(SOLID_FILL,(198, 47, 36));
    settextstyle(6,HORIZ_DIR,7);
    setbkcolor(RGB(198,47,36));
    outtextxy(180,125,"PLAY");

   //Butonul de instructiuni
   setfillstyle(SOLID_FILL,(223, 145, 26));
   setbkcolor(RGB(223, 145, 26));
   settextstyle(8,HORIZ_DIR,5);
   outtextxy(180,250, "INSTRUCTIONS");

   //Butonul de muzica
   setbkcolor(RGB(198, 47, 36));
   settextstyle(4, HORIZ_DIR, 2);
   outtextxy(500, 650, "MUSIC");
}

void instructiuni()
{
    setfillstyle(SOLID_FILL, 7);
    bar(0, 0, 655, 755);
    setfillstyle(SOLID_FILL, RGB(173, 241, 253));
    //Butonul de back
    setbkcolor(RGB(173, 241, 253));
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(55, 70, "BACK");
    setcolor(BLACK);

    setfillstyle(SOLID_FILL, (223, 145, 26));
    setbkcolor(RGB(173, 241, 253));
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(500, 650, "MUSIC");

    setbkcolor(RGB(173, 241, 253));
    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(200, 50, "INSTRUCTIONS");
    settextstyle(8, HORIZ_DIR, 3);
    outtextxy(100, 250, "The object of the game is to move");
    outtextxy(100, 275, "the rabbits and foxes around the");
    outtextxy(100, 300, "game board until all of the rabbits");
    outtextxy(100, 325, "are same in brown holes. You");
    outtextxy(100, 350, "can move a rabbit or fox by");
    outtextxy(100, 375, "first selecting it, and then select");
    outtextxy(100, 400, "any of the possible destinations.");
    outtextxy(100, 425, "Rabbits can only move by jumping");
    outtextxy(100, 450, "over obstacles (other rabbits,");
    outtextxy(100, 475, "foxes, mushrooms or a combination");
    outtextxy(100, 500, "of these), foxes can only move");
    outtextxy(100, 525, "forward or backward and cannot");
    outtextxy(100, 550, "jump over obstacles.");
    outtextxy(100, 575, "Have fun!");



}

void WinMenu()
{
    setcolor(RGB(34, 178, 76));
    readimagefile("JumpINback.bmp",0, 0, 655, 755);
    setbkcolor(RGB(173, 241, 253));
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(55, 70, "BACK");
    setbkcolor(RGB(173, 241, 253));
    settextstyle(6, HORIZ_DIR, 7);
    outtextxy(100,200,"YOU WIN!");
}

void LoseMenu()
{
    readimagefile("JumpINback.bmp", 0, 0, 655, 755);
    setbkcolor(RGB(173, 241, 253));
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(55, 70, "BACK");
    setbkcolor(RGB(173, 241, 253));
    settextstyle(6, HORIZ_DIR, 7);
    outtextxy(100, 200, "YOU LOST!");
}

void DeseneazaMenu()
{
    Background();
    Butoane();
}
#endif // MENU_H_INCLUDED
