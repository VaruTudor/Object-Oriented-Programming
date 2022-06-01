#include "ChatSessionListModel.h"

ChatSessionListModel::ChatSessionListModel(ChatSession& chatSession) : chatSession(chatSession) {}

int ChatSessionListModel::rowCount(const QModelIndex& parent) const {
    return std::size(chatSession.getMessages());
}

QVariant ChatSessionListModel::data(const QModelIndex& index, int role) const {
    int row = index.row();
    if (role == Qt::DisplayRole) {
        return QString::fromStdString(chatSession.getMessages()[row].toString());
    }
    return QVariant();
}