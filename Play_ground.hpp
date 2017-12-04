
//  Play_ground.hpp

#ifndef Play_ground_hpp
#define Play_ground_hpp

#include "Player.hpp"

class Playground
{
private:
    
    Player* P1;
    Player* P2;
    Ressource* R1;
    Ressource* R2;
    
    Card* In_game_creature_1;
    Card* In_game_creature_2;
    Card* In_game_ability_1;
    Card* In_game_ability_2;
    
    std::vector <Card*> Graveyard_1;
    std::vector <Card*> Graveyard_2;

    std::vector <Card*> m_ressource_cards_1;
    std::vector <Card*> m_ressource_cards_2;
 
    
public:
    Playground();
    Playground(Player * player_1, Player* player_2);
    ~Playground();
    Ressource *Get_R1();
    Ressource *Get_R2();
    Card *Get_In_game_creature_1();
    Card *Get_In_game_creature_2();
    Card *Get_In_game_ability_1();
    Card *Get_In_game_ability_2();
    Player *Get_Player_1();
    Player *Get_Player_2();

    std::vector <Card*> Get_ressource_cards_1();
    std::vector <Card*> Get_ressource_cards_2();
    std::vector <Card*> Get_grave_1();
    std::vector <Card*> Get_grave_2();
    
    void Send_card_to_grave(int player_number, int card_number);
    
    void Update_player_ressource(int player_number);
    
    void Set_ingame_card(int player, int card_deck_number);
    
    //void add_ressource_card(int cards_number_in_deck, int player_number);
    
    void Fin_de_tour();
};

#endif /* Play_ground_hpp */
