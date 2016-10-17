// driver.cxx
//

#include <memory>   // std::auto_ptr
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include <odb/mysql/database.hxx>

#include "playerModel.h"
#include "player-odb.hxx"

using namespace std;
using namespace odb::core;

int
main (int argc, char* argv[])
{
  try
  {
    auto_ptr<database> db (new odb::sqlite::database (argc, argv));

    unsigned long john_id, jane_id, joe_id; //player_id

    // Create a few persistent person objects.
    //
    {
      //name, health
      player john ("John", 100); 
      player jane ("Jane", 100);
      player joe ("Joe", 100);

      transaction t (db->begin ());

      // Make objects persistent and save their ids for later use.
      //
      john_id = db->persist (john);
      jane_id = db->persist (jane);
      joe_id = db->persist (joe);

      t.commit ();
    }
  }
  catch (const odb::exception& e)
  {
    cerr << e.what () << endl;
    return 1;
  }
}

//player object names should be unique
//returns Player object
Player Retrieve(string const playerName){

  try{

    transaction t (db->begin());

    //search db for matching name then store pointer to that object
    auto_ptr<Player> user (db->query_one<Player> (query::name == playerName));

    t.commit ();

    return *user; //return Player object
  }
  catch (const odb::exception& e)
  {
    cerr << e.what () << endl;
    return NULL; //no object found
  }
  
}

//edit existing Player
Player Update(Player player){
  
  if(player != NULL){ //if object not NULL
    try{
      transaction t (db->begin ());

      //load an object that you want to update
      auto_ptr<Player> user (db->load<Player> (player.id)); 
      *user = player; //replace current values with new values

      db->update (*user);

      t.commit ();
      return *user;
    }
    catch (const odb::exception& e)
    {
      cerr << e.what () << endl;
      return NULL;
    }
  }
  return NULL; //if it gets here then update failed
}

//delete player from the database
// return success = 1, fail = 0
int Delete(string const playerName){

  transaction t (db->begin ());

  //grab player
  auto_ptr<Player> user (db->query_one<Player> (query::name == playerName)); 

  if (user.get() != 0){
    db->erase (*user); //found object
  }else{
    return 0; //failed to find object
  }

  t.commit ();

  return 1; //success
}
  