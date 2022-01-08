#ifndef FORUM_H
#define FORUM_H

#include <vector>
#include <string>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>

class Forum : public QWidget
{
    Q_OBJECT
public:
    Forum(QWidget *parent = 0);
private:
    //fonctions privées
    void Attributing();
    void Layouting();
    void setting();
    //Attributs privés
    //Layout
    QVBoxLayout *mainLayout;
    QHBoxLayout *dataLayout;
    QVBoxLayout *threadListLay;
    QHBoxLayout *newThreadLay;
    //Widget
    QLabel *avatar;
    QLabel *pseudo;
    QPushButton *actualize;
    QPushButton *newSubj;
    QLineEdit *subjTitle;
    QTextEdit *subjDesc;
    //Conteneurs
    QRadioButton *threadList[3];
    std::string forumList[3] = {"Futura Science","Ile Physique",""};
};

#endif // FORUM_H
