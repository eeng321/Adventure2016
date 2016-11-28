//
// Created by michael on 31/10/16.
//

#include "chatEndpoint.h"
#include "parser.h"

using namespace std;
using namespace Net;

static constexpr int MAX_MESSAGE_SIZE = 20;

ChatEndpoint::ChatEndpoint() {

}

void ChatEndpoint::cleanMessageBuffer() {
    // TODO: [mn]: This will shift the entire array during deletion.
    // Code better solution if this takes a huge performance impact.
    if (_messageBuffer.size() > MAX_MESSAGE_SIZE) {
        _messageBuffer.erase(_messageBuffer.begin());
    }
}

void ChatEndpoint::bufferMessage(MessageModel msg){
    _messageMutex.lock();
    {
        _messageBuffer.push_back(msg);
        cleanMessageBuffer();
    }
    _messageMutex.unlock();
}

void ChatEndpoint::getMessage(const Net::Rest::Request &request, Net::Http::ResponseWriter response) {
//    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        auto messagesYaml = parser::messageVectorSerialize(_messageBuffer);
        response.send(Http::Code::Ok, messagesYaml);

    }
    catch (exception& e) {
        response.send(Http::Code::Internal_Server_Error, e.what());
    }
}

void ChatEndpoint::sendMessage(const Net::Rest::Request &request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        MessageModel message = parser::messageDeserialize(request.body());
        message.Timestamp = std::chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();

        bufferMessage(message);

        auto messagesYaml = parser::messageVectorSerialize(_messageBuffer);

        response.send(Http::Code::Ok, messagesYaml);

    }
    catch (exception& e) {
        response.send(Http::Code::Internal_Server_Error, e.what());
    }
}