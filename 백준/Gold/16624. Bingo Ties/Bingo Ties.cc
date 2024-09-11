#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<vector<int>>> numbers;
int n;

//각 행이 나머지 숫자들로 빙고가 되는지 학인하기 , 빙고가 안된다면 false 된다면 true
bool remainMatch(vector<int>& remainOne, vector<int>& remainTwo, int dupi1, int dupj1, int dupi2, int dupj2) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 5; j++) {
            //같은세트의 같은 행은 조사하지 않음
            if (i != dupi1 || j != dupj1) {
 
                if (i != dupi2 || j != dupj2) {


                    vector<bool> check(5, false);

                    for (int k = 0; k < 5; k++) {

                        for (auto a : remainOne) {
                            if (numbers[i][j][k] == a) {
                                check[k] = true;

                            }
                        }
                        for (auto a : remainTwo) {
                            if (numbers[i][j][k] == a) {
                                check[k] = true;
                            }
                        }

                    }

                    bool allCheck = true;
                    for (auto a : check) {
                        if (!a) {
                            allCheck = false;
                        }
                    }
                    //전부 true 면 false 반환

                    if (allCheck) {

                        return true;
                    }

                }
            }

        }


    }

    return false;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<vector<int>> temp(5, vector<int>(5));
        for (int u = 0; u < 5; u++) {
            for (int j = 0; j < 5; j++) {
                cin >> temp[u][j];
            }
        }

        numbers.push_back(temp);
    }

    //일치되는 숫자를 찾고 , 일치되는 숫자 쌍의 행에서 나머지를 추출해서 그 나머지들로 이뤄지는 빙고가 있는지 확인
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 5; k++) {
            for (int t = 0; t < 5; t++) {
                int target = numbers[i][k][t];

                vector<int> remainOne;

                for (int b = 0; b < 5; b++) {
                    if (b == t) continue;
                    //추출한 첫번쨰 숫자의 나머지 행의 원소들 저장
                    remainOne.push_back(numbers[i][k][b]);
                }

                //다음 빙고셋트들 확인
                for (int j = i + 1; j < n; j++) {

                    for (int p = 0; p < 5; p++) {
                        for (int l = 0; l < 5; l++) {
                            if (target == numbers[j][p][l]) { //같으면 나머지 챙겨서 확인

                                vector<int> remainTwo;

                                for (int b = 0; b < 5; b++) {
                                    if (b == l) continue;
                                    //일치한 두번째 숫자의 나머지 행의 원소들 저장
                                    remainTwo.push_back(numbers[j][p][b]);
                                }


                                if (!remainMatch(remainOne, remainTwo, i, k, j, p)) {
                                    cout << i + 1 << ' ' << j + 1 << '\n';
                                    return 0;
                                }


                            }
                        }
                    }

                }

            }
        }
    }

    cout << "no ties" << '\n';
    return 0;
}
