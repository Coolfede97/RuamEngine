#pragma once

#include <typeindex>
#include <functional>
#include <queue>

enum KeyCode;

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

    template <typename EventType>
    void InstantSubscribe(std::function<void(const EventType&)> listener) {
        auto& listeners = instantSubscribers[typeid(EventType)];
        instantSubscribers[typeid(EventType)].push_back(
            [listener](const Event& e) {
                listener(static_cast<const EventType&>(e));
            }
        );
    }



    template <typename EventType>
    void InstantPublish(const EventType& event) {
        auto thisTypeEvents = instantSubscribers.find(typeid(EventType));
        if (thisTypeEvents != instantSubscribers.end()) {
            for (auto& listener : thisTypeEvents->second) {
                listener(event);
            }
        }
    }

    void OnKeyPress(KeyCode key, std::function<void(const OnKeyPressEvent&)> callback);

private:
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> instantSubscribers;
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> subscribers;
    std::queue<Event*> eventQueue;
};
