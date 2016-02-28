#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <vector>
#include <list>
#include <queue>
#include <functional>
#include "Notification.h"

class Subscriber; //forward declaration

class Notifier
{
public:
    Notifier();

    void registerSubscriber(Subscriber &subs);
    void unregisterSubscriber(Subscriber &subs);
    void notify(Notification notif);

private:
    typedef std::reference_wrapper<Subscriber> refSubscriber;

    std::list<refSubscriber> subscribers;
    bool registerEnabled;

    void printSubscribers();
};

#endif // NOTIFIER_H
