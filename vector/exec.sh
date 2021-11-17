clang++ -Wall -Wextra -Werror my_vec.cpp -o my_vec && 
./my_vec > my_log.txt && 
clang++ -Wall -Wextra -Werror std_vec.cpp -o std_vec &&
./std_vec > std_log.txt &&
diff std_log.txt my_log.txt



