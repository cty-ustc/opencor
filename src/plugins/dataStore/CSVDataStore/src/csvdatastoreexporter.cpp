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
// CSV data store exporter class
//==============================================================================

#include "corecliutils.h"
#include "coreguiutils.h"
#include "csvdatastoreexporter.h"

//==============================================================================

#include <QCoreApplication>

//==============================================================================

namespace OpenCOR {
namespace CSVDataStore {

//==============================================================================

CsvDataStoreExporter::CsvDataStoreExporter(const QString &pFileName,
                                           DataStore::DataStore *pDataStore) :
    DataStore::DataStoreExporter(pFileName, pDataStore)
{
}

//==============================================================================

void CsvDataStoreExporter::execute() const
{
    // Export the given data store to a CSV file

    QString csvFilter = QObject::tr("CSV File")+" (*.csv)";
    QString fileName = Core::getSaveFileName(QObject::tr("Export To CSV"),
                                             Core::newFileName(mFileName, QObject::tr("Data"), false, "csv"),
                                             QStringList() << csvFilter,
                                             &csvFilter);

    if (!fileName.isEmpty()) {
        // Header

        static const QString Header = "%1 (%2)";

        DataStore::DataStoreVariable *voi = mDataStore->voi();
        DataStore::DataStoreVariables variables = mDataStore->variables();

        QByteArray data = QByteArray();

        data += Header.arg(voi->uri().replace("/prime", "'").replace("/", " | "),
                           voi->unit());

        auto variableBegin = variables.constBegin();
        auto variableEnd = variables.constEnd();

        for (auto variable = variableBegin; variable != variableEnd; ++variable) {
            if ((*variable)->isValid()) {
                data += ","+Header.arg((*variable)->uri().replace("/prime", "'").replace("/", " | "),
                                       (*variable)->unit());
            }
        }

        data += "\n";

        // Data itself

        for (qulonglong i = 0; i < mDataStore->size(); ++i) {
            data += QString::number(voi->value(i));

            for (auto variable = variableBegin; variable != variableEnd; ++variable) {
                if ((*variable)->isValid())
                    data += ","+QString::number((*variable)->value(i));
            }

            data += "\n";
        }

        // The data is ready, so write it to the file

        Core::writeFileContentsToFile(fileName, data);
    }
}

//==============================================================================

}   // namespace CSVDataStore
}   // namespace OpenCOR

//==============================================================================
// End of file
//==============================================================================
