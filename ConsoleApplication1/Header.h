#pragma once
#include <string>
using namespace std;
class Solution {

public:;
    int toInt(char c) {
        int ret;
        switch (c) {
        case '0':
            ret = 0;
            break;
        case '1':
            ret = 1;
            break;
        case '2':
            ret = 2;
            break;
        case '3':
            ret = 3;
            break;
        case '4':
            ret = 4;
            break;
        case '5':
            ret = 5;
            break;
        case '6':
            ret = 6;
            break;
        case '7':
            ret = 7;
            break;
        case '8':
            ret = 8;
            break;
        case '9':
            ret = 9;
            break;
        default:
            ret = 0;
        }
        return ret;
    }

    int sum(int arr[], int length) {
        long total = 0;
        for (int i = 0; i <= length - 1; ++i) {
            total = total + arr[i];
        }
        return total;
    }

    bool isNumber(char c) {
        char numbers[] = { '-', '+', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        bool innum = false;
        for (int i = 0; i < 12; ++i) {
            bool thischar = c == numbers[i];
            innum = innum || thischar;
        }
        return innum;
    }
    string trimFrontSpace(string s) {
        string s2;
        bool isBack = false;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] != ' '|| isBack) {
                s2.push_back(s[i]);
                isBack = true;
            }
        }
        return s2;
    }

    int myAtoi(string s) {
        if (s.length() == 0) {
            return 0;
        }
        if (s.length() == 1)
            return this->toInt(s[0]);
        string arr;
        int numarr[200];
        int nextChar = 0;
        bool isPositive = true;
        if (!(this->isNumber(s[0]) || (s[0] == ' '))) {
            return 0;
        }
        s = this->trimFrontSpace(s);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '.')
                break;
            if (i > 0) {
                if (s[i] == '+' && s[i - 1] == '-')
                    return 0;
                if (s[i] == '-' && s[i - 1] == '+')
                    return 0;

            }
            if (this->isNumber(s[i])) {
                arr.push_back(s[i]);
                nextChar++;
            }
            else {
                if (s[i] == ' ') {
                    break;
                }
                return 0;
            }
        }
        
        if (arr[0] == '-') {
            isPositive = false;
        }
        else {
            isPositive = true;
        }
        string ret = this->delNonNum(arr, nextChar);
        long n = ret.length() - 1;
        long powTen = 1;
        if (isMax(ret, isPositive)) {
            if (isPositive) {
                return 2147483647;
            }
            else {
                return (signed int)-2147483648;
            }
        }
        if (ret.length() > 0) {
            for (long i = 0; i <= (ret.length() - 1); ++i) {
                long first = toInt(ret[(n - i)]);
                numarr[i] = (first * powTen);
                powTen = powTen * 10;
            }
            int r = this->sum(numarr, ret.length());
            if (isPositive) {
                return r;
            }
            else {
                return 0 - r;
            }
        }
        return 0;
    }

    bool isMax(string st, bool isPositive) {
        bool ret = true;
        if (st.length() > 10)
            return true;
        if (st.length() < 10)
            return false;
        string sht = "";
        for (int i = 1; i < 10; i++) {
            sht.push_back(st[i]);
        }
        int a = this->myAtoi(sht);
        //int a = 0;//see if calling myAtoi is making negitive positive
        if (this->toInt(st[0]) > 2) {
            return true;
        }
        if (st[0] == '1') {
            return false;
        }
        if (isPositive) {
            ret = (a > 147483647);
        }
        else {
            ret = (a > 147483648);
        }
        return ret;
    }

    // remove leading zeros, minus sign, and spaces
    string delNonNum(string arr, int length) {
        string s;
        for (int i = 0; i < length; i++) {
            char c = arr[i];
            if ((c != '-') && (c != '+') &&(c!=' '))
                s.push_back(c);
        }
        string s2;
        bool onfront =  false;
        for (int i = 0; i < s.length(); ++i) {
            //remove leading zeros
            if (s[i] != '0'|| onfront) {
                onfront = true;
                s2.push_back(s[i]);
            }

        }
        return s2;
    }

};