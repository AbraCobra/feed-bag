# include "TXLib.h"

void Background_draw();
void WindMill_draw();
void Cloud_draw (int x, int y, COLORREF color);
void MouseBody_draw();
void Tree_draw (int x, int y, int n);
void Grass_draw (int x, int y, COLORREF color);
void Butterfly_draw (int x, int y, COLORREF color);
void Cheese_draw(int x, int y, int bigness);
void CatBody_draw (int x, int y, COLORREF color, int height);


int main()
    {
     txCreateWindow (900, 800);

     Background_draw();
     Cheese_draw (50, 480, 3);
     WindMill_draw();
     Cloud_draw (110, 60, RGB (197, 210, 216));
     Cloud_draw (100, 50, RGB (165, 187, 196));
     Cloud_draw (80, 30, RGB (151, 177, 187));
     Cloud_draw (500, 150, RGB (221, 231, 232));
     MouseBody_draw();
     Tree_draw (750, 300, 8);
     Tree_draw (850, 270, 10);
     Tree_draw (350, 320, 10);
     CatBody_draw (600, 600, TX_YELLOW, 1);
     Cheese_draw (350, 600, 2);
     Grass_draw (400, 650, RGB (128, 255, 0));
     Grass_draw (380, 650, RGB (103, 205, 0));
     Cheese_draw (500, 680, 1);
     CatBody_draw (850, 600, TX_DARKGRAY, 2);
     CatBody_draw (600, 400, TX_RED, 3);


     for (int i = 1; i < 15; i++)
        {
        Grass_draw (- 100 + 80*i, 800, RGB (128, 255, 47));
        Grass_draw (- 90 + 80*i, 800, RGB (103, 143, 33));
        }

     Butterfly_draw (600, 100, RGB (204, 139, 51));
     Butterfly_draw (300, 160, RGB (204, 155, 202));
     Butterfly_draw (700, 260, RGB (255, 255, 113));

     return 0;

     }

void Background_draw()
    {
     txSetColor (RGB (151, 255, 255));
     txSetFillColor (RGB (151, 255, 255));
     txFloodFill (110, 100);
     txSetColor (RGB (55, 165, 84));
     txSetFillColor (RGB (55, 165, 84));
     txEllipse (-120, 330, 200, 700);
     txEllipse (150, 300, 370, 500);
     txEllipse (320, 340, 610, 560);
     txEllipse (550, 400, 840, 700);
     txEllipse (740, 460, 1000, 850);
     txFloodFill (300, 700);
      }

void WindMill_draw()
    {
    txSetColor (RGB (183, 104, 87));
    txSetFillColor (RGB (183, 104, 87));
    POINT mill[5] = {{155, 260}, {110, 310}, {80, 520}, {240, 520}, {200, 310}};
    txPolygon (mill, 5);
    txSetFillColor (RGB (135, 126, 80));
    POINT blades1[4] = {{100, 180}, {190, 180}, {120, 440}, {210, 440}};
    txPolygon (blades1, 4);
    POINT blades2[4] = {{20, 350}, {20, 270}, {300, 350}, {300, 270}};
    txPolygon (blades2, 4);
    txSetColor (TX_BROWN, 5);
    txSetFillColor (RGB (64, 128, 126));
    txCircle (155, 310, 20);
    txRectangle (100, 460, 140, 520);
    }

void Cloud_draw (int x, int y, COLORREF color)
    {
     txSetColor (color);
     txSetFillColor (color);
     txEllipse (x, y, x + 210, y + 80);
     txEllipse (x - 100, y + 30, x + 120, y + 100);
     txEllipse (x + 100, y + 30, x + 340, y + 90);
     }

void MouseBody_draw()
    {
    txSetColor (TX_GRAY);
    txSetFillColor (TX_GREY);

    POINT body[3] = {{110, 730}, {200, 630}, {220, 750}};
    txPolygon (body, 3);

    POINT head[3] = {{150, 630}, {210, 590}, {250, 680}};
    txPolygon (head, 3);

    txCircle (200, 580, 30);
    txCircle (132, 622, 30);

    txSetColor (TX_PINK);
    txSetFillColor (TX_PINK);
    txCircle (200, 580, 20);
    txCircle (132, 622, 20);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);
    txCircle (210, 614, 5);
    txCircle (190, 627, 5);
    txCircle (255, 680, 7);
    txLine (275, 653, 235, 703);
    txLine (295, 663, 215, 693);
    txArc (200, 730, 10, 710, 45, 270);
    }

