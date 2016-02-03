#include "Notifier.h"
#include "Subscriber.h"
#include <algorithm>
#include <iostream>

Notifier::Notifier()
{}

void Notifier::registerSubscriber(Subscriber &subs)
{
    subscribers.push_back(subs);
    std::cout << "Registered: " << std::addressof(subs) << std::endl;

    printSubscribers();
}

void Notifier::unregisterSubscriber(Subscriber &subs)
{
    auto elem = std::find(subscribers.begin(), subscribers.end(), std::ref(subs));

    if (elem != subscribers.end())
    {
        //subscribers.erase(elem);
        eraseSubsQueue.push(elem);
        std::cout << "Unregistered: " << std::addressof(subs) << std::endl;
    }

    printSubscribers();
}

void Notifier::notify(Notification notif)
{
    std::cout << "Clean up Subscribers list" << std::endl;
    //before notify: clear unregister subscribers
    while(!eraseSubsQueue.empty())
    {
        subscribers.erase(eraseSubsQueue.front());
        eraseSubsQueue.pop();
    }

    std::cout << "List to notify: ";
    printSubscribers();

    for (auto &sub : subscribers)
    {
        std::cout << "------" << std::endl;
        std::cout << "Notifying: " << std::addressof(sub.get()) << std::endl;
        sub.get().update(notif);
    }

    std::cout << "Clean up Subscribers list" << std::endl;
    //after notify: clear unregister subscribers
    while(!eraseSubsQueue.empty())
    {
        subscribers.erase(eraseSubsQueue.front());
        eraseSubsQueue.pop();
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
