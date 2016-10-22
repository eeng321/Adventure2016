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
	:model(std::make_unique<ItemModel>()) {

	build(idIn, keywordsIn, longDescIn, shortDescIn, extraIn);
}

void Item::build(itemID idIn,
	const std::vector<std::string>& keywordsIn,
	const std::string& longDescIn,
	const std::string& shortDescIn,
	const std::vector<std::string>& extraIn){

	model->id = idIn;
	model->keywords = keywordsIn;
	model->longdesc = longDescIn;
	model->shortdesc = shortDescIn;
	model->extra = extraIn;

}

itemID Item::getId() const {
	return model->id;
}

std::vector<std::string> Item::getKeywords() const {
	return model->keywords;
}

std::string Item::getlongDesc() const {
	return model->longdesc;
}

std::string Item::getShortDesc() const {
	return model->shortdesc;
}

std::vector<std::string> Item::getExtra() const {
	return model->extra;
}

/* Setters */
void Item::setId(itemID idIn){
	model->id = idIn;
}
void Item::setKeywords(const std::vector<std::string>& keywordsIn){
	model->keywords = keywordsIn;
}

void Item::setlongDesc(const std::string& longDescIn){
	model->longdesc = longDescIn;
}

void Item::setShortDesc(const std::string& shortDescIn){
	model->shortdesc = shortDescIn;
}

void Item::setExtra(const std::vector<std::string>& extraIn){
	model->extra = extraIn;
}
