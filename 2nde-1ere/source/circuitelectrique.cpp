#include "2nde-1ere/header/circuitelectrique.h"

CircuitElectrique::CircuitElectrique()
{
    joule = new CircuitSetter(this);
    joule->exec();
}
