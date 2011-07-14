#include "preferenceswindow.h"

#include "ui_preferenceswindow.h"

namespace OpenCOR {

PreferencesWindow::PreferencesWindow(QWidget *pParent) :
    QDialog(pParent),
    mUi(new Ui::PreferencesWindow)
{
    // Set up the UI

    mUi->setupUi(this);
}

PreferencesWindow::~PreferencesWindow()
{
    // Delete the UI

    delete mUi;
}

void PreferencesWindow::retranslateUi()
{
    // Retranslate the whole window

    mUi->retranslateUi(this);
}

}
