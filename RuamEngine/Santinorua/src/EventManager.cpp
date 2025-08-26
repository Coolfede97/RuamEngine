#include "EventManager.h"

void OnKeyPress(KeyCode key, std::function<void(const OnKeyPressEvent&)> callback) {
    this.subscribe<OnKeyPressEvent>([key, callback](const OnKeyPressEvent& event) {
        if (event.key == static_cast<int>(key)) {
            callback(event);
        }
    });
}

template <typename EventType>
void publish(const Event& event) {
    this.eventQueue.push_back({ typeid(EventType), { event } });
}