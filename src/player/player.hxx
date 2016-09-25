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
  unsigned long id_;        

  std::string name_;

  int health_;
};