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
            
            std::cout << current_var->to_string() << "\n";
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

            gso_char test_char = gso_char();
            test_char.set_name("test_char");
            test_char.set_data('a');
            test_output.add_variable(&test_char);

            gso_color test_color = gso_color();
            test_color.set_name("test_color");
            test_color.set_data(255, 255, 255, 1.0f);
            test_output.add_variable(&test_color);

            // i need to add some items into the container later
            gso_container test_container = gso_container();
            test_container.set_name("test_container");
            test_container.add_variable(&test_char);
            test_container.add_variable(&test_color);
            test_output.add_variable(&test_container);

            gso_double test_double1 = gso_double();
            test_double1.set_name("test_double1");
            test_double1.set_data(1.0);

            gso_double test_double2 = gso_double();
            test_double2.set_name("test_double2");
            test_double2.set_data(1.0, 2.0);

            gso_double test_double3 = gso_double();
            test_double3.set_name("test_double3");
            test_double3.set_data(1.0, 2.0, 3.0);

            gso_double test_double4 = gso_double();
            test_double4.set_name("test_double4");
            test_double4.set_data(1.0, 2.0, 3.0, 4.0);

            test_output.add_variable(&test_double1);
            test_output.add_variable(&test_double2);
            test_output.add_variable(&test_double3);
            test_output.add_variable(&test_double4);

            gso_file test_file = gso_file();
            test_file.set_name("test_file");
            test_file.set_path("idk/idk");
            test_output.add_variable(&test_file);

            gso_float test_float1 = gso_float();
            test_float1.set_name("test_float1");
            test_float1.set_data(1.0f);

            gso_float test_float2 = gso_float();
            test_float2.set_name("test_float2");
            test_float2.set_data(1.0f, 2.0f);

            gso_float test_float3 = gso_float();
            test_float3.set_name("test_float3");
            test_float3.set_data(1.0f, 2.0f, 3.0f);

            gso_float test_float4 = gso_float();
            test_float4.set_name("test_float4");
            test_float4.set_data(1.0f, 2.0f, 3.0f, 4.0f);

            test_output.add_variable(&test_float1);
            test_output.add_variable(&test_float2);
            test_output.add_variable(&test_float3);
            test_output.add_variable(&test_float4);

            gso_int test_int1 = gso_int();
            test_int1.set_name("test_int1");
            test_int1.set_data(1);

            gso_int test_int2 = gso_int();
            test_int2.set_name("test_int2");
            test_int2.set_data(1, 2);

            gso_int test_int3 = gso_int();
            test_int3.set_name("test_int3");
            test_int3.set_data(1, 2, 3);

            gso_int test_int4 = gso_int();
            test_int4.set_name("test_int4");
            test_int4.set_data(1, 2, 3, 4);

            test_output.add_variable(&test_int1);
            test_output.add_variable(&test_int2);
            test_output.add_variable(&test_int3);
            test_output.add_variable(&test_int4);


            gso_list test_list_char = gso_list();
            test_list_char.set_name("test_list_char");
            test_list_char.set_type("char");
            gso_list_char test_list_char_item1 = gso_list_char();
            test_list_char_item1.set_data('a');
            test_list_char.add_item(&test_list_char_item1);

            gso_list test_list_color = gso_list();
            test_list_color.set_name("test_list_color");
            test_list_color.set_type("color");
            gso_list_color test_list_color_item1 = gso_list_color();
            test_list_color_item1.set_data(200, 200, 200, 1.0f);
            test_list_color.add_item(&test_list_color_item1);

            gso_list test_list_number = gso_list();
            test_list_number.set_name("test_list_number");
            test_list_number.set_type("number");
            gso_list_number test_list_number_item1 = gso_list_number();
            test_list_number_item1.set_data(10);
            test_list_number.add_item(&test_list_number_item1);

            gso_list test_list_string = gso_list();
            test_list_string.set_name("test_list_string");
            test_list_string.set_type("string");
            gso_list_string test_list_string_item1 = gso_list_string();
            test_list_string_item1.set_data("test");
            gso_list_string test_list_string_item2 = gso_list_string();
            test_list_string_item2.set_data("test2");
            test_list_string.add_item(&test_list_string_item1);
            test_list_string.add_item(&test_list_string_item2);

            test_output.add_variable(&test_list_char);
            test_output.add_variable(&test_list_color);
            test_output.add_variable(&test_list_number);
            test_output.add_variable(&test_list_string);

            gso_number test_number = gso_number();
            test_number.set_name("test_number");
            test_number.set_data(20);
            test_output.add_variable(&test_number);

            gso_string test_string = gso_string();
            test_string.set_name("test_string");
            test_string.set_data("test_string");
            test_output.add_variable(&test_string);

            gso_write_to_file(test_output, GSOFileToLoad);
        }
    }
    return 0;
}