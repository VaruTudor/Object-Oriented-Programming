#include "ChatSession.h"

void ChatSession::addMessage(const UserMessage& message) {
    messages.push_back(message);
}

const std::vector<UserMessage> ChatSession::getMessages() const {
    return messages;
}