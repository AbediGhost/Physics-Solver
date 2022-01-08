#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class AboutUs : public QWidget
{
    Q_OBJECT
public:
    AboutUs(QWidget *parent = 0);
    void load();
private:
    QLabel *information;
    QVBoxLayout *mainLay;
};

#endif // ABOUTUS_H
