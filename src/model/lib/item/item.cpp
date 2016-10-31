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
	const std::vector<std::string>& keywordsIn,
	const std::string& longDescIn,
	const std::string& shortDescIn,
	const std::vector<std::string>& extraIn)
	:id(idIn),
	keywords(keywordsIn),
	longDesc(longDescIn),
	shortDesc(shortDescIn),
	extra(extraIn){}

void Item::build(itemId idIn,
	const std::vector<std::string>& keywordsIn,
	const std::string& longDescIn,
	const std::string& shortDescIn,
	const std::vector<std::string>& extraIn){

	id = idIn;
	keywords = keywordsIn;
	longDesc = longDescIn;
	shortDesc = shortDescIn;
	extra = extraIn;

}

ItemModel Item::getModel() const {
	ItemModel model;
	model.id = id.value;
	model.keywords = keywords;
	model.shortDesc = shortDesc;
	model.longDesc = longDesc;
	model.extra = extra;
	return model;
}

void Item::setModel(const ItemModel& model) {
	id = itemId(model.id);
	keywords = model.keywords;
	shortDesc = model.shortDesc;
	longDesc = model.longDesc;
	extra = model.extra;
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

/* Setters */
void Item::setId(itemId idIn){
	id = idIn;
}
void Item::setKeywords(const std::vector<std::string>& keywordsIn){
	keywords = keywordsIn;
}

void Item::setlongDesc(const std::string& longDescIn){
	longDesc = longDescIn;
}

void Item::setShortDesc(const std::string& shortDescIn){
	shortDesc = shortDescIn;
}

void Item::setExtra(const std::vector<std::string>& extraIn){
	extra = extraIn;
}
