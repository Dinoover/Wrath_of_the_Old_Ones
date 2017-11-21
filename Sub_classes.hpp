
//  Card_Old_Gods_game


#ifndef Sub_classes_hpp
#define Sub_classes_hpp

#include <iostream>
//#include "Card.hpp"

class Ressource
{
protected:
    int* m_blood;
    int* m_gold;
    int* m_power;
    int* m_influence;
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
    int* m_blood_coast;
    int* m_gold_coast;
    int* m_power_coast;
    int* m_damage_value;
    std::string m_card_name;
    int card_type;//1-terra, 2-perso, 3-special
    unsigned long card_unique_number;
    
    //image de la carte A AJOUTER
    
public:
    Static_Parameters();
    Static_Parameters(int * blood, int * gold, int * power, int * damage, std::string name, int type);
    ~Static_Parameters();
    
    int Get_damage_value();
    void Set_damage_value(int damage);
    
    //pas besoin de setters et getters car ce sint les partametres statiques
    
};

class Sp_at_par
{
protected:
    int * m_blood_at_coast;
    int * m_gold_at_coast;
    int * m_power_at_coast;
    int m_damage_value;
public:
    Sp_at_par();
    
    Sp_at_par (int blood, int gold, int power, int damage);
    
    ~Sp_at_par();
    
    int Get_blood_at_coast();
    int Get_gold_at_coast();
    int Get_power_at_coast();
    
    void Set_blood_at_coast();
    void Set_gold_at_coast();
    void Set_power_at_coast();
    
};

class Variant_Parametrs
{
protected:
    int *m_force;
    int *m_HP;
public:
    Variant_Parametrs();
    Variant_Parametrs(int * m_force, int* m_HP);
    ~Variant_Parametrs();
    
    int Get_force();
    int Get_HP();
    
    void Set_force(int force);
    void Set_HP(int HP);
    
};

#endif /* Sub_classes_hpp */
