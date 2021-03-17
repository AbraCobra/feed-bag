# include "TXLib.h"

void Background_draw();
void WindMill_draw();
void Cloud_draw     (int x, int y, double sizeX, double sizeY, COLORREF cloudColor);
void MouseBody_draw (int x, int y, double width, double height, COLORREF bodyColor, COLORREF earsColor);
void Tree_draw      (int x, int y, int n);
void Grass_draw     (int x, int y, COLORREF color, int height);
void Butterfly_draw (int x, int y, COLORREF color, int bigness);
void Cheese_draw    (int x, int y, int bigness);
void CatBody_draw   (int x, int y, double width, double height, COLORREF catColor, COLORREF cat_breastColor);


int main()
    {
     txCreateWindow (900, 800);

     Background_draw();
     WindMill_draw ();
     Cheese_draw    ( 50, 500, 3);
     Cloud_draw     (110,  60, 1.2, 1.2, RGB (197, 210, 216));
     Cloud_draw     (500, 190, 0.5, 0.5, RGB (201, 213, 216));
     Cloud_draw     (700,  40, 0.8, 1.0, RGB (151, 177, 187));
     MouseBody_draw (110, 730, 1.0, 1.0, RGB (116, 143, 141), RGB (255, 128, 128));
     Tree_draw      (750, 300, 8);
     Tree_draw      (850, 270, 10);
     Tree_draw      (350, 320, 10);
     MouseBody_draw (355, 585, 0.5, 0.7, RGB (187, 187, 141), RGB (255, 189, 255));
     CatBody_draw   (600, 600, 1.0, 1.1, RGB (120, 187, 141), RGB (255, 170, 255));
     Cheese_draw    (350, 600, 2);
     Grass_draw     (400, 650, RGB (128, 255, 0), 1);
     Grass_draw     (380, 650, RGB (103, 205, 0), 1);
     Cheese_draw    (500, 680, 1);
     CatBody_draw   (850, 600, 0.7, 0.6, RGB (255, 157,  60), RGB (255, 245, 255));
     CatBody_draw   (600, 400, 0.3, 0.3, RGB (187, 157, 160), RGB (  0, 245, 255));
     MouseBody_draw (658, 510, 0.2, 0.2, RGB (160, 190, 141), RGB (255, 189, 240));
     Grass_draw     (630, 515, RGB (128, 255, 0), 2);
     Grass_draw     (690, 515, RGB (103, 205, 0), 2);

     for (int i = 1; i < 15; i++)
        {
        Grass_draw (- 100 + 80*i, 800, RGB (128, 255, 47), 1);
        Grass_draw (-  90 + 80*i, 800, RGB (103, 143, 33), 1);
        }

     Butterfly_draw (600, 100, RGB (204, 139,  51), 1);
     Butterfly_draw (300, 160, RGB (204, 155, 202), 2);
     Butterfly_draw (700, 260, RGB (255, 255, 113), 3);

     return 0;

     }

void Background_draw()
    {
     txSetColor     (RGB (151, 255, 255));
     txSetFillColor (RGB (151, 255, 255));
     txFloodFill    (110, 100);
     txSetColor     (RGB (55, 165, 84));
     txSetFillColor (RGB (55, 165, 84));

     txEllipse   (-120, 330,  200, 700);
     txEllipse   ( 150, 300,  370, 500);
     txEllipse   ( 320, 340,  610, 560);
     txEllipse   ( 550, 400,  840, 700);
     txEllipse   ( 740, 460, 1000, 850);
     txFloodFill ( 300, 700);
    }

void WindMill_draw()
    {
    txSetColor     (RGB (183, 104, 87));
    txSetFillColor (RGB (183, 104, 87));
    POINT mill[5] = {{155, 260}, {110, 310}, {80, 520}, {240, 520}, {200, 310}};
    txPolygon (mill, 5);

    txSetFillColor  (RGB (135, 126, 80));
    POINT blades1[4] = {{100, 180}, {190, 180}, {120, 440}, {210, 440}};
    txPolygon (blades1, 4);
    POINT blades2[4] = {{20, 350}, {20, 270}, {300, 350}, {300, 270}};
    txPolygon (blades2, 4);

    txSetColor     (TX_BROWN, 5);
    txSetFillColor (RGB(64, 128, 126));
    txCircle       (155, 310,  20);
    txRectangle    (100, 460, 140, 520);
    }

void Cloud_draw (int x, int y, double sizeX, double sizeY, COLORREF cloudColor)
    {
     txSetColor     (cloudColor);
     txSetFillColor (cloudColor);
     txEllipse (x, y, x + 210*sizeX, y + 80*sizeY);
     txEllipse (x - 100*sizeX, y + 30*sizeY, x + 120*sizeX, y + 100*sizeY);
     txEllipse (x + 100*sizeX, y + 30*sizeY, x + 340*sizeX, y +  90*sizeY);
     }

