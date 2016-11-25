
#include <sstream>
#include <iostream>
#include "itemEndpoint.h"
#include "itemDriver.h"
#include "parser.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace Net;


void ItemEndpoint::createItem(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        // Parse body to grab item arguments
        ItemModel item;
        item = parser::itemDeserialize(request.body());

        addItem(item);

        //todo: fix this with proper returns
        auto success = true;
        if (success) {
            response.send(Http::Code::Created, parser::itemSerialize(item));
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void ItemEndpoint::retrieveItem(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        auto itemId = request.param(":id").as<int>();

        ItemModel item;
        item = loadItem(itemId);

        if (!item.longDesc.empty()) {
            response.send(Http::Code::Ok, parser::itemSerialize(item));
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void ItemEndpoint::updateItem(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        auto itemId = request.param(":id").as<int>();
        ItemModel updateFields = parser::itemDeserialize(request.body());

        auto updatedItem = modifyItem(itemId, updateFields);

        //todo: fix this with proper returns
        if (true) {
            response.send(Http::Code::Ok, parser::itemSerialize(updatedItem));
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void ItemEndpoint::deleteItem(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        auto itemId = request.param(":id").as<int>();
        removeItem(itemId);

        //todo: fix this with proper returns
        auto success = true;
        if (success) {
            response.send(Http::Code::Ok);
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}
