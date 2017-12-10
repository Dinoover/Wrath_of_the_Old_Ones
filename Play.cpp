
#include <string>
#include <vector>
#include "Play.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "Play_ground.hpp"
#include "allegro_init.hpp"


void Jeu(BITMAP* files[29], BITMAP* buffer, Player Yugi, Player Kaiba)
{
    int turn=0;
    //int x,y;
    int card=0;
    int choosen_card=0;


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

    /// CREATION DECK ///
    for(unsigned int i=1; i<=Yugi.Get_p_collection().size();i++)
    {
            do
        {
            clear_bitmap(buffer);

            textprintf_ex(buffer,font,500,50,makecol(255,255,255),-1,"Player 1 : Create deck");
            textprintf_ex(buffer,font,500,70,makecol(255,255,255),-1,"Key Y -> Yes / Key N -> Next card");

            blit(files[i],buffer,0,0,20,20,800,600);

            blit(buffer,screen,0,0,0,0,800,600);

            if(key[KEY_Y])
            {
                Yugi.Set_deck_card(i-1);
                //std::cout << (Yugi.Get_p_deck())[i-1]->Get_s_parameter().Get_card_name();
            }
            rest(100);

        }while((!key[KEY_N]));
    }
    for(unsigned int i=1; i<=Kaiba.Get_p_collection().size();i++)
    {
        do
        {
            clear_bitmap(buffer);

            textprintf_ex(buffer,font,500,50,makecol(255,255,255),-1,"Player 2 : Create deck");
            textprintf_ex(buffer,font,500,70,makecol(255,255,255),-1,"Key Y -> Yes / Key N -> Next card");

            blit(files[i],buffer,0,0,20,20,800,600);

            blit(buffer,screen,0,0,0,0,800,600);

            if(key[KEY_Y])
            {
                Kaiba.Set_deck_card(i-1);
                //std::cout << (Yugi.Get_p_deck())[i-1]->Get_s_parameter().Get_card_name();
            }
            rest(100);

        }while(!key[KEY_N]);
    }

    ///Melange decks
    Yugi.Mix_deck();
    Kaiba.Mix_deck();

    Playground plateau(&Yugi, &Kaiba);

    ///BOUCLE DE JEU PRINCIPALE

    while(!key[KEY_ESC])
    {
        clear_bitmap(buffer);

        blit(files[27], buffer,0,0,0,0,800,600);

        textprintf_ex(buffer, font, 20, 20, makecol(255,255,255),-1,"PLAYER 2   %d HP", Kaiba.Get_p_HP());

        textprintf_ex(buffer, font, 20, 580, makecol(255,255,255),-1,"PLAYER 1   %d HP", Yugi.Get_p_HP());


        ///INTERACTION PLATEAU

        if(mouse_b&1 && mouse_x > 770 && mouse_y > 570 && mouse_x < 800 && mouse_y < 600)
        {
            if(turn==0)
            {
                for(unsigned int i=0; i<Yugi.Get_p_deck().size();i++)
                {
                    if(Yugi.Get_p_deck()[i]->Get_v_parameters().Get_deck_status()==true && Yugi.Get_p_deck()[i]->Get_v_parameters().Get_invoke_status()==false)
                    {
                        choosen_card=i;
                        i=100;
                    }
                }
            }
            if(turn==1)
            {
                for(unsigned int i=0; i<Kaiba.Get_p_deck().size();i++)
                {
                    if(Kaiba.Get_p_deck()[i]->Get_v_parameters().Get_deck_status()==true && Kaiba.Get_p_deck()[i]->Get_v_parameters().Get_invoke_status()==false)
                    {
                        choosen_card=i;
                        i=100;
                    }
                }
            }
            turn++;

            if(turn==2)
            turn=0;

            card=0;
        }

        if(turn==0) //J1
        textprintf_ex(buffer,font,10,300,makecol(255,255,255),-1,"turn : Player 1");
        if(turn==1) //J2
        textprintf_ex(buffer,font,10,300,makecol(255,255,255),-1,"turn : Player 2");

        //Deck J1
        if(mouse_b&1 && mouse_x > 280 && mouse_x < 320 && mouse_y > 440 && mouse_y < 500 && turn==0)
        {
            card=(Yugi.Get_p_deck())[choosen_card]->Get_s_parameter().Get_card_number();
        }
        //Deck J2
        if(mouse_b&1 && mouse_x > 80 && mouse_x < 120 && mouse_y > 100 && mouse_y < 160 && turn==1)
        {
            card=(Kaiba.Get_p_deck())[choosen_card]->Get_s_parameter().Get_card_number();
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
            card=plateau.Get_In_game_creature_1()->Get_s_parameter().Get_card_number();
        }
        //Monstre J2
        if(mouse_b&1 && mouse_x > 180 && mouse_x < 220 && mouse_y > 170 && mouse_y < 230)
        {
            card=plateau.Get_In_game_creature_2()->Get_s_parameter().Get_card_number();
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

        //Combat creature
        if(mouse_b&1 && mouse_x > 200 && mouse_y > 540 && mouse_x < 250 && mouse_y <590) //attaque
        {
            if(turn==0)
                plateau.creature_battle(1,2);
            if(turn==0)
                plateau.creature_battle(2,1);
        }


        if(mouse_b&1 && mouse_x >350 && mouse_y>540 && mouse_x<400 && mouse_y< 590) //invocke
        {
            if(turn==0)
            plateau.Set_ingame_card(1,choosen_card);

            if(turn==1)
            plateau.Set_ingame_card(2,choosen_card);
        }
        if(mouse_b&1 && mouse_x >200 && mouse_y > 540 && mouse_x <250 && mouse_y <590) //discard
        {
            if(turn==1)
            {

            }
            if(turn==2)
            {

            }
        }

        //afficher carte
        blit(files[card],buffer,0,0,400,40,800,600);

        rect(buffer,770,570,800,600,makecol(0,0,255));
        rect(buffer,350,540,400,590,makecol(0,255,0));
        rect(buffer,200,540,250,590,makecol(255,0,0));

        plateau.Update_player_ressource(1);
        plateau.Update_player_ressource(2);

        textprintf_ex(buffer,font,420,560,makecol(255,255,255),-1,"PLAYER 1:");
        textprintf_ex(buffer,font,620,560,makecol(255,255,255),-1,"PLAYER 2:");
        textprintf_ex(buffer,font,500,560,makecol(255,255,255),-1,"%d",plateau.Get_R1()->Get_blood());
        textprintf_ex(buffer,font,500,570,makecol(255,255,255),-1,"%d",plateau.Get_R1()->Get_gold());
        textprintf_ex(buffer,font,500,580,makecol(255,255,255),-1,"%d",plateau.Get_R1()->Get_power());
        textprintf_ex(buffer,font,500,590,makecol(255,255,255),-1,"%d",plateau.Get_R1()->Get_influence());
        textprintf_ex(buffer,font,700,560,makecol(255,255,255),-1,"%d",plateau.Get_R2()->Get_blood());
        textprintf_ex(buffer,font,700,570,makecol(255,255,255),-1,"%d",plateau.Get_R2()->Get_gold());
        textprintf_ex(buffer,font,700,580,makecol(255,255,255),-1,"%d",plateau.Get_R2()->Get_power());
        textprintf_ex(buffer,font,700,590,makecol(255,255,255),-1,"%d",plateau.Get_R2()->Get_influence());

        //cursor
        draw_sprite(buffer, files[24], mouse_x, mouse_y);

        //affichage
        blit(buffer, screen,0,0,0,0,800,600);

        rest(100);
    }
}
