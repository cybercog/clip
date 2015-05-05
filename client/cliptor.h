#ifndef CLIPTOR_H
#define CLIPTOR_H

#include <QWidget>
#include <QStringList>
#include <QList>

class QSystemTrayIcon;
class QMenu;

namespace Ui {
class Cliptor;
}

class Cliptor : public QWidget
{
    Q_OBJECT

public:
    explicit Cliptor(QWidget *parent = 0);
    ~Cliptor();

private slots:
    void clipboardChanged();
    void quitApplication();

private:
    Ui::Cliptor *ui;
    QSystemTrayIcon *tray;
    QMenu   *trayMenu;

    QList<QAction *> clipboardActionList;

    int clipboardActionListCount;
    int clipboardActionListPos;
};

#endif // CLIPTOR_H
