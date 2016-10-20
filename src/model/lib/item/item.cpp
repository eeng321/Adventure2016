//item.cpp

#include <string>
#include <vector>
#include <memory>

#include "item.h"
#include "itemModel.h"

using std::string;
using std::vector;

Item::Item(id itemIdIn,
	const std::vector<std::string>& keywordsIn,
	const std::string& longDescIn,
	const std::string& shortDescIn,
	const std::vector<std::string>& extraIn)
	:model(std::make_unique<ItemModel>()){

	build(itemIdIn, keywordsIn, longDescIn, shortDescIn, extraIn);
}

void Item::build(id itemIdIn,
	const std::vector<std::string>& keywordsIn,
	const std::string& longDescIn,
	const std::string& shortDescIn,
	const std::vector<std::string>& extraIn){

	model->itemId = itemIdIn;
	model->keywords = keywordsIn;
	model->longdesc = longDescIn;
	model->shortdesc = shortDescIn;
	model->extra = extraIn;

}

id Item::getId(){
	return model->itemId;
}

std::vector<std::string> Item::getKeywords(){
	return model->keywords;
}

std::string Item::getlongDesc(){
	return model->longdesc;
}

std::string Item::getShortDesc(){
	return model->shortdesc;
}

std::vector<std::string> Item::getExtra(){
	return model->extra;
}

/* Setters */
void Item::setId(id idIn){
	model->itemId = idIn;
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
