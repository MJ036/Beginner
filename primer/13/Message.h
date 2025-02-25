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
    Message(Message&&) noexcept;
    Message& operator=(const Message&);
    Message& operator=(Message&&) noexcept;
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void swap(Message &lhs, Message &rhs);

    void addFld(Folder *);
    void remFld(Folder *);

private:
    string _contents;
    set<Folder*> _folders;
    //工具函数
    //向folder中添加Message
    void add_to_Folders(const Message&);
    //从folders中的每个Folder中，删除本Message
    void remove_from_Folders();
    //移动语义的公共操作。将_folders中的原msg指针移除，添加新msg指针
    void move_Folders(Message *m);

};
class Folder{
public:
    Folder();

    void addMsg(Message* pm){_messages.insert(pm);}
    void remMsg(Message* pm){_messages.erase(pm);};
    void clear(){
        _messages.clear();
    }
private:
    set<Message*> _messages;

};
#endif


