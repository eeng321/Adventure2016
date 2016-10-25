//
// Created by braden on 13/10/16.
//

#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <vector>
#include <string>

#include "id.h"

using id = int;

class ItemModel;

class Item {
private:
	std::vector<std::string> extra;
	itemID id;
	std::vector<std::string> keywords;
	std::string longdesc;
	std::string shortdesc;

public:
	Item(itemID idIn,
		const std::vector<std::string>& keywordsIn,
		const std::string& longDescIn,
		const std::string& shortDescIn,
		const std::vector<std::string>& extra);

	void build(itemID idIn,
		const std::vector<std::string>& keywordsIn,
		const std::string& longDescIn,
		const std::string& shortDescIn,
		const std::vector<std::string>& extra);

	ItemModel getModel() const;
	void setModel(const ItemModel& model);

	/* Getters */
	itemID getId() const;
	std::vector<std::string> getKeywords() const;
	std::string getlongDesc() const;
	std::string getShortDesc() const;
	std::vector<std::string> getExtra() const;

	/* Setters */
	void setId(itemID idIn);
	void setKeywords(const std::vector<std::string>& keywordsIn);
	void setlongDesc(const std::string& longDescIn);
	void setShortDesc(const std::string& shortDescIn);
	void setExtra(const std::vector<std::string>& extraIn);

};


#endif //ITEM_H
