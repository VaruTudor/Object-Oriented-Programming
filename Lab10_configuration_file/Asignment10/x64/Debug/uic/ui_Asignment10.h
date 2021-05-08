/********************************************************************************
** Form generated from reading UI file 'Asignment10.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASIGNMENT10_H
#define UI_ASIGNMENT10_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
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

class Ui_Asignment10Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QListWidget *FilterListWidget;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QLineEdit *FilterPlaceLineEdit;
    QLabel *label_9;
    QLineEdit *FilterAgeLineEdit;
    QPushButton *filterButton;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *AdministratorListWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *NameLineEdit;
    QLabel *label_4;
    QLineEdit *PlaceLineEdit;
    QLabel *label_5;
    QLineEdit *AgeLineEdit;
    QLabel *label_6;
    QLineEdit *PhotographLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *AssistantListWidge2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *saveButton;
    QPushButton *nextButton;
    QPushButton *ChangeModePushButton;
    QPushButton *OpenPushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Asignment10Class)
    {
        if (Asignment10Class->objectName().isEmpty())
            Asignment10Class->setObjectName(QString::fromUtf8("Asignment10Class"));
        Asignment10Class->resize(865, 697);
        centralWidget = new QWidget(Asignment10Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setPointSize(14);
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);

        FilterListWidget = new QListWidget(centralWidget);
        FilterListWidget->setObjectName(QString::fromUtf8("FilterListWidget"));

        verticalLayout_3->addWidget(FilterListWidget);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Yu Gothic UI Semilight"));
        font1.setPointSize(10);
        label_8->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        FilterPlaceLineEdit = new QLineEdit(centralWidget);
        FilterPlaceLineEdit->setObjectName(QString::fromUtf8("FilterPlaceLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, FilterPlaceLineEdit);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);

        FilterAgeLineEdit = new QLineEdit(centralWidget);
        FilterAgeLineEdit->setObjectName(QString::fromUtf8("FilterAgeLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, FilterAgeLineEdit);


        verticalLayout_3->addLayout(formLayout_2);

        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        verticalLayout_3->addWidget(filterButton);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        AdministratorListWidget = new QListWidget(centralWidget);
        AdministratorListWidget->setObjectName(QString::fromUtf8("AdministratorListWidget"));

        verticalLayout->addWidget(AdministratorListWidget);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        NameLineEdit = new QLineEdit(centralWidget);
        NameLineEdit->setObjectName(QString::fromUtf8("NameLineEdit"));
        QFont font2;
        font2.setPointSize(10);
        NameLineEdit->setFont(font2);

        formLayout->setWidget(0, QFormLayout::FieldRole, NameLineEdit);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        PlaceLineEdit = new QLineEdit(centralWidget);
        PlaceLineEdit->setObjectName(QString::fromUtf8("PlaceLineEdit"));
        PlaceLineEdit->setFont(font2);

        formLayout->setWidget(1, QFormLayout::FieldRole, PlaceLineEdit);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        AgeLineEdit = new QLineEdit(centralWidget);
        AgeLineEdit->setObjectName(QString::fromUtf8("AgeLineEdit"));
        AgeLineEdit->setFont(font2);

        formLayout->setWidget(2, QFormLayout::FieldRole, AgeLineEdit);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        PhotographLineEdit = new QLineEdit(centralWidget);
        PhotographLineEdit->setObjectName(QString::fromUtf8("PhotographLineEdit"));
        PhotographLineEdit->setFont(font2);

        formLayout->setWidget(3, QFormLayout::FieldRole, PhotographLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        updateButton = new QPushButton(centralWidget);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        horizontalLayout->addWidget(updateButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        AssistantListWidge2 = new QListWidget(centralWidget);
        AssistantListWidge2->setObjectName(QString::fromUtf8("AssistantListWidge2"));

        verticalLayout_2->addWidget(AssistantListWidge2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_2->addWidget(saveButton);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout_2->addWidget(nextButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        ChangeModePushButton = new QPushButton(centralWidget);
        ChangeModePushButton->setObjectName(QString::fromUtf8("ChangeModePushButton"));

        verticalLayout_4->addWidget(ChangeModePushButton);

        OpenPushButton = new QPushButton(centralWidget);
        OpenPushButton->setObjectName(QString::fromUtf8("OpenPushButton"));

        verticalLayout_4->addWidget(OpenPushButton);


        verticalLayout_5->addLayout(verticalLayout_4);

        Asignment10Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Asignment10Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 865, 26));
        Asignment10Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Asignment10Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Asignment10Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Asignment10Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Asignment10Class->setStatusBar(statusBar);

        retranslateUi(Asignment10Class);

        QMetaObject::connectSlotsByName(Asignment10Class);
    } // setupUi

    void retranslateUi(QMainWindow *Asignment10Class)
    {
        Asignment10Class->setWindowTitle(QCoreApplication::translate("Asignment10Class", "Asignment10", nullptr));
        label_7->setText(QCoreApplication::translate("Asignment10Class", "Filter", nullptr));
        label_8->setText(QCoreApplication::translate("Asignment10Class", "Place of origin", nullptr));
        label_9->setText(QCoreApplication::translate("Asignment10Class", "Age", nullptr));
        filterButton->setText(QCoreApplication::translate("Asignment10Class", "Filter", nullptr));
        label->setText(QCoreApplication::translate("Asignment10Class", "Administator", nullptr));
        label_3->setText(QCoreApplication::translate("Asignment10Class", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("Asignment10Class", "Place of origin", nullptr));
        label_5->setText(QCoreApplication::translate("Asignment10Class", "Age", nullptr));
        label_6->setText(QCoreApplication::translate("Asignment10Class", "Photograph", nullptr));
        addButton->setText(QCoreApplication::translate("Asignment10Class", "Add", nullptr));
        deleteButton->setText(QCoreApplication::translate("Asignment10Class", "Delete", nullptr));
        updateButton->setText(QCoreApplication::translate("Asignment10Class", "Update", nullptr));
        label_2->setText(QCoreApplication::translate("Asignment10Class", "Assistant", nullptr));
        saveButton->setText(QCoreApplication::translate("Asignment10Class", "Save", nullptr));
        nextButton->setText(QCoreApplication::translate("Asignment10Class", "Next", nullptr));
        ChangeModePushButton->setText(QCoreApplication::translate("Asignment10Class", "Change mode", nullptr));
        OpenPushButton->setText(QCoreApplication::translate("Asignment10Class", "Open external", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Asignment10Class: public Ui_Asignment10Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASIGNMENT10_H
