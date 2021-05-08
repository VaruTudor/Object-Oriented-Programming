/********************************************************************************
** Form generated from reading UI file 'Asignment9d.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASIGNMENT9D_H
#define UI_ASIGNMENT9D_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Asignment9dClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Asignment9dClass)
    {
        if (Asignment9dClass->objectName().isEmpty())
            Asignment9dClass->setObjectName(QString::fromUtf8("Asignment9dClass"));
        Asignment9dClass->resize(600, 400);
        menuBar = new QMenuBar(Asignment9dClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Asignment9dClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Asignment9dClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Asignment9dClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Asignment9dClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Asignment9dClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Asignment9dClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Asignment9dClass->setStatusBar(statusBar);

        retranslateUi(Asignment9dClass);

        QMetaObject::connectSlotsByName(Asignment9dClass);
    } // setupUi

    void retranslateUi(QMainWindow *Asignment9dClass)
    {
        Asignment9dClass->setWindowTitle(QCoreApplication::translate("Asignment9dClass", "Asignment9d", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Asignment9dClass: public Ui_Asignment9dClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASIGNMENT9D_H
