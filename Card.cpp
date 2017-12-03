//
//  Card.cpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 14.11.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#include "Card.hpp"

Card::Card()
{
    
}
Card:: Card(std::ifstream  &file)
{
    int blood(0);
    int gold(0);
    int power(0);
    int influence(0);
    int damage(0);
    int HP(0);
    int force(0);
    std::string stroka;
    int card_type, card_number;

    
    file>>card_type;
    
    if(file.is_open())
    {
        if(card_type==2)
        {
            file>>card_number;
            file>>blood;
            file>>gold>>power>>influence;
            file>>blood>>gold>>power>>influence>>damage>>stroka;
            
      
            m_ressources=NULL;
           
            m_s_parametrs= new Static_Parameters(blood,gold,power,influence,damage,stroka,card_type,card_number);
            
              file>>blood>>gold>>power>>influence>>damage>>stroka;
            
             m_sp_at_parameter=new Sp_at_par (blood,gold,power,damage,influence,stroka);
            
            file>>force>>HP;
            
            m_v_parametres=new Variant_Parametrs(force, HP);
            file.ignore(1,'\n');
            
            
        }
        if(card_type==1)
        {
            file>>card_number;
            file>>blood>>gold>>power>>influence;
            m_ressources= new Ressource (blood, gold, power, influence);
            file>>stroka;
            blood=gold=power=influence=damage=0;
            m_s_parametrs=new Static_Parameters (blood,gold,power,influence,damage,stroka,card_type,card_number);
            m_sp_at_parameter=NULL;
            m_v_parametres=NULL;
            file.ignore(1,'\n');
        }
        if (card_type==3)
        {
            file>>card_number;
            m_ressources=NULL;
            m_sp_at_parameter=NULL;
            file>>blood>>gold>>power>>influence;
            damage=0;
            file>>stroka;
            m_s_parametrs=new Static_Parameters (blood,gold,power,influence,damage,stroka,card_type,card_number);
             file.ignore(1,'\n');
            
        }
    }
    else
    {
        std::cout<<"ERROR"<<std::endl;
    }
    
        
    
}
Card::~Card ()
{/*
    if(m_ressources!=NULL)
    delete m_ressources;
    
    if(m_v_parametres!=NULL)
    delete m_v_parametres;
    
    if(m_s_parametrs!=NULL)
    delete m_s_parametrs;
    
    if( m_sp_at_parameter!=NULL)
    delete m_sp_at_parameter;*/
}

/*
int Card:: Get_ressource(int var)
{
    
    if(var==1)
               return this->m_ressources->Get_blood();
    else if(var==2)
               return this->m_ressources->Get_gold();
    else if(var==3)
               return this->m_ressources->Get_power();
    else if (var==4)
               return this->m_ressources->Get_influence();
    else
    {
        return 0;
    }
    
}*/
/*int Card:: Get_s_parameter(int var)
{
    
        if (var==1)
                return this->m_s_parametrs->Get_blood_coast();
        else if (var==2)
                return this->m_s_parametrs->Get_gold_coast();
        else if (var==3)
                return this->m_s_parametrs->Get_power_coast();
        else if (var==4)
                return this->m_s_parametrs->Get_influence_coast();
        else if (var==5)
                return this->m_s_parametrs->Get_damage_value();
        else if (var==6)
                return this->m_s_parametrs->Get_card_type();
        else if (var==7)
                return this->m_s_parametrs->Get_card_number();
    else
    {
         return 0;
    }
    
}*/

Ressource Card:: Get_ressource()
{
    return *m_ressources;
}

Static_Parameters Card:: Get_s_parameter()
{
    return * m_s_parametrs;
    
}

Sp_at_par Card:: Get_sp_at_parameters()
{
    return * m_sp_at_parameter;
}
Variant_Parametrs Card:: Get_v_parameters()
{
    return *m_v_parametres;
}


Ressource* Card:: Set_ressource()
{
    return m_ressources;
}
Static_Parameters* Card:: Set_static_parameters()
{
    return m_s_parametrs;
}
Sp_at_par* Card:: Set_sp_at_parameters()
{
    return m_sp_at_parameter;
}
Variant_Parametrs* Card:: Set_variant_parameters()
{
    return m_v_parametres;
}


