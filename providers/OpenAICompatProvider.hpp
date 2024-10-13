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

#include "llmcore/Provider.hpp"

namespace QodeAssist::Providers {

class OpenAICompatProvider : public LLMCore::Provider
{
public:
    OpenAICompatProvider();

    QString name() const override;
    QString url() const override;
    QString completionEndpoint() const override;
    QString chatEndpoint() const override;
    void prepareRequest(QJsonObject &request, LLMCore::RequestType type) override;
    bool handleResponse(QNetworkReply *reply, QString &accumulatedResponse) override;
    QList<QString> getInstalledModels(const Utils::Environment &env, const QString &url) override;
};

} // namespace QodeAssist::Providers
