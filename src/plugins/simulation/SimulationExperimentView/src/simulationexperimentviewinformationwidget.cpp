/*******************************************************************************

Copyright (C) The University of Auckland

OpenCOR is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenCOR is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*******************************************************************************/

//==============================================================================
// Simulation Experiment view information widget
//==============================================================================

#include "collapsiblewidget.h"
#include "i18ninterface.h"
#include "simulationexperimentviewinformationgraphpanelandgraphswidget.h"
#include "simulationexperimentviewinformationparameterswidget.h"
#include "simulationexperimentviewinformationsimulationwidget.h"
#include "simulationexperimentviewinformationsolverswidget.h"
#include "simulationexperimentviewinformationwidget.h"

//==============================================================================

#include <QMenu>
#include <QSettings>
#include <QVBoxLayout>

//==============================================================================

namespace OpenCOR {
namespace SimulationExperimentView {

//==============================================================================

SimulationExperimentViewInformationWidget::SimulationExperimentViewInformationWidget(SimulationExperimentViewWidget *pViewWidget,
                                                                                     SimulationExperimentViewSimulationWidget *pSimulationWidget,
                                                                                     QWidget *pParent) :
    QScrollArea(pParent),
    Core::CommonWidget(this)
{
    // Create and set our vertical layout

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->setContentsMargins(QMargins());
    layout->setSpacing(0);

    setLayout(layout);

    // Remove the frame around our scroll area

    setFrameShape(QFrame::NoFrame);

    // Create our collapsible widget

    mCollapsibleWidget = new Core::CollapsibleWidget(this);

    mCollapsibleWidget->setObjectName("Collapsible");

    // Create our simulation widget

    mSimulationWidget = new SimulationExperimentViewInformationSimulationWidget(mCollapsibleWidget);

    mSimulationWidget->setObjectName("Simulation");

    // Create our solvers widget

    mSolversWidget = new SimulationExperimentViewInformationSolversWidget(mCollapsibleWidget);

    mSolversWidget->setObjectName("Solvers");

    // Create our graph panel and graphs widget

    mGraphPanelAndGraphsWidget = new SimulationExperimentViewInformationGraphPanelAndGraphsWidget(pViewWidget, pSimulationWidget, mCollapsibleWidget);

    mGraphPanelAndGraphsWidget->setObjectName("GraphPanelAndGraphs");

    // Create our parameters widget

    mParametersWidget = new SimulationExperimentViewInformationParametersWidget(mCollapsibleWidget);

    mParametersWidget->setObjectName("Parameters");

    // Add our simulation, solvers, graphs and parameters widgets to our
    // collapsible widget

                                                      mCollapsibleWidget->addWidget(mSimulationWidget);
                                                      mCollapsibleWidget->addWidget(mSolversWidget);
    Core::CollapsibleHeaderWidget *graphPanelHeader = mCollapsibleWidget->addWidget(mGraphPanelAndGraphsWidget);
                                                      mCollapsibleWidget->addWidget(mParametersWidget, false);

    // Create and set a menu for our graph panel header

    QMenu *menu = new QMenu(this);

    mGraphPanelAction = Core::newAction(true, graphPanelHeader);
    mGraphsAction = Core::newAction(true, graphPanelHeader);

    mGraphsAction->setChecked(true);

    QActionGroup *settingsActionGroup = new QActionGroup(this);

    settingsActionGroup->addAction(mGraphPanelAction);
    settingsActionGroup->addAction(mGraphsAction);

    menu->addActions(settingsActionGroup->actions());

    graphPanelHeader->setMenu(menu);

    connect(mGraphPanelAction, SIGNAL(triggered(bool)),
            this, SLOT(grapPanelPropertyEditor()));
    connect(mGraphsAction, SIGNAL(triggered(bool)),
            this, SLOT(graphsPropertyEditor()));

    // Add our collapsible widget to our layout

    layout->addWidget(mCollapsibleWidget);
}

//==============================================================================

void SimulationExperimentViewInformationWidget::retranslateUi()
{
    // Retranslate the different titles of our collapsible widget

    mCollapsibleWidget->setHeaderTitle(0, tr("Simulation"));
    mCollapsibleWidget->setHeaderTitle(1, tr("Solvers"));
    mCollapsibleWidget->setHeaderTitle(2, mGraphPanelAction->isChecked()?
                                              tr("Graph Panel"):
                                              tr("Graphs"));
    mCollapsibleWidget->setHeaderTitle(3, tr("Parameters"));

    // Retranslate our simulation, solvers, graphs and parameters widgets

    mSimulationWidget->retranslateUi();
    mSolversWidget->retranslateUi();
    mGraphPanelAndGraphsWidget->retranslateUi();
    mParametersWidget->retranslateUi();

    // Retranslate our graph panel actions

    I18nInterface::retranslateAction(mGraphPanelAction, tr("Graph Panel"),
                                     tr("Graph panel settings"));
    I18nInterface::retranslateAction(mGraphsAction, tr("Graphs"),
                                     tr("Graphs settings"));
}

//==============================================================================

Core::CollapsibleWidget * SimulationExperimentViewInformationWidget::collapsibleWidget() const
{
    // Return our collapsible widget

    return mCollapsibleWidget;
}

//==============================================================================

SimulationExperimentViewInformationSimulationWidget * SimulationExperimentViewInformationWidget::simulationWidget() const
{
    // Return our simulation widget

    return mSimulationWidget;
}

//==============================================================================

SimulationExperimentViewInformationSolversWidget * SimulationExperimentViewInformationWidget::solversWidget() const
{
    // Return our solvers widget

    return mSolversWidget;
}

//==============================================================================

SimulationExperimentViewInformationGraphPanelAndGraphsWidget * SimulationExperimentViewInformationWidget::graphPanelAndGraphsWidget() const
{
    // Return our graph panel and graphs widget

    return mGraphPanelAndGraphsWidget;
}

//==============================================================================

SimulationExperimentViewInformationParametersWidget * SimulationExperimentViewInformationWidget::parametersWidget() const
{
    // Return our parameters widget

    return mParametersWidget;
}

//==============================================================================

void SimulationExperimentViewInformationWidget::finishEditing(const bool &pPausedSimulation)
{
    // Finish the editing of any of the information we support
    // Note: when a simulation is paused, the simulation and solvers widgets are
    //       disabled, so no editing to finish...

    if (!pPausedSimulation) {
        mSimulationWidget->finishEditing();
        mSolversWidget->finishEditing();
    }

    mGraphPanelAndGraphsWidget->finishEditing();
    mParametersWidget->finishEditing();
}

//==============================================================================

void SimulationExperimentViewInformationWidget::grapPanelPropertyEditor()
{
    // Update the title of our collapsible widget's third header's title by
    // retranslating ourselves

    retranslateUi();
}

//==============================================================================

void SimulationExperimentViewInformationWidget::graphsPropertyEditor()
{
    // Update the title of our collapsible widget's third header's title by
    // retranslating ourselves

    retranslateUi();
}

//==============================================================================

}   // namespace SimulationExperimentView
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
