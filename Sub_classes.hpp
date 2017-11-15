//  Card_Old_Gods_game


#ifndef Sub_classes_hpp
#define Sub_classes_hpp

#include <iostream>
#include "Card.hpp"

class Ressource
{
protected:
    int* m_blood;
    int* m_gold;
    int* m_power;
public:
    Ressource();
    
    Ressource (int blood, int gold, int power);
    
    ~Ressource();
    
    int Get_blood();
    int Get_gold();
    int Get_power();
    
    void Set_blood();
    void Set_gold();
    void Set_power();
};

class Static_Parameters
{
protected:
    int* m_blood_coast;
    int* m_gold_coast;
    int* m_power_coast;
    int m_damage_value;
    std::string m_card_name;
    int card_type;
    //image de la carte A AJOUTER
    
public:
    
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
    
};

#endif /* Sub_classes_hpp */
