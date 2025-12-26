// اگر تعداد ثبت‌نام‌ها بیشتر از ۵۰ باشه، باید محدود بشه
// پس Yes چاپ می‌کنیم، وگرنه No



#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n > 50)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
