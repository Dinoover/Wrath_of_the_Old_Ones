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
//constructeur pour e plateau a 2 joueurs
Playground:: Playground (Player * player_1, Player* player_2)
{
    //on pointe les joueurs existants
    P1= player_1;
    P2= player_2;

    //leurs ressources sont initialement a 0
    R1=new Ressource(0,0,0,0);
    R2=new Ressource(0,0,0,0);

    //il n'y a pas de cartes sur le plateau
    In_game_creature_1=NULL;
    In_game_creature_2=NULL;

    In_game_ability_1=NULL;
    In_game_ability_2=NULL;

}

Playground:: ~Playground()
{

}

//getteurs
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

//pour envoyer la carte au cemetiere
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

//pour recalculer la totalite des ressources du joueur (numero 1 ou 2)
void Playground:: Update_player_ressource(int player_number)
{
    int i;
    //les ressources sont remis a 0 avant de les recalculer
    R1->Set_blood(0);
    R1->Set_gold(0);
    R1->Set_power(0);
    R1->Set_influence(0);

    R2->Set_blood(0);
    R2->Set_gold(0);
    R2->Set_power(0);
    R2->Set_influence(0);

    //en fonction du joueur
    if (player_number==1)
    {
        //on parcoure le deck et quand on trouve une carte ressource qui est posee sur le champ de bataille on ajoute ces ressources a valeurs existants
        for (i=0;i<P1->Get_p_deck().size();i++)
        {
            if (((P1->Get_p_deck())[i]->Get_s_parameter().Get_card_type()==1) && ((P1->Get_p_deck())[i]->Get_v_parameters().Get_invoke_status()==true ) &&((P1->Get_p_deck())[i]->Get_v_parameters().Get_deck_status()==false ))
           {
               R1->Set_blood(R1->Get_blood()+(P1->Get_p_deck())[i]->Get_ressource().Get_blood());
               R1->Set_gold(R1->Get_gold()+(P1->Get_p_deck())[i]->Get_ressource().Get_gold());
               R1->Set_power(R1->Get_power()+(P1->Get_p_deck())[i]->Get_ressource().Get_power());
               R1->Set_influence(R1->Get_influence()+(P1->Get_p_deck())[i]->Get_ressource().Get_influence());

           }
        }

    }
    //la meme chose
    else if(player_number==2)
    {
        for (i=0;i<P2->Get_p_deck().size();i++)
        {
            if ((P2->Get_p_deck())[i]->Get_s_parameter().Get_card_type()==1 && ((P2->Get_p_deck())[i]->Get_v_parameters().Get_invoke_status()==true )&&((P2->Get_p_deck())[i]->Get_v_parameters().Get_deck_status()==false ))
            {
                R2->Set_blood(R2->Get_blood()+(P2->Get_p_deck())[i]->Get_ressource().Get_blood());
                R2->Set_gold(R2->Get_gold()+(P2->Get_p_deck())[i]->Get_ressource().Get_gold());
                R2->Set_power(R2->Get_power()+(P2->Get_p_deck())[i]->Get_ressource().Get_power());
                R2->Set_influence(R2->Get_influence()+(P2->Get_p_deck())[i]->Get_ressource().Get_influence());

            }
        }

    }
}
//pour mettre une carte sur le plateau
void Playground:: Set_ingame_card(int player, int card_deck_number)
{
    int type(0);//le type de la carte
    //si c'est le jouer 1 ou 2
    if(player==1)
    {
        //la carte change l'information dans ces bools(elle est sur le champ et elle "n'est plus" dans le deck)
        (P1->Get_p_deck())[card_deck_number]->Set_variant_parameters()->Set_invoke_status(true);
        (P1->Get_p_deck())[card_deck_number]->Set_variant_parameters()->Set_deck_status(false);

        type= P1->Get_p_deck()[card_deck_number]->Get_s_parameter().Get_card_type();

        if(type==1)//on ajoute le pointeur sur une carte ressource dans notre vecteur
        {
            m_ressource_cards_1.push_back(P1->Get_p_deck()[card_deck_number]);
        }
        if (type==2)//on pointe la carte necessaire
        {
            In_game_creature_1=P1->Get_p_deck()[card_deck_number];

        }
        if (type==3)//pareille
        {
            In_game_ability_1=P1->Get_p_deck()[card_deck_number];
        }


    }
    //meme chose
    else if (player==2)
    {
        (P2->Get_p_deck())[card_deck_number]->Set_variant_parameters()->Set_invoke_status(true);
        (P2->Get_p_deck())[card_deck_number]->Set_variant_parameters()->Set_deck_status(false);

        type= P2->Get_p_deck()[card_deck_number]->Get_s_parameter().Get_card_type();

        if(type==1)
        {
            m_ressource_cards_2.push_back(P2->Get_p_deck()[card_deck_number]);
        }
        if (type==2)
        {
            In_game_creature_2=P2->Get_p_deck()[card_deck_number];

        }
        if (type==3)
        {
            In_game_ability_2=P2->Get_p_deck()[card_deck_number];
        }

    }



}

