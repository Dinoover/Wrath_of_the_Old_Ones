//
//  Play_ground.cpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 04.12.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#include "Play_ground.hpp"


Playground:: Playground()
{
    
}
Playground:: Playground (Player * player_1, Player* player_2)
{
    P1= player_1;
    P2= player_2;
    
    R1=new Ressource(0,0,0,0);
    R2=new Ressource(0,0,0,0);
    
    In_game_creature_1=NULL;
    In_game_creature_2=NULL;
    
    In_game_ability_1=NULL;
    In_game_ability_2=NULL;

}

Playground:: ~Playground()
{
    
}
Ressource* Playground::Get_R1()
{
    return R1;
}
Ressource* Playground::Get_R2()
{
    return R2;
}
Card* Playground::Get_In_game_creature_1()
{
    return In_game_creature_1;
}
Card* Playground::Get_In_game_creature_2()
{
    return In_game_creature_2;
}
Card* Playground:: Get_In_game_ability_1()
{
    return In_game_ability_1;
}
Card* Playground:: Get_In_game_ability_2()
{
    return In_game_ability_2;
}
Player* Playground:: Get_Player_1()
{
    return P1;
}
Player* Playground:: Get_Player_2()
{
    return P2;
}

std::vector <Card*> Playground:: Get_ressource_cards_1()
{
    return  m_ressource_cards_1;
}

std::vector <Card*> Playground:: Get_ressource_cards_2()
{
    return  m_ressource_cards_2;
}

std::vector <Card*> Playground:: Get_grave_1()
{
    return Graveyard_1;
}
std::vector <Card*> Playground:: Get_grave_2()
{
    return Graveyard_2;
}

void Playground:: Send_card_to_grave(int player_number, int card_number)
{
    int i;//en fonction du joueur
    if (player_number==1)
    {    //on parcours la deck
        for(i=0;i<(P1->Get_p_deck()).size();i++)
        {   //on trouve la carte a tuer
            if((P1->Get_p_deck())[i]->Get_s_parameter().Get_card_number()==card_number)
            {
                //on pointe cette carte avec cemetiere
                Graveyard_1.push_back(new Card ());
                Graveyard_1[Graveyard_1.size()-1]=(P1->Get_p_deck())[i];
                //on rends les caracterestiques de la carte a "non vivant"
                Graveyard_1[Graveyard_1.size()-1]->Set_variant_parameters()->Set_live_status(false);
                Graveyard_1[Graveyard_1.size()-1]->Set_variant_parameters()->Set_invoke_status(false);
                Graveyard_1[Graveyard_1.size()-1]->Set_variant_parameters()->Set_deck_status(false);
                
            }
        }
        
    }
    else if(player_number==2)
    {
        //ici pareille que en haut
        for(i=0;i<(P2->Get_p_deck()).size();i++)
        {
            if((P2->Get_p_deck())[i]->Get_s_parameter().Get_card_number()==card_number)
            {
                Graveyard_2.push_back(new Card ());
                Graveyard_2[Graveyard_2.size()-1]=(P2->Get_p_deck())[i];
                Graveyard_2[Graveyard_2.size()-1]->Set_variant_parameters()->Set_live_status(false);
                Graveyard_2[Graveyard_2.size()-1]->Set_variant_parameters()->Set_invoke_status(false);
                Graveyard_2[Graveyard_2.size()-1]->Set_variant_parameters()->Set_deck_status(false);
                
            }
        }
    }
    
}


void Playground:: add_ressource_card(int cards_number_in_deck, int player_number)
{
    if(player_number==1)
    {
        m_ressource_cards_1.push_back(P1->Get_p_deck()[cards_number_in_deck]);
        m_ressource_cards_1[m_ressource_cards_1.size()-1]->Set_variant_parameters()->Set_invoke_status(true);
        
        
    }
    else if(player_number==2)
    {
        m_ressource_cards_2.push_back(P2->Get_p_deck()[cards_number_in_deck]);
        m_ressource_cards_2[m_ressource_cards_2.size()-1]->Set_variant_parameters()->Set_invoke_status(true);
    }
    
}

void Playground:: Update_player_ressource(int player_number)
{
    int i;//en fonction du joueur
    R1->Set_blood(0);
    R1->Set_gold(0);
    R1->Set_power(0);
    R1->Set_influence(0);
    
    R2->Set_blood(0);
    R2->Set_gold(0);
    R2->Set_power(0);
    R2->Set_influence(0);
    if (player_number==1)
    {
        for (i=0;i<P1->Get_p_deck().size();i++)
        {
            if (((P1->Get_p_deck())[i]->Get_s_parameter().Get_card_type()==1) && ((P1->Get_p_deck())[i]->Get_v_parameters().Get_invoke_status()==true ))
           {
               R1->Set_blood(R1->Get_blood()+(P1->Get_p_deck())[i]->Get_ressource().Get_blood());
               R1->Set_gold(R1->Get_gold()+(P1->Get_p_deck())[i]->Get_ressource().Get_gold());
               R1->Set_power(R1->Get_power()+(P1->Get_p_deck())[i]->Get_ressource().Get_power());
               R1->Set_influence(R1->Get_influence()+(P1->Get_p_deck())[i]->Get_ressource().Get_influence());
               
           }
        }
        
    }
    else if(player_number==2)
    {
        for (i=0;i<P2->Get_p_deck().size();i++)
        {
            if ((P2->Get_p_deck())[i]->Get_s_parameter().Get_card_type()==1 && ((P2->Get_p_deck())[i]->Get_v_parameters().Get_invoke_status()==true ))
            {
                R2->Set_blood(R2->Get_blood()+(P2->Get_p_deck())[i]->Get_ressource().Get_blood());
                R2->Set_gold(R2->Get_gold()+(P2->Get_p_deck())[i]->Get_ressource().Get_gold());
                R2->Set_power(R2->Get_power()+(P2->Get_p_deck())[i]->Get_ressource().Get_power());
                R2->Set_influence(R2->Get_influence()+(P2->Get_p_deck())[i]->Get_ressource().Get_influence());
                
            }
        }

    }
}

/*void Playground:: Fin_de_tour()
{
    
}*/
