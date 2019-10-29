CXX=g++
CPPFLAGS = -g
LDFLAGS = -g

# Palindrome
SRCS_PALINDROME = palindrome.cpp
OBJS_PALINDROME = $(subst .cpp,.o,$(SRCS_PALINDROME))
TARGET_PALINDROME = palindrome
TEST_PALINDROME = memcheck_palindrome

# Reverse String
SRCS_REVERSESTRING = reverseString.cpp
OBJS_REVERSESTRING = $(subst .cpp,.o,$(SRCS_REVERSESTRING))
TARGET_REVERSESTRING = reverseString
TEST_REVERSESTRING = memcheck_reverseString

SRCS = $(SRCS_PALINDROME) $(SRCS_REVERSESTRING)
OBJECTS = $(subst .cpp,.o,$(SRCS))
TARGETS = $(TARGET_PALINDROME) $(TARGET_REVERSESTRING)
TESTS = $(TEST_PALINDROME) $(TEST_REVERSESTRING)

all: $(TARGETS)

palindrome: $(OBJS_PALINDROME)
	$(CXX) $(CPPFLAGS) -o palindrome $(OBJS_PALINDROME)

reverseString: $(OBJS_REVERSESTRING)
	$(CXX) $(CPPFLAGS) -o reverseString $(OBJS_REVERSESTRING)

memcheck_palindrome: $(TARGET_PALINDROME)
	/usr/bin/valgrind --leak-check=full ./$(TARGET_PALINDROME) $(palString)

memcheck_reverseString: $(TARGET_REVERSESTRING)
	/usr/bin/valgrind --leak-check=full ./$(TARGET_REVERSESTRING) $(revString)

test_palindrome: $(TEST_PALINDROME)
test_reverseString: $(TEST_REVERSESTRING)
tests: $(TESTS)

clean:
	rm -f $(OBJECTS) $(TARGETS)

%.o:%c
	$(CXX) $(CPPFLAGS) -c $<



