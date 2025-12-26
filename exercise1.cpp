// اول فهمیدم شماره‌ها از پایین سمت چپ شروع میشه و مارپیچ ساعتگرده.

// بعد لایه به لایه می‌رم و روی هر ضلع می‌شمارم تا شماره مورد نظر رو پیدا کنم.

// وقتی مختصات کیان و شمع رو پیدا کردم، فقط اختلاف افقی و عمودی رو محاسبه می‌کنم و جهت رو می‌زنم.










#include <bits/stdc++.h>
using namespace std;

// این تابع شماره یک کاشی رو می‌گیره و ردیف و ستونش رو پیدا می‌کنه
void get_position(int n, int num, int &r, int &c) {
    int layer = 0; // داریم از بیرونی‌ترین لایه شروع می‌کنیم
    int val = 1;   // شماره کاشی فعلی که داریم بررسی می‌کنیم

    while(layer < (n+1)/2) { // تا وقتی وسط مارپیچ نرسیدیم ادامه می‌دیم
        int len = n - 2*layer; // طول ضلع مربع فعلی (هر لایه داخل‌تر کوچیک‌تر میشه)

        if(len == 1) { // اگه فقط یه خانه مونده، یعنی وسط ماتریس
            if(val == num) { r = n-1-layer; c = layer; } // همون همون خانه است
            return;
        }

        // حرکت روی ضلع پایین از چپ به راست
        for(int i=0;i<len-1;i++) {
            if(val == num) { r = n-1-layer; c = layer + i; return; }
            val++;
        }

        // حرکت روی ضلع راست از پایین به بالا
        for(int i=0;i<len-1;i++) {
            if(val == num) { r = n-1-layer - i; c = layer + len -1; return; }
            val++;
        }

        // حرکت روی ضلع بالا از راست به چپ
        for(int i=0;i<len-1;i++) {
            if(val == num) { r = layer; c = layer + len -1 - i; return; }
            val++;
        }

        // حرکت روی ضلع چپ از بالا به پایین
        for(int i=0;i<len-1;i++) {
            if(val == num) { r = layer + i; c = layer; return; }
            val++;
        }

        layer++; // رفتیم لایه بعدی و یک دور داخل‌تر شدیم
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, d;
    cin >> n >> s >> d; // n طول اتاق، s شماره کاشی کیان، d شماره کاشی شمع

    int rs, cs, rd, cd;
    get_position(n, s, rs, cs); // پیدا کردن جای کاشی کیان
    get_position(n, d, rd, cd); // پیدا کردن جای کاشی شمع

    // محاسبه اختلاف افقی و جهت
    if(cs < cd) cout << cd - cs << " R\n"; // اگه شمع سمت راست کیانه
    else if(cs > cd) cout << cs - cd << " L\n"; // اگه شمع سمت چپ کیانه

    // محاسبه اختلاف عمودی و جهت
    if(rs < rd) cout << rd - rs << " D\n"; // اگه شمع پایین کیانه
    else if(rs > rd) cout << rs - rd << " U\n"; // اگه شمع بالای کیانه

    return 0;
}
