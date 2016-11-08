//item.cpp

#include <string>
#include <vector>
#include <memory>

#include "item.h"
#include "itemModel.h"
#include "id.h"

using std::string;
using std::vector;

Item::Item(itemId idIn,
	std::vector<std::string> keywordsIn,
	std::string longDescIn,
	std::string shortDescIn,
	std::vector<std::string> extraIn)
	:id(std::move(idIn)),
	keywords(std::move(keywordsIn)),
	longDesc(std::move(longDescIn)),
	shortDesc(std::move(shortDescIn)),
	extra(std::move(extraIn)){}

Item::Item(itemId idIn,
    std::vector<std::string> keywordsIn,
    std::string longDescIn,
    std::string shortDescIn,
    std::vector<std::string> extraIn,
    std::vector<std::string> attributesIn,
    int costIn,
    std::string typeIn,
    std::vector<std::string> flagsIn,
    int weightIn)
    :id(std::move(idIn)),
     keywords(std::move(keywordsIn)),
     longDesc(std::move(longDescIn)),
     shortDesc(std::move(shortDescIn)),
     extra(std::move(extraIn)),
     attributes(std::move(attributesIn)),
     cost(costIn),
     type(std::move(typeIn)),
     wear_flags(std::move(flagsIn)),
     weight(weightIn){}

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
    model.wear_flags = wear_flags;
    model.weight = weight;
	return model;
}

void Item::setModel(const ItemModel& model) {
	id = itemId(model.id);
	keywords = model.keywords;
	shortDesc = model.shortDesc;
	longDesc = model.longDesc;
	extra = model.extra;
    attributes = model.attributes;
    cost = model.cost;
    type = model.type;
    wear_flags = model.wear_flags;
    weight = model.weight;
}

itemId Item::getId() const {
	return id;
}

std::vector<std::string> Item::getKeywords() const {
	return keywords;
}

std::string Item::getlongDesc() const {
	return longDesc;
}

std::string Item::getShortDesc() const {
	return shortDesc;
}

std::vector<std::string> Item::getExtra() const {
	return extra;
}

std::vector<std::string> Item::getAttributes() const {
    return attributes;
}

int Item::getCost() const {
    return cost;
}

std::string Item::getType() const {
    return type;
}

std::vector<std::string> Item::getWearFlags() const {
    return wear_flags;
}

int Item::getWeight() const {
    return weight;
}

/* Setters */
void Item::setId(itemId idIn){
	id = std::move(idIn);
}
void Item::setKeywords(std::vector<std::string> keywordsIn){
	keywords = std::move(keywordsIn);
}

void Item::setlongDesc(std::string longDescIn){
	longDesc = std::move(longDescIn);
}

void Item::setShortDesc(std::string shortDescIn){
	shortDesc = std::move(shortDescIn);
}

void Item::setExtra(std::vector<std::string> extraIn){
	extra = std::move(extraIn);
}

void Item::setAttributes(std::vector<std::string> attributesIn) {
    attributes = std::move(attributesIn);
}

void Item::setCost(int costIn) {
    cost = std::move(costIn);
}

void Item::setType(std::string typeIn) {
    type = std::move(typeIn);
}

void Item::setWearFlags(std::vector<std::string> flagsIn) {
    wear_flags = std::move(flagsIn);
}

void Item::setWeight(int weightIn) {
    weight = std::move(weightIn);
}