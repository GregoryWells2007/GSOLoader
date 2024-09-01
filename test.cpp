#include "iostream"
#include "string"
#include "regex"
#include "chrono"
#include "src/siron_rw.hpp"

#include <unistd.h>

// stack overflow: https://stackoverflow.com/questions/9435385/split-a-string-using-c11
std::vector<std::string> split(const std::string& input, const std::string& regex) {
    std::regex re(regex);
    std::sregex_token_iterator
        first{input.begin(), input.end(), re, -1},
        last;
    return {first, last};
}

// my function don't worry about it
std::string lowercase(std::string input) {
    for (int i = 0; i < input.size(); i++)
        input[i] = std::tolower(input[i]);
    return input;
}

siron_object build_siron_test() {
    siron_object test_output = siron_object();
    test_output.header = siron_header();
    test_output.vars = {};
    test_output.header.version = 1.0;

    siron_char* test_char = new siron_char();
    test_char->set_name("test_char");
    test_char->set_data('a');
    test_output.add_variable(test_char);

    siron_color* test_color = new siron_color();
    test_color->set_name("test_color");
    test_color->set_data(255, 255, 255, 1.0f);
    test_output.add_variable(test_color);

    // i need to add some items into the container later
    siron_container* test_container = new siron_container();
    test_container->set_name("test_container");
    test_container->add_variable(test_char);
    test_container->add_variable(test_color);
    test_output.add_variable(test_container);

    siron_double* test_double1 = new siron_double();
    test_double1->set_name("test_double1");
    test_double1->set_data(1.0);

    siron_double* test_double2 = new siron_double();
    test_double2->set_name("test_double2");
    test_double2->set_data(1.0, 2.0);

    siron_double* test_double3 = new siron_double();
    test_double3->set_name("test_double3");
    test_double3->set_data(1.0, 2.0, 3.0);

    siron_double* test_double4 = new siron_double();
    test_double4->set_name("test_double4");
    test_double4->set_data(1.0, 2.0, 3.0, 4.0);

    test_output.add_variable(test_double1);
    test_output.add_variable(test_double2);
    test_output.add_variable(test_double3);
    test_output.add_variable(test_double4);

    siron_file* test_file = new siron_file();
    test_file->set_name("test_file");
    test_file->set_path("write_file_test.siron");
    test_output.add_variable(test_file);

    siron_float* test_float1 = new siron_float();
    test_float1->set_name("test_float1");
    test_float1->set_data(1.0f);

    siron_float* test_float2 = new siron_float();
    test_float2->set_name("test_float2");
    test_float2->set_data(1.0f, 2.0f);

    siron_float* test_float3 = new siron_float();
    test_float3->set_name("test_float3");
    test_float3->set_data(1.0f, 2.0f, 3.0f);

    siron_float* test_float4 = new siron_float();
    test_float4->set_name("test_float4");
    test_float4->set_data(1.0f, 2.0f, 3.0f, 4.0f);

    test_output.add_variable(test_float1);
    test_output.add_variable(test_float2);
    test_output.add_variable(test_float3);
    test_output.add_variable(test_float4);

    siron_int* test_int1 = new siron_int();
    test_int1->set_name("test_int1");
    test_int1->set_data(1);

    siron_int* test_int2 = new siron_int();
    test_int2->set_name("test_int2");
    test_int2->set_data(1, 2);

    siron_int* test_int3 = new siron_int();
    test_int3->set_name("test_int3");
    test_int3->set_data(1, 2, 3);

    siron_int* test_int4 = new siron_int();
    test_int4->set_name("test_int4");
    test_int4->set_data(1, 2, 3, 4);

    test_output.add_variable(test_int1);
    test_output.add_variable(test_int2);
    test_output.add_variable(test_int3);
    test_output.add_variable(test_int4);


    siron_list* test_list_char = new siron_list();
    test_list_char->set_name("test_list_char");
    test_list_char->set_type("char");
    siron_list_char* test_list_char_item1 =new siron_list_char();
    test_list_char_item1->set_data('a');
    test_list_char->add_item(test_list_char_item1);

    siron_list* test_list_color = new siron_list();
    test_list_color->set_name("test_list_color");
    test_list_color->set_type("color");
    siron_list_color* test_list_color_item1 = new siron_list_color();
    test_list_color_item1->set_data(200, 200, 200, 1.0f);
    test_list_color->add_item(test_list_color_item1);

    siron_list* test_list_number = new siron_list();
    test_list_number->set_name("test_list_number");
    test_list_number->set_type("number");
    siron_list_number* test_list_number_item1 = new siron_list_number();
    test_list_number_item1->set_data(10);
    test_list_number->add_item(test_list_number_item1);

    siron_list* test_list_string = new siron_list();
    test_list_string->set_name("test_list_string");
    test_list_string->set_type("string");
    siron_list_string* test_list_string_item1 = new siron_list_string();
    test_list_string_item1->set_data("test");
    siron_list_string* test_list_string_item2 = new siron_list_string();
    test_list_string_item2->set_data("test2");
    test_list_string->add_item(test_list_string_item1);
    test_list_string->add_item(test_list_string_item2);

    test_output.add_variable(test_list_char);
    test_output.add_variable(test_list_color);
    test_output.add_variable(test_list_number);
    test_output.add_variable(test_list_string);

    siron_number* test_number = new siron_number();
    test_number->set_name("test_number");
    test_number->set_data(20);
    test_output.add_variable(test_number);

    siron_string* test_string = new siron_string();
    test_string->set_name("test_string");
    test_string->set_data("test_string");
    test_output.add_variable(test_string);

    return test_output;
}

