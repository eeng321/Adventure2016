//
// Created by braden on 13/10/16.
//

#ifndef ITEM_H
#define ITEM_H

#include<memory>

using id = int;

class ItemModel;

class Item {
private:
	std::unique_ptr<ItemModel> model;

public:
	Item(id itemIdIn,
		const std::vector<std::string>& keywordsIn,
		const std::string& longDescIn,
		const std::string& shortDescIn,
		const std::vector<std::string>& extra);

	void build(id itemIdIn,
		const std::vector<std::string>& keywordsIn,
		const std::string& longDescIn,
		const std::string& shortDescIn,
		const std::vector<std::string>& extra);

	/* Getters */
	id getId();
	std::vector<std::string> getKeywords();
	std::string getlongDesc();
	std::string getShortDesc();
	std::vector<std::string> getExtra();

	/* Setters */
	void setId(id idIn);
	void setKeywords(const std::vector<std::string>& keywordsIn);
	void setlongDesc(const std::string& longDescIn);
	void setShortDesc(const std::string& shortDescIn);
	void setExtra(const std::vector<std::string>& extraIn);

};


#endif //ITEM_H
