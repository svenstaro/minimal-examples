#include "Component.hpp"

#include <QtCore/QObject>

#include <yaml-cpp/yaml.h>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/ptr_container/ptr_map.hpp>

#include <map>
#include <memory>

class Node : public QObject {
    Q_OBJECT

public:
    Node();
    ~Node();

    Node* AddChild(Node* node);
    Component* AddComponent(Component* component);

    void Display(int level = 0);

    void Serialize(YAML::Emitter& out);
    static Node* Deserialize(const YAML::Node& node);

    boost::ptr_map<boost::uuids::uuid, Node> mChildren;
    std::map<boost::uuids::uuid, std::shared_ptr<Component>> mComponents;
    Node* mParent;
    boost::uuids::uuid mId;
};
