#ifndef PS_ELEMENT_H
#define PS_ELEMENT_H

#include <QLabel>
#include <QDoubleSpinBox>

/*Element de base du physics_solver.
 * Il contient un Qlabel comme identiiant et
 * un QDoubleSpinBox qui contient la valeur
 * info(QString) contient les details de l'element
*/

class PS_Element
{
public:
    PS_Element(QString id);
    QLabel get_name();
    int get_value();
    QString get_info();
private:
    QLabel *name;
    QDoubleSpinBox *container;
    unsigned int value;
    QString unite;
    QString info;
};

#endif // PS_ELEMENT_H
