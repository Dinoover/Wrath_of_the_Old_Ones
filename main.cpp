
///  Wrath_of_the_Old_Ones_Card_Game ///


#include "Play.hpp"
#include "allegro.h"
#include "allegro_init.hpp"


int main(int argc, char * argv[])
{
    srand(time(NULL));

    allegro_initialisation();

    BITMAP* files[29];
    bitmap_load(files);

    BITMAP* buffer;
    buffer = create_bitmap(800,600);

    int choise = 0;

    std::vector<Card*> cards_table;
    int cards_n(0);
    std::string line;
    std::ifstream myfile ("Cards.txt");
    if (myfile.is_open())
    {
        myfile>>cards_n;
        for(int i=0;i<cards_n;i++)
        {
            cards_table.push_back(new Card (myfile));
            //std::cout<< cards_table[i]->Get_s_parameter().Get_card_type()<<cards_table[i]->Get_NAME();
        }

        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
        return 1;
    }

    Player Yugi("Yugikek", cards_table);
    Player Kaiba("kaiba",cards_table);
    Player Kebab("kebab", cards_table);



    while(choise!=1)
    {
        clear_bitmap(buffer);

        blit(files[25], buffer, 0,0,0,0,800,600);

        draw_sprite(buffer, files[26], 150, 120);

        draw_sprite(buffer, files[28], 150,320);

        draw_sprite(buffer, files[24], mouse_x, mouse_y);

        blit(buffer, screen,0,0,0,0,800,600);

        if(mouse_b==1 && mouse_x > 315 && mouse_x < 485 && mouse_y > 310 && mouse_y < 360)
        {
            choise=1;
        }

        if(mouse_b==1 && mouse_x > 245 && mouse_x < 555 && mouse_y > 370 && mouse_y < 460)
        {
            Kebab.Booster(Kebab.Get_p_deck());
        }

        if(mouse_b==1 && mouse_x > 245 && mouse_x < 555 && mouse_y > 470 && mouse_y < 520)
        {
            return 0;
        }
    }

    Jeu(files, buffer, Yugi, Kaiba);

    for(unsigned int i=0;i<cards_table.size();i++)
    {
        delete cards_table[i];
    }

    bitmap_destroy(files);

    return 0;
}
END_OF_MAIN();
