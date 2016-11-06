//
// Created by braden on 13/10/16.
//

#ifndef ITEM_MODEL_H
#define ITEM_MODEL_H

#pragma once
#include "../../back_end/lib/hiberlite/include/hiberlite.h"
#include <string>
#include <vector>

#include "id.h"
#include "itemType.h"


class ItemModel {
public:
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar) {
        ar & HIBERLITE_NVP(extra);
        ar & HIBERLITE_NVP(id);
        ar & HIBERLITE_NVP(keywords);
        ar & HIBERLITE_NVP(longDesc);
        ar & HIBERLITE_NVP(shortDesc);
    }

    std::vector<std::string> attributes;
    int cost;
    std::vector<std::string> extra;
    int id;
    item_type type;
    std::vector<std::string> keywords;
    std::string longDesc;
    std::string shortDesc;
    std::vector<std::string> wear_flags;
    int weight;

	ItemModel();

};


#endif //ITEM_MODEL_H
