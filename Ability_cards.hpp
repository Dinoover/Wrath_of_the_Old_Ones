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

class Ability
{
private:
    int Ability_number;
    std::string Ability_description;
public:
    Ability();
    ~Ability();
    
    virtual void Use_ability();

};

//Cartes avec alilites differentes

class Fire_Ability: public Ability
{
private:
public:
   void Use_ability(Card* card_to_destroy);
};

class Sacrifice_abilit: public Ability
{
private:
    
public:
    void Use_ability(Card* card_to_destroy, Card* card_to_get);
};

#endif /* Ability_cards_hpp */
