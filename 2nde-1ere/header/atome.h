#ifndef ATOME_H
#define ATOME_H

#include <SFML/Graphics.hpp>
#include <QMessageBox>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>
#include <sstream>

class Atome : public sf::Drawable,public sf::Transformable
{
public:
    Atome(int m_numeroAtomique,sf::Vector2f m_position);
    virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
    void genererLdN();
    void load();
    void loadInformation();
    void Updating();
private:
    void setting();
    //____________
    int numeroAtomique;
    int nbreLdN;
    sf::Text information;
    sf::Font mFont;
    sf::Vector2f position;
    sf::CircleShape noyau;
    std::vector<sf::RectangleShape> support;
    std::vector<sf::CircleShape> electron;
    std::vector<sf::CircleShape> ligneDeNiveau;
    std::default_random_engine generator;
};

#endif // ATOME_H
