/********************************************************************************
** Form generated from reading UI file 'FilePlanter.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPLANTER_H
#define UI_FILEPLANTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentFileTransferClass
{
public:
    QWidget *centralWidget;
    QPushButton *btn_sendfile;
    QPlainTextEdit *text_cmd;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_choosefile;
    QLineEdit *line_file;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_users;
    QPushButton *btn_userfresh;
    QScrollArea *scroll_userlist;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StudentFileTransferClass)
    {
        if (StudentFileTransferClass->objectName().isEmpty())
            StudentFileTransferClass->setObjectName(QStringLiteral("StudentFileTransferClass"));
        StudentFileTransferClass->resize(650, 400);
        StudentFileTransferClass->setMinimumSize(QSize(650, 400));
        StudentFileTransferClass->setMaximumSize(QSize(650, 400));
        centralWidget = new QWidget(StudentFileTransferClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_sendfile = new QPushButton(centralWidget);
        btn_sendfile->setObjectName(QStringLiteral("btn_sendfile"));
        btn_sendfile->setGeometry(QRect(10, 60, 75, 23));
        text_cmd = new QPlainTextEdit(centralWidget);
        text_cmd->setObjectName(QStringLiteral("text_cmd"));
        text_cmd->setGeometry(QRect(10, 90, 271, 251));
        text_cmd->setReadOnly(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 60, 71, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 271, 45));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_choosefile = new QPushButton(layoutWidget);
        btn_choosefile->setObjectName(QStringLiteral("btn_choosefile"));

        horizontalLayout->addWidget(btn_choosefile);

        line_file = new QLineEdit(layoutWidget);
        line_file->setObjectName(QStringLiteral("line_file"));
        line_file->setReadOnly(true);

        horizontalLayout->addWidget(line_file);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(310, 10, 331, 303));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lab_users = new QLabel(layoutWidget1);
        lab_users->setObjectName(QStringLiteral("lab_users"));

        horizontalLayout_2->addWidget(lab_users);

        btn_userfresh = new QPushButton(layoutWidget1);
        btn_userfresh->setObjectName(QStringLiteral("btn_userfresh"));

        horizontalLayout_2->addWidget(btn_userfresh);


        verticalLayout_2->addLayout(horizontalLayout_2);

        scroll_userlist = new QScrollArea(layoutWidget1);
        scroll_userlist->setObjectName(QStringLiteral("scroll_userlist"));
        scroll_userlist->setMinimumSize(QSize(327, 270));
        scroll_userlist->setMaximumSize(QSize(327, 270));
        scroll_userlist->setStyleSheet(QLatin1String("QWidget#scrollAreaWidgetContents{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"\n"
""));
        scroll_userlist->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scroll_userlist->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scroll_userlist->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 308, 268));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        scroll_userlist->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scroll_userlist);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(310, 320, 331, 20));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        StudentFileTransferClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StudentFileTransferClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 23));
        StudentFileTransferClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StudentFileTransferClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        StudentFileTransferClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StudentFileTransferClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StudentFileTransferClass->setStatusBar(statusBar);

        retranslateUi(StudentFileTransferClass);

        QMetaObject::connectSlotsByName(StudentFileTransferClass);
    } // setupUi

    void retranslateUi(QMainWindow *StudentFileTransferClass)
    {
        StudentFileTransferClass->setWindowTitle(QApplication::translate("StudentFileTransferClass", "StudentFileTransfer", nullptr));
        btn_sendfile->setText(QApplication::translate("StudentFileTransferClass", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        label_3->setText(QApplication::translate("StudentFileTransferClass", "\345\221\275\344\273\244\350\241\214\350\276\223\345\207\272\357\274\232", nullptr));
        label_2->setText(QApplication::translate("StudentFileTransferClass", "\346\226\207\344\273\266\345\217\221\351\200\201\345\231\250", nullptr));
        btn_choosefile->setText(QApplication::translate("StudentFileTransferClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        lab_users->setText(QApplication::translate("StudentFileTransferClass", "\345\275\223\345\211\215\345\234\250\347\272\277\347\224\250\346\210\267:0\344\272\272", nullptr));
        btn_userfresh->setText(QApplication::translate("StudentFileTransferClass", "\345\210\267\346\226\260", nullptr));
        label->setText(QApplication::translate("StudentFileTransferClass", "\345\255\246\347\224\237\347\253\257\347\250\213\345\272\217\346\233\264\346\226\260\344\270\200\351\224\256\351\203\250\347\275\262\345\267\245\345\205\267", nullptr));
        label_4->setText(QApplication::translate("StudentFileTransferClass", "Design by:Leventure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentFileTransferClass: public Ui_StudentFileTransferClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPLANTER_H
