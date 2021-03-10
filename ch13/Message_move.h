#include <iostream>
#include <set>
#include <string>

class Folder;

class Message
{
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);

public:
  Message(const std::string &str = std::string())
      : content(str)
  {
  }

  Message &operator=(const Message &rhs);
  Message& Message::operator=(Message&& rhs);
  Message(const Message &rhs);
  Message(Message&& rhs);
  ~Message();

void move_Folders(Message *m);
  void save(Folder &f);
  void remove(Folder &);

private:
  std::string content;
  std::set<Folder *> folders;

  void add_to_Folders(const Message &m);
  void remove_from_Folders();

  void remFldr(Folder *f)
  {
    folders.erase(f);
  }

  void addFlder(Folder *f)
  {
    folders.insert(f);
  }
};

void swap(Message &lhs, Message &rhs);

class Folder
{
  friend class Message;
  friend void swap(Folder &lhs, Folder &rhs);

public:
  Folder() = default;
  ~Folder();
  Folder(const Folder &rhs);

  Folder &operator=(const Folder &rhs);

  void print();

private:
  std::set<Message *> messages;

  void add_to_messages(const Folder &f);
  void remove_from_messages();

  void addMsg(Message *m)
  {
    messages.insert(m);
  }

  void remMsg(Message *m)
  {
    messages.erase(m);
  }
};

void swap(Folder &lhs, Folder &rhs);
