
//  Card.hpp


#ifndef Card_hpp
#include <fstream>
#include <vector>
#include <map>
#include "Sub_classes.hpp"


class Ability
{
    
private:
    int m_ability_number;//numero unique de l'abilite
    bool used;//si on utilise cette abilite ou pas
public:
    Ability();
    Ability (int number);
    ~Ability();
    //getteurs et setteurs basiques
    int Get_ab_num();
    bool Get_use_stat();
    
    void Set_ab_number(int var);
    void Set_use_stat(bool var);

    
};

class Card
{
private:
 
    Ressource* m_ressources;//pour les cartes de ressource
    Static_Parameters* m_s_parametrs;//nom, image, cout d'attaque normale etc..
    Variant_Parametrs* m_v_parametres;//la vie, la force, si la carte est dans le deck, mort ou sur le champ de bataille
    Sp_at_par * m_sp_at_parameter;//attaque supplementaire et ses parametres
    Ability * m_ability;//abilite pour les cartes de type abilite
    
public:
     Card( std::ifstream &file);
     Card();
    ~Card();
  
    
    //les getters ne sont pas void car ils vont retournes l'adress des objets pointée par les atributes et comme ca on va pouvoirutiliser les setters des ces objets
    //ex: card->Set_ressource().Set_blood();
    Ressource* Set_ressource();
    Static_Parameters* Set_static_parameters();
    Sp_at_par* Set_sp_at_parameters();
    Variant_Parametrs* Set_variant_parameters();
    Ability* Set_m_ability();
    
    
   //Pareille pour les getteurs, on va pouvoir utiliser les getteurs des objets elle-memes
    Ressource  Get_ressource();
    Static_Parameters Get_s_parameter();
    Sp_at_par Get_sp_at_parameters();
    Variant_Parametrs Get_v_parameters();
    Ability Get_m_ability();
    
    
    
    
};

#endif /* Card_hpp */
