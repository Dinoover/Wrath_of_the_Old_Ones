//
//  Sub_classes.cpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 14.11.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#include "Sub_classes.hpp"

Ressource:: Ressource()
{
    
}

Ressource:: Ressource (int blood, int gold, int power, int influence)
{
    *m_blood=blood;
    *m_gold=gold;
    *m_power=power;
    *m_influence=influence;
    
}

Ressource:: ~Ressource()
{
    
}

 int Ressource:: Get_blood()
{
    return *m_blood;
}
 int Ressource:: Get_gold()
{
    return * m_gold;
}
int Ressource:: Get_power()
{
    return *m_power;
}
int Ressource::Get_influence()
{
    return *m_influence;
}


void Ressource:: Set_blood(int var)
{
    *m_blood=var;
}
void Ressource:: Set_gold(int var)
{
    *m_gold=var;
}
void Ressource:: Set_power(int var)
{
    *m_power=var;
}

void Ressource::Set_influence(int influence)
{
    *m_influence=influence;
}
