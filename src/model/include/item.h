//
// Created by braden on 13/10/16.
//

#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <string>

#include "id.h"

class ItemModel;

class Item {
private:
    std::vector<std::string> attributes;
    int cost;
    std::vector<std::string> extra;
    itemId id;
    std::string type;
    std::vector<std::string> keywords;
    std::string longDesc;
    std::string shortDesc;
    std::vector<std::string> wear_flags;
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
         std::string typeIn,
         std::vector<std::string> wear_flagsIn,
         int weightIn);

    Item();

//    void build(itemId idIn,
//               const std::vector<std::string>& keywordsIn,
//               const std::string& longDescIn,
//               const std::string& shortDescIn,
//               const std::vector<std::string>& extra);

    ItemModel getModel() const;
    void setModel(const ItemModel& model);

    /* Getters */
    itemId getId() const;
    std::vector<std::string> getKeywords() const;
    std::string getlongDesc() const;
    std::string getShortDesc() const;
    std::vector<std::string> getExtra() const;
    std::vector<std::string> getAttributes() const;
    int getCost() const;
    std::string getType() const;
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
    void setType(std::string typeIn);
    void setWearFlags(std::vector<std::string> flagsIn);
    void setWeight(int weightIn);

};


#endif //ITEM_H
