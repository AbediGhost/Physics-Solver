#ifndef EQUATION_BILAN_H
#define EQUATION_BILAN_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <vector>
#include <map>
#include <sstream>

class Equation_Bilan : public QDialog
{
    Q_OBJECT
public:
    Equation_Bilan();
    void attribut();
public slots:
    void Start();
private:
    void init();
    void parse();
    QLabel *indic1;
    QLabel *indic2;
    QLineEdit *Reactif;
    QLabel *fleche;
    QLineEdit *Produit;
    QPushButton *Equilibre;
    QLineEdit *Resultat;
    QHBoxLayout *firstLay;
    QHBoxLayout *SecLay;
    QFormLayout *FinLay;
    QVBoxLayout *MainLay;
    std::vector<int> ProdCoeffPos;
    std::vector<int> ReacCoeffPos;
    std::map<std::string,int> ReacMap;
    std::map<std::string,int> ProdMap;
};

#endif // EQUATION_BILAN_H
