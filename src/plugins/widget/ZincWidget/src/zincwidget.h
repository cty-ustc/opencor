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
// Zinc widget
//==============================================================================

#pragma once

//==============================================================================

#include "commonwidget.h"
#include "zincwidgetglobal.h"

//==============================================================================

#include <QOpenGLWidget>

//==============================================================================

#include "opencmiss/zinc/sceneviewer.hpp"
#include "opencmiss/zinc/sceneviewerinput.hpp"

//==============================================================================

namespace OpenCMISS {
namespace Zinc {
    class Context;
}   // namespace Zinc
}   // namespace OpenCMISS

//==============================================================================

namespace OpenCOR {
namespace ZincWidget {

//==============================================================================

class ZincWidget;

//==============================================================================

class ZincWidgetSceneViewerCallback : public OpenCMISS::Zinc::Sceneviewercallback
{
public:
    explicit ZincWidgetSceneViewerCallback(ZincWidget *pZincWidget);

private:
    ZincWidget *mZincWidget;

    virtual void operator()(const OpenCMISS::Zinc::Sceneviewerevent &pSceneViewerEvent);
};

//==============================================================================

class ZINCWIDGET_EXPORT ZincWidget : public QOpenGLWidget,
                                     public Core::CommonWidget
{
    Q_OBJECT

public:
    enum ProjectionMode {
        Invalid,
        Parallel,
        Perspective
    };

    explicit ZincWidget(QWidget *pParent);

    OpenCMISS::Zinc::Context * context() const;
    void setContext(OpenCMISS::Zinc::Context *pContext);

    OpenCMISS::Zinc::Sceneviewer sceneViewer() const;

    ProjectionMode projectionMode();
    void setProjectionMode(const ProjectionMode &pProjectionMode);

    int viewParameters(double *pEye, double *pLookAt, double *pUp,
                       double &pAngle);
    void setViewParameters(double *pEye, double *pLookAt, double *pUp,
                           double &pAngle);

    OpenCMISS::Zinc::Scenefilter sceneFilter();
    void setSceneFilter(const OpenCMISS::Zinc::Scenefilter &pSceneFilter);

    double tumbleRate();
    void setTumbleRate(const double &pTumbleRate);

    int project(double *pInCoordinates, double *pOutCoordinates);
    int unproject(double *pInCoordinates, double *pOutCoordinates);

    void viewAll();

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int pWidth, int pHeight);

    virtual void mouseMoveEvent(QMouseEvent *pEvent);
    virtual void mousePressEvent(QMouseEvent *pEvent);
    virtual void mouseReleaseEvent(QMouseEvent *pEvent);
    virtual void wheelEvent(QWheelEvent *pEvent);

    virtual QSize sizeHint() const;

private:
    bool mGraphicsInitialized;

    int mDevicePixelRatio;

    OpenCMISS::Zinc::Context *mContext;
    OpenCMISS::Zinc::Sceneviewer mSceneViewer;
    OpenCMISS::Zinc::Sceneviewernotifier mSceneViewerNotifier;

    ZincWidgetSceneViewerCallback mZincWidgetSceneViewerCallback;

    void createSceneViewer();

    void updateSceneViewerViewerportSize(const int &pWidth, const int &pHeight,
                                         const bool &pCheckDevicePixelRatio = false);

    OpenCMISS::Zinc::Sceneviewerinput::ButtonType buttonMap(const Qt::MouseButton &pButton) const;
    OpenCMISS::Zinc::Sceneviewerinput::ModifierFlags modifierMap(const Qt::KeyboardModifiers &pModifiers) const;

signals:
    void contextAboutToBeDestroyed();
    void graphicsInitialized();
    void devicePixelRatioChanged(const int &pDevicePixelRatio);
};

//==============================================================================

}   // namespace ZincWidget
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================