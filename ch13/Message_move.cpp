#include "Message_move.h"

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

void Message::move_Folders(Message *m)
{
  folders = std::move(m->folders);
  for (auto f : folders)
  {
    f->remMsg(m);
    f->addMsg(this);
  }
  m->folders.clear();
}

Message::Message(Message &&rhs)
    : content(std::move(rhs.content))
{
  move_Folders(&rhs);
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

Message &Message::operator=(Message &&rhs)
{
  if (this != &rhs)
  {
    remove_from_Folders();
    content = std::move(rhs.content);
    move_Folders(&rhs);
  }
  return *this;
}

Message &Message::operator=(const Message &rhs)
{
  remove_from_Folders();
  content = rhs.content;
  add_to_Folders(rhs);
  return *this;
}