void MouseBody_draw (int x, int y, double width, double height, COLORREF bodyColor, COLORREF earsColor)
    {
    txSetColor     (bodyColor);
    txSetFillColor (bodyColor);

    POINT body[3] = {{x, y}, {x + 90*width, y - 100*height}, {x + 110*height, y + 20*height}};
    txPolygon (body, 3);

    POINT head[3] = {{x +  40*width, y - 100*height},
                     {x + 100*width, y - 140*height},
                     {x + 140*width, y -  50*height}};
    txPolygon (head, 3);

    txCircle (x + 90*width, y - 150*height, 30*width);
    txCircle (x + 22*width, y - 108*height, 30*width);

    txSetColor     (earsColor);
    txSetFillColor (earsColor);
    txCircle (x + 90*width, y - 150*height, 20*width);
    txCircle (x + 22*width, y - 108*height, 20*width);

    txSetColor     (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);

    txCircle (x + 100*width, y - 116*height, 5*width);
    txCircle (x +  80*width, y - 103*height, 5*width);
    txCircle (x + 145*width, y -  50*height, 7*width);
    txLine   (x + 165*width, y -  77*height, x + 125*width, y - 27*height);
    txLine   (x + 185*width, y -  63*height, x + 105*width, y - 37*height);
    txArc    (x +  90*width, y, x - 100*width, y - 20*height, 45, 270);
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

void CatBody_draw (int x, int y, double width, double height, COLORREF catColor, COLORREF cat_breastColor)
    {
    txSetColor     (TX_DARKGRAY, 3);
    txSetFillColor (catColor);

    txRectangle (x + 50*width, y + 120*height, x + 110*width, y + 100*height);
    POINT cat_body[4] = {{x, y}, {x + 40*width, y},
                        {x + 60*width, y + 120*height},
                        {x - 30*width, y + 120*height}};
    txPolygon (cat_body, 4);

    POINT cats_earL[3] = {{x, y}, {x - 45*width, y - 75*height}, {x + 25*width, y - 45*height}};
    POINT cats_earR[3] = {{x + 25*width, y - 45*height}, {x + 85*width, y - 75*height}, {x + 40*width, y}};
    txPolygon (cats_earL, 3);
    txPolygon (cats_earR, 3);

    txSetFillColor (cat_breastColor);
    txEllipse (x - 10*width, y - 20*height, x + 50*width, y+ 100*height);

    txSetFillColor (catColor);
    txCircle (x + 20*width, y - 30*height, 40*width);

    txSetColor (TX_BLACK, 6);
    txCircle (x, y - 30*height, 5*width);
    txCircle (x + 40*width, y - 30*height, 5*width);

    txSetColor (TX_BLACK);
    txLine (x + 10*width, y - 15*height, x - 45*width, y - 20*height);
    txLine (x + 10*width, y - 15*height, x - 45*width, y - 10*height);
    txLine (x + 30*width, y - 15*height, x + 85*width, y - 20*height);
    txLine (x + 30*width, y - 15*height, x + 85*width, y - 10*height);
    txLine (x + 22*width, y - 12*height, x + 22*width, y -  5*height);

    txSetFillColor (TX_LIGHTRED);
    txEllipse (x + 15*width, y - 20*height, x + 30*width, y - 14*height);
    }

void Grass_draw (int x, int y, COLORREF color, int height)
    {
    txSetColor (color);
    txSetFillColor (color);
    POINT grass[15] = {{x, y}, {x - 70, y - 30/height},
                      {x +  20, y}, {x -  10, y -  30/height},
                      {x +  40, y}, {x +  20, y - 100/height},
                      {x +  60, y}, {x +  60, y -  60/height},
                      {x +  80, y}, {x + 110, y - 100/height},
                      {x +  90, y}, {x + 130, y -  60/height},
                      {x + 110, y}, {x + 130, y -  20/height},
                      {x + 120, y}};
    txPolygon (grass, 15);
    }

void Butterfly_draw (int x, int y, COLORREF color, int bigness)
    {
    int a = x;
    int b = y;
    txSetColor (TX_DARKGRAY);
    txLine (a, b, a + 30/bigness, b - 40/bigness);
    txLine (a, b, a + 50/bigness, b - 5/bigness);
    txSetColor (color);
    txSetFillColor (color);

    for (int i = 20/bigness; i >= 4/bigness; i-= 4/bigness)
        {
        txCircle (x, y, i);
        x -= i;
        y += i;
        }

    txSetColor     (RGB (128, 255, 255));
    txSetFillColor (RGB (193, 224, 244));
    POINT wingL[3] = {{a - 15/bigness, b + 25/bigness},
                      {a + 30/bigness, b + 25/bigness},
                      {a - 15/bigness, b + 75/bigness}};
    txPolygon (wingL, 3);

    POINT wingR[3] = {{a - 25/bigness, b + 15/bigness},
                      {a - 25/bigness, b - 35/bigness},
                      {a - 75/bigness, b + 15/bigness}};
    txPolygon (wingR, 3);
    }

void Cheese_draw (int x, int y, int bigness)
    {
    txSetColor (TX_LIGHTRED, 5);
    txSetFillColor (RGB (181, 0, 0));
    POINT cheese[3] = {{x, y}, {x - 140/bigness, y + 30/bigness}, {x + 150/bigness, y + 30/bigness}};
    txPolygon (cheese, 3);

    txSetColor     (RGB (181, 170, 43), 5);
    txSetFillColor (RGB (227, 221, 140));
    txRectangle (x - 140/bigness, y + 30/bigness, x + 150/bigness, y + 80/bigness);
    txCircle (x -  80/bigness, y + 50/bigness, 5/bigness);
    txCircle (x -  45/bigness, y + 60/bigness, 5/bigness);
    txCircle (x +  10/bigness, y + 40/bigness, 5/bigness);
    txCircle (x +  60/bigness, y + 50/bigness, 5/bigness);
    txCircle (x + 130/bigness, y + 55/bigness, 5/bigness);
    }
