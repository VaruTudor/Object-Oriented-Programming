#pragma once

#include "User.h"
#include "Message.h"

class UserMessage {
private:
	User& user;
	Message message;
public:
	UserMessage(User& user, const Message& message);
	const User& getUser() const;
	const Message& getMessage() const;
	std::string toString() const;
};