#pragma once
#include <iostream>
#include <string>
#include <fstream>

using std::string;


class PhoneUser {
public:

    string GetName();
    string GetSecondName();
    string GetAddress();
    int GetPhoneNumber();
    int GetTimeInnerCityCalls();
    int GetTimeLongDistanceCalls();


    void SetName(string name);
    void SetSecondName(string second_name);
    void SetAddress();
    void SetAddress(std::ifstream& file);
    void SetPhoneNumber(int phone_number);
    void SetTimeInnerCityCalls(int time_inner_city_calls);
    void SetTimeLongDistanceCalls(int time_long_distance_calls);

    bool operator==(const PhoneUser& other) const;

private:
    string name_;
    string second_name_;
    string address_;
    int phone_number_ = 0;
    int time_inner_city_calls_ = 0;//внутригород
    int time_long_distance_calls_ = 0;//межгород
};
