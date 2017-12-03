//
//  Player.hpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 03.12.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Card.hpp"

class Player
{
private:
    std::string p_name;
    int p_HP;
    int p_Money;
    std::vector <Card*> p_collection;
    std::map<Card*, Variant_Parametrs> p_deck;
    
public:
    Player(std::string name, std::vector<Card*> Cards);
    ~Player();
    
    void Save_player();
    
    
    
};

#endif /* Player_hpp */
