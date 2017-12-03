
#include <string>
#include <vector>
#include "Play.hpp"
#include <iostream>
#include <fstream>


void Jeu(BITMAP* files[29], BITMAP* buffer, Player Yugi, Player Kaiba)
{
    /*
    std::vector<std::string> nom;
    int select_j=0;
    int ok=0;
    int in;

    while(select_j!=2)
    {
        clear_bitmap(buffer);

        blit(files[25], buffer, 0,0,0,0,800,600);

        rectfill(buffer,20,20,780,580,makecol(0,0,0));
        rectfill(buffer,30,30,770,570,makecol(255,255,255));

        textprintf_ex(buffer,font,50,50,makecol(0,0,0),-1,"Lovecraft");

        textprintf_ex(buffer,font,50,100,makecol(0,0,0),-1,"Yu-gi-oh");

        rect(buffer,600,500,675,575,makecol(255,0,0));
        if(mouse_b&1 && mouse_x>600 && mouse_x<675 && mouse_y>500 && mouse_y <575)
            ok=1;

        if(mouse_b&1 && mouse_x>40 && mouse_x<100 && mouse_y>40 && mouse_y <55)
        {select_j++;allegro_message(" select");}

        if(mouse_b&1 && mouse_x>40 && mouse_x<100 && mouse_y>95 && mouse_y <110)
        {select_j++;allegro_message("j select");}

        ///NEW PLAYER
        rect(buffer,200,500,300,575,makecol(0,255,0));
        if(mouse_b&1 && mouse_x>200 && mouse_x<300 && mouse_y>500 && mouse_y < 575)
        {
            while(!key[KEY_ENTER])
            {
                in = readkey();

                if((in & 0xff) == 'a')
                    nom.push_back("a");
                if((in & 0xff) == 'b')
                    nom.push_back("b");
                if((in & 0xff) == 'c')
                    nom.push_back("c");
                if((in & 0xff) == 'd')
                    nom.push_back("d");
                if((in & 0xff) == 'e')
                    nom.push_back("e");
                if((in & 0xff) == 'f')
                    nom.push_back("f");
                if((in & 0xff) == 'g')
                    nom.push_back("g");
                if((in & 0xff) == 'h')
                    nom.push_back("h");
                if((in & 0xff) == 'i')
                    nom.push_back("i");
                if((in & 0xff) == 'j')
                    nom.push_back("j");
                if((in & 0xff) == 'k')
                    nom.push_back("k");
                if((in & 0xff) == 'l')
                    nom.push_back("l");
                if((in & 0xff) == 'm')
                    nom.push_back("m");
                if((in & 0xff) == 'n')
                    nom.push_back("n");
                if((in & 0xff) == 'o')
                    nom.push_back("o");
                if((in & 0xff) == 'p')
                    nom.push_back("p");
                if((in & 0xff) == 'q')
                    nom.push_back("q");
                if((in & 0xff) == 'r')
                    nom.push_back("r");
                if((in & 0xff) == 's')
                    nom.push_back("s");
                if((in & 0xff) == 't')
                    nom.push_back("t");
                if((in & 0xff) == 'u')
                    nom.push_back("u");
                if((in & 0xff) == 'v')
                    nom.push_back("v");
                if((in & 0xff) == 'w')
                    nom.push_back("w");
                if((in & 0xff) == 'x')
                    nom.push_back("x");
                if((in & 0xff) == 'y')
                    nom.push_back("y");
                if((in & 0xff) == 'z')
                    nom.push_back("z");

                rest(50);
            }
        }



        draw_sprite(buffer, files[24], mouse_x, mouse_y);

        blit(buffer, screen,0,0,0,0,800,600);

        rest(20);
    }
*/



    while(!key[KEY_ESC])
    {
        clear_bitmap(buffer);

        blit(files[27], buffer,0,0,0,0,800,600);

        draw_sprite(buffer, files[24], mouse_x, mouse_y);

        //textprintf_ex(screen,font,20,20,makecol(255,255,255),-1,"%d      %d",mouse_x,mouse_y);

        textprintf_ex(buffer, font, 20, 20, makecol(255,255,255),-1,"PLAYER 2   %d HP", Kaiba.Get_p_HP());

        textprintf_ex(buffer, font, 20, 580, makecol(255,255,255),-1,"PLAYER 1   %d HP", Yugi.Get_p_HP());


        ///INTERACTION PLATEAU

        //Deck J1
        if(mouse_b&1 && mouse_x > 280 && mouse_x < 320 && mouse_y > 440 && mouse_y < 500)
        {

        }
        //Deck J2
        if(mouse_b&1 && mouse_x > 80 && mouse_x < 120 && mouse_y > 100 && mouse_y < 160)
        {

        }
        //Defausse J1
        if(mouse_b&1 && mouse_x > 280 && mouse_x < 320 && mouse_y > 370 && mouse_y < 430)
        {

        }
        //Defausse J2
        if(mouse_b&1 && mouse_x > 80 && mouse_x < 120 && mouse_y > 170 && mouse_y < 230)
        {

        }
        //Enjeu J1
        if(mouse_b&1 && mouse_x >330 && mouse_x < 370 && mouse_y > 400 && mouse_y < 460)
        {

        }
        //Enjeu J2
        if(mouse_b&1 && mouse_x > 30 && mouse_x < 70 && mouse_y > 140 && mouse_y < 200)
        {

        }
        //Monstre J1
        if(mouse_b&1 && mouse_x > 180 && mouse_x < 220 && mouse_y > 370 && mouse_y < 430)
        {

        }
        //Monstre J2
        if(mouse_b&1 && mouse_x > 180 && mouse_x < 220 && mouse_y > 170 && mouse_y < 230)
        {

        }
        //Spé J1
        if(mouse_b&1 && mouse_x > 180 && mouse_x < 220 && mouse_y > 440 && mouse_y < 500)
        {

        }
        //Spé J2
        if(mouse_b&1 && mouse_x > 180 && mouse_x <220 && mouse_y > 100 && mouse_y < 160)
        {

        }
        //ressource J1
        if(mouse_b&1 && mouse_x > 30 && mouse_x < 120 && mouse_y > 370 && mouse_y < 500)
        {

        }
        //resource J2
        if(mouse_b&1 && mouse_x > 280 && mouse_x <370 && mouse_y > 100 && mouse_y < 230)
        {

        }

        blit(buffer, screen,0,0,0,0,800,600);

        rest(20);
    }
}
