//
//  Card.cpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 14.11.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#include "Card.hpp"

bool Card:: Get_hand_status()
{
    return m_hand;
}

bool Card:: Get_invoke_status()
{
    return m_invoked;
}

bool Card:: Get_live_status()
{
    return m_alive;
}

void Card:: Set_hand_status(bool set)
{
    m_hand=set;
}

void Card:: Set_invoke_status(bool set)
{
    m_invoked=set;
}

void Card:: Set_live_status(bool set)
{
    m_alive=set;
}
