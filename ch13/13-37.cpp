#include "13-37.h"

//Folder definitions:

void swap(Folder &lhs, Folder &rhs)
{
  using std::swap;
  lhs.remove_from_messages();
  rhs.remove_from_messages();
  swap(lhs.messages, rhs.messages);
  lhs.add_to_messages(lhs);
  rhs.add_to_messages(rhs);
}

void Folder::remove_from_messages()
{
  for (auto m : messages)
    m->remFldr(this);
}

Folder::~Folder()
{
  remove_from_messages();
}

void Folder::add_to_messages(const Folder &f)
{
  for (auto m : f.messages)
    m->addFlder(this);
}

Folder::Folder(const Folder &rhs)
    : messages(rhs.messages)
{
  add_to_messages(rhs);
}

Folder &Folder::operator=(const Folder &rhs)
{
  remove_from_messages();
  messages = rhs.messages;
  add_to_messages(rhs);
  return *this;
}

void Folder::print()
{
  if (messages.size() != 0)
  {
    std::cout << "The folder contains the following messages:\n";
    for (const auto m : messages)
      std::cout << m->content << std::endl
                << std::endl;
  }
  else
    std::cout << "The file is currently empty\n";
}

// Message Defintions:

void swap(Message &lhs, Message &rhs)
{
  lhs.remove_from_Folders();
  rhs.remove_from_Folders();

  using std::swap;
  swap(lhs.content, rhs.content);
  swap(lhs.folders, rhs.folders);

  lhs.add_to_Folders(lhs);
  rhs.add_to_Folders(rhs);
}

void Message::save(Folder &f)
{
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f)
{
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
  for (auto f : m.folders)
    f->addMsg(this);
}

Message::Message(const Message &rhs)
    : content(rhs.content),
      folders(rhs.folders)
{
  add_to_Folders(rhs);
}

void Message::remove_from_Folders()
{
  for (auto f : folders)
    f->remMsg(this);
}

Message::~Message()
{
  remove_from_Folders();
}

Message &Message::operator=(const Message &rhs)
{
  remove_from_Folders();
  content = rhs.content;
  add_to_Folders(rhs);
  return *this;
}

int main()
{

  Folder f1;
  f1.print();
  Message m1("this is the first message");
  Message m2("this is the second message");
  m1.save(f1);
  m2.save(f1);
  f1.print();
  m2.remove(f1);
  f1.print();
  Message m3(m1);
  f1.print();
  Folder f2 = f1;
  f2.print();

  return 0;
}
