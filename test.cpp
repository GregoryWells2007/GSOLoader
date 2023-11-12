#include "iostream"
#include "string"
#include "regex"
#include "src/gso_rw.h"


// stack overflow: https://stackoverflow.com/questions/9435385/split-a-string-using-c11
std::vector<std::string> split(const std::string& input, const std::string& regex) {
    std::regex re(regex);
    std::sregex_token_iterator
        first{input.begin(), input.end(), re, -1},
        last;
    return {first, last};
}

// the inputs are (Reading/Writing) Path
int main(int argc, char** argv) {
    const char* GSOFileToLoad = "";
    bool reading = false;

    std::cout << "[" << argv[1] << "]\n";

    if (std::string(argv[1]) == std::string("Reading"))
        reading = true;
    GSOFileToLoad = argv[2];

    if (reading) {
        std::cout << "Loading File: " << GSOFileToLoad << "\n";
        gso_object currentObject = gso_read_from_file(GSOFileToLoad);

        char quit = 'n';

        while (quit != 'y') {

            std::string variable_type;
            std::string variable_name;

            std::cout << "Reading a variable: \n";
            std::cout << "  Variable type: ";
            std::cin >> variable_type;
            std::cout << "  Variable Name (add a '/' if its in a container): ";
            std::cin >> variable_name;

            std::vector<std::string> variable_path = split(variable_name, "/");

            gso_var* current_var = currentObject.get_variable(gso_string_type(variable_path[0].c_str()));

            for (int i = 1; i < variable_path.size(); i++) {
                gso_container container = *dynamic_cast<gso_container*>(current_var);
                current_var = container.get_variable(gso_string_type(variable_path[i].c_str()));
            }
            
            if (variable_type == "number") {
                gso_number variable = *dynamic_cast<gso_number*>(current_var);
                int variable_data = variable;
                std::cout << "  Variable loaded: " << variable_data << "\n";
            }
            if (variable_type.find("int") != std::string::npos) {
                gso_int variable = *dynamic_cast<gso_int*>(current_var);
                gso_tuple_type<int, int, int, int> variable_data = variable;
                std::cout << "  Variable Loaded: \n";
        
                std::cout << "      " << variable_data.get(0) << "\n";
                if (variable.get_count() > 1)
                    std::cout << "      " << variable_data.get(1) << "\n";
                if (variable.get_count() > 2)
                    std::cout << "      " << variable_data.get(2) << "\n";
                if (variable.get_count() > 3)
                    std::cout << "      " << variable_data.get(3) << "\n";
            }
            if (variable_type.find("float") != std::string::npos) {
                gso_float variable = *dynamic_cast<gso_float*>(current_var);
                gso_tuple_type<float, float, float, float> variable_data = variable;
                std::cout << "    Variable Loaded: \n";
        
                std::cout << "      " << variable_data.get(0) << "\n";
                if (variable.get_count() > 1)
                    std::cout << "      " << variable_data.get(1) << "\n";
                if (variable.get_count() > 2)
                    std::cout << "      " << variable_data.get(2) << "\n";
                if (variable.get_count() > 3)
                    std::cout << "      " << variable_data.get(3) << "\n";
            }
            if (variable_type.find("double") != std::string::npos) {
                gso_double variable = *dynamic_cast<gso_double*>(current_var);
                gso_tuple_type<double, double, double, double> variable_data = variable;
                std::cout << "    Variable Loaded: \n";
        
                std::cout << "      " << variable_data.get(0) << "\n";
                if (variable.get_count() > 1)
                    std::cout << "      " << variable_data.get(1) << "\n";
                if (variable.get_count() > 2)
                    std::cout << "      " << variable_data.get(2) << "\n";
                if (variable.get_count() > 3)
                    std::cout << "      " << variable_data.get(3) << "\n";
            }
            if (variable_type == "color") {
                gso_color variable = *dynamic_cast<gso_color*>(current_var);
                std::cout << "  Variable loaded: (" << variable.r << ", " << variable.g << ", " << variable.b << ", " << variable.a << ")\n";
            }
            if (variable_type == "char") {
                gso_char variable = *dynamic_cast<gso_char*>(current_var);
                char variable_data = variable;
                std::cout << "    Variable loaded: " << variable_data << "\n";
            }
            if (variable_type == "string") {
                gso_string variable = *dynamic_cast<gso_string*>(current_var);
                std::string variable_data = ((gso_string_type)variable).ccharv();
                std::cout << "  Variable loaded: " << variable_data << "\n";
            }
            if (variable_type == "file") {
                gso_file variable = *dynamic_cast<gso_file*>(current_var);
                std::string variable_data = ((gso_string_type)variable).ccharv();
                std::cout << "  Variable loaded: \n" << variable_data << "\n";
            }
            if (variable_type == "list") {
                gso_list variable = *dynamic_cast<gso_list*>(current_var);
                std::cout << "  Variable Loaded: \n";
                std::cout << "      List Type: " << variable.type << "\n";
                if (variable.type == "char") { 
                    for (int i = 0; i < variable.items.size(); i++) {
                        gso_list_char char_var = variable.get_item<gso_list_char>(i);
                        char char_value = char_var;
                        std::cout << "      " << char_value << "\n";
                    }
                }
                if (variable.type == "color") { 
                    for (int i = 0; i < variable.items.size(); i++) {
                        gso_list_color color_var = variable.get_item<gso_list_color>(i);
                        std::cout << "      (" << color_var.r << ", " << color_var.g << ", " << color_var.b << ", " << color_var.a << ")\n";
                    }
                }

                if (variable.type == "number") { 
                    for (int i = 0; i < variable.items.size(); i++) {
                        gso_list_number number_var = variable.get_item<gso_list_number>(i);
                        double number_value = number_var;
                        std::cout << "      " << number_value << "\n";
                    }
                }
                if (variable.type == "string") { 
                    for (int i = 0; i < variable.items.size(); i++) {
                        gso_list_string string_var = variable.get_item<gso_list_string>(i);
                        std::string string_value = ((gso_string_type)string_var).ccharv();
                        std::cout << "      " << string_value << "\n";
                    }
                }
            }

            std::cout << "Quit (y/n): ";
            std::cin >> quit;  
        }
    } else {
        std::cout << "Writing File at path: " << GSOFileToLoad << "\n";
        std::cout << "Do you want to just write a custom GSO file (y/n): ";
        char custom = ' ';
        std::cin >> custom;
        if (custom == 'y') {
            std::cout << "not supported yet im working on this\n";
        } else {
            std::cout << "Writing a test GSO file at: " << GSOFileToLoad << "\n";
            gso_object test_output = gso_object();
            test_output.header.version = 1.0;

            gso_write_to_file(test_output, GSOFileToLoad);
        }
    }
    return 0;
}