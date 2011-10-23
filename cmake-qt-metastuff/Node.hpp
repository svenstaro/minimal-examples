#ifndef NODE_HPP
#define NODE_HPP

#include <QtCore/QObject>

class Node : public QObject {
    Q_OBJECT
public:
    Node();
    ~Node();

    void DoStuff();
};

#endif
