/*
عدد رو از بزرگ‌ترین مقدار رومی شروع می‌کنیم.
هر بار اگر عدد باقی‌مانده از مقدار فعلی بزرگ‌تر یا مساوی بود،
سمبلش رو به جواب اضافه می‌کنیم و مقدارش رو از عدد کم می‌کنیم.
این کار رو تا رسیدن عدد به صفر ادامه می‌دیم.
چون حالت‌های کاهشی (مثل IV، IX، CM و ...) توی جدول هستن،
قوانین رومی به‌صورت خودکار رعایت می‌شن.
*/





#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> roman = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    
    string result = "";
    for (auto& p : roman) {
        while (num >= p.first) {
            result += p.second;
            num -= p.first;
        }
    }
    return result;
}

int main() {
    int num;
    cin >> num;
    cout << intToRoman(num) << endl;
    return 0;
}