enum class test_options {
    none, reading, writing, timing
};

void read_file(const char* path) {
    std::cout << "Loading File: " << path << "\n";
    siron_object currentObject = siron_read_from_file(path);

    char quit = 'n';

    while (quit != 'y' && quit != 'Y') {

        std::string variable_type;
        std::string variable_name;

        std::cout << "Reading a variable: \n";
        std::cout << "  Variable type: ";
        std::cin >> variable_type;
        std::cout << "  Variable Name (add a '/' if its in a container): ";
        std::cin >> variable_name;

        std::vector<std::string> variable_path = split(variable_name, "/");

        siron_var* current_var = currentObject.get_variable(siron_string_type(variable_path[0].c_str()));

        for (int i = 1; i < variable_path.size(); i++) {
            siron_container container = *dynamic_cast<siron_container*>(current_var);
            current_var = container.get_variable(siron_string_type(variable_path[i].c_str()));
        }
        
        std::cout << current_var->to_string() << "\n";
        std::cout << "Quit (y/n): ";
        std::cin >> quit;  
    }
}
void write_file(const char* path) {
    std::cout << "Do you want to write a custom file (y/n): ";
    char custom = ' ';
    std::cin >> custom;
    if (custom == 'y' || custom == 'Y') {
        std::cout << "Come back later I have more important things to work on\n";
    } else {
        std::cout << "Writing a test siron file at: " << path << "\n";
        siron_object test_output = build_siron_test();
        siron_write_to_file(test_output, path);
    }
}
void time_file() {
    int iteration_count = 10;
    std::vector<float> read_times = {};
    float read_times_avarage = 0;
    std::vector<float> write_times = {};
    float write_times_avarage = 0;

    std::cout << "Starting siron time tests\n";
    std::cout << ": Iteration Count: " << iteration_count << "\n\n";
    std::cout << "Running siron write speed test\n\n";
    siron_object siron_test_file = build_siron_test();
    for (int i = 0; i < iteration_count; i++) {
        std::cout << ": Starting iteration " << i << "\n";

        auto tp1_w = std::chrono::high_resolution_clock::now();
        siron_write_to_file(siron_test_file, "time_test.siron");
        auto tp2_w = std::chrono::high_resolution_clock::now();
        auto total_time_write = std::chrono::duration_cast<std::chrono::milliseconds>(tp2_w - tp1_w);
        write_times.push_back((total_time_write.count() / 1000.0f));

        std::cout << ": Finished iteration\n\n";
    }
    std::cout << "Finished siron write speed test\n\n\n";

    std::cout << "Running siron read speed test\n\n";

    for (int i = 0; i < iteration_count; i++) {
        std::cout << ": Starting iteration " << i << "\n";

        auto tp1 = std::chrono::high_resolution_clock::now();
        siron_object currentObject = siron_read_from_file("time_test.siron");
        auto tp2 = std::chrono::high_resolution_clock::now();
        auto total_time_read = std::chrono::duration_cast<std::chrono::milliseconds>(tp2 - tp1);
        read_times.push_back((total_time_read.count() / 1000.0f));

        std::cout << ": Finished iteration\n\n";
    }

    std::cout << "Finished siron read speed test\n\n";


    std::cout << "Finalizing results\n";

    for (int k = 0; k < iteration_count; k++) {
        read_times_avarage += read_times[k];
        write_times_avarage += write_times[k];
    }
    read_times_avarage /= iteration_count;
    write_times_avarage /= iteration_count;


    std::cout << ": Read speed test\n";
    std::cout << ":  Avarage time " << read_times_avarage << "s |\n";
    std::cout << ":  Times ";
    for (int k = 0; k < iteration_count; k++)
        std::cout << read_times[k] << "s ";
    std::cout << "\n";

    std::cout << ": Write speed test\n";
    std::cout << ":  Avarage time " << write_times_avarage << "s |\n";\
    std::cout << ":  Times ";
        for (int k = 0; k < iteration_count; k++)
        std::cout << write_times[k] << "s ";
    std::cout << "\n";
}

// the inputs are (Reading/Writing) Path
int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "You need to input the file type\n";
        return 0;
    }

    const char* sironFileToLoad = "";
    test_options option = test_options::none;

    std::string name = lowercase(std::string(argv[1]));
    sironFileToLoad = argv[2];

    if (name == std::string("reading"))
        option = test_options::reading;
    else if (name == std::string("writing"))
        option = test_options::writing;
    else if (name == std::string("timing"))
        option = test_options::timing;

    if (option != test_options::timing && argc == 2) {
        std::cout << "You need to input a path to a file\n";
        return 0;
    }

    switch(option) {
        case test_options::none: std::cout << "You need to say a valid option\n"; break;
        case test_options::reading: read_file(sironFileToLoad); break;
        case test_options::writing: write_file(sironFileToLoad); break;
        case test_options::timing: time_file(); break;
    }


    return 0;
}