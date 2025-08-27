#pragma once

#include <typeindex>
#include <functional>
#include <queue>
#include <memory>

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
    void Subscribe(std::function<void(const EventType&)> listener) {
        subscribers[typeid(EventType)].push_back(
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

    template <typename EventType>
    void Publish(EventType& event) {
        eventQueue.push(std::make_unique<EventType>(event));
    }

    void HandleEvents() {
        while (!eventQueue.empty()) {
            auto& eventPtr = eventQueue.front();
            auto thisTypeEvents = subscribers.find(typeid(*eventPtr));
            if (thisTypeEvents != subscribers.end()) {
                for (auto& listener : thisTypeEvents->second) {
                    listener(*eventPtr);
                }
            }
            eventQueue.pop();
        }
    }

    void OnKeyPress(KeyCode key, std::function<void(const OnKeyPressEvent&)> callback);

private:
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> instantSubscribers;
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> subscribers;
    std::queue<std::unique_ptr<Event>> eventQueue;
};
