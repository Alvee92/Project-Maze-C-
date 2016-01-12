#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

#endif // MYEXCEPTION_H
