#ifndef COMPONENT
#define COMPONENT

#include <QObject>
#include <QMetaType>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include <yaml-cpp/yaml.h>

// forward declaration
class Node;

class Component : public QObject {
    Q_OBJECT
public:
    Component();
    Component(const Component& other);
    virtual void SayName() = 0;
    virtual ~Component() = 0;
    
    void Serialize(YAML::Emitter& out);
    static Component* Deserialize(const YAML::Node& node);

    virtual void OnSerialize(YAML::Emitter& out);
    virtual void OnDeserialize(const YAML::Node& node);

    boost::uuids::uuid mId;
    Node* mNode;
};

#endif
