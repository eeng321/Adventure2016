
#ifndef EXTENDED_DESCRIPTION_H
#define EXTENDED_DESCRIPTION_H

#include <string>
#include <vector>
#include "../../back_end/lib/hiberlite/include/hiberlite.h"



struct extendedDescription{
	std::vector<std::string> description;
	std::vector<std::string> keywords;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(description);
        ar & HIBERLITE_NVP(keywords);
    }

};

#endif
