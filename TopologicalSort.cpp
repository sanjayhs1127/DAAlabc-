#include <iostream>
using namespace std;

int main() {
    int vertices = 6;

    int graph[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    int indegree[6] = {0};

    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            if(graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    cout << "Topological Sort Order: ";

    for(int count = 0; count < vertices; count++) {
        int current = -1;

        for(int i = 0; i < vertices; i++) {
            if(indegree[i] == 0) {
                current = i;
                break;
            }
        }

        if(current == -1) {
            cout << "\nCycle detected. Topological sort not possible.";
            return 0;
        }

        cout << current << " ";
        indegree[current] = -1;

        for(int j = 0; j < vertices; j++) {
            if(graph[current][j] == 1) {
                indegree[j]--;
            }
        }
    }

    return 0;
}