#include "4eme-3eme/header/ps_element.h"

PS_Element::PS_Element(QString id)
{
    name = new QLabel;
    container = new QDoubleSpinBox;
}

int PS_Element::get_value()
{
    return container->value();
}
QString PS_Element::get_info()
{
    return this->info;
}
