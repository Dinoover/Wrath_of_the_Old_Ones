//
//  Card.hpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 14.11.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <iostream>
#include "Sub_classes.hpp"

class Card
{
private:
    bool m_hand;
    bool m_invoked;
    bool m_alive;
    
    Ressource* m_ressources;//pour les carte-terrain
    Static_Parameters m_s_parametrs;//nom, image, cout etc..
    Variant_Parametrs* m_v_parametres;//la vie, la force
    Sp_at_par * m_sp_at_parameter;//attaque speciale
    
    //Accees au tableau des energies A FAIRE
    
public:
    Card();
    ~Card();
    
    bool Get_hand_status();
    bool Get_invoke_status();
    bool Get_live_status();
    
    void Set_hand_status (bool var);
    void Set_invoke_status (bool var);
    void Set_live_status (bool var);

    
    
    
};


#endif /* Card_hpp */
