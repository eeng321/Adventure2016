//
// Created by michael on 31/10/16.
//

#ifndef ADVENTURE2016_CHATENDPOINT_H
#define ADVENTURE2016_CHATENDPOINT_H

#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/router.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"
#include "../../model/include/messageModel.h"
#include <mutex>

class ChatEndpoint {

public:
    ChatEndpoint();
    void getMessage(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void sendMessage(const Net::Rest::Request& request, Net::Http::ResponseWriter response);

private:
    std::vector<MessageModel> _messageBuffer;
    std::mutex _messageMutex;

    void bufferMessage(MessageModel msg);
    void cleanMessageBuffer();
};

#endif //ADVENTURE2016_CHATENDPOINT_H
