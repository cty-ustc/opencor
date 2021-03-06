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
// Raw Text view plugin
//==============================================================================

#pragma once

//==============================================================================

#include "editingviewinterface.h"
#include "filehandlinginterface.h"
#include "i18ninterface.h"
#include "plugininfo.h"
#include "plugininterface.h"
#include "viewinterface.h"

//==============================================================================

namespace OpenCOR {
namespace RawTextView {

//==============================================================================

PLUGININFO_FUNC RawTextViewPluginInfo();

//==============================================================================

class RawTextViewWidget;

//==============================================================================

class RawTextViewPlugin : public QObject, public EditingViewInterface,
                          public FileHandlingInterface, public I18nInterface,
                          public PluginInterface, public ViewInterface
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "OpenCOR.RawTextViewPlugin" FILE "rawtextviewplugin.json")

    Q_INTERFACES(OpenCOR::EditingViewInterface)
    Q_INTERFACES(OpenCOR::FileHandlingInterface)
    Q_INTERFACES(OpenCOR::I18nInterface)
    Q_INTERFACES(OpenCOR::PluginInterface)
    Q_INTERFACES(OpenCOR::ViewInterface)

public:
#include "editingviewinterface.inl"
#include "filehandlinginterface.inl"
#include "i18ninterface.inl"
#include "plugininterface.inl"
#include "viewinterface.inl"

private:
    RawTextViewWidget *mViewWidget = nullptr;
};

//==============================================================================

} // namespace RawTextView
} // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
