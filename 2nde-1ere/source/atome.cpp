#include "2nde-1ere/header/atome.h"

Atome::Atome(int m_numeroAtomique, sf::Vector2f m_position)
{
    numeroAtomique = m_numeroAtomique;
    nbreLdN = 0;
    noyau.setRadius(40);
    noyau.setOrigin(40,40);
    noyau.setFillColor(sf::Color::White);
    noyau.setPosition(m_position);
    position = m_position;
    load();
    setting();
}
void Atome::draw(sf::RenderTarget &target,sf::RenderStates states)const
{
    states.transform *= getTransform();
    target.draw(information,states);
    target.draw(noyau,states);
    for(int i=0;i<electron.size();i++)
        target.draw(electron[i],states);
    for(int i=0;i<ligneDeNiveau.size();i++)
        target.draw(ligneDeNiveau[i],states);
}
void Atome::load()
{
    nbreLdN = 0;
    int mJp = numeroAtomique;
    for(int i=1;i<4;i++)
    {
        if((mJp-(2*i*i)) >= 0)
        {
            ++nbreLdN;
            mJp-= 2*i*i;
        }
        else if(mJp > 0)
        {
            ++nbreLdN;
            mJp -= mJp;
        }
    }
    for(int i=0;i<numeroAtomique;i++)
    {
        sf::CircleShape tempo;
        tempo.setRadius(10);
        tempo.setOrigin(10,10);
        tempo.setFillColor(sf::Color::Cyan);
        sf::RectangleShape tampo;
        tampo.setFillColor(sf::Color::Red);
        tampo.setPosition(noyau.getPosition());
        support.push_back(tampo);
        electron.push_back(tempo);
    }
    loadInformation();
}
void Atome::setting()
{
    int m_nA = numeroAtomique;
    for(int i=0;i<nbreLdN;i++)
    {
        int mI = i+1;
        if((m_nA - (2*mI*mI)) >= 0)
        {
            for(int j=0;j<(2*mI*mI);j++)
            {
                if(mI == 1)
                    support[(2*i*i)+j].rotate(((j*180)+(mI*10)));
                else
                    support[(2*i*i)+j].rotate(((j*45)+(mI*10)));
                if(i != 2)
                    support[(2*i*i)+j].setSize(sf::Vector2f(1,40+(mI*30)+(i*20)));
                else if(i == 2)
                    support[(2*i*i)+j+2].setSize(sf::Vector2f(1,40+(mI*30)+(i*20)));
            }
            m_nA -= 2*mI*mI;
        }
        else if(m_nA > 0 && numeroAtomique != 1)
        {
            for(int j=0;j<m_nA;j++)
            {
                if(mI == 1)
                    support[(2*i*i)+j].rotate(((j*180)+(mI*10)));
                else
                    support[(2*i*i)+j].rotate(((j*45)+(mI*10)));
                if(i == 1)
                    support[(2*i*i)+j].setSize(sf::Vector2f(1,40+(mI*30)+(i*20)));
                else if(i == 2)
                    support[(2*i*i)+j+2].setSize(sf::Vector2f(1,40+(mI*30)+(i*20)));
            }
        }
        else if(numeroAtomique == 1)
        {
            support[0].setSize(sf::Vector2f(1,40+(mI*30)+(i*20)));
        }
        sf::CircleShape tempo;
        tempo.setRadius(40+(mI*30)+(i*20));
        tempo.setOrigin(tempo.getRadius(),tempo.getRadius());
        tempo.setPosition(noyau.getPosition());
        tempo.setOutlineColor(sf::Color::Cyan);
        tempo.setOutlineThickness(1);
        tempo.setFillColor(sf::Color::Transparent);
        ligneDeNiveau.push_back(tempo);
    }

}
void Atome::Updating()
{
    for(int i=0;i<electron.size();i++)
    {
        std::uniform_int_distribution<int> distribution(1,10);
        int speed = distribution(generator);
        support[i].rotate(-speed);
        electron[i].setPosition((support[i].getPosition().x)+support[i].getSize().y*cos((support[i].getRotation()*3.14159265358979)/180),
                                (support[i].getPosition().y)+support[i].getSize().y*sin((support[i].getRotation()*3.14159265358979)/180));
    }
}
void Atome::loadInformation()
{
    std::ifstream lector("res/Donnees/TableauPeriodique.dat");
    if(!lector)
        QMessageBox::warning(0,"","Alerte");
    std::string info;
    for(int i=0;i<numeroAtomique;i++)
        std::getline(lector,info);
    std::stringstream tempoStream;
    tempoStream <<info;
    int numA=0,elecPerif=0;
    std::string name,famil;
    tempoStream >> numA >> name >> elecPerif >> famil;
    std::stringstream writter;
    writter <<"Nom : "<<name<<"\n"
            <<"Numero atomique : "<<numA<<"\n"
            <<"Famille : "<<famil<<"\n"
            <<"Nombre d'electrons peripheriques : "<<elecPerif<<"\n";
    mFont.loadFromFile("res/Media/ALGER.ttf");
    information.setString(writter.str());
    information.setFont(mFont);
    information.setFillColor(sf::Color::Yellow);
    information.setPosition(50,420);
    information.setCharacterSize(25);
}
