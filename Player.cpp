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
    int i,j;
    int cards_number(0);
    int card;
    std::ifstream file (name+".txt");
    if(file.is_open())
    {
        file.ignore(2,'\n');
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
