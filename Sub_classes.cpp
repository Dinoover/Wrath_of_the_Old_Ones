//
//  Sub_classes.cpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 14.11.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#include "Sub_classes.hpp"

Ressource::Get_blood()
{
    return *m_blood;
}

Ressource::Get_gold()
{
    return *m_gold;
}

Ressource::Get_power()
{
    return *m_power;
}

Ressource::Get_influence()
{
    return *m_influence;
}

void Ressource::Set_blood(int blood)
{
    *m_blood=blood;
}

void Ressource::Set_gold(int gold)
{
    *m_gold=gold;
}

void Ressource::Set_power(int power)
{
    *m_power=power;
}

void Ressource::Set_influence(int influence)
{
    *m_influence=influence;
}
