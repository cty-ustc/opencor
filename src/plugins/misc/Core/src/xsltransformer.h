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
// XSL transformation
//==============================================================================

#ifndef XSLTRANSFORMER_H
#define XSLTRANSFORMER_H

//==============================================================================

#include "coreglobal.h"

//==============================================================================

#include <QList>
#include <QObject>
#include <QString>
#include <QWaitCondition>

//==============================================================================

namespace OpenCOR {
namespace Core {

//==============================================================================

class DummyMessageHandler;

//==============================================================================

class XslTransformerJob
{
public:
    explicit XslTransformerJob(const QString &pInput, const QString &pXsl);

    QString input() const;
    QString xsl() const;

private:
    QString mInput;
    QString mXsl;
};

//==============================================================================

class CORE_EXPORT XslTransformer : public QObject
{
    Q_OBJECT

public:
    explicit XslTransformer();
    ~XslTransformer();

    void transform(const QString &pInput, const QString &pXsl);

private:
    QThread *mThread;

    bool mPaused;
    bool mStopped;

    QWaitCondition mPausedCondition;

    QList<XslTransformerJob *> mJobs;

Q_SIGNALS:
    void done(const QString &pInput, const QString &pOutput);

private Q_SLOTS:
    void started();
};

//==============================================================================

}   // namespace Core
}   // namespace OpenCOR

//==============================================================================

#endif

//==============================================================================
// End of file
//==============================================================================
