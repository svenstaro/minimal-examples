#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <QtCore/QObject>

#include <QMetaType>

#include <string>

class Component : public QObject {
    Q_OBJECT
public:
    virtual void ShowName() = 0;
    virtual ~Component() = 0;

    std::string mName;
};

#endif
