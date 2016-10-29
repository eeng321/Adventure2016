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
	std::vector<std::string> extra;
	itemId id;
	std::vector<std::string> keywords;
	std::string longdesc;
	std::string shortdesc;

public:
	Item(itemId idIn,
		const std::vector<std::string>& keywordsIn,
		const std::string& longDescIn,
		const std::string& shortDescIn,
		const std::vector<std::string>& extra);

	void build(itemId idIn,
		const std::vector<std::string>& keywordsIn,
		const std::string& longDescIn,
		const std::string& shortDescIn,
		const std::vector<std::string>& extra);

	ItemModel getModel() const;
	void setModel(const ItemModel& model);

	/* Getters */
	itemId getId() const;
	std::vector<std::string> getKeywords() const;
	std::string getlongDesc() const;
	std::string getShortDesc() const;
	std::vector<std::string> getExtra() const;

	/* Setters */
	void setId(itemId idIn);
	void setKeywords(const std::vector<std::string>& keywordsIn);
	void setlongDesc(const std::string& longDescIn);
	void setShortDesc(const std::string& shortDescIn);
	void setExtra(const std::vector<std::string>& extraIn);

};


#endif //ITEM_H
