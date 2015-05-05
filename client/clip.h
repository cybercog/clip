#ifndef CLIP_H
#define CLIP_H

#include <QWidget>
#include <QStringList>
#include <QList>

class QSystemTrayIcon;
class QMenu;

namespace Ui {
    class Clip;
}


class Clip : public QWidget
{
    Q_OBJECT

public:
    explicit Clip(QWidget *parent = 0);
    ~Clip();

private slots:
    void clipboardChanged();
    void quitApplication();
    void pasteToClipboard();

private:
    Ui::Clip *ui;
    QSystemTrayIcon *tray;
    QMenu   *trayMenu;

    QList<QAction *> clipboardActionList;

    int clipboardActionListCount;
    int clipboardActionListPos;
    bool pasting;
};

#endif // CLIP_H
