/* Copyright 2013-2019 MultiMC Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <QWidget>
#include <QString>

#include "pages/BasePage.h"
#include <MultiMC.h>

namespace Ui
{
class DefaultGameOptionsPage;
}

class GameOptions;
class MinecraftInstance;

class DefaultGameOptionsPage : public QWidget, public BasePage
{
    Q_OBJECT

public:
    explicit DefaultGameOptionsPage(QWidget *parent = 0);
    virtual ~DefaultGameOptionsPage();

    void openedImpl() override;
    void closedImpl() override;

    virtual QString displayName() const override
    {
        return tr("Game Options");
    }
    virtual QIcon icon() const override
    {
        return MMC->getThemedIcon("settings");
    }
    virtual QString id() const override
    {
        return "defaultgameoptions";
    }
    virtual QString helpPage() const override
    {
        return "Default-Game-Options";
    }

    bool apply() override;

private:
    void applySettings();
    void loadSettings();
    void updateEnabledWidgets();

private slots:
    void radioChanged(int);

private: // data
    Ui::DefaultGameOptionsPage *ui = nullptr;
};
