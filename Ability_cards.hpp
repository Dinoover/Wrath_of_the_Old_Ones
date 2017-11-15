//
//  Ability_cards.hpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 15.11.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#ifndef Ability_cards_hpp
#define Ability_cards_hpp

#include "Card.hpp"

class Ability_card : public Card
{
public:
    Ability_card();
    ~Ability_card();
    
    
    virtual void Use_ability(Card* carta);
};

//Cartes avec alilites differentes

class Purify_card :public Ability_card
{
public:
    
    void Use_ability(Card* carta);
    
};

#endif /* Ability_cards_hpp */
