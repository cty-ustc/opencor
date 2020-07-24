/*******************************************************************************

Copyright (C) The University of Auckland

OpenCOR is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenCOR is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://gnu.org/licenses>.

*******************************************************************************/

//==============================================================================
// Mapping view widget
//==============================================================================

#pragma once

//==============================================================================

#include "viewwidget.h"
#include "cellmlfile.h"
#include "mappingvieweditingwidget.h"

//==============================================================================

#include <QStringListModel> //TODO remove when over
#include <QTableView>
#include <QMap>

//==============================================================================

namespace Ui {
    class MappingViewWidget;
} // namespace Ui

//==============================================================================

namespace OpenCOR {
namespace MappingView {

//==============================================================================

class MappingViewWidget : public Core::ViewWidget
{
    Q_OBJECT

public:
    explicit MappingViewWidget(QWidget *pParent);
    ~MappingViewWidget() override;

    void retranslateUi() override;

    QWidget * widget(const QString &pFileName) override; 

    void initialize(const QString &pFileName);
    void finalize(const QString &pFileName);

    void filePermissionsChanged(const QString &pFileName);
    void fileSaved(const QString &pFileName);
    void fileReloaded(const QString &pFileName);
    void fileRenamed(const QString &pOldFileName, const QString &pNewFileName);

    bool saveFile(const QString &pOldFileName, const QString &pNewFileName);

private:
    Ui::MappingViewWidget *mGui;

    MappingViewEditingWidget* mEditingWidget = nullptr;
    QMap<QString, MappingViewEditingWidget*> mEditingWidgets;
};

//==============================================================================

} // namespace MappingView
} // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
