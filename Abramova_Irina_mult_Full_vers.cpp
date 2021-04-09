#include "TxLib.h"
#include <cmath>

void EntryScene ();
void SpringCountryScene();
void PinkMountainScene();
void NightSavanahScene();
void NightSavanahSceneEnd();
void SpringFonBegining();
void FinishScene();
void SpringFon();
void MountainsLandscape();
void SavanahLandscape();
void Cloud_draw          (int  x, int  y, double sizeX, double sizeY, COLORREF cloudColor);
void Tree_draw           (int  x, int  y, int n, double sizeX, double sizeY);
void WindMill_draw       (int  x, int  y, double sizeX, double sizeY);
void Millblades_draw     (int x0, int y0, int x, int y);
void Butterfly_draw      (int  x, int  y, COLORREF color, int bigness);
void Water_lily_draw     (int  x, int  y, double sizeX, double sizeY);
void Cactus_draw         (int  x, int  y, double sizeX, double sizeY);
void Chuck_draw          (int  x, int  y, double sizeX, double sizeY, int eyebrows, int hear);
void Title_draw          (int  x, int  y);
void TitleEnd_draw       (int  x, int  y);
void WorkisDone          (int  x, int  y);
void FinishTitles        (int  x, int  y);
void Grass_draw          (int  x, int  y, COLORREF color, double sizeX, double sizeY);
void MouseBody_draw      (int  x, int  y, double width, double height, COLORREF bodyColor, COLORREF earsColor);
void CatBody_draw        (int  x, int  y, double width, double height, double eyebrows,
                          COLORREF catColor, COLORREF cat_breastColor);
void Skateboard_draw     (int  x, int  y, double sizeX, double sizeY);
void Skate_wheels_drawer (int x0, int y0,  int r);
void BigDipper_draw      (int x, int y, int r);
void Girl_draw           (int  x, int  y, double sizeX, double sizeY, int hands_UP,
                          int legs_DISTANCE,  int eyebrows_UP,
                          int eyesCRAZYleft,  int eyesPUPILleft,
                          int eyesCRAZYright, int eyesPUPILright,
                          int mouthTOPpoint,  int mouthLOWERpoint,
                          COLORREF HairColor, COLORREF BodyColor = (RGB (224, 199, 160)));
int main()
    {
    txCreateWindow (1100, 900);

    EntryScene();
    SpringCountryScene();
    PinkMountainScene ();
    NightSavanahScene ();
    NightSavanahSceneEnd();
    FinishScene();

    return 0;
    }

