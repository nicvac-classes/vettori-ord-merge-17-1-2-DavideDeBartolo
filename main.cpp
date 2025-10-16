#include <iostream>

void merge(const std::vector<int>& V1, const std::vector<int>& V2, std::vector<int>& V3) {
    size_t i = 0, j = 0;
    while (i < V1.size() && j < V2.size()) {
        if (V1[i] < V2[j]) {
            V3.push_back(V1[i]);
            i++;
        } else {
            V3.push_back(V2[j]);
            j++;
        }
    }
    while (i < V1.size()) {
        V3.push_back(V1[i]);
        i++;
    }
    while (j < V2.size()) {
        V3.push_back(V2[j]);
        j++;
    }
}

int binarySearch(const std::vector<int>& V3, int value) {
    int left = 0, right = V3.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (V3[mid] == value) {
            return mid;
        } else if (V3[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    int N, M;
    std::cout << "Inserisci il numero di elementi per V1: ";
    std::cin >> N;
    std::cout << "Inserisci il numero di elementi per V2: ";
    std::cin >> M;

    std::vector<int> V1(N), V2(M);
    for (int i = 0; i < N; i++) {
        V1[i] = rand() % 100; // Numeri casuali tra 0 e 99
    }
    for (int i = 0; i < M; i++) {
        V2[i] = rand() % 100; // Numeri casuali tra 0 e 99
    }

    std::sort(V1.begin(), V1.end());
    std::sort(V2.begin(), V2.end());

    std::cout << "Vettore V1 ordinato: ";
    for (int num : V1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Vettore V2 ordinato: ";
    for (int num : V2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> V3;
    merge(V1, V2, V3);

    std::cout << "Vettore V3 risultante: ";
    for (int num : V3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int value;
    std::cout << "Inserisci un valore da cercare in V3: ";
    std::cin >> value;

    int index = binarySearch(V3, value);
    if (index != -1) {
        std::cout << "Valore trovato all'indice: " << index << std::endl;
    } else {
        std::cout << "Valore non trovato." << std::endl;
    }

    return 0;
}
