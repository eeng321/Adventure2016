// playerDriver.cxx 
// CRUD operations

#include <memory>   // std::auto_ptr
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include <odb/sqlite/database.hxx>
#include <odb/schema-catalog.hxx>

#include "Player.hxx"

using namespace std;
using namespace odb::core;


//create entry in db
// return success = 1, fail = 0
int Create(Player player){

  try{
    auto_ptr<database> db (create_database (argc, argv));
    transaction t (db->begin());

    db->persist(player); //put player into db

    t.commit();
    return 1;
  }
  catch (const odb::exception& e){
    cerr << e.what () << endl;
    return 0;
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

Player& Player::operator=(Player newPlayer){
  swap(newPlayer);
  return *this;
}


