
//  Sub_classes.cpp


#include "Sub_classes.hpp"

Ressource:: Ressource()
{
    
}

Ressource:: Ressource (int blood, int gold, int power, int influence)
{
    m_blood=blood;
    m_gold=gold;
    m_power=power;
    m_influence=influence;
    
}

Ressource:: ~Ressource()
{
    
}
//getters
 int Ressource:: Get_blood()
{
    return m_blood;
}
 int Ressource:: Get_gold()
{
    return  m_gold;
}
int Ressource:: Get_power()
{
    return m_power;
}
int Ressource::Get_influence()
{
    return m_influence;
}

//setters
void Ressource:: Set_blood(int var)
{
    m_blood=var;
}
void Ressource:: Set_gold(int var)
{
    m_gold=var;
}
void Ressource:: Set_power(int var)
{
    m_power=var;
}

void Ressource::Set_influence(int influence)
{
    m_influence=influence;
}





//Static_par

Static_Parameters:: Static_Parameters()
{
    
}
Static_Parameters:: Static_Parameters(int  blood, int  gold, int power,int influence, int  damage, std::string name, int type, int number)
{
    m_blood_coast=blood;
    m_gold_coast=gold;
    m_power_coast=power;
    m_influence_coast=influence;
    m_damage_value=damage;
    m_card_name=name;
    card_type=type;// 1- pour les cartes ressource, 2 pour les creatures et 3 pour les cartes abilitees
    card_unique_number=number;
    
}
Static_Parameters:: ~Static_Parameters()
{
    
}
//getters
int Static_Parameters:: Get_damage_value()
{
      return m_damage_value;
}
int Static_Parameters:: Get_card_number()
{
    return card_unique_number;
}

int Static_Parameters:: Get_blood_coast()
{
    return m_blood_coast;
}
int Static_Parameters:: Get_gold_coast()
{
    return m_gold_coast;
}
int Static_Parameters:: Get_power_coast()
{
    return m_power_coast;
}
int Static_Parameters:: Get_influence_coast()
{
    return m_influence_coast;
}

std::string Static_Parameters:: Get_card_name()
{
    return m_card_name;
}

 int Static_Parameters:: Get_card_type()
{
    return card_type;
}


//setters, on va avoir besoin de set manuelement que ces deux parametres, les autres sont invarient
void Static_Parameters:: Set_damage_value(int var)
{
    m_damage_value=var;
}
void Static_Parameters:: Set_card_number(int var)
{
    card_unique_number=var;
}


//Attaque Supplementaire

Sp_at_par:: Sp_at_par()
{
    
}

Sp_at_par:: Sp_at_par (int blood, int gold, int power, int damage, int influence, std::string name)
{
    m_blood_at_coast=blood;
    m_gold_at_coast=gold;
    m_power_at_coast=power;
    m_damage_value=damage;
    m_influence_at_coast=influence;
     m_special_at_name=name;
}

Sp_at_par:: ~Sp_at_par()
{

}
//getters
int Sp_at_par:: Get_blood_at_coast()
{
    return m_blood_at_coast;
}
int Sp_at_par:: Get_gold_at_coast()
{
    return m_gold_at_coast;
}
int Sp_at_par:: Get_power_at_coast()
{
    return m_power_at_coast;
}
int Sp_at_par:: Get_influence_at_coast()
{
    return m_influence_at_coast;
}

//setters
void Sp_at_par:: Set_blood_at_coast(int var)
{
    m_blood_at_coast=var;
}
void Sp_at_par:: Set_gold_at_coast(int var)
{
    m_gold_at_coast=var;
}
void Sp_at_par:: Set_power_at_coast(int var)
{
    m_power_at_coast=var;
}
void Sp_at_par:: Set_influence_at_coast(int var)
{
    m_influence_at_coast=var;
}



//Variant Parameters
Variant_Parametrs:: Variant_Parametrs()
{
    m_HP=1;
    m_force=1;
    m_deck=true;
    m_alive=true;
    m_invoked=false;
}
Variant_Parametrs:: Variant_Parametrs(int force, int HP)
{   if (force!=0 && HP!=0)
    {
    m_force=force;
    m_HP=HP;
    }
    else
    {
        m_HP=0;
        m_force=0;
    }
    m_deck=true;
    m_alive=true;
    m_invoked=false;
    
    
}
Variant_Parametrs:: ~Variant_Parametrs()
{
    
}

//getters
int Variant_Parametrs:: Get_force()
{
    return m_force;
}
int Variant_Parametrs:: Get_HP()
{
    return m_HP;
}

int Variant_Parametrs:: Get_card_deck_number()
{
    return m_card_deck_number;
}

bool Variant_Parametrs:: Get_deck_status()
{
    return m_deck;
}

bool Variant_Parametrs:: Get_invoke_status()
{
    return m_invoked;
}

bool Variant_Parametrs:: Get_live_status()
{
    return m_alive;
}

//setters
void Variant_Parametrs:: Set_deck_status(bool set)
{
    m_deck=set;
}

void Variant_Parametrs:: Set_invoke_status(bool set)
{
    m_invoked=set;
}

void Variant_Parametrs:: Set_live_status(bool set)
{
    m_alive=set;
}

void Variant_Parametrs:: Set_card_deck_number(int number)
{
    m_card_deck_number=number;
}

void Variant_Parametrs:: Set_force(int force)
{
    m_force=force;
}
void Variant_Parametrs:: Set_HP(int HP)
{
    m_HP=HP;
}




