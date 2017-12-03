//
//  Card.hpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 14.11.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#ifndef Card_hpp
#include<fstream>
#include "Sub_classes.hpp"


class Card
{
private:
    bool m_deck;
    bool m_invoked;
    bool m_alive;
    
    Ressource* m_ressources;//pour les carte-terrain
    Static_Parameters* m_s_parametrs;//nom, image, cout etc..
    Variant_Parametrs* m_v_parametres;//la vie, la force
    Sp_at_par * m_sp_at_parameter;//attaque speciale
    
    //Accees au tableau des energies A FAIRE
    
public:
     Card( std::ifstream &file);
     Card();
    ~Card();
    
    bool Get_deck_status();
    bool Get_invoke_status();
    bool Get_live_status();
    int Get_card_number();
    
    void Set_deck_status (bool var);
    void Set_invoke_status (bool var);
    void Set_live_status (bool var);
    
    
    
    
    int Get_ressource(int var);
    

    int  Get_s_parameter(int var);
    
    
    std::string Get_NAME()
    {
        return this->m_s_parametrs->Get_card_name();
    }

    //virtual void Use_Ability(Card* carta);
    
    
};


#endif /* Card_hpp */
