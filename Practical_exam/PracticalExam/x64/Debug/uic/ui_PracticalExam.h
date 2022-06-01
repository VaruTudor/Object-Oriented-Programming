/********************************************************************************
** Form generated from reading UI file 'PracticalExam.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICALEXAM_H
#define UI_PRACTICALEXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticalExamClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QListWidget *StarsListWidget;
    QCheckBox *DysplayCheckBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *nameLineEdit;
    QLabel *label;
    QLineEdit *RALineEdit;
    QLabel *label_2;
    QLineEdit *DecLineEdit;
    QLabel *label_3;
    QLineEdit *diameterLineEdit;
    QLabel *label_4;
    QPushButton *AddPushButton;
    QVBoxLayout *verticalLayout_4;
    QListWidget *SearchListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *SearchPushButton;
    QLineEdit *SearchLineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PracticalExamClass)
    {
        if (PracticalExamClass->objectName().isEmpty())
            PracticalExamClass->setObjectName(QString::fromUtf8("PracticalExamClass"));
        PracticalExamClass->resize(859, 642);
        centralWidget = new QWidget(PracticalExamClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        StarsListWidget = new QListWidget(centralWidget);
        StarsListWidget->setObjectName(QString::fromUtf8("StarsListWidget"));

        verticalLayout->addWidget(StarsListWidget);

        DysplayCheckBox = new QCheckBox(centralWidget);
        DysplayCheckBox->setObjectName(QString::fromUtf8("DysplayCheckBox"));

        verticalLayout->addWidget(DysplayCheckBox);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nameLineEdit = new QLineEdit(centralWidget);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        RALineEdit = new QLineEdit(centralWidget);
        RALineEdit->setObjectName(QString::fromUtf8("RALineEdit"));

        gridLayout->addWidget(RALineEdit, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        DecLineEdit = new QLineEdit(centralWidget);
        DecLineEdit->setObjectName(QString::fromUtf8("DecLineEdit"));

        gridLayout->addWidget(DecLineEdit, 2, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        diameterLineEdit = new QLineEdit(centralWidget);
        diameterLineEdit->setObjectName(QString::fromUtf8("diameterLineEdit"));

        gridLayout->addWidget(diameterLineEdit, 3, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        AddPushButton = new QPushButton(centralWidget);
        AddPushButton->setObjectName(QString::fromUtf8("AddPushButton"));

        verticalLayout_2->addWidget(AddPushButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        SearchListWidget = new QListWidget(centralWidget);
        SearchListWidget->setObjectName(QString::fromUtf8("SearchListWidget"));

        verticalLayout_4->addWidget(SearchListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        SearchPushButton = new QPushButton(centralWidget);
        SearchPushButton->setObjectName(QString::fromUtf8("SearchPushButton"));

        horizontalLayout->addWidget(SearchPushButton);

        SearchLineEdit = new QLineEdit(centralWidget);
        SearchLineEdit->setObjectName(QString::fromUtf8("SearchLineEdit"));

        horizontalLayout->addWidget(SearchLineEdit);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_2);

        PracticalExamClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PracticalExamClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 859, 26));
        PracticalExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PracticalExamClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PracticalExamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PracticalExamClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PracticalExamClass->setStatusBar(statusBar);

        retranslateUi(PracticalExamClass);

        QMetaObject::connectSlotsByName(PracticalExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *PracticalExamClass)
    {
        PracticalExamClass->setWindowTitle(QCoreApplication::translate("PracticalExamClass", "PracticalExam", nullptr));
        DysplayCheckBox->setText(QCoreApplication::translate("PracticalExamClass", "Display only ", nullptr));
        label->setText(QCoreApplication::translate("PracticalExamClass", "name", nullptr));
        label_2->setText(QCoreApplication::translate("PracticalExamClass", "RA", nullptr));
        label_3->setText(QCoreApplication::translate("PracticalExamClass", "Dec", nullptr));
        label_4->setText(QCoreApplication::translate("PracticalExamClass", "Diameter", nullptr));
        AddPushButton->setText(QCoreApplication::translate("PracticalExamClass", "AddStar", nullptr));
        SearchPushButton->setText(QCoreApplication::translate("PracticalExamClass", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PracticalExamClass: public Ui_PracticalExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICALEXAM_H
