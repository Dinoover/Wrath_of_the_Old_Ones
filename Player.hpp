
//  Player.hpp

#ifndef Player_hpp
#define Player_hpp

#include "Card.hpp"

class Player
{
private:
    std::string p_name;//le nom
    int p_HP;//les pv en jeu
    int p_Money;// de l'argent pour le magasin
    std::vector <Card*> p_collection;//la collection du joueur
    std::vector<Card*> p_deck;// la deck du joueur
    
public:
    Player();
    Player(std::string name, std::vector<Card*> Cards);
    ~Player();
    
    //getteurs
    int Get_p_HP();
    int Get_p_Money();
    std::string Get_p_name();
    //pareille que dans la classe carte, pour recuperer les valeurs d'atribues, on pourras utiliser ces getteurs + les getteurs de la carte
    std::vector <Card*> Get_p_collection();
    std::vector <Card*> Get_p_deck();
    //setteurs basiques
    void Set_p_HP(int var);
    void Set_p_Money(int var);
    void Set_p_name(std::string var);
    //setteurs d'une carte dans la deck du joueur
    void Set_deck_card(std::vector<Card*> cards_table, int number );
    
    //quand on quite le jeu on sauvegade la collection et l'argent de player
    void Save_player();
  

    
    
};

#endif /* Player_hpp */
