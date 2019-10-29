// Purpose:  Code Sample to Reverse a string via multiple methods:
//    Printing from end of string via string-end iterator
//    Standard library algorithm::reverse method
//    Standard library vector-end iterator
//    Standard library stack

#include <iostream>       // cout, endl
#include <string>         // string, iterator
#include <algorithm>      // reverse
#include <vector>         // vector, iterator
#include <stack>          // stack

int main(int argc, char** argv)
{
  // Usage
  if (argc != 2)
    {
      std::cout << "Usage: " << argv[0];
      std::cout << " [single string to reverse]" << std::endl;
      return 0;
    }
  
  std::string s(argv[1]); // initial string

  // Initial String
  std::cout << "Initial string:\t\t\t\t" << s << std::endl;


  // Reverse by printing from the string end w/ string end-iterator.
  std::string::iterator sp=s.end();

  std::cout << "Print from end of string w/ pointer:\t";
  do
    {
      --sp;
      std::cout << *sp;
    } while (sp != s.begin());
  std::cout << std::endl;
  

  // Reverse via standard library algorithm::reverse
  std::string s1(s);      // working string for reversal
  
  std::cout << "Using algorithm::reverse():\t\t";
  reverse(s1.begin(), s1.end());
  std::cout << s1 << std::endl;
  

  // Reverse via standard library vector, reverse_iterator
  std::vector<char> myvect;
  
  std::cout << "Reverse via Vector rbegin(), rend():\t";
  for (std::string::iterator sptr=s.begin();
       sptr != s.end(); ++sptr)
    {
      myvect.push_back(*sptr);
    }

  for (std::vector<char>::reverse_iterator it=myvect.rbegin();
       it != myvect.rend(); ++it)
    {
      std::cout << *it;
    }
  std::cout << std::endl;

  
  // Reverse via standard library stack
  std::stack<char> mystack;

  std::cout << "Reversing w/ stack:\t\t\t";
  for (std::string::iterator sptr=s.begin();
       sptr != s.end(); ++sptr)
    {
      mystack.push(*sptr);
    }
  while (!mystack.empty())
    {
      std::cout << mystack.top();
      mystack.pop();
    }
  std::cout << std::endl;

}
