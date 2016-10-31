//
// Created by michael on 31/10/16.
//

#include "chatEndpoint.h"
#include "parser.h"

using namespace std;
using namespace Net;

ChatEndpoint::ChatEndpoint() {

}

void ChatEndpoint::getMessage(const Net::Rest::Request &request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {

        string messages = "";

        // todo: testing. need to cut off at 10? or deserialize into message vector
        for (int i = 0; i < _messageBuffer.size(); i ++) {
            messages = messages + parser::modelSerialize(_messageBuffer[i]) + "\n";
        }

        response.send(Http::Code::Ok, messages);

    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void ChatEndpoint::sendMessage(const Net::Rest::Request &request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        cout << request.body() << endl;

        MessageModel message = parser::messageDeserialize(request.body());
        _messageBuffer.push_back(message);

        //todo: should it turn more messages?
        response.send(Http::Code::Ok, parser::modelSerialize(message));

    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }

}