#include "qsfmlcanvas.h"

QSfmlCanvas::QSfmlCanvas(QWidget *parent,const QPoint& position,const QSize& taille)
    : QWidget(parent),
      initialized(false)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    setFocusPolicy(Qt::StrongFocus);
    timer = new QTimer();
    move(position);
    resize(taille);
    sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(30);
}

QSfmlCanvas::~QSfmlCanvas()
{

}

void QSfmlCanvas::ShowEvent(QShowEvent*)
{
}

QPaintEngine* QSfmlCanvas::paintEngine() const
{
    return 0;
}

void QSfmlCanvas::paintEvent(QPaintEvent*)
{
    OnUpdate();
    display();
}
void QSfmlCanvas::OnInit()
{
}
void QSfmlCanvas::OnUpdate()
{
}
void QSfmlCanvas::update()
{
    OnUpdate();
    display();
}
