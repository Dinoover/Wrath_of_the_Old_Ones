//
//  Card.hpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 14.11.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#ifndef Card_hpp
#include<fstream>
#include <vector>
#include <map>
#include "Sub_classes.hpp"


class Card
{
private:
 
    Ressource* m_ressources;//pour les carte-terrain
    Static_Parameters* m_s_parametrs;//nom, image, cout etc..
    Variant_Parametrs* m_v_parametres;//la vie, la force
    Sp_at_par * m_sp_at_parameter;//attaque speciale
    
    //Accees au tableau des energies A FAIRE
    
public:
     Card( std::ifstream &file);
     Card();
    ~Card();
    //int Get_ressource(int var);
   // int  Get_s_parameter(int var);
    
    Ressource* Set_ressource();
    Static_Parameters* Set_static_parameters();
    Sp_at_par* Set_sp_at_parameters();
    Variant_Parametrs* Set_variant_parameters();
    
    Ressource  Get_ressource();
    Static_Parameters Get_s_parameter();
    Sp_at_par Get_sp_at_parameters();
    Variant_Parametrs Get_v_parameters();
    
    std::string Get_NAME()
    {
        return this->m_s_parametrs->Get_card_name();
    }

    //virtual void Use_Ability(Card* carta);
    
    
};


#endif /* Card_hpp */
