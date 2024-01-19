#include "PrintRequest.h"
#include "PrintQueue.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    PrintQueue printQueue;

    // ��������� �������� �������� ������ �� ����
    for (int i = 0; i < 5; ++i) {
        string user;
        string priority;

        cout << "Enter user name for print request: ";
        cin >> user;

        cout << "Enter priority for print request ('high' (1), 'medium' (2) or 'low' (3)): ";
        cin >> priority;

        PrintRequest request(user, priority);
        printQueue.AddPrintRequest(request);
    }

    // �������� ���������� ����� �������� �����
    printQueue.PrintStatistics();

    // ��������� ����, �������� ����� ����� �� �����
    cout << "\nPrinting...\n";
    printQueue.PrintStatistics();

    return 0;
}
