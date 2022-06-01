#include "User.h"

User::User(const std::string& uniqueUserName, const std::string& name) : uniqueUserName(uniqueUserName), name(name) {}

const std::string& User::getUniqueUserName() const {
    return uniqueUserName;
}

const std::string& User::getName() const {
    return name;
}