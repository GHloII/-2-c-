#include <iostream>
#include <string>
#include <fstream>
#include "PhoneUser.h"

using std::string;


string PhoneUser::GetName() {
    return name_;
}

string PhoneUser::GetSecondName() {
    return second_name_;
}

string PhoneUser::GetAddress() {
    return address_;
}

int PhoneUser::GetPhoneNumber() {
    return phone_number_;
}

int PhoneUser::GetTimeInnerCityCalls() {
    return time_inner_city_calls_;
}

int PhoneUser::GetTimeLongDistanceCalls() {
    return time_long_distance_calls_;
}

void PhoneUser::SetName(string name) {
    name_ = name;
}

void PhoneUser::SetSecondName(string second_name) {
    second_name_ = second_name;
}

void PhoneUser::SetAddress() {
    while (true)
    {
        std::string tmp;
        std::cin >> tmp;
        address_ = address_ + " " + tmp;
        if (tmp.back() == '\"') break;
    }
}

void PhoneUser::SetAddress(std::ifstream& file) {
    while (true)
    {
        std::string tmp;
        file >> tmp;
        address_ = address_ + " " + tmp;
        if (tmp.back() == '\"') break;
    }
}

void PhoneUser::SetPhoneNumber(int phone_number) {
    phone_number_ = phone_number;
}

void PhoneUser::SetTimeInnerCityCalls(int time_inner_city_calls) {
    time_inner_city_calls_ = time_inner_city_calls;
}

void PhoneUser::SetTimeLongDistanceCalls(int time_long_distance_calls) {
    time_long_distance_calls_ = time_long_distance_calls;
}

bool PhoneUser::  operator==(const PhoneUser& other) const {
    return (name_ == other.name_ &&
        second_name_ == other.second_name_ &&
        address_ == other.address_ &&
        phone_number_ == other.phone_number_ &&
        time_inner_city_calls_ == other.time_inner_city_calls_ &&
        time_long_distance_calls_ == other.time_long_distance_calls_);
}















