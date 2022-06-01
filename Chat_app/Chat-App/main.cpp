#include <QtWidgets/QApplication>
#include "ChatWindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    std::vector<User> users;
    users.push_back(User("bill_nye_the_russian_spy", "Brad Pitt"));
    users.push_back(User("zero_deaths", "Jim Carrey"));
    users.push_back(User("pig_benis", "Bradley Cooper"));

    ChatSession chatSession;
    ChatSessionListModel* chatSessionListModel = new ChatSessionListModel(chatSession);

    std::vector<std::unique_ptr<ChatWindow>> chatWindows;

    for (auto& user : users) {
        chatWindows.push_back(std::make_unique<ChatWindow>(chatSessionListModel, chatSession, user));
        chatWindows.back()->show();
    }

    return a.exec();
}