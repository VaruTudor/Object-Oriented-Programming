#include "Message.h"

Message::Message(const std::string& messageContent, const std::time_t& timestamp) : messageContent(messageContent), timestamp(timestamp) {}

const std::string& Message::getMessageContent() const {
    return messageContent;
}

const std::time_t& Message::getTimestamp() const {
    return timestamp;
}