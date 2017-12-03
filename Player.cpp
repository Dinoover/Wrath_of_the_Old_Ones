//
//  Player.cpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 03.12.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#include "Player.hpp"

Player:: Player (std::string name, std::vector<Card*> Cards)
{
    p_Money=0;
    int i,j;
    int cards_number(0);
    int card;
    std::ifstream file (name+".txt");
    if(file.is_open())
    {
        file>>p_Money;
        file>>cards_number;
        for(i=0;i<cards_number;i++)
        {
            file>>card;
            for(j=0; j<Cards.size(); j++)
            {
                if (Cards[j]->Get_s_parameter().Get_card_number()==card)
                {
                    p_collection.push_back(Cards[j]);
                    
                }
                
            }
            
        }
        
        
        file.close();
    }
    else
    {
        std::ofstream new_file(name+".txt");
        if(new_file.is_open())
        {
            new_file<<p_Money;
            new_file<<std::endl;
            new_file<<Cards.size();
            new_file<<std::endl;
            for(i=0; i<Cards.size();i++)
            {
                new_file<<Cards[i]->Get_s_parameter().Get_card_number();
                p_collection.push_back(Cards[i]);
                new_file<<std::endl;
            }
            
            new_file.close();
            
            
        }
        else
        {
            std::cout<<"ERROR file opening is incorrect";
        }
    }
}

Player:: ~Player()
{
    
}
void Player:: Save_player()
{
    int i;
    std::ofstream new_file(p_name+".txt");
    if(new_file.is_open())
    {
        new_file<<p_Money;
        new_file<<std::endl;
        new_file<<p_collection.size();
        for(i=0; i<p_collection.size();i++)
        {
            new_file<<p_collection[i]->Get_s_parameter().Get_card_number();
            p_collection.push_back(p_collection[i]);
            new_file<<std::endl;
        }
        
        new_file.close();
        
        
    }
    else
    {
        std::cout<<"ERROR file opening is incorrect";
    }
}

int Player:: Get_p_HP()
{
    return p_HP;
}
int Player:: Get_p_Money()
{
    return p_Money;
}
std::string Player:: Get_p_name()
{
    return p_name;
}
std::vector <Card*> Player:: Get_p_collection()
{
    return p_collection;
}
std::vector <Card*> Player:: Get_p_deck()
{
    return p_deck;
}

void Player:: Set_p_HP(int var)
{
    p_HP=var;
}
void Player:: Set_p_Money(int var)
{
    p_Money=var;
}
void Player:: Set_p_name(std::string var)
{
    p_name=var;
}
void Player:: Set_deck_card(std::vector<Card*> cards_table, int number )
{
    p_deck.push_back(new Card());
    *(p_deck.end())=(cards_table[number]);
}
