# Compiles with a flag for gdb and then begins debugging
 g++ -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic driver.cpp -g; gdb a.out;
