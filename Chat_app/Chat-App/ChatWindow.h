#pragma once

#include <QtWidgets/QWidget>
#include "ui_ChatWindow.h"
#include "ChatSessionListModel.h"
#include "ChatSession.h"
#include "Observer.h"
#include "User.h"

class ChatWindow : public QWidget, public Observer {
    Q_OBJECT

private:
    ChatSessionListModel* chatSessionListModel;

private:
    void keyPressEvent(QKeyEvent* event) override;

public:
    ChatSession& chatSession;
    User& user;

public:
    ChatWindow(ChatSessionListModel* chatSessionListModel, ChatSession& chatSession, User& user, QWidget* parent = Q_NULLPTR);
    void update() override;

public slots:
    void sendMessage();

private:
    Ui::ChatWindowClass ui;
};