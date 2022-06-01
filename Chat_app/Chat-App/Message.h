#pragma once

#include <string>
#include <ctime>

class Message {
private:
	std::string messageContent;
	std::time_t timestamp;
public:
	Message(const std::string& messageContent, const std::time_t& timestamp);
	const std::string& getMessageContent() const;
	const std::time_t& getTimestamp() const;
};