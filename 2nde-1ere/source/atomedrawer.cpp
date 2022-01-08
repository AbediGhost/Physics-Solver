#include "2nde-1ere/header/atomedrawer.h"

AtomeDrawer::AtomeDrawer(QWidget *parent, const QPoint &position, const QSize &taille):
    QSfmlCanvas(parent,position,taille)
{
    update = true;
    currentElement = 1;
    OnInit();
}
void AtomeDrawer::OnInit()
{
    Attributing();
}
void AtomeDrawer::OnUpdate()
{
    MyUpdate();
    MyDraw();
    timer->start(30);
}
void AtomeDrawer::MyDraw()
{
    clear(sf::Color::Black);
    draw(*mAtome);
}
void AtomeDrawer::MyUpdate()
{
    if(update == true)
        mAtome->Updating();
    EventManage();
}
void AtomeDrawer::Attributing()
{
    sf::Vector2f saPos(290,200);
    mAtome = new Atome(currentElement,saPos);
}
void AtomeDrawer::EventManage()
{
    sf::Vector2f saPos(290,200);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        update = !update;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        currentElement -= 1;
        if(currentElement < 1)
            currentElement = 18;
        delete mAtome;
        mAtome = 0;
        mAtome = new Atome(currentElement,saPos);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        currentElement += 1;
        if(currentElement > 18)
            currentElement = 1;
        delete mAtome;
        mAtome = 0;
        mAtome = new Atome(currentElement,saPos);
    }
}
