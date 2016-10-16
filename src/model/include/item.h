//
// Created by braden on 13/10/16.
//

#ifndef ITEM_H
#define ITEM_H




typedef int id;

typedef std::string description;

typedef std::string username;

class Item {
private:
	std::vector<std::string> extra;
	id itemId;
	std::vector<std::string> keywords;
	std::string longdesc;
	std::string shortdesc;

public:


	void build();
};


#endif //ITEM_H
