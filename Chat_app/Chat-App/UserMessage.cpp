#include "UserMessage.h"

UserMessage::UserMessage(User& user, const Message& message) : user(user), message(message) {}

const User& UserMessage::getUser() const {
    return user;
}

const Message& UserMessage::getMessage() const {
    return message;
}

std::string UserMessage::toString() const {
    return user.getName() + ": " + message.getMessageContent();
}