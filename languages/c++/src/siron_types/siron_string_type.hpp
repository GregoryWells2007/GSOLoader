#pragma once
#include <cstring>
#include "iostream"

struct siron_string_type {
private:
    char* value = new char[1];

    static int str_len(const char* val) { return strlen(val); }
    static char* add_string(char* str1, char* str2) {
        char* buffer = new char[str_len(str1) + str_len(str2) + 1];

        for (int i1 = 0; i1 < str_len(str1); i1++)
            buffer[i1] = str1[i1];

        for (int i2 = 0; i2 < str_len(str2); i2++)
            buffer[i2 + str_len(str1)] = str2[i2];

        buffer[str_len(str1) + str_len(str2)] = '\0';

        return buffer;
    }
    static char* add_string(char* str1, char str2) {
        char* buffer = new char[str_len(str1) + 2];

        for (int i1 = 0; i1 < str_len(str1); i1++)
            buffer[i1] = str1[i1];

        buffer[str_len(str1)] = str2;

        buffer[str_len(str1) + 1] = '\0';

        return buffer;
    }
    static char* unconst_char_ptr(const char* char_ptr) {
        return const_cast<char*>(char_ptr);
    }
public:
    siron_string_type() { 
        value = new char[1];
        value[0] = '\0'; 
    };
    siron_string_type(char val) {
        value = new char[2];
        value[0] = val;
        value[1] = '\0';
    }
    siron_string_type(char* val) { value = val + '\0'; }
    siron_string_type(const char* val) { value = unconst_char_ptr(val); }
    
    int size() { return str_len(value); }

    operator char*() { return value; } 
    char operator[](int index) { return value [index]; }
    void operator +=(char val) { value = add_string(value, val); }
    void operator +=(char* val) { value = add_string(value, val); }
    void operator +=(const char* val) { value = add_string(value, unconst_char_ptr(val));}

    siron_string_type operator +(char val) { return add_string(value, val); }
    siron_string_type operator +(char* val) { return add_string(value, val); }
    siron_string_type operator +(const char* val) { return add_string(value, unconst_char_ptr(val));}

    void operator =(siron_string_type val) { value = val; }
    void operator =(const char* val) { value = unconst_char_ptr(val); }
    void operator =(char* val) { value = val; }

    
    bool operator ==(char* val) { return (strcmp(value, val) == 0); }
    bool operator ==(const char* val) { return (strcmp(value, unconst_char_ptr(val)) == 0); }
    bool operator ==(siron_string_type val) { return (strcmp(value, unconst_char_ptr(val)) == 0); }

    int find(char val) {
        for (int i = 0; i < str_len(value); i++)
            if (value[i] == val)
                return i;
        return -1;
    }

    char* charv() { return value; }
    const char* ccharv() { return value; }

    int find(const char* val) {
        char first_char = val[0];
        for (int i = 0; i < str_len(value); i++)
            if (value[i] == first_char) {
                bool same = true;
                for (int c = 1; c < str_len(val); c++)
                    if (value[i + c] != val[c]) {
                        same = false;
                        break;
                    }

                if (same)
                    return i;
            }
        return -1;
    }

    int count(char val) {
        int count = 0;
        for (int i = 0; i < str_len(value); i++)
            if (value[i] == val)
                count++;
        return count;
    }

    siron_string_type substring(int index1, int index2) {
        siron_string_type out_value;
        for (int i = 0; i < (index2 - index1); i++)
            out_value += value[i + index1];
        return out_value;
    }
};