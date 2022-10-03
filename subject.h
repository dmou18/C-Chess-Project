#ifndef Subject_H
#define Subject_H
#include <Vector> 
#include <Observer>

struct Position;
class Piece;
class Observer;


class Subject() {
    vector<Piece> observers*;
    protected:
    virtual void setState(Piece) = 0;
    public:
    void attach (Observer *);
    void detach();
    void NotifyObervers();
    virtual Position getState();
};


void Subject:attach(Observer *ob) {
    observers.emplace_back(ob);
}


void Subject:detach() {
    if (observers.size() != 0) {
        observers.pop_back();
    }
}


void Subject:NotifyObservers {
    for (auto &ob : observers) ob->notify(*this);
}


#endif
