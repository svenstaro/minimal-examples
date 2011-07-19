#include <memory>
#include <iostream>

class Event {
public:
    Event() {}
    virtual ~Event() = 0;
};

Event::~Event() {}

class RealEvent : public Event {
public:
    RealEvent(int data) {
        mData = data;
    }
    ~RealEvent() {}
    int mData;
};

void DoRofl(std::shared_ptr<Event> safe_event) {
    std::shared_ptr<RealEvent> real_dynamic_event = \
        std::dynamic_pointer_cast<RealEvent>(safe_event);
    std::cout << real_dynamic_event->mData << std::endl;

    std::shared_ptr<RealEvent> real_static_event = \
        std::static_pointer_cast<RealEvent>(safe_event);
    std::cout << real_static_event->mData << std::endl;
}

void DoSomething(Event * event) {
    std::shared_ptr<Event> safe_event(event);
    DoRofl(safe_event);
}

int main() {
    DoSomething(new RealEvent(4));

    return 0;
}
