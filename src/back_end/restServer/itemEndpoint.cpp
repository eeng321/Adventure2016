
#include <sstream>
#include <iostream>
#include "itemEndpoint.h"
#include "parser.h"
//#include "itemDriver.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace Net;

void ItemEndpoint::login(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        string accountInfo(request.body());
        vector<string> inputs;
        boost::split(inputs, accountInfo, boost::is_any_of("?=&"));

        ItemModel item = verifyCredentials(inputs[2], inputs[4]);

        if (item.loginName == inputs[2]) {
            response.send(Http::Code::Ok, parser::itemSerialize(item));
        }
        else {
            response.send(Http::Code::Forbidden);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void ItemEndpoint::registerItem(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        string accountInfo(request.body());
        vector<string> inputs;
        boost::split(inputs, accountInfo, boost::is_any_of("?=&"));

        ItemModel item = registerAccount(inputs[2], inputs[4]);

        if (item.loginName == inputs[2]) {
            response.send(Http::Code::Ok, parser::itemSerialize(item));
        }
        else {
            response.send(Http::Code::Forbidden);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }

}

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
        item.loginName = "";
        item = loadItem(itemId);

        if (item.loginName != "") {
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
