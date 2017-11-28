//
//  Sub_classes.cpp
//  Card_Old_Gods_game
//
//  Created by Lazovchik on 14.11.17.
//  Copyright © 2017 Lazovchik. All rights reserved.
//

#include "Sub_classes.hpp"
//Ressource
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
//Static_par

Static_Parameters:: Static_Parameters()
{
    
}
Static_Parameters:: Static_Parameters(int * blood, int * gold, int * power,int* influence, int * damage, std::string name, int type, int number)
{
    *m_blood_coast=*blood;
    *m_gold_coast=*gold;
    *m_power_coast=*power;
    *m_influence_coast=*influence;
    *m_damage_value=*damage;
    m_card_name=name;
    card_type=type;
    card_unique_number=number;
    
}
Static_Parameters:: ~Static_Parameters()
{
    
}

int Static_Parameters:: Get_damage_value()
{
      return *m_damage_value;
}
int Static_Parameters:: Get_card_number()
{
    return card_unique_number;
}
void Static_Parameters:: Set_damage_value(int var)
{
    *m_damage_value=var;
}
void Static_Parameters:: Set_card_number(int var)
{
    card_unique_number=var;
}



Sp_at_par:: Sp_at_par()
{
    
}

Sp_at_par:: Sp_at_par (int blood, int gold, int power, int damage, int influence, std::string name)
{
    *m_blood_at_coast=blood;
    *m_gold_at_coast=gold;
    *m_power_at_coast=power;
    *m_damage_value=damage;
    *m_influence_at_coast=influence;
     m_special_at_name=name;
}

Sp_at_par:: ~Sp_at_par()
{

}

int Sp_at_par:: Get_blood_at_coast()
{
    return *m_blood_at_coast;
}
int Sp_at_par:: Get_gold_at_coast()
{
    return *m_gold_at_coast;
}
int Sp_at_par:: Get_power_at_coast()
{
    return *m_power_at_coast;
}
int Sp_at_par:: Get_influence_at_coast()
{
    return *m_influence_at_coast;
}


void Sp_at_par:: Set_blood_at_coast(int var)
{
    *m_blood_at_coast=var;
}
void Sp_at_par:: Set_gold_at_coast(int var)
{
    *m_gold_at_coast=var;
}
void Sp_at_par:: Set_power_at_coast(int var)
{
    *m_power_at_coast=var;
}
void Sp_at_par:: Set_influence_at_coast(int var)
{
    *m_influence_at_coast=var;
}
Variant_Parametrs:: Variant_Parametrs()
{
    
}
Variant_Parametrs:: Variant_Parametrs(int * force, int* HP)
{   if (force!=NULL && HP!=NULL)
    {
    *m_force=*force;
    *m_HP=*HP;
    }
    else
    {
        m_HP=NULL;
        m_force=NULL;
    }
    
    
    
}
Variant_Parametrs:: ~Variant_Parametrs()
{
    
}

int Variant_Parametrs:: Get_force()
{
    return *m_force;
}
int Variant_Parametrs:: Get_HP()
{
    return *m_HP;
}

void Variant_Parametrs:: Set_force(int force)
{
    *m_force=force;
}
void Variant_Parametrs:: Set_HP(int HP)
{
    *m_HP=HP;
}






