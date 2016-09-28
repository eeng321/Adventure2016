// playerDriver.cxx
//

#include <memory>   // std::auto_ptr
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include <odb/sqlite/database.hxx>

#include "player.hxx"
#include "player-odb.hxx"

using namespace std;
using namespace odb::core;

// int main (int argc, char* argv[])
// {
//   try
//   {
//     auto_ptr<database> db (new odb::sqlite::database (argc, argv));

//     unsigned long john_id, jane_id, joe_id; //player_id

//     // Create a few persistent person objects.
//     //
//     {
//       //playerid (name, health)
//       player john ("John", 100); 
//       player jane ("Jane", 100);
//       player joe ("Joe", 100);

//       transaction t (db->begin ());

//       // Make objects persistent and save their ids for later use.
//       //
//       john_id = db->persist (john);
//       jane_id = db->persist (jane);
//       joe_id = db->persist (joe);

//       t.commit ();
//     }
//   }
//   catch (const odb::exception& e)
//   {
//     cerr << e.what () << endl;
//     return 1;
//   }
// }

//create entry into db
int Create(string const playerName){
  try{
    player user (playerName, 100); //create player object
    transaction t (db->begin());

    db->persist(user); //make objects persistent

    t.commit();
  }
  catch (const odb::exception& e){
    cerr << e.what () << endl;
    return 1;  
  }

}

//player object names should be unique
//returns player id
int Retrieve(string const playerName){

  try{
    typedef odb::query<player> query;
    typedef odb::result<player> result;
    transaction t (db->begin());

    result r (db->query<player> (query::name == playerName); //query database for matching names

    for (result::iterator i (r.begin ()); i != r.end (); ++i)
    {
      int playerID = i->id; //return first match's id b/c there should only be 1 match
      break; //leave loop after first match, incase there is multiple due to error
    }

    t.commit ();

    return playerID; //return target player id
  }
  catch (const odb::exception& e)
  {
    cerr << e.what () << endl;
    return -1; //return something not in db
  }
  
}

//add stuff into param for changing
int Update(string const playerName){
  int playerID = Retrieve(playerName); //get id of the player name you want

  if(playerID != -1){ //if we can find player in db
    try{
      transaction t (db->begin ());

      auto_ptr<player> user (db->load<player> (playerID));
      //update changes
      //.
      //.
      db->update (*user);

      t.commit ();
    }
    catch (const odb::exception& e)
    {
      cerr << e.what () << endl;
      return 1;
    }
  }
  return 0; //failed
}

//delete player from the database
void Delete(string const playerName){
  int playerID = Retrieve(playerName);

  if(playerID != -1){ //if player is found
    transaction t (db->begin ());

    auto_ptr<player> user (db->load<player> (playerID)); //grab player

    db->erase (*user);

    t.commit ();
  }

}


