#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>


void copy_text(char* file, std::string a);
void create_file(char* name);
void rename_file(char* file, char* file_to);
void move_file(char* file, char* dir);

int main (int argc, char* argv[]) {
    char *a = argv[1];
    if (*a == 'c') create_file(argv[2]);
    else if(*a == 'r') rename_file(argv[2], argv[3]);
    else if(*a == 'm') move_file(argv[2], argv[3]);
    else if(*a == 'd') remove(argv[2]);
    else 
        std::cout << "unknown command\n";
    return 0;
}

void move_file(char* file, char* dir) {
    copy_text(file, (std::string)dir + '/' + file);
    remove(file);
}

void copy_text(char* file, std::string a) {
    std::ifstream f(file);
    std::ofstream f2(a);
    std::string text;
    if (!f.is_open()) 
        exit(1);
    while(std::getline(f, text)) f2 << text;
    f2 << '\n';
    f.close();
    f2.close();
}
void rename_file(char* file, char* file_to){ 
    copy_text(file, file_to);
    remove(file);
}
void create_file(char* name) {
    std::ofstream file(name);
    file.close();
}
