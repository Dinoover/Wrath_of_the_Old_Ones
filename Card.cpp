
//  Card.cpp


#include "Card.hpp"

Card::Card()
{
    
}
Card:: Card(std::ifstream  &file)
{
    //les variables pour recuperer les donnees de fichier
    int blood(0);
    int gold(0);
    int power(0);
    int influence(0);
    int damage(0);
    int ab_number(0);//le numero de l'abilite
    int HP(0);
    int force(0);
    std::string stroka;// pour recuperes les noms des cartes
    int card_type, card_number;

    
    file>>card_type;
    
    if(file.is_open())
    {
        //si la carte est creature
        if(card_type==2)
        {
            m_ressources=NULL;//cette carte de produit pas de resssource
            m_ability=NULL;//cette carte n'as pas d'abilitees
            
            //on recupere les donnees dans l'ordre prevu
            file>>card_number;
            file>>blood>>gold>>power>>influence;
            file>>blood>>gold>>power>>influence>>damage>>stroka;
            //on remplie les parametres statiques de la carte
            m_s_parametrs= new Static_Parameters(blood,gold,power,influence,damage,stroka,card_type,card_number);
            
            file>>blood>>gold>>power>>influence>>damage>>stroka;
            //on remplie les parametres de l'attaque supplementaire
            m_sp_at_parameter=new Sp_at_par (blood,gold,power,damage,influence,stroka);
            
            file>>force>>HP;
            //on remplie et initialise les parametres variants
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
            m_v_parametres=new Variant_Parametrs();
            m_ability=NULL;
            file.ignore(1,'\n');
        }
        if (card_type==3)
        {
            file>>card_number;
            m_ressources=NULL;
            m_sp_at_parameter=NULL;
            file>>blood>>gold>>power>>influence>>ab_number;
            damage=0;
            file>>stroka;
            m_s_parametrs=new Static_Parameters (blood,gold,power,influence,damage,stroka,card_type,card_number);
            //apres en fonction de numero de l'abilite on va utiliser un certain sous-programme pour immiter ces effets
            m_ability= new Ability(ab_number);
            m_v_parametres=new Variant_Parametrs();
             file.ignore(1,'\n');
            
        }
    }
    else
    {
        std::cout<<"ERROR"<<std::endl;
    }
    
        
    
}
Card::~Card ()
{
   
}

//les getteurs et les setteurs, fonctionnent comme decrit dans le hpp
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
Ability Card:: Get_m_ability()
{
    return *m_ability;
}


//setters

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
Ability* Card:: Set_m_ability()
{
    return m_ability;
}




//ability

Ability:: Ability()
{
    
}
Ability:: Ability (int number)
{
    m_ability_number=number;
}
Ability:: ~Ability ()
{
    
}
//getters et setters
int Ability:: Get_ab_num()
{
    return m_ability_number;
}
bool Ability:: Get_use_stat()
{
    return used;
}

void Ability:: Set_ab_number(int var)
{
    m_ability_number=var;
}
void Ability:: Set_use_stat(bool var)
{
    used=var;
}