//pour effectuer le combat
void Playground:: creature_battle (int attacker, int defender)//on met le joueur attaquant et le jouer qui est attaque
{
    //si le jouer 1 attaque et l'inverse
    if (attacker==1 && defender==2)
    {
        //si on a la carte sur le plateau on peut attaquer
        if(In_game_creature_1!=NULL)
        {
             //si l'adversaire a une carte sur le plateau on attaque la carte
            if (In_game_creature_2!=NULL)
            {
                //deminution des pv de la carte aversaire
                In_game_creature_2->Set_variant_parameters()->Set_HP(In_game_creature_2->Get_v_parameters().Get_HP()-In_game_creature_1->Get_s_parameter().Get_damage_value());
                if(In_game_creature_2->Get_v_parameters().Get_HP()<=0)//si elle set more on l'envoie sur la cemetiere et on change toutes ses statuts
                {
                    Graveyard_2.push_back(new Card ());
                    Graveyard_2[Graveyard_2.size()-1]=In_game_creature_2;
                    Graveyard_2[Graveyard_2.size()-1]->Set_variant_parameters()->Set_live_status(false);
                    Graveyard_2[Graveyard_2.size()-1]->Set_variant_parameters()->Set_invoke_status(false);
                    Graveyard_2[Graveyard_2.size()-1]->Set_variant_parameters()->Set_deck_status(false);
                    In_game_creature_2=NULL;
                }
            }
            else
            {//si l'adveraire n'as pas de carte on attaque l'adversaire
                P2->Set_p_HP(P2->Get_p_HP()-In_game_creature_1->Get_s_parameter().Get_damage_value());
            }
        }

    }
    //pareille
    else if (attacker==2 && defender==1)
    {
        if(In_game_creature_2!=NULL)
        {
            if (In_game_creature_2!=NULL)
            {
                In_game_creature_1->Set_variant_parameters()->Set_HP(In_game_creature_1->Get_v_parameters().Get_HP()-In_game_creature_2->Get_s_parameter().Get_damage_value());
                if(In_game_creature_1->Get_v_parameters().Get_HP()<=0)
                {
                    Graveyard_1.push_back(new Card ());
                    Graveyard_1[Graveyard_1.size()-1]=In_game_creature_1;
                    Graveyard_1[Graveyard_1.size()-1]->Set_variant_parameters()->Set_live_status(false);
                    Graveyard_1[Graveyard_1.size()-1]->Set_variant_parameters()->Set_invoke_status(false);
                    Graveyard_1[Graveyard_1.size()-1]->Set_variant_parameters()->Set_deck_status(false);
                    In_game_creature_1=NULL;
                }
            }
            else
            {
                P1->Set_p_HP(P1->Get_p_HP()-In_game_creature_2->Get_s_parameter().Get_damage_value());
            }
        }

    }
}
