/********************************************************************************
** Form generated from reading UI file 'instructions.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTIONS_H
#define UI_INSTRUCTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Instructions
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Instructions)
    {
        if (Instructions->objectName().isEmpty())
            Instructions->setObjectName(QString::fromUtf8("Instructions"));
        Instructions->resize(400, 300);
        label = new QLabel(Instructions);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 30, 81, 17));
        pushButton = new QPushButton(Instructions);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 250, 80, 25));

        retranslateUi(Instructions);

        QMetaObject::connectSlotsByName(Instructions);
    } // setupUi

    void retranslateUi(QDialog *Instructions)
    {
        Instructions->setWindowTitle(QApplication::translate("Instructions", "Dialog", nullptr));
        label->setText(QApplication::translate("Instructions", "Instrucciones", nullptr));
        pushButton->setText(QApplication::translate("Instructions", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Instructions: public Ui_Instructions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTIONS_H
