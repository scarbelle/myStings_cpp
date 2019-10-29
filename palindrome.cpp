#include <string>
#include <iostream>       // cout, endl

int main(int argc, char** argv)
{
  if (argc != 2)
    {
      std::cout << "Usage: " << argv[0];
      std::cout << " [single string to test.]" << std::endl;
      return 0;
    }
  else
    {
      std::string s(argv[1]); 
      bool palindrome=true;
      bool done=false;

      std::cout << "String: " << s << std::endl;

      if (s.length() == 1)
        {
          done=true;
        }
      else
        {
          std::string::iterator front=s.begin();
          std::string::iterator back=(--s.end());

          while (!done && (front < back))
            {
              std::cout << " front: " << *front;
              std::cout << " back: " << *back << std::endl;
              if (*front != *back)
                {
                  palindrome=false;
                  done=true;
                }
              ++front; --back;
            }
        }
      std::cout << "String: " << argv[1] << " is ";
      if (!palindrome)
        {
          std::cout << "NOT ";
        }
      std::cout << "a palindrome." << std::endl;
    }
}
