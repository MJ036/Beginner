#include "Message.h"
#include <functional>
#include <mysql/mysql.h>
#include <utility>

void Message::save(Folder& f){
    _folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f){
    _folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m){
    for(auto f : m._folders){
        f->addMsg(this);
    }
}
void Message::remove_from_Folders(){
    for(auto f : _folders){
        f->remMsg(this);
    }
}

Message::Message(const Message& m):
    _contents(m._contents),_folders(m._folders)
{
    add_to_Folders(*this);
}

Message::~Message(){
    remove_from_Folders();
}

Message&  Message::operator=(const Message& rhs){
    remove_from_Folders();
    _contents = rhs._contents;
    _folders = rhs._folders;
    add_to_Folders(rhs);
    return *this;
}
Message::Message(Message&& rhs) noexcept
:_contents(std::move(rhs._contents))
{
    move_Folders(&rhs);  

}
Message& Message::operator=(Message&& rhs) noexcept{
    if(this != &rhs){
        remove_from_Folders();
        _contents = std::move(rhs._contents);
        move_Folders(&rhs);

        
    }

    return *this;
}
void Message::swap(Message &lhs, Message &rhs){
    using std::swap;
    for(auto f : lhs._folders){
        f->remMsg(&lhs);
    }
    for(auto f : rhs._folders){
        f->remMsg(&rhs);
    }
    swap(lhs._contents,rhs._contents);
    swap(lhs._folders, rhs._folders);
    for(auto f : lhs._folders){
        f->addMsg(&rhs);
    }
    for(auto f : rhs._folders){
        f->addMsg(&lhs);
    }
}
void Message::addFld(Folder *pf){
    _folders.insert(pf);
}
void Message::remFld(Folder *pf){
    _folders.erase(pf);
}
void Message::move_Folders(Message *m){
    _folders = std::move(m->_folders);
    for(auto f : _folders){
        f->remMsg(m);
        f->addMsg(this);
    }
    m->_folders.clear();
}
