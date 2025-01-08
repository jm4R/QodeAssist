/* 
 * Copyright (C) 2024 Petr Mironychev
 *
 * This file is part of QodeAssist.
 *
 * QodeAssist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QodeAssist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QodeAssist. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <QObject>
#include <QString>
#include <QVector>

#include "ChatModel.hpp"
#include "RequestHandler.hpp"

namespace QodeAssist::Chat {

class ClientInterface : public QObject
{
    Q_OBJECT

public:
    explicit ClientInterface(ChatModel *chatModel, QObject *parent = nullptr);
    ~ClientInterface();

    void sendMessage(
        const QString &message,
        const QList<QString> &attachments = {},
        bool includeCurrentFile = false);
    void clearMessages();
    void cancelRequest();

signals:
    void errorOccurred(const QString &error);
    void messageReceivedCompletely();

private:
    void handleLLMResponse(const QString &response, const QJsonObject &request, bool isComplete);
    QString getCurrentFileContext() const;

    LLMCore::RequestHandler *m_requestHandler;
    ChatModel *m_chatModel;
};

} // namespace QodeAssist::Chat
