#ifndef FILEORGANISERWIDGET_H
#define FILEORGANISERWIDGET_H

#include "commonwidget.h"

#include <QTreeView>

class QStandardItem;
class QStandardItemModel;

class FileOrganiserWidget : public QTreeView, public CommonWidget
{
    Q_OBJECT

public:
    explicit FileOrganiserWidget(const QString &pName, QWidget *pParent);

    virtual void loadSettings(QSettings &pSettings);
    virtual void saveSettings(QSettings &pSettings);

    bool newFolder();
    bool deleteItems();

protected:
    virtual QSize sizeHint() const;

    virtual bool viewportEvent(QEvent *pEvent);

private:
    QStandardItemModel *mDataModel;

    void loadItemSettings(QSettings &pSettings, QStandardItem *pParentItem);
    void saveItemSettings(QSettings &pSettings, QStandardItem *pItem,
                          const int &pParentItemIndex);

    QString newFolderName(QStandardItem *pFolderItem);

private slots:
    void resizeToContents();
};

#endif
