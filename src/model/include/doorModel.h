
#include "../../back_end/lib/hiberlite/include/hiberlite.h"
#include <string>
#include <vector>


#ifndef DOOR_MODEL_H
#define DOOR_MODEL_H


enum class Direction {
	north, south, east, west
};

namespace hiberlite {
    template <class A>
    void hibernate(A& ar, Direction& value, const unsigned int) {
        ar& db_atom<Direction>(value);
    }

    template <>
    inline std::string db_atom<Direction>::sqliteStorageClass() {
        return "INTEGER";
    }

    template <>
    template <class Stmt, class Arg>
    void db_atom<Direction>::loadValue(Stmt& res, Arg& arg) {
        val = static_cast<Direction>(res.get_int(arg));
    }

    template <>
    inline void db_atom<Direction>::bindValue(sqlite3_stmt* stmt, int col) {
        sqlite3_bind_int(stmt, col, static_cast<int>(val));
    }
}

class DoorModel {
public:
	friend class hiberlite::access;
	template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(direction);
        ar & HIBERLITE_NVP(keywords);
        ar & HIBERLITE_NVP(roomTo);
        ar & HIBERLITE_NVP(description);
    }
    
	Direction direction;
	std::vector<std::string> keywords;
	int roomTo;//The room this door leads too
	std::vector<std::string> description;
};


#endif //DOOR_H