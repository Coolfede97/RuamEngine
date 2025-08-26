#pragma once

#include <typeindex>
#include <functional>
#include "Input.h"

struct Event {
    virtual ~Event() = default;
};

struct OnKeyPressEvent : public Event {
    int key;

    OnKeyPressEvent(int key) : key(key) {}
};

struct OnKeyReleaseEvent : public Event {
    int key;

    OnKeyReleaseEvent(int key) : key(key) {}
};


class EventManager {
public:

    // template <typename EventType>
    // void subscribe(std::function<void(const EventType&)> listener) {
    //     auto& listeners = subscribers[typeid(EventType)];
    //     subscribers[typeid(EventType)].push_back(
    //         [listener](const Event& e) {
    //             listener(static_cast<const EventType&>(e));
    //         }
    //     );
    // }

    template<typename EventType>
    void getEvent(std::function<void>(const EventType&)> callback) {
        

    }

    template <typename EventType>
    void publish(const EventType& event);
    // void publish(const EventType& event) {
        // auto thisTypeEvents = subscribers.find(typeid(EventType));
        // if (thisTypeEvents != subscribers.end()) {
        //     for (auto& listener : thisTypeEvents->second) {
        //         listener(event);
        //     }
        // }
    // }

    void OnKeyPress(KeyCode key, std::function<void(const OnKeyPressEvent&)> callback);

private:
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> subscribers;
    std::unordered_map<std::type_index, std::vector<Event>> eventQueue;
};
