#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <sys/mman.h>

#include "timecheck.h"

typedef decltype(DELTA_TIME()) time_type;

enum class TEST {
    SWITCH,
    IF_ELSE,
    FUNC_ARRAY,
    SELF_MODIFY
};

constexpr size_t MAX_COUNT = 40;

template<TEST = TEST::SWITCH>
time_type test(size_t size, size_t count) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.emplace_back(random() % std::min(count, MAX_COUNT));
    }

    volatile auto variable = 24;
    START_TIME();
    for (auto i = 0; i < size; ++i) {
        switch (arr[i]) {
        case 0: {
            variable = 0;
        } break;
        case 1: {
            variable = 1;
        } break;
        case 2: {
            variable = 2;
        } break;
        case 3: {
            variable = 3;
        } break;
        case 4: {
            variable = 4;
        } break;
        case 5: {
            variable = 5;
        } break;
        case 6: {
            variable = 6;
        } break;
        case 7: {
            variable = 7;
        } break;
        case 8: {
            variable = 8;
        } break;
        case 9: {
            variable = 9;
        } break;
        case 10: {
            variable = 10;
        } break;
        case 11: {
            variable = 11;
        } break;
        case 12: {
            variable = 12;
        } break;
        case 13: {
            variable = 13;
        } break;
        case 14: {
            variable = 14;
        } break;
        case 15: {
            variable = 15;
        } break;
        case 16: {
            variable = 16;
        } break;
        case 17: {
            variable = 17;
        } break;
        case 18: {
            variable = 18;
        } break;
        case 19: {
            variable = 19;
        } break;
        case 20: {
            variable = 20;
        } break;
        case 21: {
            variable = 21;
        } break;
        case 22: {
            variable = 22;
        } break;
        case 23: {
            variable = 23;
        } break;
        case 24: {
            variable = 24;
        } break;
        case 25: {
            variable = 25;
        } break;
        case 26: {
            variable = 26;
        } break;
        case 27: {
            variable = 27;
        } break;
        case 28: {
            variable = 28;
        } break;
        case 29: {
            variable = 29;
        } break;
        case 30: {
            variable = 30;
        } break;
        case 31: {
            variable = 31;
        } break;
        case 32: {
            variable = 32;
        } break;
        case 33: {
            variable = 33;
        } break;
        case 34: {
            variable = 34;
        } break;
        case 35: {
            variable = 35;
        } break;
        case 36: {
            variable = 36;
        } break;
        case 37: {
            variable = 37;
        } break;
        case 38: {
            variable = 38;
        } break;
        case 39: {
            variable = 39;
        } break;
        default: break;
        }        
    }
    END_TIME();

    return DELTA_TIME();
}

