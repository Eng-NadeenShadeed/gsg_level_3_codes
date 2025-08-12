#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define nl '\n'
#define TT int t; cin >> t; while(t--)
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<string> activities ={"Swimming", "Running", "Football"};
vector<string> schedule;  // لتخزين الأنشطة اليومية الحالية
int cnt =0;// نعد كم جدول نشاط طبعنا
void fun(int day , int n , int prev) {
    if(day == n) {
        // وصلنا لنهاية الايام
        // نطبع الجدول ونزيد العداد
        for(int i =0; i<n ; ++i) {
            cout<<schedule[i]<<" ";
            if(i!=n-1) cout<<" ";
        }
        cout<<nl;
        cnt++;
        return;
    }
    for(int i =0 ; i<3; ++i) {
       if(i != prev) {// نمنع اختيار نفس النشاط مثل اليوم السابق
           schedule[day] = activities[i];// نحفظ النشاط في جدول اليوم الحالي
           fun(day+1, n, i);// ننادي الدالة لليوم اللي بعده مع تذكر النشاط الحالي
       }
    }
}
int main() {
    Fast
    int n ; cin>>n ;
    schedule.resize(n);
    fun(0, n,-1);
    cout<<"count: " << cnt << nl;// نطبع عدد الجداول الناتجة
    return 0;
}
