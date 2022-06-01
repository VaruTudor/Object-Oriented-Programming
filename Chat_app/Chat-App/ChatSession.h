#pragma once

#include "UserMessage.h"
#include "Subject.h"
#include <vector>

class ChatSession : public Subject {
private:
	std::vector<UserMessage> messages;
public:
	void addMessage(const UserMessage& message);
	const std::vector<UserMessage> getMessages() const;
};