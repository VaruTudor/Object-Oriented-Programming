#pragma once

#include "ChatSession.h"
#include <qabstractitemmodel.h>

class ChatSessionListModel : public QAbstractListModel {
private:
    ChatSession& chatSession;
public:
    ChatSessionListModel(ChatSession& chatSession);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
};