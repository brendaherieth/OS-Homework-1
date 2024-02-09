#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 
void printmenu() {
    std::cout << "Menu options" << std::endl;
    std::cout << "Option 1: dr" << std::endl;
    std::cout << "Option 2: cd" << std::endl;
    std::cout << "Option 3: mkdir" << std::endl;
    std::cout << "Option 4: echo" << std::endl;
    std::cout << "Option 5: type" << std::endl;
    std::cout << "Option 6: exit" << std::endl;
}

bool shouldexitProgram(int input) {
    if (input < 1) {
        std::cout << "Input can't be less than 1" << std::endl;
        return false;
    }
    else if (input > 6) {
        std::cout << "Input can't be greater than 6" << std::endl;
        return false;
    }
    else if (input == 6) {
        std::cout << " Program stop " << std::endl << std::endl;
        return true;
    }
    else {
        return false;
    }
}

void homeworkprogram() {
    int userinput;
    std::string file1Name, file2Name, message, command;
    std::ofstream file1, file2;

    do {
        std::cin >> userinput;
        switch (userinput) {
        case 1: // directory files
            std::cout << " Execute dr " << std::endl << std::endl;
            std::system("ls");
            break;
        case 2: //current directory
            std::cout << " Execute cd " << std::endl << std::endl;
            std::system("cd");
            break;
        case 3: // Make new directory
            std::cout << " Execute mkdir " << std::endl << std::endl;
            std::system("mkdir NewDirectory");
            break;
        case 4:
            std::cout << "Enter message to display: ";
            std::cin.ignore(); // ignoring any previous newline characters.
            getline(std::cin, message); // read the entire line of input including spaces.
            // call helper method to display message
            std::system(("echo " + message).c_str());
            break;
        case 5:
            std::cout << "Enter file 1 name: ";
            std::cin >> file1Name;
            std::cout << "Enter file 2 name: ";
            std::cin >> file2Name;
            file1.open(file1Name);
            if (!file1.is_open()) {
                std::cout << "Error: unable to create/open file " << file1Name << std::endl;
            }
            else {
                file1 << "Content of file 1\n"; // Writing content to file
                file1.close(); // Close file after content is written into
            }
            file2.open(file2Name);
            if (!file2.is_open()) {
                std::cout << "Error: unable to create/open file " << file2Name << std::endl;
            }
            else {
                file2 << "Content of file 2\n"; // Writing content to file
                file2.close(); // Close file after content is written into
            }
            // Concatenate and display content of the two files
            command = "type " + file1Name + " && type " + file2Name;
            std::system(command.c_str());
            std::cout << " Execute type " << std::endl << std::endl;
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (!shouldexitProgram(userinput));
}

int main() {
    
    printmenu();
    homeworkprogram();
    return 0;
}