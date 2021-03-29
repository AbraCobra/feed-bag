#include "TXLib.h"
#include <cmath>

void Background_draw();
void WindMill_draw  (int x, int y, double sizeX, double sizeY);
void Cloud_draw     (int x, int y, double sizeX, double sizeY, COLORREF cloudColor);
void MouseBody_draw (int x, int y, double width, double height, COLORREF bodyColor, COLORREF earsColor);
void Tree_draw      (int x, int y, int n, double sizeX, double sizeY);
void Grass_draw     (int x, int y, COLORREF color, double sizeX, double sizeY);
void Butterfly_draw (int x, int y, COLORREF color, int bigness);
void Cheese_draw    (int x, int y, int bigness);
void CatBody_draw   (int x, int y, double width, double height, double eyebrows,
                     COLORREF catColor, COLORREF cat_breastColor);
void Flower_draw    (int x, int y, int r, int R, double sizeX, double sizeY);
void Girl_draw      (int x, int y, double sizeX, double sizeY, int hands_UP,
                     int legs_DISTANCE,  int eyebrows_UP,
                     int eyesCRAZYleft,  int eyesPUPILleft,
                     int eyesCRAZYright, int eyesPUPILright,
                     int mouthTOPpoint,  int mouthLOWERpoint,
                     COLORREF HairColor, COLORREF BodyColor = (RGB (224, 199, 160)));

