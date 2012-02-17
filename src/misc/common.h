//==============================================================================
// Some common methods between the command line and GUI version of OpenCOR
//==============================================================================

#ifndef COMMON_H
#define COMMON_H

//==============================================================================

#include <QString>

//==============================================================================

class QCoreApplication;

//==============================================================================

namespace OpenCOR {

//==============================================================================

static const QString OpencorHomepageUrl = "http://www.opencor.ws/";

void error(QCoreApplication *pApp, const QString &pMsg);

void initApplication(QCoreApplication *pApp);

bool consoleApplication(QCoreApplication *pApp, int *pRes);

//==============================================================================

}   // namespace OpenCOR

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
