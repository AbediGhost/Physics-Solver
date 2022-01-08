#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H

#include <QWidget>
#include <QTimer>
#include <SFML/Graphics.hpp>
#include <QMessageBox>

class QSfmlCanvas : public QWidget,public sf::RenderWindow
{
    Q_OBJECT

public:
    QSfmlCanvas(QWidget*,const QPoint&,const QSize&);
    virtual ~QSfmlCanvas();
public slots:
    void update();
protected:
    virtual void OnInit() = 0;
    virtual void OnUpdate() = 0;
    virtual QPaintEngine *paintEngine() const;
    virtual void ShowEvent(QShowEvent*);
    virtual void paintEvent(QPaintEvent*);
    QTimer *timer;
    bool initialized = false;
private:

};

#endif // QSFMLCANVAS_H
