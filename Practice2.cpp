#include <iostream>
#include <locale>
using namespace std;

void checking(int num) {
	if (num < 1) {
		throw invalid_argument(" � ������� �� ����� ���� ������������� ��� ������� ����� ���������");
	}

}

int inputLength() {
	int input;
	bool incorrect_length;
	do {
		cout << " ������� ����� ������� :  ";
		cin >> input;
		try {
			checking(input);
			incorrect_length = false;
		}
		catch (invalid_argument & ex) {
			cerr << "\t" << ex.what() << endl;
			incorrect_length = true;
		}
	} while (incorrect_length);

	return input;

}

int * getResult(const int *arr, const int l, int &newlen) {
	int* result = new int[newlen];
	for (int i = 0; i < l; i++) {
		if (arr[i] < 0 && arr[i] % 2 == 0) {
			result [newlen] = arr[i];
			newlen++;
		}
	}
	return result;
	delete[] result;
	
}

int main() {
	setlocale(LC_ALL, "rus");
	int res_len = 0;
	int length = inputLength();
	int *array = new int[length];
	for (int i = 0; i < length; i++) {
		cout << " ������� " << i + 1 << "-� ������� �������: ";
		cin >> array[i];
	}
	int* res = getResult(array, length, res_len);
	cout << " ������ ������������� �������� �������: ";
	for (int i = 0; i < res_len; i++)
		cout << " " << *(res + i);
	cout << "\n ����� ������ �������: " << res_len;
	
	delete[] array;
	return 0;

}