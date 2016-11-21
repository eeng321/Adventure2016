//
// Created by braden on 13/10/16.
//

#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <string>

#include "id.h"
#include "itemType.h"

class ItemModel;

class Item {
private:
    std::vector<std::string> attributes;
    int cost;
    std::vector<std::string> extra;
    itemId id;
    item_type type;
    std::vector<std::string> keywords;
    std::string longDesc;
    std::string shortDesc;
    std::vector<std::string> wearFlags;
    int weight;

public:
    Item(itemId idIn,
         std::vector<std::string> keywordsIn,
         std::string longDescIn,
         std::string shortDescIn,
         std::vector<std::string> extraIn);

    Item(itemId idIn,
         std::vector<std::string> keywordsIn,
         std::string longDescIn,
         std::string shortDescIn,
         std::vector<std::string> extraIn,
         std::vector<std::string> attributesIn,
         int costIn,
         item_type typeIn,
         std::vector<std::string> wearFlagsIn,
         int weightIn);

    Item();

    ItemModel getModel() const;

    void setModel(const ItemModel &model);

    /* Getters */
    itemId getId() const;

    std::vector<std::string> getKeywords() const;

    std::string getlongDesc() const;

    std::string getShortDesc() const;

    std::vector<std::string> getExtra() const;

    std::vector<std::string> getAttributes() const;

    int getCost() const;

    item_type getType() const;

    std::vector<std::string> getWearFlags() const;

    int getWeight() const;


    /* Setters */
    void setId(itemId idIn);

    void setKeywords(std::vector<std::string> keywordsIn);

    void setlongDesc(std::string longDescIn);

    void setShortDesc(std::string shortDescIn);

    void setExtra(std::vector<std::string> extraIn);

    void setAttributes(std::vector<std::string> attributesIn);

    void setCost(int costIn);

    void setType(item_type typeIn);

    void setWearFlags(std::vector<std::string> flagsIn);

    void setWeight(int weightIn);

};


#endif //ITEM_H
