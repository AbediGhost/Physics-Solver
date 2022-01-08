#include "forum.h"

Forum::Forum(QWidget *parent) : QWidget(parent)
{
    Attributing();
    setting();
    Layouting();
    setLayout(mainLayout);
    setWindowTitle("Forum d'entraide");
}
void Forum::Attributing()
{
    //Layout
    mainLayout = new QVBoxLayout;
    dataLayout = new QHBoxLayout;
    threadListLay = new QVBoxLayout;
    newThreadLay = new QHBoxLayout;
    //Widget
    avatar = new QLabel;
    pseudo = new QLabel;
    actualize = new QPushButton;
    for(int i=0;i<3;i++)
        threadList[i] = new QRadioButton;
    //Conteneurs
    actualize = new QPushButton;
    newSubj = new QPushButton;
    subjTitle = new QLineEdit;
    subjDesc = new QTextEdit;

}
void Forum::Layouting()
{
    dataLayout->addWidget(avatar);
    dataLayout->addWidget(pseudo);
    for(int i=0;i<3;i++)
        threadListLay->addWidget(threadList[i]);
    newThreadLay->addWidget(subjTitle);
    newThreadLay->addWidget(newSubj);
    mainLayout->addLayout(dataLayout);
    mainLayout->addLayout(threadListLay);
    mainLayout->addWidget(actualize);
    mainLayout->addLayout(newThreadLay);
    mainLayout->addWidget(subjDesc);
}
void Forum::setting()
{
    for(int i=0;i<3;i++)
        threadList[i]->setText(QString::fromStdString(forumList[i]));
}
