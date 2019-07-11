# Compiles, outputs warnings, and then checks for memory leaks
g++ -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic driver.cpp; valgrind --leak-check=full -v ./a.out
