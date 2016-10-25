//item.cpp

#include <string>
#include <vector>
#include <memory>

#include "item.h"
#include "itemModel.h"
#include "id.h"

using std::string;
using std::vector;

Item::Item(itemID idIn,
	const std::vector<std::string>& keywordsIn,
	const std::string& longDescIn,
	const std::string& shortDescIn,
	const std::vector<std::string>& extraIn)
	:id(idIn),
	keywords(keywordsIn),
	longdesc(longDescIn),
	shortdesc(shortDescIn),
	extra(extraIn){}

void Item::build(itemID idIn,
	const std::vector<std::string>& keywordsIn,
	const std::string& longDescIn,
	const std::string& shortDescIn,
	const std::vector<std::string>& extraIn){

	id = idIn;
	keywords = keywordsIn;
	longdesc = longDescIn;
	shortdesc = shortDescIn;
	extra = extraIn;

}

ItemModel Item::getModel() const {
	ItemModel model;
	model.id = id.value;
	model.keywords = keywords;
	model.shortdesc = shortdesc;
	model.longdesc = longdesc;
	model.extra = extra;
	return model;
}

void Item::setModel(const ItemModel& model) {
	id = itemID(model.id);
	keywords = model.keywords;
	shortdesc = model.shortdesc;
	longdesc = model.longdesc;
	extra = model.extra;
}

itemID Item::getId() const {
	return id;
}

std::vector<std::string> Item::getKeywords() const {
	return keywords;
}

std::string Item::getlongDesc() const {
	return longdesc;
}

std::string Item::getShortDesc() const {
	return shortdesc;
}

std::vector<std::string> Item::getExtra() const {
	return extra;
}

/* Setters */
void Item::setId(itemID idIn){
	id = idIn;
}
void Item::setKeywords(const std::vector<std::string>& keywordsIn){
	keywords = keywordsIn;
}

void Item::setlongDesc(const std::string& longDescIn){
	longdesc = longDescIn;
}

void Item::setShortDesc(const std::string& shortDescIn){
	shortdesc = shortDescIn;
}

void Item::setExtra(const std::vector<std::string>& extraIn){
	extra = extraIn;
}
