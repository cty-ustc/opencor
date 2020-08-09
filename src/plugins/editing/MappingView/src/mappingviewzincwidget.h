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
// Mapping Zinc widget
//==============================================================================

#pragma once

//==============================================================================

#include <QFile>
#include <QStandardItemModel>

//==============================================================================

#include "zincwidget.h"

//==============================================================================

#include "zincbegin.h"
    #include "opencmiss/zinc/fieldfiniteelement.hpp"
    #include "opencmiss/zinc/timekeeper.hpp"
    #include "opencmiss/zinc/scenepicker.hpp"
#include "zincend.h"

//==============================================================================

namespace OpenCOR {
namespace MappingView {

//==============================================================================

class MappingViewEditingWidget;

//==============================================================================

class MappingViewZincWidget : public ZincWidget::ZincWidget
{
    Q_OBJECT

public:
    explicit MappingViewZincWidget(QWidget *pParent, const QString &pMainFileName,
                                   MappingViewEditingWidget *pEditingWidget);

    ~MappingViewZincWidget() override;

    void changeSource(const QString &pMainFileName);

    static constexpr double nodeSizeOrigin = 20.;

public slots:
    //TODO keep slot here or manage signal through parent class ?
    void setNodeSizes(int pSize);

protected:
    void initializeGL() override;

    void mouseMoveEvent(QMouseEvent *pEvent) override;
    void mousePressEvent(QMouseEvent *pEvent) override;
    void mouseReleaseEvent(QMouseEvent *pEvent) override;
    void wheelEvent(QWheelEvent *pEvent) override;

//  void changeEvent(QEvent *pEvent) override;
    void dragEnterEvent(QDragEnterEvent *pEvent) override;
    void dragMoveEvent(QDragMoveEvent *pEvent) override;
    void dropEvent(QDropEvent *pEvent) override;

private:

    QString mMainFileName;
    QString mAuxFileName;

    MappingViewEditingWidget *mEditingWidget;

    QPoint mMousePosClick;

    double mNodeSize;

    char *mZincSceneViewerDescription;

    //size of the square drawn around the mouse for selections
    //TODO improve this, should depend on the number of pixel at screen
    int mSizeSelection = 2;
    int mIdSelectedNode = -1;

    OpenCMISS::Zinc::Fieldmodule mFieldModule;
    OpenCMISS::Zinc::Context *mZincContext;
    OpenCMISS::Zinc::Scene *mScene;
    OpenCMISS::Zinc::Region *mRegion;
    OpenCMISS::Zinc::Scenepicker *mScenePicker;

    void initAuxFile();
    void setup();
    void draw();

    void click(int pX, int pY);

};

//==============================================================================

} // namespace ZincWidget
} // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
