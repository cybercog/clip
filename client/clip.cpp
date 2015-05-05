#include "clip.h"
#include "ui_clip.h"
#include <QClipboard>
#include <QTimer>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMimeData>

Clip::Clip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clip),
    clipboardActionListCount(10),
    clipboardActionListPos(0),
    pasting(false)
{
    ui->setupUi(this);
    qApp->setQuitOnLastWindowClosed(false);
    hide();

    //menu and actions
    trayMenu = new QMenu(this);

    for (int i = 0; i<clipboardActionListCount; i++) {
        QAction *action = new QAction("       -       ", this);
        action->setProperty("mimeData", "-");
        clipboardActionList.append(action);
        trayMenu->addAction(action);
        connect(action, SIGNAL(triggered()),
                    this, SLOT(pasteToClipboard()));
    }
    trayMenu->addSeparator();

    QAction *quitAction = new QAction(tr("Quit"), this);
    trayMenu->addAction(quitAction);

    connect(quitAction, SIGNAL(triggered()),
                this, SLOT(quitApplication()));

    //system tray icon
    QSystemTrayIcon *tray = new QSystemTrayIcon(this);
    tray->setIcon(QIcon(":/img/assets/clipboard-icon.png"));
    tray->show();
    tray->setContextMenu(trayMenu);

    //start listen clipboard
    connect(QApplication::clipboard(), SIGNAL(dataChanged()),
                this, SLOT(clipboardChanged()));
}

void Clip::clipboardChanged()
{
    if (pasting) {
        return;
    }
    QString text = QApplication::clipboard()->text();
    QString truncated = text;
    truncated.truncate(12);
    truncated = truncated.append("...");
    const QMimeData *mimeData = QApplication::clipboard()->mimeData();

    if (mimeData->hasText()) {
        QAction *action = clipboardActionList.at(clipboardActionListPos);

        action->setText(truncated);
        action->setProperty("mimeData", "text/plain");
        action->setProperty("fullText", text);

        qDebug() << text << mimeData->hasText();
    }

    if (clipboardActionListPos < clipboardActionListCount-1) {
        clipboardActionListPos++;
    } else {
        clipboardActionListPos = 0;
    }

//    // we need to ignore every other dataChanged() signal because
//    // those signals are triggered by us calling QClipboard::setText()
//    static bool ignoreSignal = false;

//    if (ignoreSignal == false) {
//        clipboardText = QApplication::clipboard()->text();

//        // will trigger another dataChanged() signal
//        // (after our method exits)
//        QTimer::singleShot(50, this, SLOT(setClipboard()));

//        // ignore the next dataChanged() signal
//        ignoreSignal = true;
//    }
//    else {
//        // We're ignoring this signal. Don't ignore the next signal.
//        ignoreSignal = false;
     //    }
}

void Clip::quitApplication()
{
    qApp->quit();
}

void Clip::pasteToClipboard()
{
    pasting = true;
    QAction *action = (QAction *)sender();

    QApplication::clipboard()->setText(action->property("fullText").toString ());

    pasting = false;
}

Clip::~Clip()
{
    delete ui;
}
