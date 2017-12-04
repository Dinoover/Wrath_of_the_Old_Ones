
//  Player.cpp


#include "Player.hpp"
//constructeur de player


Player:: Player()
{
    
}
Player:: Player (std::string name, std::vector<Card*> Cards)
{
    p_tour=false; 
    p_HP=10;
    p_Money=0;//initialement pour un nouveua player on donne 0 argent
    int i,j;
    int cards_number(0);//combien il y de cartes dans la collection
    int card;//numero de la carte qu'on recupere
   //d'abbord on essay d'ouvrir un ficher avec le nom du joueur en mode lecture
    std::ifstream file (name+".txt");
    if(file.is_open())// si le fichier existe, alors on va le lire
    {
        file>>p_Money;// premier valeur lue- l'argent
        file>>cards_number;// second valeur- nombre des cartes dans la collection
        for(i=0;i<cards_number;i++)
        {
            file>>card;// le numero de la carte
            for(j=0; j<Cards.size(); j++)
            {
                if (Cards[j]->Get_s_parameter().Get_card_number()==card)// on cherche la carte avec ce numero dans la collection generale et ajoute le dand la collection du joueur
                {
                    p_collection.push_back(Cards[j]);
                    
                }
                /*else
                {
                    std::cout<<"Reading error"<<std::endl;
                }*/
                
            }
            
        }
        
        
        file.close();
    }
    else//si e file n'existe pas (le joueur est nouveau)
    {
        //on cree le file et l'ouvre en mode ecriture
        std::ofstream new_file(name+".txt");
        if(new_file.is_open())
        {
            //on est genereux et on recopie toute la collection existante dans le file du joueur et dans ca collection a lui
            new_file<<p_Money;
            new_file<<std::endl;
            new_file<<Cards.size();
            new_file<<std::endl;
            for(i=0; i<Cards.size();i++)
            {
                new_file<<Cards[i]->Get_s_parameter().Get_card_number();
                p_collection.push_back(Cards[i]);
                new_file<<std::endl;
            }
            
            new_file.close();
            
            
        }
        else
        {
            std::cout<<"ERROR file opening is incorrect";
        }
    }
}

Player:: ~Player()
{
    
}

//on sauvegarde la collection et les donnees du joueur
void Player:: Save_player()
{
    int i;
    //on ouvre son file (ca efface son contenu) et on retape toutes les infos necessaires recuperees de l'objet
    std::ofstream new_file(p_name+".txt");
    if(new_file.is_open())
    {
        new_file<<p_Money;
        new_file<<std::endl;
        new_file<<p_collection.size();
        for(i=0; i<p_collection.size();i++)
        {
            new_file<<p_collection[i]->Get_s_parameter().Get_card_number();
            p_collection.push_back(p_collection[i]);
            new_file<<std::endl;
        }
        
        new_file.close();
        
        
    }
    else
    {
        std::cout<<"ERROR file opening is incorrect";
    }
}
//les getteurs et les setteurs
bool Player:: Get_tour()
{
    return p_tour;
}
int Player:: Get_p_HP()
{
    return p_HP;
}
int Player:: Get_p_Money()
{
    return p_Money;
}
std::string Player:: Get_p_name()
{
    return p_name;
}
std::vector <Card*> Player:: Get_p_collection()
{
    return p_collection;
}
std::vector <Card*> Player:: Get_p_deck()
{
    return p_deck;
}

void Player:: Set_tour(bool var)
{
    p_tour=var;
}
void Player:: Set_p_HP(int var)
{
    p_HP=var;
}
void Player:: Set_p_Money(int var)
{
    p_Money=var;
}
void Player:: Set_p_name(std::string var)
{
    p_name=var;
}
//le setteur pour le deck, on prends la collection generale et le numero de la carte a ajouter dans notre deck
void Player:: Set_deck_card(int number)//(std::vector<Card*> cards_table, int number )
{
    Card* carta;
    // on cree une carte vide dans le deck et on recopie le contenu de la carte souhaite dans cette carte vide
    p_deck.push_back(new Card());
    carta=new Card ();
     *carta=* p_collection[number];
    *(p_deck[Get_p_deck().size()-1])=(*carta);
    delete carta;
}

void Player:: Mix_deck()
{
    int i;
    int a(0),b(0);
    for (i=0;i<30;i++)
    {
        a=0;
        b=0;
        
            a=rand()%(p_deck.size()-1);
            b=rand()%(p_deck.size()-1);
        
      
        std::swap(*p_deck[a], *p_deck[b]);
    }
    
}

