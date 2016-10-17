#ifndef ADVENTURE2016_CREDENTIAL_H
#define ADVENTURE2016_CREDENTIAL_H

#include "../../back_end/lib/hiberlite/include/hiberlite.h"
#include "../../model/include/playerModel.h"
#include <string>

class Credential {
public:

    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(player);
        ar & HIBERLITE_NVP(password);
    }

    // Player identification attributes
    PlayerModel player;
    std::string password;
};
HIBERLITE_EXPORT_CLASS(Credential)

#endif //ADVENTURE2016_CREDENTIAL_H