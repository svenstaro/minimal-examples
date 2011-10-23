#include <QtCore/QObject>

class TestClass : public QObject {
public:
    TestClass() {}
    ~TestClass() {}
private:
    Q_OBJECT
};
