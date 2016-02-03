#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <vector>
#include "Notification.h"
#include <functional>


class Subscriber
{
public:
    virtual ~Subscriber() {};
    virtual void update(Notification notif) = 0;

    friend bool operator==(const std::reference_wrapper<Subscriber> &lhs,
                           const std::reference_wrapper<Subscriber> &rhs);

protected:
    Subscriber() {};

};

//it's not a class method -> symmetry assumption
inline bool operator==(const std::reference_wrapper<Subscriber> &lhs,
                       const std::reference_wrapper<Subscriber> &rhs)
{
    return std::addressof(lhs.get()) == std::addressof(rhs.get());
}

#endif // SUBSCRIBER_H
