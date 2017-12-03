
//  Card_Old_Gods_game







#include "Player.hpp"



int main(int argc, const char * argv[]) {
    
    std::vector<Card*> cards_table;
    int cards_n(0);
    std::string line;
    std::ifstream myfile ("Cards.txt");
    if (myfile.is_open())
    {
        myfile>>cards_n;
        for(int i=0;i<cards_n;i++)
        {
            
            cards_table.push_back(new Card (myfile));
            //std::cout<< cards_table[i]->Get_s_parameter(1)<<cards_table[i]->Get_NAME();
        }
      
        myfile.close();
    }
    
    else std::cout << "Unable to open file";
    
    for(int i=0;i<cards_table.size();i++)
    {
        delete cards_table[i];
        
    }
    
    return 0;
}