void EntryScene()
    {
    txBegin();

    int t = 0;
    while (t <= 110)
        {
        txClear();
        SpringFonBegining();

        Grass_draw (    0 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (  100 +  2*t, 400, TX_GREEN, 0.7, 0.7);
        Grass_draw (  150 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (  250 +  2*t, 400, TX_GREEN, 0.6, 0.6);
        Grass_draw (  350 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (- 100 +  2*t, 400, TX_GREEN, 0.7, 0.7);
        Grass_draw (- 150 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (- 250 +  2*t, 400, TX_GREEN, 0.6, 0.6);
        Grass_draw (- 350 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (  550 +  2*t, 400, TX_GREEN, 0.5, 0.5);
        Grass_draw (  750 +  2*t, 400, TX_GREEN, 0.6, 0.6);
        Grass_draw (  950 +  2*t, 400, TX_GREEN, 0.5, 0.5);

        Title_draw          ( 1100 - 15*t, 100);
        Skateboard_draw     (- 100 + 10*t, 700, 0.8, 0.8);
        Skate_wheels_drawer ( - 50 + 10*t + ROUND (4*cos(t)) + ROUND (3*sin(t)), 730 + ROUND (3*cos(t)) - ROUND (4*sin(t)), 20);
        Chuck_draw          (   20 + 10*t, 600, 0.5, 0.5, (t%2*20) - 10, (t%2*30) + 50);

        txSleep (100);
        t++;
        }

    txEnd();
    }

void SpringCountryScene()
    {
    txBegin();

    int t = 0;
    while (t <= 100)
        {
        txClear();
        SpringFon();

        Cloud_draw     (      2*t,  20, 1.2, 1.2, TX_WHITE);
        Cloud_draw     (2*t + 900, 170, 0.5, 0.5, TX_WHITE);


        Millblades_draw (675, 180, ROUND (  100*cos(t*0.1) + 675),        ROUND (  100*sin(t*0.1) + 180));
        Millblades_draw (675, 180, ROUND (- 100*cos(t*0.1) + 675),        ROUND (- 100*sin(t*0.1) + 180));
        Millblades_draw (675, 180, ROUND (- 100*cos(t*0.1  + 1.5) + 675), ROUND (- 100*sin(t*0.1  + 1.5) + 180));
        Millblades_draw (675, 180, ROUND (  100*cos(t*0.1  + 1.5) + 675), ROUND (  100*sin(t*0.1  + 1.5) + 180));

        Butterfly_draw (t + 600, ROUND (abs (sin (t*0.5)*M_PI)*40 +  50), RGB (204, 139,  51), 2);
        Butterfly_draw (t + 300, ROUND (abs (sin (t*0.5)*M_PI)*40 +  70), RGB (204, 155, 202), 2);
        Butterfly_draw (t + 500, ROUND (abs (sin (t*0.2)*M_PI)*70 + 100), RGB (255, 255, 113), 3);

        Grass_draw     (350, 500, TX_GREEN, 1.1, 1.1);
        CatBody_draw   (430, (t/3%2*50 - 30) + 400, 0.7, 0.6, 1.0, RGB (255, 157, 60), RGB (255, 245, 255));
        MouseBody_draw (550, (t/4%2*50 - 50) + 500, 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));

        Grass_draw     (350, 500, TX_GREEN, 1.1, 1.1);
        Grass_draw     (450, 500, TX_GREEN, 0.9, 0.9);
        Grass_draw     (460, 520, TX_GREEN, 0.9, 0.9);


        Girl_draw      (600 - 4*t, 500 - 0.5*t, 0.7, 0.7, (t/5)%10 + 10, ((t/4)%2)*50 - 50,
                       (t/2)%10, 0, 0, 0, 0, t%2*3, 0, RGB (219, 112, 147));

        Skateboard_draw     (- 100 + 10*t, 700, 0.8, 0.8);
        Skate_wheels_drawer (-  50 + 10*t + ROUND (4*cos(t)) + ROUND (3*sin(t)), 730 + ROUND (3*cos(t)) - ROUND (4*sin(t)), 20);
        Chuck_draw          (   20 + 10*t, 600, 0.5, 0.5, (t%2*20) - 10, (t%2*30) + 50);

        txSleep (100);
        t++;
        }

    txEnd();
    }

void SpringFon()
    {
    txSetColor     (RGB (204, 255, 255));
    txSetFillColor (RGB (204, 255, 255));

    POINT sky[6] = {{0, 450}, {0, 350}, {600, 350}, {750, 350}, {1100, 350}, {1100, 430}};
    txPolygon (sky, 6);

    for (int gradSky = 1; gradSky < 200; gradSky++)
        {
        txSetColor     (RGB (204 - 2*gradSky, 255, 255));
        txSetFillColor (RGB (204 - 2*gradSky, 255, 255));

        POINT heaven[4] = {{0, 350 - 4*gradSky}, {0, 360 - 4*gradSky}, {1100, 360 - 4*gradSky},{1100, 350 - 4*gradSky}};
        txPolygon (heaven, 4);
        }

    txSetColor     (RGB (51, 204, 51));
    txSetFillColor (RGB (51, 204, 51));

    POINT hill[7] = {{0, 800}, {0, 450}, {600, 350}, {750, 350}, {1100, 430}, {1100, 800}, {0, 800}};
    txPolygon (hill, 7);
    txSetFillColor (RGB (0, 204, 0));
    txCircle  (300, 1150, 570);
    txCircle  (800, 1250, 570);

    Tree_draw     ( 140, 290,   8, 0.8, 1.0);
    Tree_draw     ( 850, 300,   8, 0.5, 0.7);
    Tree_draw     ( 950, 230,   8, 0.9, 1.3);
    WindMill_draw ( 675, 180, 1.0, 1.0);
    }

void PinkMountainScene()
    {
    txBegin();

    int t = 0;
    while (t <= 110)
        {
        txClear();
        MountainsLandscape();

        Water_lily_draw (7*t +  150, 700, 0.8, 0.8);
        Water_lily_draw (  t +  350, 600, 0.5, 0.5);
        Water_lily_draw (  t +   50, 650, 0.3, 0.3);
        Water_lily_draw (  t +  850, 550, 0.7, 0.7);
        Chuck_draw      (7*t +  180, 600, 0.5, 0.5, (t%2*20) - 10, (t%2*30) + 50);

        txSleep (100);
        t++;
        }

    txEnd();
    }

void NightSavanahScene()
    {

    txBegin();
    int t = 0;
    while (t < 14)
        {
        txClear();
        SavanahLandscape();

        BigDipper_draw (  20, 150, 4);
        BigDipper_draw (  40, 350, 5);
        BigDipper_draw (1010, 150, 4);
        BigDipper_draw (1010, 250, 5);
        Cactus_draw    ( 270, 450, 2, 2);
        Cactus_draw    ( 170, 450, 3, 3);
        Cactus_draw    ( 870, 440, 2, 2);
        Cactus_draw    ( 970, 470, 4, 4);
        Cactus_draw    ( 100, 460, 4, 4);
        Cactus_draw    ( 850, 560, 1, 1);

        Chuck_draw     (t*50, 10 + 20*t, 0.5, 0.5, 10, (t%2*30) + 50);

        txSleep(200);
        t++;
        }

    txEnd();
    }

void NightSavanahSceneEnd()
    {
    txBegin();

    int t = 0;
    while (t < 10)
        {
        txClear();
        SavanahLandscape();

        BigDipper_draw (  20, 150, 4);
        BigDipper_draw (  40, 350, 5);
        BigDipper_draw (1010, 150, 4);
        BigDipper_draw (1010, 250, 5);
        Cactus_draw    ( 270, 450, 2, 2);
        Cactus_draw    ( 170, 450, 3, 3);
        Cactus_draw    ( 870, 440, 2, 2);
        Cactus_draw    ( 970, 470, 4, 4);
        Cactus_draw    ( 100, 460, 4, 4);
        Cactus_draw    ( 850, 560, 1, 1);
        Chuck_draw     ( 820, 520, 0.5, 0.5, - 30, (t%2*30) + 50);

        txSleep(200);
        t++;
        }

    txEnd();
    }


void FinishScene()
    {
    txBegin();

    int t = 0;
    while (t < 500)
        {
        txClear();
        SavanahLandscape();

        BigDipper_draw (  20, 150, 4);
        BigDipper_draw (  40, 350, 5);
        BigDipper_draw (1010, 150, 4);
        BigDipper_draw (1010, 250, 5);

        FinishTitles   ( 250,  900 - 5*t);
        WorkisDone     ( 300, 1500 - 5*t);

        txSleep(20);
        t++;
        }

    txEnd();
    }

void WindMill_draw (int x, int y, double sizeX, double sizeY)
    {
    txSetColor     (RGB (183, 104, 87));
    txSetFillColor (RGB (183, 104, 87));
    POINT mill[7] = {{                   x, y - ROUND ( 40*sizeY)}, {x + ROUND (40*sizeX), y - ROUND ( 10*sizeY)},
                     {x + ROUND (60*sizeX), y + ROUND (120*sizeY)}, {x + ROUND (60*sizeX), y + ROUND (170*sizeY)},
                     {x - ROUND (60*sizeX), y + ROUND (170*sizeY)}, {x - ROUND (60*sizeX), y + ROUND (120*sizeY)},
                     {x - ROUND (40*sizeX), y - ROUND ( 10*sizeY)}};
    txPolygon (mill, 7);
    }

void Millblades_draw (int x0, int y0, int x, int y)
    {
    txSetColor (RGB (109, 91, 82), 25);
    txLine     (x0, y0, x, y);
    }

void Tree_draw (int x, int y, int n, double sizeX, double sizeY)
    {
    txSetFillColor (RGB (128, 64, 0));
    POINT trunk[3] = {{x, y}, {x - ROUND (20*sizeX), y + ROUND (200*sizeY)},
                              {x + ROUND (20*sizeX), y + ROUND (200*sizeY)}};
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

void Butterfly_draw (int x, int y, COLORREF color, int bigness)
    {
    int x0 = x;
    int y0 = y;
    txSetColor (TX_DARKGRAY);
    txLine (x0, y0, x0 + 30/bigness, y0 - 40/bigness);
    txLine (x0, y0, x0 + 50/bigness, y0 -  5/bigness);
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
    POINT wingL[3] = {{x0 - 15/bigness, y0 + 25/bigness},
                      {x0 + 30/bigness, y0 + 25/bigness},
                      {x0 - 15/bigness, y0 + 75/bigness}};
    txPolygon (wingL, 3);

    POINT wingR[3] = {{x0 - 25/bigness, y0 + 15/bigness},
                      {x0 - 25/bigness, y0 - 35/bigness},
                      {x0 - 75/bigness, y0 + 15/bigness}};
    txPolygon (wingR, 3);
    }

void MountainsLandscape()
    {
    txSetColor      (RGB (255, 240, 245));
    txSetFillColor  (RGB (255, 240, 245));

    POINT lavandsky[4] = {{0, 550}, {0, 0}, {1150, 0}, {1150, 550}};
    txPolygon (lavandsky, 4);

    //---------------------------------------------------------------------------------------------------------

    txSetColor      (RGB (238, 130, 238));
    txSetFillColor  (RGB (216, 191, 216));

    POINT pinkfirst[3] = {{730, 35}, {860, 160}, {1010, 220}};
    txPolygon (pinkfirst, 3);

    POINT pinksecond[3] = {{633, 11}, {725, 155}, {965, 255}};
    txPolygon (pinksecond, 3);

    POINT pinkback[3] = {{510, 320}, {0, 280}, {0, 40}};
    txPolygon (pinkback, 3);

    //----------------------------------------------------------------------------------------------------------

    txSetColor     (RGB (221, 160, 221));
    txSetFillColor (RGB (221, 160, 221));

    POINT lilacfirst[4] = {{370, 340}, {630, 10}, {750, 155}, {985, 260}};
    txPolygon (lilacfirst, 4);

    POINT lilacsecond[4] = {{1150, 480}, {1100, 470}, {970, 260}, {1120, 60}};
    txPolygon (lilacsecond, 4);

    POINT lilacthird[6] = {{690, 50}, {730, 30}, {860, 160}, {950, 190}, {1110, 200}, {960, 260}};
    txPolygon (lilacthird, 6);

    POINT lilacfourth[7] = {{560, 140}, {270, 320}, {370, 400}, {510, 340}, {660, 410}, {740, 340}, {650, 280}};
    txPolygon (lilacfourth, 7);

    POINT lilacfifth[5] = {{320, 300}, {80, 170}, {0,260}, {0, 470}, {320, 300}};
    txPolygon (lilacfifth, 5);

    POINT lilacsixth[7] = {{860, 250}, {640, 410}, {800, 470}, {970, 420}, {1150, 480}, {980, 400}, {860, 250}};
    txPolygon (lilacsixth, 7);

    //---------------------------------------------------------------------

    txSetColor      (RGB (238, 130, 238));
    txSetFillColor  (RGB (216, 191, 216));
    POINT pinkthird[4] = {{560, 130}, {660, 280}, {730, 352}, {825, 285}};
    txPolygon (pinkthird, 4);
    POINT pinkfourth[4] = {{860, 250}, {970, 260}, {1105, 470}, {970, 400}};
    txPolygon (pinkfourth, 4);

    //--------------------------------------------------------------------

    txSetColor      (RGB (124, 252, 0));
    txSetFillColor  (RGB (124, 252, 0));

    POINT greenhills[9] = {{  0, 420}, {200, 270}, { 300, 420}, { 510, 340},
                           {700, 510}, {970, 410}, {1150, 550}, {1150, 580}, {0, 500}};
    txPolygon (greenhills, 9);

    txSetColor      (RGB (152, 251, 152), 3);
    txSetFillColor  (RGB (152, 251, 152));

    POINT sungreenfirst[3] = {{200, 270}, {300, 420}, {375, 390}};
    txPolygon (sungreenfirst, 3);

    POINT sungreensecond[3] = {{510, 340}, {700, 510}, {807, 468}};
    txPolygon (sungreensecond, 3);

    POINT sungreenthird[3] = {{970, 410}, {1150, 480}, {1150, 550}};
    txPolygon (sungreenthird, 3);

    //--------------------------------------------------------------------

    txSetColor      (RGB (0, 255, 252), 3);
    txSetFillColor  (RGB (0, 255, 252));

    POINT river[4] = {{0, 800}, {0, 500}, {1150, 570},{1150, 800}};
    txPolygon (river, 4);

   //---------------------------------------------------------------------

    txSetColor      (RGB (50, 255, 50), 3);
    txSetFillColor  (RGB (50, 255, 50));
    POINT riverbank[4] = {{0, 900}, {0, 800}, {1150, 800},{1150, 900}};
    txPolygon (riverbank, 4);
    }

void SavanahLandscape()
    {
    txSetColor     (RGB (0, 102, 102));
    txSetFillColor (RGB (0, 102, 102));

    POINT savanahsky[4]= {{0,0}, {1100, 0}, {1100, 900}, {0, 900}};
    txPolygon (savanahsky, 4);

    txSetColor     (RGB (255, 155, 0));
    txSetFillColor (RGB (255, 155, 0));
    txCircle       (550, 200, 200);

    txSetColor     (RGB (102, 0, 51));
    txSetFillColor (RGB (102, 0, 51));

    POINT mountainfirst[3] = {{640, 210}, {440, 500}, {850, 500}};
    txPolygon (mountainfirst, 3);

    POINT mountainfirstline[4] = {{0, 500}, {1100, 500}, {1100, 550}, {0, 550}};
    txPolygon (mountainfirstline, 4);

    txSetColor     (RGB (153, 102, 0));
    txSetFillColor (RGB (153, 102, 0));

    POINT mountainsecond[3] = {{500, 250}, {310, 570}, {650, 570}};
     txPolygon (mountainsecond, 3);

    POINT mountainsecondline[4] = {{0, 550}, {1100, 550}, {1100, 620}, {0, 620}};
    txPolygon (mountainsecondline, 4);

    txSetColor     (RGB (204, 102, 51));
    txSetFillColor (RGB (204, 102, 51));

    POINT mountainthird[3] = {{630, 320}, {460, 620}, {820, 620}};
    txPolygon (mountainthird, 3);

    POINT mountainthirdline[4] = {{0, 620}, {1100, 620}, {1100, 670}, {0, 670}};
    txPolygon (mountainthirdline, 4);

    txSetColor     (RGB (204, 153, 51));
    txSetFillColor (RGB (204, 153, 51));

    POINT mountainfouth[3] = {{500, 400}, {350, 670}, {650, 670}};
    txPolygon (mountainfouth, 3);

    POINT mountainfouthline[4] = {{0, 670}, {1100, 670}, {1100, 720}, {0, 720}};
    txPolygon (mountainfouthline, 4);

    txSetColor     (RGB (204, 153, 102));
    txSetFillColor (RGB (204, 153, 102));

    POINT mountainfifth[3] = {{610, 420}, {480, 670}, {780, 670}};
    txPolygon (mountainfifth, 3);

    POINT mountainfifthline[4]= {{0, 670}, {1100, 670}, {1100, 900}, {0, 900}};
    txPolygon (mountainfifthline, 4);
    }

void Cactus_draw  (int x, int y, double sizeX, double sizeY)
    {
    txSetColor (RGB (102, 51, 51), 40/sizeY);

    txLine (           x,       y - 190/sizeY, x,            y + 170/sizeY);
    txLine (x - 50/sizeX,                   y, x + 60/sizeX,             y);
    txLine (x - 50/sizeX,                   y, x - 60/sizeX, y -  95/sizeY);
    txLine (x + 60/sizeX,                   y, x + 70/sizeX, y -  90/sizeY);
    txLine (           x,       y + 100/sizeY, x - 60/sizeX, y + 100/sizeY);
    txLine (x - 60/sizeX,       y + 100/sizeY, x - 50/sizeX, y +  50/sizeY);
    }

void Chuck_draw  (int x, int y, double sizeX, double sizeY, int eyebrows, int hear)
    {
    txSetColor     (RGB(255, 255, 51));
    txSetFillColor (RGB(255, 255, 51));

    POINT bird[14]= {{x, y}, {x - ROUND (15*sizeX), y + ROUND (30*sizeY)}, {x - ROUND (105*sizeX), y + ROUND (160*sizeY)},
                     {x - ROUND ( 90*sizeX), y + ROUND (190*sizeY)}, {x - ROUND ( 45*sizeX), y + ROUND (200*sizeY)},
                     {x - ROUND (  5*sizeX), y + ROUND (220*sizeY)}, {x + ROUND ( 45*sizeX), y + ROUND (215*sizeY)},
                     {x + ROUND ( 90*sizeX), y + ROUND (200*sizeY)}, {x + ROUND (125*sizeX), y + ROUND (190*sizeY)},
                     {x + ROUND (145*sizeX), y + ROUND (170*sizeY)}, {x + ROUND (155*sizeX), y + ROUND (140*sizeY)},
                     {x + ROUND ( 95*sizeX), y + ROUND ( 70*sizeY)}, {x + ROUND ( 45*sizeX), y + ROUND ( 35*sizeY)},
                     {x + ROUND ( 15*sizeX), y + ROUND ( 10*sizeY)}};
    txPolygon (bird, 14);

    txSetColor     (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txCircle (x - 30*sizeX, y + 112*sizeY, 22*sizeX);
    txCircle (x + 75*sizeX, y + 112*sizeY, 22*sizeX);

    txSetFillColor (TX_BLACK);
    txCircle (x - 25*sizeX, y + 112*sizeY, 12*sizeX);
    txCircle (x + 80*sizeX, y + 112*sizeY, 12*sizeX);

    txSetColor(RGB (153, 51, 0), 7);
    txLine    (x + 15*sizeX, y + 100*sizeY, x -  75*sizeX, y + (70 - eyebrows)*sizeY);
    txLine    (x + 45*sizeX, y + 100*sizeY, x + 130*sizeX, y + (50 - eyebrows)*sizeY);

    txSetColor(TX_BLACK, 3);
    txLine (x + 15*sizeX, y + 10*sizeY, x -  (75 + hear/2)*sizeX, y - (30 - hear)*sizeY);
    txLine (x + 15*sizeX, y + 10*sizeY, x -  (85 + hear/2)*sizeX, y - (10 - hear)*sizeY);
    txLine (x + 15*sizeX, y + 10*sizeY, x - (115 + hear/2)*sizeX, y + (20 - hear)*sizeY);

    txLine (x - 85*sizeX, y + 130*sizeY, x - 115*sizeX, y +  90*sizeY);
    txLine (x - 85*sizeX, y + 130*sizeY, x - 125*sizeX, y + 110*sizeY);
    txLine (x - 85*sizeX, y + 130*sizeY, x - 130*sizeX, y + 130*sizeY);

    txSetColor     (RGB (153, 102, 0), 2);
    txSetFillColor (RGB (204, 153, 0));

    POINT beakUp[4] = {{                    x, y + ROUND (145*sizeY)}, {x + ROUND (45*sizeX), y + ROUND (135*sizeY)},
                       {x + ROUND (140*sizeX), y + ROUND (155*sizeY)}, {x + ROUND (35*sizeX), y + ROUND (115*sizeY)}};
    txPolygon (beakUp, 4);

    POINT beakDown[3] = {{                  x, y + ROUND (145*sizeY)}, {x + ROUND (45*sizeX), y + ROUND (135*sizeY)},
                         {x + ROUND(97*sizeX), y + ROUND (150*sizeY)}};
    txPolygon (beakDown, 3);
    }


void Cloud_draw (int x, int y, double sizeX, double sizeY, COLORREF cloudColor)
    {
     txSetColor     (cloudColor);
     txSetFillColor (cloudColor);
     txEllipse (            x,            y, x + 210*sizeX, y +  80*sizeY);
     txEllipse (x - 100*sizeX, y + 30*sizeY, x + 120*sizeX, y + 100*sizeY);
     txEllipse (x + 100*sizeX, y + 30*sizeY, x + 340*sizeX, y +  90*sizeY);
    }

void Water_lily_draw  (int  x, int  y, double sizeX, double sizeY)
    {
    txSetColor     (RGB (50, 205, 50));
    txSetFillColor (RGB (50, 205, 50));

    txEllipse (x, y, x + 340*sizeX, y + 60*sizeY);

    txSetColor     (RGB (237, 255, 33));
    txSetFillColor (RGB (237, 255, 33));

    txLine (x + 200*sizeX, y - 20*sizeY, x + 200*sizeX, y - 160*sizeY);
    txLine (x + 230*sizeX, y - 20*sizeY, x + 230*sizeX, y - 170*sizeY);

    txSetColor     (RGB (202, 55, 103));
    txSetFillColor (RGB (202, 55, 103));

    POINT petalmiddle [3] = {{x + ROUND (180*sizeX), y + ROUND (10*sizeY)},
                             {x + ROUND (210*sizeX), y - ROUND (80*sizeY)},
                             {x + ROUND (240*sizeX), y + ROUND (10*sizeY)}};
    txPolygon (petalmiddle, 3);
    }

void Title_draw (int x, int y)
    {
    txSetColor   (RGB (255, 215, 0));
    txSelectFont ("Comic Sans MS", 200);
    txTextOut    (x, y, "CHUCK`S");

    txSetColor   (RGB (255, 215, 0));
    txSelectFont ("Comic Sans MS", 200);
    txTextOut    (x, 300, "JOURNEY");
    }

void SpringFonBegining()
    {
    txSetColor     (RGB (204, 255, 255));
    txSetFillColor (RGB (204, 255, 255));

    POINT sky[6] = {{0, 450}, {0, 350}, {600, 350}, {750, 350}, {1100, 350}, {1100, 430}};
    txPolygon (sky, 6);

    for (int gradSky = 1; gradSky < 200; gradSky++)
        {
        txSetColor     (RGB (204 - 2*gradSky, 255, 255));
        txSetFillColor (RGB (204 - 2*gradSky, 255, 255));

        POINT heaven[4] = {{   0, 350 - 4*gradSky}, {   0, 360 - 4*gradSky},
                           {1100, 360 - 4*gradSky}, {1100, 350 - 4*gradSky}};
        txPolygon (heaven, 4);
        }

    txSetColor     (RGB (51, 204, 51));
    txSetFillColor (RGB (51, 204, 51));

    POINT hillbegin[4] = {{0, 400}, {0, 900}, {1100, 900}, {1100, 400}};
    txPolygon (hillbegin, 4);
    }

void Grass_draw (int x, int y, COLORREF color, double sizeX, double sizeY)
    {
    txSetColor     (color);
    txSetFillColor (color);
    POINT grass[15] = {{                    x, y}, {x - ROUND ( 70*sizeX), y - ROUND ( 30*sizeY)},
                       {x + ROUND ( 20*sizeX), y}, {x - ROUND ( 10*sizeX), y - ROUND ( 30*sizeY)},
                       {x + ROUND ( 40*sizeX), y}, {x + ROUND ( 20*sizeX), y - ROUND (100*sizeY)},
                       {x + ROUND ( 60*sizeX), y}, {x + ROUND ( 60*sizeX), y - ROUND ( 60*sizeY)},
                       {x + ROUND ( 80*sizeX), y}, {x + ROUND (110*sizeX), y - ROUND (100*sizeY)},
                       {x + ROUND ( 90*sizeX), y}, {x + ROUND (130*sizeX), y - ROUND ( 60*sizeY)},
                       {x + ROUND (110*sizeX), y}, {x + ROUND (130*sizeX), y - ROUND ( 20*sizeY)},
                       {x + ROUND (120*sizeX), y}};
    txPolygon (grass, 15);
    }

void Skateboard_draw   (int x, int y, double sizeX, double sizeY)
    {
    txSetColor     (RGB (35, 144, 120), 5);
    txSetFillColor (RGB (139, 131, 120));
    txEllipse (x, y, x + 340*sizeX, y + 20*sizeY);
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

    POINT girlsGown[4] = {{x - ROUND (30*sizeX), y}, {x + ROUND(30*sizeX), y},
                          {x + ROUND (70*sizeX), y + ROUND(120*sizeY)},
                          {x - ROUND (80*sizeX), y + ROUND(120*sizeY)}};
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
    txEllipse      (x - 50*sizeX, y - 70*sizeY, x + 50*sizeX, y);

    txSetColor     (TX_BLACK, 1);
    txSetFillColor (TX_WHITE);
    txLine  (x - 17*sizeX, y - 55*sizeY, x - 37*sizeX, y - (55 - eyebrows_UP)*sizeY);
    txLine  (x + 17*sizeX, y - 55*sizeY, x + 37*sizeX, y - (55 - eyebrows_UP)*sizeY);
    txCircle       (x - 27*sizeX, y - 40*sizeY, (10 -  eyesCRAZYleft)*sizeX);
    txCircle       (x + 27*sizeX, y - 40*sizeY, (10 - eyesCRAZYright)*sizeX);

    txSetColor     (TX_BLUE);
    txSetFillColor (TX_BLUE);
    txCircle       (x - 27*sizeX, y - 40*sizeY, (5 -  eyesPUPILleft)*sizeX);
    txCircle       (x + 27*sizeX, y - 40*sizeY, (5 - eyesPUPILright)*sizeX);

    txSetColor(HairColor, 5);
    txLine (           x,  y - 70*sizeY,            x,     y - 58*sizeY);
    txLine (x -  5*sizeX,  y - 68*sizeY, x -  5*sizeX,     y - 60*sizeY);
    txLine (x - 10*sizeX,  y - 66*sizeY, x - 10*sizeX,     y - 62*sizeY);
    txLine (x +  5*sizeX,  y - 68*sizeY, x +  5*sizeX,     y - 60*sizeY);
    txLine (x + 10*sizeX,  y - 66*sizeY, x + 10*sizeX,     y - 62*sizeY);

    txSetColor     (RGB (207, 58, 96));
    txSetFillColor (RGB (207, 58, 96));
    POINT girlsMouth[4] = {{x - ROUND (22*sizeX), y - ROUND ( 20*sizeY)},
                           {x - ROUND ( 7*sizeX), y - ROUND ((20 - mouthTOPpoint)*sizeY)},
                           {x + ROUND (22*sizeX), y - ROUND ( 20*sizeY)},
                           {                   x, y - ROUND ((10 - mouthLOWERpoint)*sizeY)}};
    txPolygon (girlsMouth, 4);
    }

void FinishTitles (int x, int y)
    {
    txSetColor    (RGB (255, 192, 203));
    txSelectFont  ("Monotype Corsiva", 180);
    txTextOut     (x, y, "THE END");
    }

void WorkisDone  (int x, int y)
    {
    txSetColor   (RGB (255, 215, 0));
    txSelectFont ("Comic Sans MS", 60);
    txTextOut    ( x, y, "Работу выполнила");
    txTextOut    ( x, y + 100, "учитель информатики");
    txTextOut    ( x, y + 200, "Абрамова И.В.");
    txTextOut    ( x, y + 300, "гимназия 36, Краснодар");
    }

void MouseBody_draw (int x, int y, double width, double height, COLORREF bodyColor, COLORREF earsColor)
   {
    txSetColor     (bodyColor);
    txSetFillColor (bodyColor);

    POINT body[3] = {{x, y}, {x + ROUND (90*width), y - ROUND (100*height)}, {x + ROUND (110*height), y + ROUND (20*height)}};
    txPolygon (body, 3);

    POINT head[3] = {{x + ROUND ( 40*width), y - ROUND (100*height)},
                     {x + ROUND (100*width), y - ROUND (140*height)},
                     {x + ROUND (140*width), y - ROUND ( 50*height)}};
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

void CatBody_draw (int x, int y, double width, double height, double eyebrows, COLORREF catColor, COLORREF cat_breastColor)
    {
    txSetColor     (TX_DARKGRAY, 3);
    txSetFillColor (catColor);

    txRectangle (x + 50*width, y + 120*height, x + 110*width, y + 100*height);

    POINT cat_body[4] = {{x, y}, {x + ROUND (40*width), y},
                        {x + ROUND (60*width), y + ROUND (120*height)},
                        {x - ROUND (30*width), y + ROUND (120*height)}};
    txPolygon (cat_body, 4);

    POINT cats_earL[3] = {{x, y}, {x - ROUND (45*width), y - ROUND (75*height)},
                                  {x + ROUND (25*width), y - ROUND (45*height)}};
    POINT cats_earR[3] = {{x + ROUND (25*width), y - ROUND (45*height)},
                          {x + ROUND (85*width), y - ROUND (75*height)}, {x + ROUND (40*width), y}};
    txPolygon (cats_earL, 3);
    txPolygon (cats_earR, 3);

    txSetFillColor (cat_breastColor);
    txEllipse (x - 10*width, y - 20*height, x + 50*width, y + 100*height);

    txSetFillColor (catColor);
    txCircle   (x + 20*width, y - 30*height, 40*width);

    txSetColor (TX_BLACK, 6);
    txCircle   (           x, y - 30*height, 5*width);
    txCircle   (x + 40*width, y - 30*height, 5*width);

    txSetColor (TX_BLACK);
    txLine (x + 10*width, y - 15*height, x - 45*width, y - 20*height);
    txLine (x + 10*width, y - 15*height, x - 45*width, y - 10*height);
    txLine (x + 30*width, y - 15*height, x + 85*width, y - 20*height);
    txLine (x + 30*width, y - 15*height, x + 85*width, y - 10*height);
    txLine (x + 22*width, y - 12*height, x + 22*width, y -  5*height);

    txSetColor (TX_BLACK,3);
    txLine (x +  10*width, y - 45*height, x - 20*width, y - (45 + eyebrows)*height);
    txLine (x +  30*width, y - 45*height, x + 60*width, y - (45 + eyebrows)*height);

    txSetFillColor (TX_LIGHTRED);
    txEllipse (x + 15*width, y - 20*height, x + 30*width, y - 14*height);
    }
void Skate_wheels_drawer (int x0, int y0,  int r)
    {
    txSetColor     (RGB ( 96, 123, 139), 15);
    txSetFillColor (TX_WHITE);
    txCircle(x0, y0, r);
    txCircle(x0 + 170, y0, r);
    }

void BigDipper_draw ( int x, int y, int r)
    {
    txSetColor     (RGB (176, 196, 222));
    txSetFillColor (RGB ((252 + rand()%255), (252 + rand()%255), (252 + rand()%255)));
    txCircle (x, y, r);
    txCircle (x +  70, y -  70, r/2);
    txCircle (x + 110, y +  30, r/2);
    txCircle (x +  50, y + 110, r/2);
    txCircle (x -  30, y +  30, r/2);
    txCircle (x - 160, y +  50, r/2);
    txCircle (x - 240, y + 110,   r);
    }
