
//  Card_Old_Gods_game


#ifndef Sub_classes_hpp
#define Sub_classes_hpp

#include <iostream>

//#include "Card.hpp"

class Ressource
{
protected:
    int m_blood;
    int m_gold;
    int m_power;
    int m_influence;
public:
    Ressource();
    
    Ressource (int blood, int gold, int power, int influence);
    
    ~Ressource();
    
    int Get_blood();
    int Get_gold();
    int Get_power();
    int Get_influence();
    
    void Set_blood(int var);
    void Set_gold(int var);
    void Set_power(int var);
    void Set_influence(int influence);
};

class Static_Parameters
{
protected:
    int m_blood_coast;
    int m_gold_coast;
    int m_power_coast;
    int m_influence_coast;
    int m_damage_value;
    
    std::string m_card_name;
    int card_type;//1-terra, 2-perso, 3-special
    int card_unique_number;
    
    //image de la carte A AJOUTER
    
public:
    Static_Parameters();
    Static_Parameters(int  blood, int  gold, int  power,int influence, int  damage, std::string name, int type, int number);
    ~Static_Parameters();
    
    int Get_damage_value();
    int Get_card_number();
    int Get_blood_coast();
    int Get_gold_coast();
    int Get_power_coast();
    int Get_influence_coast();
    std::string Get_card_name();
    int Get_card_type();
    void Set_damage_value(int var);
    void Set_card_number(int var);
    
    //pas besoin de setters et getters car ce sont les partametres statiques
    
};

class Sp_at_par
{
protected:
    std::string m_special_at_name;
    int m_blood_at_coast;
    int m_gold_at_coast;
    int m_power_at_coast;
    int m_influence_at_coast;
    int m_damage_value;
public:
    Sp_at_par();
    
    Sp_at_par (int blood, int gold, int power, int damage, int influence, std::string name);
    
    ~Sp_at_par();
    
    int Get_blood_at_coast();
    int Get_gold_at_coast();
    int Get_power_at_coast();
    int Get_influence_at_coast();
    
    void Set_blood_at_coast(int var);
    void Set_gold_at_coast(int var);
    void Set_power_at_coast(int var);
    void Set_influence_at_coast(int var);
    
};

class Variant_Parametrs
{
protected:
    int m_force;
    int m_HP;
    bool m_deck;
    bool m_invoked;
    bool m_alive;
  
public:
    Variant_Parametrs();
    Variant_Parametrs(int  m_force, int m_HP);
    ~Variant_Parametrs();
    
    int Get_force();
    int Get_HP();
    int Get_card_deck_number();
    
    void Set_force(int force);
    void Set_HP(int HP);
    void Set_card_deck_number(int number);
    
    bool Get_deck_status();
    bool Get_invoke_status();
    bool Get_live_status();
    
    void Set_deck_status (bool var);
    void Set_invoke_status (bool var);
    void Set_live_status (bool var);
    
};

#endif /* Sub_classes_hpp */