void Tree_draw (int x, int y, int n)
    {
    txSetFillColor (RGB (128, 64, 0));
    POINT trunk[3] = {{x, y}, {x - 20, y + 200}, {x + 20, y + 200}};
    txPolygon (trunk, 3);

    for (int j = n; j > 0; j--)
        {
        for (int i = 0; i < j; i++)
            {
            txSetFillColor (RGB (rand() % 10, rand() % 255, rand() % 10));
            txCircle (x + 15*i, y + 15*j, 10);
            }
        }
    for (int j = n; j > 0; j--)
        {
        for (int i = 0; i < j; i++)
            {
            txSetFillColor (RGB (rand() % 10, rand() % 255, rand() % 10));
            txCircle (x - 15*i, y + 15*j, 10);
            }
        }
    }

void CatBody_draw (int x, int y, COLORREF color, int height)
    {
    txSetColor (TX_DARKGRAY, 3);
    txSetFillColor (color);

    txRectangle (x + 50/height, y + 120/height, x + 110/height, y + 100/height);
    POINT cat_body[4] = {{x, y}, {x + 40/height, y}, {x + 60/height, y + 120/height}, {x - 30/height, y + 120/height}};
    txPolygon (cat_body, 4);

    POINT cats_earL[3] = {{x, y}, {x - 45/height, y - 75/height}, {x + 25/height, y - 45/height}};
    POINT cats_earR[3] = {{x + 25/height, y - 45/height}, {x + 85/height, y - 75/height}, {x + 40/height, y}};
    txPolygon (cats_earL, 3);
    txPolygon (cats_earR, 3);

    txSetFillColor (TX_WHITE);
    txEllipse (x - 10/height, y - 20/height, x + 50/height, y+ 100/height);

    txSetFillColor (color);
    txCircle (x + 20/height, y - 30/height, 40/height);

    txSetColor (TX_BLACK, 6);
    txCircle (x, y - 30/height, 5/height);
    txCircle (x + 40/height, y - 30/height, 5/height);

    txSetColor (TX_BLACK);
    txLine (x + 10/height, y - 15/height, x - 45/height, y - 20/height);
    txLine (x + 10/height, y - 15/height, x - 45/height, y - 10/height);
    txLine (x + 30/height, y - 15/height, x + 85/height, y - 20/height);
    txLine (x + 30/height, y - 15/height, x + 85/height, y - 10/height);

    txSetFillColor (TX_LIGHTRED);
    txEllipse (x + 15/height, y - 20/height, x + 30/height, y - 14/height);
    }

void Grass_draw (int x, int y, COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);
    POINT grass[15] = {{x, y}, {x - 70, y - 30}, {x + 20, y}, {x - 10, y - 30}, {x + 40, y}, {x + 20, y - 100}, {x + 60, y}, {x + 60, y - 60}, {x + 80, y}, {x + 110, y - 100}, {x + 90, y}, {x + 130, y - 60}, {x + 110, y}, {x + 130,y-20}, {x + 120, y}};
    txPolygon (grass, 15);
    }

void Butterfly_draw (int x, int y, COLORREF color)
    {
    int a = x;
    int b = y;
    txLine (a, b, a + 30, b - 40);
    txLine (a, b, a + 50, b - 5);
    txSetColor (color);
    txSetFillColor (color);

    for (int i = 20; i >= 4; i-= 4)
        {
        txCircle (x, y, i);
        x -= i;
        y += i;
        }

    txSetColor (RGB (128, 255, 255));
    txSetFillColor (RGB (193, 224, 244));
    POINT wingL[3] = {{a - 15, b + 25}, {a + 30, b + 25}, {a - 15, b + 75}};
    txPolygon (wingL, 3);
    POINT wingR[3] = {{a - 25, b + 15}, {a - 25, b - 35}, {a - 75, b + 15}};
    txPolygon (wingR, 3);
    txSetColor (TX_DARKGRAY);
    }

void Cheese_draw(int x, int y, int bigness)
    {
    txSetColor (TX_LIGHTRED, 5);
    txSetFillColor (RGB (181, 0, 0));
    POINT cheese[3] = {{x, y}, {x - 140/bigness, y + 30/bigness}, {x + 150/bigness, y + 30/bigness}};
    txPolygon (cheese, 3);

    txSetColor (RGB (181, 170, 43), 5);
    txSetFillColor (RGB (227, 221, 140));
    txRectangle (x - 140/bigness, y + 30/bigness, x + 150/bigness, y + 80/bigness);
    txCircle (x - 80/bigness,y + 50/bigness, 5/bigness);
    txCircle (x - 45/bigness,y + 60/bigness, 5/bigness);
    txCircle (x + 10/bigness,y + 40/bigness, 5/bigness);
    txCircle (x + 60/bigness,y + 50/bigness, 5/bigness);
    txCircle (x + 130/bigness,y + 55/bigness, 5/bigness);
    }
