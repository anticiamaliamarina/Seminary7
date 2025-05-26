#pragma once
#include "Observer.h"
#include <QWidget>
#include "user.h"
#include "chatSession.h"
#include <qlistwidget.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qlineedit.h>
#include <qstring.h>
#include <qpushbutton.h>

class ChatWindow : public QWidget, public Observer {
    Q_OBJECT

    User& user;
    ChatSession& chatSession;
    QListWidget* list;
    QPushButton* send;
    QLineEdit* writeMessage;

    void update() override; 

public:
    ChatWindow(User& user, ChatSession& chatSession);

private slots:
    void handleSendMessage();
};