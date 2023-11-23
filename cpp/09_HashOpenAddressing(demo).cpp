#include <iostream>
#include <vector>
#include "HashOpenAddressing.h"
using namespace std;

int main(void) {
    HashOpenAddressing<int>   h(13);

    while (true) {
        system("cls");
        cout << "\n ### 해시 테이블 ###" << endl;
        cout << "1) 데이터 삽입" << endl;
        cout << "2) 데이터 삭제" << endl;
        cout << "3) 데이터 검색" << endl;
        cout << "4) 전체 출력" << endl;
        cout << "5) 프로그램 종료" << endl;
        cout << "메뉴 선택: ";
        int choice;
        cin >> choice;

        int num;
        if (choice == 1) {
            cout << "삽입 할 데이터 입력: ";
            cin >> num;
            int inserted = h.insert(num);
            if (inserted != NULL)
                cout << "삽입 된 데이터: " << inserted << std::endl;
            else
                cout << "데이터 삽입에 실패하였습니다." << std::endl;
        }
        else if (choice == 2) {
            cout << "삭제 할 데이터 입력: ";
            cin >> num;
            int removed = h.remove(num);
            if (removed != NULL)
                cout << "삭제 된 데이터: " << removed << endl;
            else
                cout << "데이터가 존재하지 않습니다." << endl;
        }
        else if (choice == 3) {
            cout << "검색 할 데이터 입력: ";
            cin >> num;
            int searched = h.search(num);
            if (searched != NULL)
                cout << "검색된 데이터: " << searched << endl;
            else
                cout << "데이터가 존재하지 않습니다." << endl;
        }
        else if (choice == 4)   h.output();
        else if (choice == 5) {
            cout << "프로그램 종료!!!" << endl;
            break;
        }
        else cout << "잘못 선택 하셨습니다." << endl;
        system("pause");
    }
    return 0;
}
