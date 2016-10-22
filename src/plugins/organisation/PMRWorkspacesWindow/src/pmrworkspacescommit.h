/*******************************************************************************

Copyright The University of Auckland

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*******************************************************************************/

//==============================================================================
// A PMR workspace commit dialog
//==============================================================================

#pragma once

//==============================================================================

#include <QDialog>
#include <QStringList>

//==============================================================================

namespace Ui {
    class PmrWorkspacesCommit;
}

//==============================================================================

namespace OpenCOR {
namespace PMRWorkspaces {

//==============================================================================

class PmrWorkspacesCommit : public QDialog
{
    Q_OBJECT

public:
    explicit PmrWorkspacesCommit(const QStringList &pStagedFiles, QWidget * pParent=0);
    ~PmrWorkspacesCommit();

    virtual void retranslateUi();

    const QString message() const;

private:
    Ui::PmrWorkspacesCommit *mGui;
};

//==============================================================================

}   // namespace PMRWorkspaces
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
