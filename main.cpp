#include "Sem7.h"
#include <QtWidgets/QApplication>
#include <ChatWindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    User user1(1, "Maria");
    User user2(2, "Gabi");

    ChatSession session;
    ChatWindow* mariaWindow = new ChatWindow(user1, session);
    mariaWindow->setWindowTitle("Maria");
    mariaWindow->show();

    ChatWindow* gabiWindow = new ChatWindow(user2, session);
    gabiWindow->setWindowTitle("Gabi");
    gabiWindow->show();

    return a.exec();
}
