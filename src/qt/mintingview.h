#ifndef MINTINGVIEW_H
#define MINTINGVIEW_H

#include <QWidget>
#include <QComboBox>
#include "mintingfilterproxy.h"

class WalletModel;


QT_BEGIN_NAMESPACE
class QTableView;
class QMenu;
QT_END_NAMESPACE

class MintingView : public QWidget
{
    Q_OBJECT
public:
    explicit MintingView(QWidget *parent = 0);
    void setModel(WalletModel *model);

    enum MintingEnum
    {
        Minting1day,
        Minting7days,
        Minting14days,
        Minting30days,
        Minting90days
    };

private:
    WalletModel *model;
    QTableView *mintingView;
    QComboBox *mintingCombo;
    MintingFilterProxy *mintingProxyModel;
    QMenu *contextMenu;

private Q_SLOTS:
    void contextualMenu(const QPoint &);
    void copyAddress();
    void copyTransactionId();

Q_SIGNALS:

public Q_SLOTS:
    void exportClicked();
    void chooseMintingInterval(int idx);
};

#endif // MINTINGVIEW_H