int main()
    {
     txCreateWindow (900, 800);

     for (int x=100; x<=900; x+=5)
        {
        txClear();
        Background_draw();
        Tree_draw      (240, 290,   8, 0.8, 1.0);
        WindMill_draw  ( 80, 280, 0.5, 0.5);
        WindMill_draw  (450, 290, 0.3, 0.3);
        WindMill_draw  (280, 260, 0.3, 0.3);
        Tree_draw      (750, 300,   8, 0.5, 0.7);
        Tree_draw      (850, 230,   8, 0.9, 1.3);
        Tree_draw      (650, 320,   8, 0.3, 0.5);


        Cloud_draw     (    x,  60, 1.2, 1.2, RGB (197, 210, 216));
        Cloud_draw     (x + 100, 170, 0.5, 0.5, RGB (201, 213, 216));
        Cloud_draw     (x + 250,  40, 0.8, 1.0, RGB (151, 177, 187));
        Butterfly_draw (x + 600, ceil (abs (sin (x*0.5)*M_PI)*40 +  50), RGB (204, 139,  51), 2);
        Butterfly_draw (x + 300, ceil (abs (sin (x*0.5)*M_PI)*40 +  70), RGB (204, 155, 202), 2);
        Butterfly_draw (x + 500, ceil (abs (sin (x*0.2)*M_PI)*70 + 100), RGB (255, 255, 113), 3);
        Cheese_draw    (350, 600, 2);
        Cheese_draw    ( 50, 500, 3);

        for (int y = 500; y<=801; y+=50)
            {
            int x = 1;
            while (x<=901)
                {
                Grass_draw   (x + 150, y, RGB (128, 255, 0), 0.5, 0.5);
                Grass_draw   (      x, y, RGB (103, 205, 0), 0.6, 0.4);
                x+=70;
                }
            }

        for (int y = 500; y<=800; y+=120)
        {
        for (int x =  20; x<=901; x+=150)
            {
            Flower_draw  (x, y, 10, 20, 0.1, 0.1);
            }
        }

        MouseBody_draw (x + 200, 650, 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
        MouseBody_draw (700 - x, 510, 0.2, 0.2, RGB (160, 190, 141), RGB (255, 189, 240));
        CatBody_draw   (900 - x, 600, 0.7, 0.6,   1.0, RGB (255, 157,  60), RGB (255, 245, 255));
        CatBody_draw   (x + 150, 500, 0.5, 0.5, -10.0, RGB (187, 157, 160), RGB (  0, 245, 255));
        Girl_draw      (      x, 600, 1.0, 1.0, 0, 10, 0, 0, 0, 0, 0, 0, 0, TX_YELLOW);

        txSleep (300);

        }

     return 0;
     }

void Background_draw()
    {
     txSetColor     (RGB (151, 255, 255));
     txSetFillColor (RGB (151, 255, 255));
     txFloodFill         (110, 100);
     txSetColor     (RGB ( 55, 165, 84));
     txSetFillColor (RGB ( 55, 165, 84));

     txEllipse   (-120, 330,  200, 700);
     txEllipse   ( 150, 300,  370, 500);
     txEllipse   ( 320, 340,  610, 560);
     txEllipse   ( 550, 400,  840, 700);
     txEllipse   ( 740, 460, 1000, 850);
     txFloodFill ( 300, 700);
    }

void WindMill_draw(int x, int y, double sizeX, double sizeY)
    {
    txSetColor     (RGB (183, 104, 87));
    txSetFillColor (RGB (183, 104, 87));
    POINT mill[7] = {{x, y - 40*sizeY}, {x + 40*sizeX, y - 10*sizeY},
                     {x + 60*sizeX, y + 120*sizeY}, {x + 60*sizeX, y + 170*sizeY},
                     {x - 60*sizeX, y + 170*sizeY}, {x - 60*sizeX, y + 120*sizeY},
                     {x - 40*sizeX, y - 10*sizeY}};
    txPolygon (mill, 7);

    txSetFillColor  (RGB (135, 126, 80));
    POINT blades1[3] = {{x, y}, {x - 100*sizeX, y - 110*sizeY}, {x - 130*sizeX, y - 80*sizeY}};
    txPolygon (blades1, 3);

    POINT bladesIn1[3] = {{x, y}, {x - 100*sizeX, y + 110*sizeY}, {x - 130*sizeX, y + 80*sizeY}};
    txPolygon (bladesIn1, 3);

    POINT blades2[3] = {{x, y}, {x + 100*sizeX, y - 110*sizeY}, {x + 130*sizeX, y - 80*sizeY}};
    txPolygon (blades2, 3);

    POINT bladesIn2[3] = {{x, y}, {x + 100*sizeX, y + 110*sizeY}, {x + 130*sizeX, y + 80*sizeY}};
    txPolygon (bladesIn2, 3);
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

void Tree_draw (int x, int y, int n, double sizeX, double sizeY)
    {
    txSetFillColor (RGB (128, 64, 0));
    POINT trunk[3] = {{x, y}, {x - 20*sizeX, y + 200*sizeY}, {x + 20*sizeX, y + 200*sizeY}};
    txPolygon (trunk, 3);

    txSetFillColor (RGB (40, 203, 88));

    for (int j = n; j > 0; j--)
        {
        for (int i = 0; i < j; i++)
            {
            txSetFillColor (RGB (rand()%10, rand()%255, rand()%10));
            txCircle (x + 15*i*sizeX, y + 15*j*sizeY, 16*sizeX);
            }
        }
    for (int j = n; j > 0; j--)
        {
        for (int i = 0; i < j; i++)
            {
            txSetFillColor (RGB (rand()%10, rand()%255, rand()%10));
            txCircle (x - 15*i*sizeX, y + 15*j*sizeY, 16*sizeX);
            }
        }
    }

void CatBody_draw (int x, int y, double width, double height, double eyebrows, COLORREF catColor, COLORREF cat_breastColor)
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
    txEllipse (x - 10*width, y - 20*height, x + 50*width, y + 100*height);

    txSetFillColor (catColor);
    txCircle (x + 20*width, y - 30*height, 40*width);

    txSetColor (TX_BLACK, 6);
    txCircle (           x, y - 30*height, 5*width);
    txCircle (x + 40*width, y - 30*height, 5*width);

    txSetColor (TX_BLACK);
    txLine (x + 10*width, y - 15*height, x - 45*width, y - 20*height);
    txLine (x + 10*width, y - 15*height, x - 45*width, y - 10*height);
    txLine (x + 30*width, y - 15*height, x + 85*width, y - 20*height);
    txLine (x + 30*width, y - 15*height, x + 85*width, y - 10*height);
    txLine (x + 22*width, y - 12*height, x + 22*width, y -  5*height);

    txSetColor (TX_BLACK,3);
    txLine (x +  10*width, y - 45*height, x - 20*width, y - (45 + eyebrows)*height );
    txLine (x +  30*width, y - 45*height, x + 60*width, y - (45 + eyebrows)*height);

    txSetFillColor (TX_LIGHTRED);
    txEllipse (x + 15*width, y - 20*height, x + 30*width, y - 14*height);
    }

void Grass_draw (int x, int y, COLORREF color, double sizeX, double sizeY)
    {
    txSetColor (color);
    txSetFillColor (color);
    POINT grass[15] = {{x, y}, {x - 70*sizeX, y - 30*sizeY},
                      {x +  20*sizeX, y}, {x -  10*sizeX, y -  30*sizeY},
                      {x +  40*sizeX, y}, {x +  20*sizeX, y - 100*sizeY},
                      {x +  60*sizeX, y}, {x +  60*sizeX, y -  60*sizeY},
                      {x +  80*sizeX, y}, {x + 110*sizeX, y - 100*sizeY},
                      {x +  90*sizeX, y}, {x + 130*sizeX, y -  60*sizeY},
                      {x + 110*sizeX, y}, {x + 130*sizeX, y -  20*sizeY},
                      {x + 120*sizeX, y}};
    txPolygon (grass, 15);
    }

void Butterfly_draw (int x, int y, COLORREF color, int bigness)
    {
    int a = x;
    int b = y;
    txSetColor (TX_DARKGRAY);
    txLine (a, b, a + 30/bigness, b - 40/bigness);
    txLine (a, b, a + 50/bigness, b -  5/bigness);
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
    txSetColor     (TX_LIGHTRED, 5);
    txSetFillColor (RGB (181, 0, 0));
    POINT cheese[3] = {{x, y}, {x - 140/bigness, y + 30/bigness}, {x + 150/bigness, y + 30/bigness}};
    txPolygon (cheese, 3);

    txSetColor     (RGB (181, 170,  43), 5);
    txSetFillColor (RGB (227, 221, 140));
    txRectangle (x - 140/bigness, y + 30/bigness, x + 150/bigness, y + 80/bigness);
    txCircle (x -  80/bigness, y + 50/bigness, 5/bigness);
    txCircle (x -  45/bigness, y + 60/bigness, 5/bigness);
    txCircle (x +  10/bigness, y + 40/bigness, 5/bigness);
    txCircle (x +  60/bigness, y + 50/bigness, 5/bigness);
    txCircle (x + 130/bigness, y + 55/bigness, 5/bigness);
    }

void Flower_draw (int x, int y, int r, int R, double sizeX, double sizeY)
    {
    txSetColor(RGB (131,  209, 92),5);
    txLine   (x,                        y, x - 40*sizeX, y + 210*sizeY);
    txLine   (x - 40*sizeX, y + 210*sizeY, x - 35*sizeX, y + 105*sizeY);
    txLine   (x - 40*sizeX, y + 210*sizeY, x - 15*sizeX, y +  70*sizeY);
    txLine   (x - 40*sizeX, y + 210*sizeY, x -  5*sizeX, y +  30*sizeY);

    txSetColor     (RGB (rand()%255, rand()%10, rand()%10), 3);
    txSetFillColor (RGB (rand()%255, rand()%10, rand()%10));

    txCircle (x - 40*sizeX, y - 40*sizeY, r*sizeX);
    txCircle (x - 40*sizeX, y + 40*sizeY, r*sizeX);
    txCircle (x + 40*sizeX, y + 40*sizeY, r*sizeX);
    txCircle (x + 40*sizeX, y - 40*sizeY, r*sizeX);

    txSetFillColor (RGB (rand()%255, rand()%10, rand()%10));
    txCircle (x, y, R*sizeX);

    txSetFillColor (RGB (rand()%255, rand()%10, rand()%100));

    POINT petalUp[5] = {{x - 15*sizeX, y - 30*sizeY},
                        {x - 30*sizeX, y - 70*sizeY},
                        {           x, y - 110*sizeY},
                        {x + 30*sizeX, y - 70*sizeY},
                        {x + 15*sizeX, y - 30*sizeY}};
    txPolygon (petalUp, 5);

    POINT petalDown[5] = {{x - 15*sizeX, y +  30*sizeY},
                          {x - 30*sizeX, y +  70*sizeY},
                          {           x, y + 110*sizeY},
                          {x + 30*sizeX, y +  70*sizeY},
                          {x + 15*sizeX, y +  30*sizeY}};
    txPolygon (petalDown, 5);

    POINT petalLeft[5] = {{x -  30*sizeX, y - 15*sizeY},
                          {x -  70*sizeX, y - 30*sizeY},
                          {x - 110*sizeX,            y},
                          {x -  70*sizeX, y + 30*sizeY},
                          {x -  30*sizeX, y + 15*sizeY}};
    txPolygon (petalLeft, 5);

    POINT petalRight[5] = {{x +  30*sizeX, y - 15*sizeY},
                           {x +  70*sizeX, y - 30*sizeY},
                           {x + 110*sizeX,            y},
                           {x +  70*sizeX, y + 30*sizeY},
                           {x +  30*sizeX, y + 15*sizeY}};
    txPolygon (petalRight, 5);
    }

void Girl_draw (int x, int y, double sizeX, double sizeY, int hands_UP,
                int legs_DISTANCE, int eyebrows_UP,    int eyesCRAZYleft,
                int eyesPUPILleft, int eyesCRAZYright, int eyesPUPILright,
                int mouthTOPpoint, int mouthLOWERpoint, COLORREF HairColor, COLORREF BodyColor)
    {
    txSetColor (BodyColor, 7);

    txLine (x - 50*sizeX, y + 25*sizeY, x - 100*sizeX, y + (80 - hands_UP)*sizeY);
    txLine (x + 50*sizeX, y + 25*sizeY, x + 100*sizeX, y + (80 - hands_UP)*sizeY);

    txLine (x, y, x - (5 + legs_DISTANCE/2)*sizeX, y + 200*sizeY);
    txLine (x, y, x + (5 + legs_DISTANCE/2)*sizeX, y + 200*sizeY);

    txSetColor     ((TX_BLACK), 2);
    txSetFillColor (TX_BLACK);
    txCircle   (x - 50*sizeX, y + 30*sizeY, 25*sizeX);
    txCircle   (x + 50*sizeX, y + 30*sizeY, 25*sizeX);

    POINT girlsGown[4] = {{x - 30*sizeX, y}, {x + 30*sizeX, y},
                          {x + 70*sizeX, y + 120*sizeY},
                          {x - 80*sizeX, y + 120*sizeY}};
    txPolygon (girlsGown, 4);

    txSetFillColor (TX_WHITE);
    txCircle (x + 25*sizeX, y +  25*sizeY, 9*sizeX);
    txCircle (x + 10*sizeX, y +  50*sizeY, 9*sizeX);
    txCircle (x - 30*sizeX, y +  50*sizeY, 9*sizeX);
    txCircle (x - 30*sizeX, y +  80*sizeY, 9*sizeX);
    txCircle (x + 30*sizeX, y +  80*sizeY, 9*sizeX);
    txCircle (x - 15*sizeX, y +  25*sizeY, 9*sizeX);
    txCircle (x - 50*sizeX, y + 110*sizeY, 9*sizeX);
    txCircle (           x, y + 110*sizeY, 9*sizeX);
    txCircle (x + 50*sizeX, y + 110*sizeY, 9*sizeX);

    txSetColor     (HairColor, 5);
    txSetFillColor (HairColor);
    txLine         (x -  40*sizeX, y - 55*sizeY, x - 100*sizeX, y + 20*sizeY);
    txLine         (x - 100*sizeX, y + 20*sizeY, x - 115*sizeX, y + 10*sizeY);
    txLine         (x - 115*sizeX, y + 10*sizeY, x -  40*sizeX, y - 20*sizeY);

    txSetFillColor (TX_BLACK);
    txCircle  (x -  80*sizeX, y -  3*sizeY, 10*sizeX);

    txLine   (x +  40*sizeX, y - 55*sizeY, x + 100*sizeX, y + 20*sizeY);
    txLine   (x + 100*sizeX, y + 20*sizeY, x + 115*sizeX, y + 10*sizeY);
    txLine   (x + 115*sizeX, y + 10*sizeY, x +  40*sizeX, y - 20*sizeY);
    txCircle (x +  80*sizeX, y -  3*sizeY, 10*sizeX);

    txSetColor     (BodyColor);
    txSetFillColor (BodyColor);
    txEllipse      (x -  50*sizeX, y - 70*sizeY, x + 50*sizeX, y);

    txSetColor     (TX_BLACK, 1);
    txSetFillColor (TX_WHITE);
    txLine  (x - 17*sizeX, y - 55*sizeY, x - 37*sizeX, y - (55 - eyebrows_UP)*sizeY);
    txLine  (x + 17*sizeX, y - 55*sizeY, x + 37*sizeX, y - (55 - eyebrows_UP)*sizeY);
    txCircle       (x - 27*sizeX, y - 40*sizeY, (10 - eyesCRAZYleft)*sizeX);
    txCircle       (x + 27*sizeX, y - 40*sizeY, (10 - eyesCRAZYright)*sizeX);

    txSetColor     (TX_BLUE);
    txSetFillColor (TX_BLUE);
    txCircle       (x - 27*sizeX, y - 40*sizeY, (5 - eyesPUPILleft)*sizeX);
    txCircle       (x + 27*sizeX, y - 40*sizeY, (5 - eyesPUPILright)*sizeX);

    txSetColor(HairColor, 5);
    txLine (           x,  y - 70*sizeY,            x,     y - 58*sizeY);
    txLine (x -  5*sizeX,  y - 68*sizeY, x -  5*sizeX,     y - 60*sizeY);
    txLine (x - 10*sizeX,  y - 66*sizeY, x - 10*sizeX,     y - 62*sizeY);
    txLine (x +  5*sizeX,  y - 68*sizeY, x +  5*sizeX,     y - 60*sizeY);
    txLine (x + 10*sizeX,  y - 66*sizeY, x + 10*sizeX,     y - 62*sizeY);

    txSetColor     (RGB (207, 58, 96));
    txSetFillColor (RGB (207, 58, 96));
    POINT girlsMouth[4] = {{x - 22*sizeX, y -  20*sizeY},
                           {x -  7*sizeX, y - (20 - mouthTOPpoint)*sizeY},
                           {x + 22*sizeX, y -  20*sizeY},
                           {           x, y - (10 - mouthLOWERpoint)*sizeY}};
    txPolygon (girlsMouth, 4);

    }
