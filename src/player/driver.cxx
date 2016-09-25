// driver.cxx
//

#include <memory>   // std::auto_ptr
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include <odb/mysql/database.hxx>

#include "person.hxx"
#include "person-odb.hxx"

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
  