// playerDriver.cxx
//

#include <memory>   // std::auto_ptr
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include <odb/mysql/database.hxx>

#include "person.hxx"
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
int Create(string const name){
  try{
    player username (name, 100); //create player object
    transaction t (db->begin());
    db->persist(username); //make objects persistent
    t.commit();
  }
  catch (const odb::exception& e){
    cerr << e.what () << endl;
    return 1;
  }

}

int Retrieve(int argc, char* argv[]){

}

int Update(int argc, char* argv[]){

}

int Delete(int argc, char* argv[]){

}


