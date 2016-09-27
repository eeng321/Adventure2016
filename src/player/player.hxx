//Player class

#include <string>

#include <odb/core.hxx>     

#pragma db object           
class Player
{
  ...

private:
  Player () {}              

  friend class odb::access; 

  #pragma db id auto       

  unsigned long id_; //player id
  std::string name_; //player name
  int health_; 		 //player health
  int row_, col_; 		 //player position
};