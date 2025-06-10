/*X*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool cmpX(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool cmpY(const Point &a, const Point &b) {
    return a.y < b.y;
}

double dist(const Point &a, const Point &b) {
    return sqrt(1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y));
}

// Brute force nếu số điểm nhỏ
double bruteForce(Point P[], int l, int r) {
    double d = 1e18;
    for (int i = l; i <= r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
            d = min(d, dist(P[i], P[j]));
        }
    }
    return d;
}

double stripClosest(vector<Point> &strip, double d) {
    sort(strip.begin(), strip.end(), cmpY);
    int n = strip.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < d; ++j) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    return d;
}

double closestUtil(Point P[], int l, int r) {
    if (r - l + 1 <= 3) return bruteForce(P, l, r);

    int mid = (l + r) / 2;
    Point midPoint = P[mid];

    double dl = closestUtil(P, l, mid);
    double dr = closestUtil(P, mid + 1, r);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = l; i <= r; ++i) {
        if (abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);
    }

    return min(d, stripClosest(strip, d));
}

double closest(Point P[], int n) {
    sort(P, P + n, cmpX);
    return closestUtil(P, 0, n - 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        Point *P = new Point[N];
        for (int i = 0; i < N; ++i) {
            cin >> P[i].x >> P[i].y;
        }
        cout << fixed << setprecision(6) << closest(P, N) << endl;
        delete[] P;
    }
    return 0;
}
