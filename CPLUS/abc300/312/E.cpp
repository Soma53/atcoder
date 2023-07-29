#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<(int)(n); ++i)
#define repp(i, s, n) for (int i=(s); i<=(int)(n); ++i)

using ll = long long;
const ll mod = 1000000007;

template <typename T>
bool chmax(T &a, const T& b) {if (a < b) {a = b;return true;}return false;}
template <typename T>
bool chmin(T &a, const T& b) {if (a > b) {a = b;return true;}return false;}

struct Face {
    int coord, r1, r2, axis;
    int cuboid;
};

bool operator<(const Face& a, const Face& b) {
    return make_tuple(a.axis, a.coord, a.r1) < make_tuple(b.axis, b.coord, b.r1);
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> cuboids(N, vector<int>(6));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> cuboids[i][j];
        }
    }

    vector<Face> faces;
    for(int i = 0; i < N; i++) {
        faces.push_back({cuboids[i][0], cuboids[i][1], cuboids[i][4], 0, i});
        faces.push_back({cuboids[i][3], cuboids[i][1], cuboids[i][4], 0, i});
        faces.push_back({cuboids[i][1], cuboids[i][2], cuboids[i][5], 1, i});
        faces.push_back({cuboids[i][4], cuboids[i][2], cuboids[i][5], 1, i});
        faces.push_back({cuboids[i][2], cuboids[i][0], cuboids[i][3], 2, i});
        faces.push_back({cuboids[i][5], cuboids[i][0], cuboids[i][3], 2, i});
    }

    sort(faces.begin(), faces.end());

    vector<set<int>> touching(N);
    vector<Face> last[3];
    for(const auto& face : faces) {
        for(const auto& prev : last[face.axis]) {
            if(prev.r2 > face.r1 && prev.r1 < face.r2) {
                touching[face.cuboid].insert(prev.cuboid);
                touching[prev.cuboid].insert(face.cuboid);
            }
        }
        last[face.axis].push_back(face);
    }

    for(int i = 0; i < N; i++) {
        cout << touching[i].size() << endl;
    }


    return 0;
}