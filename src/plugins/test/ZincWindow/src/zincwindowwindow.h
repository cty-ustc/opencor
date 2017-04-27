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
// Zinc window
//==============================================================================

#pragma once

//==============================================================================

#include "windowwidget.h"

//==============================================================================

namespace Ui {
    class ZincWindowWindow;
}

//==============================================================================

namespace OpenCMISS {
namespace Zinc {
    class Context;
}   // namespace Zinc
}   // namespace OpenCMISS

//==============================================================================

namespace OpenCOR {

//==============================================================================

namespace ZincWidget {
    class ZincWidget;
}   // namespace ZincWidget

//==============================================================================

namespace ZincWindow {

//==============================================================================

class ZincWindowWidget;

//==============================================================================

class ZincWindowWindow : public Core::WindowWidget
{
    Q_OBJECT

public:
    explicit ZincWindowWindow(QWidget *pParent);
    ~ZincWindowWindow();

    virtual void retranslateUi();

private:
    Ui::ZincWindowWindow *mGui;

    ZincWidget::ZincWidget *mZincWidget;
    OpenCMISS::Zinc::Context *mZincContext;

    char *mZincSceneViewerDescription;

    int mAxesFontPointSize;

private slots:
    void createAndSetZincContext();
    void graphicsInitialized();
    void devicePixelRatioChanged(const int &pDevicePixelRatio);
};

//==============================================================================

}   // namespace ZincWindow
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================