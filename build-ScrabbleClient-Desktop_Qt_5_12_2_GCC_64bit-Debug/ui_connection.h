/********************************************************************************
** Form generated from reading UI file 'connection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTION_H
#define UI_CONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Connection
{
public:
    QLabel *label;

    void setupUi(QDialog *Connection)
    {
        if (Connection->objectName().isEmpty())
            Connection->setObjectName(QString::fromUtf8("Connection"));
        Connection->resize(506, 364);
        label = new QLabel(Connection);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 30, 161, 51));

        retranslateUi(Connection);

        QMetaObject::connectSlotsByName(Connection);
    } // setupUi

    void retranslateUi(QDialog *Connection)
    {
        Connection->setWindowTitle(QApplication::translate("Connection", "Dialog", nullptr));
        label->setText(QApplication::translate("Connection", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Connection: public Ui_Connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTION_H
