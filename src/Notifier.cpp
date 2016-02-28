#include "Notifier.h"
#include "Subscriber.h"
#include <algorithm>
#include <iostream>

Notifier::Notifier()
    :registerEnabled(true)
{}

void Notifier::registerSubscriber(Subscriber &subs)
{
    if (!registerEnabled) return;

    subscribers.push_front(subs);
    std::cout << "Registered: " << std::addressof(subs) << std::endl;

    printSubscribers();
}

void Notifier::unregisterSubscriber(Subscriber &subs)
{
    auto elem = std::find(subscribers.begin(), subscribers.end(), std::ref(subs));

    if (elem != subscribers.end())
    {
        subscribers.erase(elem);
        std::cout << "Unregistered: " << std::addressof(subs) << std::endl;
    }

    printSubscribers();
}

void Notifier::notify(Notification notif)
{
    if (notif == Notification::GAMEOVER) registerEnabled = false;

    std::cout << "List to notify: ";
    printSubscribers();

    //getting a copy of the current registered subscribers
    auto currentSubs = subscribers;

    for (auto& sub : currentSubs)
    {
        std::cout << "Notifying: " << std::addressof(sub.get()) << std::endl;
        sub.get().update(notif);
    }

}

void Notifier::printSubscribers()
{
    std::cout << "[ ";
    for (auto &sub : subscribers)
    {
        std::cout << std::addressof(sub.get()) << " ";
    }
    std::cout << "]" << std::endl;
}
