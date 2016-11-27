//item.cpp

#include <string>
#include <vector>
#include <memory>

#include "item.h"
#include "itemModel.h"
#include "id.h"

using std::string;
using std::vector;

const int BLANK_ITEM_ID = 0;

Item::Item()
    : id(BLANK_ITEM_ID) {

}

Item::Item(itemId idIn,
           vector<string> keywordsIn,
           vector<string> longDescIn,
           string shortDescIn,
           vector<extendedDescription> extraIn)
        : id(std::move(idIn)),
          keywords(std::move(keywordsIn)),
          longDesc(std::move(longDescIn)),
          shortDesc(std::move(shortDescIn)),
          extra(std::move(extraIn)) {}

Item::Item(itemId idIn,
           vector<string> keywordsIn,
           vector<string> longDescIn,
           string shortDescIn,
           vector<extendedDescription> extraIn,
           vector<string> attributesIn,
           int costIn,
           item_type typeIn,
           vector<string> flagsIn,
           int weightIn)
        : id(std::move(idIn)),
          keywords(std::move(keywordsIn)),
          longDesc(std::move(longDescIn)),
          shortDesc(std::move(shortDescIn)),
          extra(std::move(extraIn)),
          attributes(std::move(attributesIn)),
          cost(costIn),
          type(std::move(typeIn)),
          wearFlags(std::move(flagsIn)),
          weight(weightIn) {}

ItemModel Item::getModel() const {
    ItemModel model;
    model.id = id.value;
    model.keywords = keywords;
    model.shortDesc = shortDesc;
    model.longDesc = longDesc;
    model.extra = extra;
    model.attributes = attributes;
    model.cost = cost;
    model.type = type;
    model.wearFlags = wearFlags;
    model.weight = weight;
    return model;
}

void Item::setModel(const ItemModel &model) {
    id = itemId(model.id);
    keywords = model.keywords;
    shortDesc = model.shortDesc;
    longDesc = model.longDesc;
    extra = model.extra;
    attributes = model.attributes;
    cost = model.cost;
    type = model.type;
    wearFlags = model.wearFlags;
    weight = model.weight;
}

itemId Item::getId() const {
    return id;
}

vector<string> Item::getKeywords() const {
    return keywords;
}

vector<string> Item::getLongDesc() const {
    return longDesc;
}

string Item::getShortDesc() const {
    return shortDesc;
}

std::vector<extendedDescription> Item::getExtra() const {
    return extra;
}

vector<string> Item::getAttributes() const {
    return attributes;
}

int Item::getCost() const {
    return cost;
}

item_type Item::getType() const {
    return type;
}

std::vector<std::string> Item::getWearFlags() const {
    return wearFlags;
}

int Item::getWeight() const {
    return weight;
}

/* Setters */
void Item::setId(itemId idIn) {
    id = std::move(idIn);
}

void Item::setKeywords(std::vector<std::string> keywordsIn) {
    keywords = std::move(keywordsIn);
}

void Item::setlongDesc(std::vector<std::string> longDescIn) {
    longDesc = std::move(longDescIn);
}

void Item::setShortDesc(std::string shortDescIn) {
    shortDesc = std::move(shortDescIn);
}

void Item::setExtra(std::vector<extendedDescription> extraIn) {
    extra = std::move(extraIn);
}

void Item::setAttributes(std::vector<std::string> attributesIn) {
    attributes = std::move(attributesIn);
}

void Item::setCost(int costIn) {
    cost = std::move(costIn);
}

void Item::setType(item_type typeIn) {
    type = std::move(typeIn);
}

void Item::setWearFlags(std::vector<std::string> flagsIn) {
    wearFlags = std::move(flagsIn);
}

void Item::setWeight(int weightIn) {
    weight = std::move(weightIn);
}