#include <iostream>
#include <vector>

#define K 3

std::vector<int>::iterator id2it(std::vector<int> V, int id) {
    std::vector<int>::iterator nth = V.begin() + id;
    return nth;
}

void insertionSort(std::vector<int>& A, int start, int finish) {
    for (int i = start; i < finish; i++) {
        int tempVal = A[i + 1];
        int j = i + 1;
        while (j > start && A[j - 1] > tempVal) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tempVal;
    }
    for (int i=start; i <= finish; ++i) {
        std::cout << ">> [" << i << "] " << A[i] << std::endl;
    }
    std::cout << "---------" << std::endl;
}

void merge(std::vector<int>& A, int s, int m, int e) {
    int n1 = m - s + 1;
    int n2 = e - m;
    std::vector<int> LA(A.begin() + s, A.begin() + m + 1);
    std::vector<int> RA(A.begin() + m + 1, A.begin() + e + 1);
    int RIDX = 0;
    int LIDX = 0;
    for (int i = s; i < e - s + 1; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
    }
}

void sort(std::vector<int>& A, int Sstart, int Sfinish) {
    int Smiddle = (Sstart + Sfinish) / 2;
    std::cout << "Sstart:" << Sstart << " Sfinish:" << Sfinish << std::endl;
    if (Sfinish - Sstart > K) {
        sort(A, Sstart, Smiddle);
        sort(A, Smiddle + 1, Sfinish);
        merge(A, Sstart, Smiddle, Sfinish);
    } else {
        insertionSort(A, Sstart, Sfinish);
    }
}

int main() {
    std::vector<int> A = { 2, 5, 1, 6, 7, 3, 8, 4, 9 };
    sort(A, 0, A.size() - 1);
    for (int i=0; i < A.size(); ++i) {
        std::cout << A[i] << std::endl;
    }
}
