#pragma once

#include <string>

class User {
private:
	std::string uniqueUserName;
	std::string name;
public:
	User(const std::string& uniqueUserName, const std::string& name);
	const std::string& getUniqueUserName() const;
	const std::string& getName() const;
};