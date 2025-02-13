#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "mai.h"
#include <sys/socket.h>

using namespace std;

class Folder;

class Message
{
    friend class Folder;
public:
    explicit Message(const string &str = ""):_contents(str){}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void swap(Message &lhs, Message &rhs);

    void addFld(Folder *);
    void remFld(Folder *);

private:
    string _contents;
    set<Folder*> _folders;
    //向folder中添加Message
    void add_to_Folders(const Message&);
    //从folders中的每个Folder中，删除本Message
    void remove_from_Folders();

};
class Folder{
public:
    Folder();

    void addMsg(Message* pm){_messages.insert(pm);}
    void remMsg(Message* pm){_messages.erase(pm);};
private:
    set<Message*> _messages;

};
#endif


