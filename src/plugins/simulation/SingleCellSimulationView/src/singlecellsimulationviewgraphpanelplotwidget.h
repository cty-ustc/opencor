//==============================================================================
// Single cell simulation view graph panel plot widget
//==============================================================================

#ifndef SINGLECELLSIMULATIONVIEWGRAPHPANELPLOTWIDGET_H
#define SINGLECELLSIMULATIONVIEWGRAPHPANELPLOTWIDGET_H

//==============================================================================

#include "qwt_plot.h"

//==============================================================================

class QwtPlotCurve;
class QwtPlotDirectPainter;

//==============================================================================

namespace OpenCOR {
namespace SingleCellSimulationView {

//==============================================================================

class SingleCellSimulationViewGraphPanelPlotWidget : public QwtPlot
{
    Q_OBJECT

public:
    enum Axis {
        AxisX,
        AxisY
    };

    explicit SingleCellSimulationViewGraphPanelPlotWidget(QWidget *pParent = 0);
    ~SingleCellSimulationViewGraphPanelPlotWidget();

    void replotNow();

    QwtPlotCurve * addCurve(double *pX, double *pY,
                            const qulonglong &pOriginalSize);

    void removeCurve(QwtPlotCurve *pCurve, const bool &pReplot = true);
    void removeCurves();

    void drawCurveSegment(QwtPlotCurve *pCurve,
                          const qulonglong &pFrom, const qulonglong &pTo);

    void setFixedAxisScale(const Axis &pAxis,
                           const double &pMin = 0.0, const double &pMax = 0.0);

    void setInteractive(const bool &pInteractive);

protected:
    virtual bool eventFilter(QObject *pObject, QEvent *pEvent);
    virtual void mouseMoveEvent(QMouseEvent *pEvent);
    virtual void mousePressEvent(QMouseEvent *pEvent);
    virtual void mouseReleaseEvent(QMouseEvent *pEvent);
    virtual void wheelEvent(QWheelEvent *pEvent);

private:
    enum Action {
        None,
        Zoom
    };

    QwtPlotDirectPainter *mDirectPainter;

    QList<QwtPlotCurve *> mCurves;

    Action mAction;

    QPoint mOriginPoint;

    double mMinFixedScaleX;
    double mMaxFixedScaleX;

    double mMinFixedScaleY;
    double mMaxFixedScaleY;

    bool mInteractive;

    void handleMouseDoubleClickEvent(QMouseEvent *pEvent);

    void setAxesScales(const double &pMinX, const double &pMaxX,
                       const double &pMinY, const double &pMaxY,
                       const bool &pCanReplot = true);
    void resetAxesScales();
    void scaleAxesScales(const double &pScalingFactorX,
                         const double &pScalingFactorY);
    void checkAxesScales(const bool &pCanReplot = true);
};

//==============================================================================

}   // namespace SingleCellSimulationView
}   // namespace OpenCOR

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
