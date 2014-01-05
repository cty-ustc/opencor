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
// CoreEditing plugin
//==============================================================================

#include "coreeditingplugin.h"
#include "editinginterface.h"
#include "guiutils.h"

//==============================================================================

#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QMainWindow>
#include <QMenu>

//==============================================================================

namespace OpenCOR {
namespace CoreEditing {

//==============================================================================

PLUGININFO_FUNC CoreEditingPluginInfo()
{
    Descriptions descriptions;

    descriptions.insert("en", QString::fromUtf8("the core editing plugin."));
    descriptions.insert("fr", QString::fromUtf8("l'extension d'édition de base."));

    return new PluginInfo(PluginInfo::Editing,
                          QStringList() << "QScintillaSupport",
                          descriptions);
}

//==============================================================================

CoreEditingPlugin::CoreEditingPlugin() :
    mEditor(0)
{
}

//==============================================================================
// Core interface
//==============================================================================

void CoreEditingPlugin::initialize()
{
    // Create our different File|New actions

    mFileNewFileAction = newAction(mMainWindow, false,
                                   ":/oxygen/actions/document-new.png",
                                   QKeySequence::New);

    // Create our Edit menu

    mEditMenu = newMenu(mMainWindow, EditGroup);

    // Create our different Edit actions, and add them to our Edit menu

    mEditUndoAction = newAction(mMainWindow, false,
                                ":/oxygen/actions/edit-undo.png",
                                QKeySequence::Undo);
    mEditRedoAction = newAction(mMainWindow, false,
                                ":/oxygen/actions/edit-redo.png",
                                QKeySequence::Redo);

    mEditCutAction    = newAction(mMainWindow, false,
                                  ":/oxygen/actions/edit-cut.png",
                                  QKeySequence::Cut);
    mEditCopyAction   = newAction(mMainWindow, false,
                                  ":/oxygen/actions/edit-copy.png",
                                  QKeySequence::Copy);
    mEditPasteAction  = newAction(mMainWindow, false,
                                  ":/oxygen/actions/edit-paste.png",
                                  QKeySequence::Paste);
    mEditDeleteAction = newAction(mMainWindow, false,
                                  ":/oxygen/actions/edit-delete.png",
                                  QKeySequence::Delete);

    mEditFindAction     = newAction(mMainWindow, false,
                                    ":/oxygen/actions/edit-find.png",
                                    QKeySequence::Find);
    mEditFindNextAction = newAction(mMainWindow, false, "",
                                    QKeySequence::FindNext);
    mEditPreviousAction = newAction(mMainWindow, false, "",
                                    QKeySequence::FindPrevious);
    mEditReplaceAction  = newAction(mMainWindow, false, "",
                                    QKeySequence::Replace);

    mEditSelectAllAction = newAction(mMainWindow, false, "",
                                     QKeySequence::SelectAll);

    mEditMenu->addAction(mEditUndoAction);
    mEditMenu->addAction(mEditRedoAction);
    mEditMenu->addSeparator();
    mEditMenu->addAction(mEditCutAction);
    mEditMenu->addAction(mEditCopyAction);
    mEditMenu->addAction(mEditPasteAction);
    mEditMenu->addAction(mEditDeleteAction);
/*---GRY---
    mEditMenu->addSeparator();
    mEditMenu->addAction(mEditFindAction);
    mEditMenu->addAction(mEditFindNextAction);
    mEditMenu->addAction(mEditPreviousAction);
    mEditMenu->addAction(mEditReplaceAction);
*/
    mEditMenu->addSeparator();
    mEditMenu->addAction(mEditSelectAllAction);

    // Set our settings

    mGuiSettings->addMenuAction(GuiMenuActionSettings::FileNew, mFileNewFileAction);

    mGuiSettings->addMenu(GuiMenuSettings::View, mEditMenu);

    // Keep track of changes to the clipboard

    connect(QApplication::clipboard(), SIGNAL(dataChanged()),
            this, SLOT(clipboardDataChanged()));
}

//==============================================================================

void CoreEditingPlugin::finalize()
{
    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::initialized(const Plugins &pLoadedPlugins)
{
    Q_UNUSED(pLoadedPlugins);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::loadSettings(QSettings *pSettings)
{
    Q_UNUSED(pSettings);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::saveSettings(QSettings *pSettings) const
{
    Q_UNUSED(pSettings);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::settingsLoaded(const Plugins &pLoadedPlugins)
{
    Q_UNUSED(pLoadedPlugins);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::handleArguments(const QStringList &pArguments)
{
    Q_UNUSED(pArguments);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::handleAction(const QUrl &pUrl)
{
    Q_UNUSED(pUrl);

    // We don't handle this interface...
}

//==============================================================================
// GUI interface
//==============================================================================

void CoreEditingPlugin::changeEvent(QEvent *pEvent)
{
    Q_UNUSED(pEvent);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::updateGui(Plugin *pViewPlugin, const QString &pFileName)
{
    Q_UNUSED(pFileName);

    // Show/enable or hide/disable various actions, depending on whether the
    // view plugin handles the editing interface

    EditingInterface *editingInterface = qobject_cast<EditingInterface *>(pViewPlugin->instance());

    Core::showEnableAction(mFileNewFileAction, editingInterface);

    Core::showEnableAction(mEditUndoAction, editingInterface);
    Core::showEnableAction(mEditRedoAction, editingInterface);

    Core::showEnableAction(mEditCutAction, editingInterface);
    Core::showEnableAction(mEditCopyAction, editingInterface);
    Core::showEnableAction(mEditPasteAction, editingInterface);
    Core::showEnableAction(mEditDeleteAction, editingInterface);

/*---GRY---
    Core::showEnableAction(mEditFindAction, editingInterface);
    Core::showEnableAction(mEditFindNextAction, editingInterface);
    Core::showEnableAction(mEditPreviousAction, editingInterface);
    Core::showEnableAction(mEditReplaceAction, editingInterface);
*/

    Core::showEnableAction(mEditSelectAllAction, editingInterface);

    // Reset our previous editor

    if (mEditor) {
        disconnect(mEditor, SIGNAL(canUndo(const bool &)),
                   mEditUndoAction, SLOT(setEnabled(bool)));
        disconnect(mEditor, SIGNAL(canRedo(const bool &)),
                   mEditRedoAction, SLOT(setEnabled(bool)));

        disconnect(mEditor, SIGNAL(copyAvailable(bool)),
                   mEditCutAction, SLOT(setEnabled(bool)));
        disconnect(mEditor, SIGNAL(copyAvailable(bool)),
                   mEditCopyAction, SLOT(setEnabled(bool)));
        disconnect(mEditor, SIGNAL(copyAvailable(bool)),
                   mEditDeleteAction, SLOT(setEnabled(bool)));

        disconnect(mEditUndoAction, SIGNAL(triggered()),
                   this, SLOT(doUndo()));
        disconnect(mEditRedoAction, SIGNAL(triggered()),
                   this, SLOT(doRedo()));

        disconnect(mEditCutAction, SIGNAL(triggered()),
                   mEditor, SLOT(cut()));
        disconnect(mEditCopyAction, SIGNAL(triggered()),
                   mEditor, SLOT(copy()));
        disconnect(mEditPasteAction, SIGNAL(triggered()),
                   mEditor, SLOT(paste()));
        disconnect(mEditDeleteAction, SIGNAL(triggered()),
                   mEditor, SLOT(delete_selection()));
    }

    // Set up our new editor

    mEditor = editingInterface?editingInterface->editor(pFileName):0;

    if (mEditor) {
        mEditor->setContextMenu(mEditMenu->actions());

        connect(mEditor, SIGNAL(canUndo(const bool &)),
                mEditUndoAction, SLOT(setEnabled(bool)));
        connect(mEditor, SIGNAL(canRedo(const bool &)),
                mEditRedoAction, SLOT(setEnabled(bool)));

        connect(mEditor, SIGNAL(copyAvailable(bool)),
                mEditCutAction, SLOT(setEnabled(bool)));
        connect(mEditor, SIGNAL(copyAvailable(bool)),
                mEditCopyAction, SLOT(setEnabled(bool)));
        connect(mEditor, SIGNAL(copyAvailable(bool)),
                mEditDeleteAction, SLOT(setEnabled(bool)));

        connect(mEditUndoAction, SIGNAL(triggered()),
                this, SLOT(doUndo()));
        connect(mEditRedoAction, SIGNAL(triggered()),
                this, SLOT(doRedo()));

        connect(mEditCutAction, SIGNAL(triggered()),
                mEditor, SLOT(cut()));
        connect(mEditCopyAction, SIGNAL(triggered()),
                mEditor, SLOT(copy()));
        connect(mEditPasteAction, SIGNAL(triggered()),
                mEditor, SLOT(paste()));
        connect(mEditDeleteAction, SIGNAL(triggered()),
                mEditor, SLOT(delete_selection()));

        updateUndoRedoActions();

        mEditCutAction->setEnabled(mEditor->hasSelectedText());
        mEditCopyAction->setEnabled(mEditor->hasSelectedText());
        clipboardDataChanged();
        mEditDeleteAction->setEnabled(mEditor->hasSelectedText());
    } else {
        mEditUndoAction->setEnabled(false);
        mEditRedoAction->setEnabled(false);

        mEditCutAction->setEnabled(false);
        mEditCopyAction->setEnabled(false);
        mEditPasteAction->setEnabled(false);
        mEditDeleteAction->setEnabled(false);

/*---GRY---
        mEditFindAction->setEnabled(false);
        mEditFindNextAction->setEnabled(false);
        mEditPreviousAction->setEnabled(false);
        mEditReplaceAction->setEnabled(false);
*/

        mEditSelectAllAction->setEnabled(false);
    }
}

//==============================================================================

void CoreEditingPlugin::initializeView()
{
    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::finalizeView()
{
    // We don't handle this interface...
}

//==============================================================================

bool CoreEditingPlugin::hasViewWidget(const QString &pFileName)
{
    Q_UNUSED(pFileName);

    // We don't handle this interface...

    return false;
}

//==============================================================================

QWidget * CoreEditingPlugin::viewWidget(const QString &pFileName,
                                        const bool &pCreate)
{
    Q_UNUSED(pFileName);
    Q_UNUSED(pCreate);

    // We don't handle this interface...

    return 0;
}

//==============================================================================

void CoreEditingPlugin::removeViewWidget(const QString &pFileName)
{
    Q_UNUSED(pFileName);

    // We don't handle this interface...
}

//==============================================================================

QString CoreEditingPlugin::viewName() const
{
    // We don't handle this interface...

    return QString();
}

//==============================================================================

QIcon CoreEditingPlugin::fileTabIcon(const QString &pFileName) const
{
    Q_UNUSED(pFileName);

    // We don't handle this interface...

    return QIcon();
}

//==============================================================================

bool CoreEditingPlugin::saveFile(const QString &pOldFileName,
                                 const QString &pNewFileName)
{
    Q_UNUSED(pOldFileName);
    Q_UNUSED(pNewFileName);

    // We don't handle this interface...

    return false;
}

//==============================================================================

void CoreEditingPlugin::fileOpened(const QString &pFileName)
{
    Q_UNUSED(pFileName);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::fileReloaded(const QString &pFileName)
{
    Q_UNUSED(pFileName);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::fileSaved(const QString &pFileName)
{
    Q_UNUSED(pFileName);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::fileRenamed(const QString &pOldFileName,
                                    const QString &pNewFileName)
{
    Q_UNUSED(pOldFileName);
    Q_UNUSED(pNewFileName);

    // We don't handle this interface...
}

//==============================================================================

void CoreEditingPlugin::fileClosed(const QString &pFileName)
{
    Q_UNUSED(pFileName);

    // We don't handle this interface...
}

//==============================================================================

bool CoreEditingPlugin::canClose()
{
    // We don't handle this interface...

    return true;
}

//==============================================================================
// I18n interface
//==============================================================================

void CoreEditingPlugin::retranslateUi()
{
    // Retranslate our different File|New action

    retranslateAction(mFileNewFileAction, tr("File"),
                      tr("Create a new file"));

    // Retranslate our Edit menu

    retranslateMenu(mEditMenu, tr("Edit"));

    // Retranslate our different Edit actions

    retranslateAction(mEditUndoAction, tr("Undo"),
                      tr("Undo the last action"));
    retranslateAction(mEditRedoAction, tr("Redo"),
                      tr("Redo the last action"));

    retranslateAction(mEditCutAction, tr("Cut"),
                      tr("Cut the selected object"));
    retranslateAction(mEditCopyAction, tr("Copy"),
                      tr("Copy the selected object to the clipboard"));
    retranslateAction(mEditPasteAction, tr("Paste"),
                      tr("Paste the contents of the clipboard"));
    retranslateAction(mEditDeleteAction, tr("Delete"),
                      tr("Delete the selected object"));

    retranslateAction(mEditFindAction, tr("Find..."),
                      tr("Search for a specific object"));
    retranslateAction(mEditFindNextAction, tr("Find Next"),
                      tr("Search forwards for the same object"));
    retranslateAction(mEditPreviousAction, tr("Find Previous"),
                      tr("Search backwards for the same object"));
    retranslateAction(mEditReplaceAction, tr("Replace"),
                      tr("Search for a specific object and replace it with another"));

    retranslateAction(mEditSelectAllAction, tr("Select All"),
                      tr("Select all the objects"));
}

//==============================================================================
// Plugin specific
//==============================================================================

void CoreEditingPlugin::clipboardDataChanged()
{
    // Enable our paste action if the clipboard contains some text

    mEditPasteAction->setEnabled(QApplication::clipboard()->text().size());
}

//==============================================================================

void CoreEditingPlugin::updateUndoRedoActions()
{
    // Update our undo/redo actions

    mEditUndoAction->setEnabled(mEditor->isUndoAvailable());
    mEditRedoAction->setEnabled(mEditor->isRedoAvailable());
}

//==============================================================================

void CoreEditingPlugin::doUndo()
{
    // Undo the last action and update our undo/redo actions

    mEditor->undo();

    updateUndoRedoActions();
}

//==============================================================================

void CoreEditingPlugin::doRedo()
{
    // Redo the last action and update our undo/redo actions

    mEditor->redo();

    updateUndoRedoActions();
}

//==============================================================================

}   // namespace CoreEditing
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
