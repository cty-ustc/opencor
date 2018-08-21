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
// SED-ML support
//==============================================================================

#pragma once

//==============================================================================

#include "sedmlsupportglobal.h"

//==============================================================================

#include <QString>

//==============================================================================

#include "qwtbegin.h"
    #include "qwt_symbol.h"
#include "qwtend.h"

//==============================================================================

namespace OpenCOR {
namespace SEDMLSupport {

//==============================================================================

QStringList SEDMLSUPPORT_EXPORT lineStyles();

int SEDMLSUPPORT_EXPORT lineStyleIntegerValue(const QString &pLineStyleValue);
QString SEDMLSUPPORT_EXPORT lineStyleStringValue(int pLineStyleValueIndex);
QString SEDMLSUPPORT_EXPORT lineStyleStringValue(Qt::PenStyle pLineStyle);

QStringList SEDMLSUPPORT_EXPORT symbolStyles();

int SEDMLSUPPORT_EXPORT symbolStyleIntegerValue(const QString &pSymbolStyleValue);
QString SEDMLSUPPORT_EXPORT symbolStyleStringValue(int pSymbolStyleValueIndex);
QString SEDMLSUPPORT_EXPORT symbolStyleStringValue(QwtSymbol::Style pSymbolStyle);

//==============================================================================

}   // namespace SEDMLSupport
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
