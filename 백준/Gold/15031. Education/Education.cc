#include <bits/stdc++.h>
using namespace std;

struct Department {
    int students;
    int original_index;
};

struct Building {
    int capacity;
    int rental;
    int original_index;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 부서의 학생 수 입력
    vector<int> s(n);
    for(auto &x: s) cin >> x;

    // 건물의 용량 입력
    vector<int> p(m);
    for(auto &x: p) cin >> x;

    // 건물의 임대료 입력
    vector<int> r(m);
    for(auto &x: r) cin >> x;

    // 부서를 구조체로 저장 (학생 수와 원래 인덱스)
    vector<Department> departments(n);
    for(int i=0;i<n;i++) {
        departments[i].students = s[i];
        departments[i].original_index = i;
    }

    // 학생 수가 많은 순서대로 부서 정렬
    sort(departments.begin(), departments.end(), [&](const Department &a, const Department &b) -> bool{
        if(a.students != b.students) return a.students > b.students;
        return a.original_index < b.original_index;
    });

    // 건물을 구조체로 저장 (용량, 임대료, 원래 인덱스)
    vector<Building> buildings(m);
    for(int i=0;i<m;i++) {
        buildings[i].capacity = p[i];
        buildings[i].rental = r[i];
        buildings[i].original_index = i+1; // 1-based 인덱스
    }

    // 건물을 임대료가 낮은 순서대로 정렬
    sort(buildings.begin(), buildings.end(), [&](const Building &a, const Building &b) -> bool{
        if(a.rental != b.rental) return a.rental < b.rental;
        return a.capacity < b.capacity;
    });

    // 각 부서에 배정된 건물 번호 저장 (초기값 -1)
    vector<int> assigned(n, -1);

    // 건물 사용 여부 표시
    vector<bool> used(m, false);

    // 각 부서에 대해 배정 가능한 건물 찾기
    for(int i=0;i<n;i++){
        int required = departments[i].students;
        bool found = false;
        for(int j=0; j<m; j++){
            if(!used[j] && buildings[j].capacity >= required){
                assigned[departments[i].original_index] = buildings[j].original_index;
                used[j] = true;
                found = true;
                break;
            }
        }
        if(!found){
            // 모든 부서를 배정할 수 없는 경우
            cout << "impossible";
            return 0;
        }
    }

    // 원래 부서 순서대로 건물 번호 출력
    for(int i=0;i<n;i++){
        cout << assigned[i] << (i<n-1 ? ' ' : '\n');
    }

    return 0;
}
