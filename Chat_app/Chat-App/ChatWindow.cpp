#include "ChatWindow.h"
#include <QKeyEvent>

ChatWindow::ChatWindow(ChatSessionListModel* chatSessionListModel, ChatSession& chatSession, User& user, QWidget* parent) :
    chatSessionListModel(chatSessionListModel),
    chatSession(chatSession),
    user(user),
    QWidget(parent) {
    ui.setupUi(this);
    chatSession.registerObserver(this);
    ui.messagesListView->setModel(chatSessionListModel);
    ui.currentUserLabel->setText(QString::fromStdString("Current user: " + user.getName()));
}

void ChatWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        sendMessage();
    }
}

void ChatWindow::update() {
    emit chatSessionListModel->layoutChanged();
    ui.messagesListView->scrollToBottom();
}

void ChatWindow::sendMessage() {
    std::string messageContent = ui.messageLineEdit->text().toStdString();
    if (std::size(messageContent) > 0) {
        chatSession.addMessage(UserMessage(user, Message(messageContent, std::time(nullptr))));
        ui.messageLineEdit->clear();
        ui.messageLineEdit->setFocus();
        chatSession.notify();
    }
}