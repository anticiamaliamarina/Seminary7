#include "ChatWindow.h"
#include <QListWidgetItem>
#include <QDateTime>

ChatWindow::ChatWindow(User& user, ChatSession& chatSession)
    : QWidget(nullptr), user(user), chatSession(chatSession) {

    QVBoxLayout* main = new QVBoxLayout(this);
    list = new QListWidget;
    main->addWidget(list);

    QHBoxLayout* stuff = new QHBoxLayout();
    writeMessage = new QLineEdit();
    writeMessage->setPlaceholderText("Write your message");
    send = new QPushButton("Send");
    connect(send, &QPushButton::clicked, this, &ChatWindow::handleSendMessage);

    stuff->addWidget(writeMessage);
    stuff->addWidget(send);
    main->addLayout(stuff);

    chatSession.registerObserver(this);

    update();
}

void ChatWindow::update() {
    list->clear();
    auto all = chatSession.getAll();
    for (const auto& userMsg : all) {
        QString text = QString::fromStdString(userMsg.getUser().getName() + ": " + userMsg.getMessage().getMessage());
        list->addItem(text);
    }
}

void ChatWindow::handleSendMessage() 
{
    std::string msgText = writeMessage->text().toStdString();
    if (msgText.empty()) return;

    QString timeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    Message* msg = new Message(timeStr.toStdString(), msgText);

    chatSession.addMessage(&user, msg);
    writeMessage->clear();
}