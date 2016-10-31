//
// Created by michael on 31/10/16.
//

// Global Variable to hold message queue.
// Didn't want to persist into database because that seems like too much overhead for a temporary

#include "chatEndpoint.h"

using namespace std;
using namespace Net;

ChatEndpoint::ChatEndpoint() {

}

void ChatEndpoint::getMessage(const Net::Rest::Request &request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {

        auto message = _messageBuffer[0].Message;

        response.send(Http::Code::Ok, message);

    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void ChatEndpoint::sendMessage(const Net::Rest::Request &request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {

        // parse body into messsage.
        // add to buffer

        MessageModel message;
        message.From = "Michael";
        message.To = "Steffi";
        message.Message = "Hello World!";

        _messageBuffer.push_back(message);

        MessageModel message2;
        message2.From = "Michael";
        message2.To = "Steffi";
        message2.Message = "Hello World2!";

        _messageBuffer.push_back(message2);


        auto msg = _messageBuffer[0].Message;

        response.send(Http::Code::Ok, msg);

    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }

}