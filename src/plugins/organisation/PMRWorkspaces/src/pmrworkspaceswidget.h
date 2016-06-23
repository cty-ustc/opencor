/*******************************************************************************

Licensed to the OpenCOR team under one or more contributor license agreements.
See the NOTICE.txt file distributed with this work for additional information
regarding copyright ownership. The OpenCOR team licenses this file to you under
the Apache License, Version 2.0 (the "License"); you may not use this file
except in compliance with the License. You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.

*******************************************************************************/

//==============================================================================
// Workspaces widget
//==============================================================================

#pragma once

//==============================================================================

#include "commonwidget.h"
#include "corecliutils.h"
#include "pmrworkspace.h"
#include "webviewerwidget.h"

//==============================================================================

#include <QMap>

//==============================================================================

namespace OpenCOR {

//==============================================================================

namespace PMRSupport {
    class PmrRepository;
}   // namespace PMRSupport

//==============================================================================

namespace PMRWorkspaces {

//==============================================================================

class PmrWorkspacesWidget : public WebViewerWidget::WebViewerWidget, public Core::CommonWidget
{
    Q_OBJECT

public:
    explicit PmrWorkspacesWidget(PMRSupport::PmrRepository *pPmrRepository, QWidget *pParent);
    ~PmrWorkspacesWidget();

    virtual void loadSettings(QSettings *pSettings);
    virtual void saveSettings(QSettings *pSettings) const;

    void setSelected(const QString &pSelectedUrl);

protected:
    virtual QSize sizeHint() const;

private:
    QString mTemplate;

    PMRSupport::PmrRepository *mPmrRepository;

    QMap<QString, bool> mExpandedItems;
    QString mSelectedUrl;

    static QString workspacePath(const QString &pUrl, const QString &pPath);
    QMap<QString, QString> mWorkspaceFolders;                 // Folder name --> Url

    static QString actionHtml(const QList<QPair<QString, QString> > &pActions);
    static QString containerHtml(const QString &pClass, const QString &pIcon,
                                 const QString &pId, const QString &pName,
                                 const QString &pStatus,
                                 const QList<QPair<QString, QString> > &pActions);
    static QString fileHtml(const QString &pName, const QString &pStatus,
                            const QList<QPair<QString, QString> > &pActions);
    static QString emptyContentsHtml(void);

    QString contentsHtml(const QString &pPath) const;
    QStringList folderHtml(const QString &pPath) const;
    QStringList workspaceHtml(const QString &pUrl, const QString &pName, const QString &pPath) const;






Q_SIGNALS:
    void warning(const QString &pMessage);

public Q_SLOTS:
    void clearWorkspaces(void);
    void initialiseWorkspaces(const PMRSupport::PmrWorkspaceList &pWorkspaces);
    void refreshWorkspaces(const bool &pScanFolders);

private Q_SLOTS:
    void linkClicked();
    void linkHovered();

    void workspaceCloned(PMRSupport::PmrWorkspace *pWorkspace);
    void workspaceCreated(const QString &pUrl);
};

//==============================================================================

}   // namespace PMRWorkspaces
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
