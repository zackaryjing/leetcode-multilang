#include <iostream>
#include <vector>
#include "../utils/treegenerator.h"
#include "../utils/vector_helper.h"

using namespace std;


int main() {

    int n = 3;
    auto idToPos = [&](int k)-> pair<int, int> {
        k -= 1;
        int bottomRow = k / n;
        int row = n - 1 - bottomRow;
        int col = bottomRow & 1 ? n - 1 - k % n : k % n;
        return {row, col};
    };
    for (int i = 1; i <= n * n; ++i) {
        cout << idToPos(i).first << " " << idToPos(i).second << endl;
    }

}
