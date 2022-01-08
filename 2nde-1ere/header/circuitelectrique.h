#ifndef CIRCUITELECTRIQUE_H
#define CIRCUITELECTRIQUE_H

#include <QWidget>
#include "2nde-1ere/header/circuitsetter.h"

class CircuitElectrique : public QWidget
{
public:
    CircuitElectrique();
private:
    CircuitSetter *joule;
};

#endif // CIRCUITELECTRIQUE_H
