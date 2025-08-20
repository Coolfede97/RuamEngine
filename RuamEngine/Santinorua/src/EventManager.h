#pragma once

#include <typeindex>
#include <functional>
#include "Input.h"

struct Event {
    virtual ~Event() = default;
};

struct OnKeyPress : public Event {
    int key;

    OnKeyPress(int key) : key(key) {}
};


class EventManager {
public:

    template <typename EventType>
    void subscribe(std::function<void(const EventType&)> listener) {
        auto& listeners = subscribers[typeid(EventType)];
        subscribers[typeid(EventType)].push_back(
            [listener](const Event& e) {
                listener(static_cast<const EventType&>(e));
            }
        );
    }

    template <typename EventType>
    void publish(EventType& event) {
        auto thisTypeEvents = subscribers.find(typeid(EventType));
        if (thisTypeEvents != subscribers.end()) {
            for (auto& listener : thisTypeEvents->second) {
                listener(event);
            }
        }
    }

private:
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> subscribers;
};
