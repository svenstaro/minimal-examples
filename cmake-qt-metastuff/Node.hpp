#ifndef NODE_HPP
#define NODE_HPP

#include <QtCore/QObject>
#include <QMetaType>

#include <string>

class Node : public QObject {
    Q_OBJECT
public:
    Node();
    Node(const Node& other);
    ~Node();

    void ShowName();

    std::string mName;
};

#endif