template<>
time_type test<TEST::IF_ELSE>(size_t size, size_t count) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.emplace_back(random() % std::min(count, MAX_COUNT));
    }

    volatile auto variable = 1399;
    START_TIME();
    for (auto i = 0; i < size; ++i) {
        if (arr[i] == 0) { variable = 0; }
        else if (arr[i] == 1) { variable = 1; }
        else if (arr[i] == 2) { variable = 2; }
        else if (arr[i] == 3) { variable = 3; }
        else if (arr[i] == 4) { variable = 4; }
        else if (arr[i] == 5) { variable = 5; }
        else if (arr[i] == 6) { variable = 6; }
        else if (arr[i] == 7) { variable = 7; }
        else if (arr[i] == 8) { variable = 8; }
        else if (arr[i] == 9) { variable = 9; }
        else if (arr[i] == 10) { variable = 10; }
        else if (arr[i] == 11) { variable = 11; }
        else if (arr[i] == 12) { variable = 12; }
        else if (arr[i] == 13) { variable = 13; }
        else if (arr[i] == 14) { variable = 14; }
        else if (arr[i] == 15) { variable = 15; }
        else if (arr[i] == 16) { variable = 16; }
        else if (arr[i] == 17) { variable = 17; }
        else if (arr[i] == 18) { variable = 18; }
        else if (arr[i] == 19) { variable = 19; }
        else if (arr[i] == 20) { variable = 20; }
        else if (arr[i] == 21) { variable = 21; }
        else if (arr[i] == 22) { variable = 22; }
        else if (arr[i] == 23) { variable = 23; }
        else if (arr[i] == 24) { variable = 24; }
        else if (arr[i] == 25) { variable = 25; }
        else if (arr[i] == 26) { variable = 26; }
        else if (arr[i] == 27) { variable = 27; }
        else if (arr[i] == 28) { variable = 28; }
        else if (arr[i] == 29) { variable = 29; }
        else if (arr[i] == 30) { variable = 30; }
        else if (arr[i] == 31) { variable = 31; }
        else if (arr[i] == 32) { variable = 32; }
        else if (arr[i] == 33) { variable = 33; }
        else if (arr[i] == 34) { variable = 34; }
        else if (arr[i] == 35) { variable = 35; }
        else if (arr[i] == 36) { variable = 36; }
        else if (arr[i] == 37) { variable = 37; }
        else if (arr[i] == 38) { variable = 38; }
        else if (arr[i] == 39) { variable = 39; }
    }
    END_TIME();
    return DELTA_TIME();
}

typedef void (*func_type)(volatile size_t&);
template<size_t N>
void func(volatile size_t& variable) {
    volatile size_t temp = N;
    variable = temp;
}

template<size_t N>
void initialize_func_array(std::vector<func_type>& arr) {
    arr.emplace_back(&func<N>);
    initialize_func_array<N-1>(arr);
}

template<>
void initialize_func_array<0>(std::vector<func_type>& arr) {
    arr.emplace_back(&func<0>);
}

template<>
time_type test<TEST::FUNC_ARRAY>(size_t size, size_t count) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.emplace_back(random() % std::min(count, size_t(MAX_COUNT)));
    }

    std::vector<func_type> functions;
    initialize_func_array<MAX_COUNT>(functions);

    volatile size_t variable = 4123;
    START_TIME();
    for (auto i = 0; i < size; ++i) {
        functions[arr[i]](variable);
    }
    END_TIME();
    return DELTA_TIME();
}

extern "C" size_t self_modify(size_t);
template<>
time_type test<TEST::SELF_MODIFY>(size_t size, size_t count) {
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        arr.emplace_back(random() % std::min(count, MAX_COUNT));
    }

    START_TIME();
    for (size_t i = 0; i < size; ++i) {
        self_modify(arr[i]);
    }
    END_TIME();
    return DELTA_TIME();
}

int change_page_permissions_of_address(size_t addr) {
    int page_size = getpagesize();
    addr -= (size_t)addr % page_size;

    if(mprotect((void*)addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return -1;
    }

    return 0;
}

int main() {
    auto& fout  = std::cout;
    if (change_page_permissions_of_address((size_t)self_modify) == -1) {
        fout << "Can't change permissions for code modification" << std::endl;
        return -1;
    }

    constexpr auto count_iterations = 10000000;

    for (size_t i = 2; i < MAX_COUNT; ++i) {
        fout << static_cast<size_t>(TEST::SWITCH) << " " << i << " " << test<TEST::SWITCH>(count_iterations, i) << std::endl;
        fout << static_cast<size_t>(TEST::IF_ELSE) << " " << i << " " << test<TEST::IF_ELSE>(count_iterations, i) << std::endl;
        fout << static_cast<size_t>(TEST::FUNC_ARRAY) << " " << i << " " << test<TEST::FUNC_ARRAY>(count_iterations, i) << std::endl;
        fout << static_cast<size_t>(TEST::SELF_MODIFY) << " " << i << " " << test<TEST::SELF_MODIFY>(count_iterations, i) << std::endl;
    }
    return 0;
}