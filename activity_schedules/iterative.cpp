#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define nl '\n'
#define TT int t; cin >> t; while(t--)
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<string> activities ={"Swimming", "Running", "Football"};
int main() {
    Fast
    int n; cin >> n;

    // نستخدم صف لتخزين الجداول الجزئية التي نبنيها خطوة خطوة
    queue<vector<string>> q;
    q.push({});  // نبدأ بجدول فارغ (بدون أنشطة)
    int cnt = 0; // عداد عدد الجداول الصحيحة التي سنطبعها
    // نكرر حتى ننتهي من استكشاف كل الجداول الممكنة
    while (!q.empty()) {
        // نأخذ أول جدول جزئي من الصف
        vector<string> current = q.front();
        q.pop();
        // إذا وصل طول الجدول لعدد الأيام المطلوب، نطبع الجدول
        if ((int)current.size() == n) {
            for (int i = 0; i < n; ++i) {
                cout << current[i];
                if (i != n - 1) cout << " ";  // نطبع مسافة بين الأنشطة
            }
            cout << nl;

            cnt++;  // نزيد العداد
            continue; // نكمل مع الجدول التالي في الصف
        }

        // نحاول نضيف نشاط جديد لليوم الحالي بشرط أنه مختلف عن نشاط اليوم السابق
        for (auto &act : activities) {
            // إذا الجدول الحالي فاضي (اليوم الأول) أو النشاط مختلف عن آخر نشاط في الجدول
            if (current.empty() || act != current.back()) {
                // ننشئ نسخة جديدة من الجدول الجزئي ونضيف النشاط الجديد له
                vector<string> newSchedule = current;
                newSchedule.push_back(act);

                // نضيف الجدول الجديد للصف لاستكمال بناء الأيام القادمة
                q.push(newSchedule);
            }
        }
    }

    // بعد طباعة كل الجداول، نطبع عدد الجداول الكلي
    cout << "COUNT: " << cnt << nl;
    return 0;
}
