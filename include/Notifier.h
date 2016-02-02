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
    //queue<position> in vector<Subscriber> to remove
    std::queue<std::list<refSubscriber>::iterator> eraseSubsQueue;

    void printSubscribers();
};

#endif // NOTIFIER_H
