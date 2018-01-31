#include <vector>
#include <tuple>

using namespace std;

std::tuple<int, int> nextPos(const vector<vector<int>> &x, int i, int j) {
    if (j == x[i].size() - 1) {
      return std::make_tuple(i+1,0);
    } else {
      return std::make_tuple(i,j+1);
    }
}

bool can_be_extended(const vector<vector<int>> &x, int i, int j) {
    if(x[i][j] == 1) {
        // check 2                                                                                                                                                                                                                                                              
        if(i > 0 && x[i-1][j] == 2) return false;
        if(i < x.size() - 1 && x[i+1][j] == 2) return false;
        if(j > 0 && x[i][j-1] == 2) return false;
        if(j < x[i].size() - 1 && x[i][j+1] == 2) return false;
        // check 1                                                                                                                                                                                                                                                              
        if(i > 0 && j > 0 && x[i-1][j-1] == 1) return false;
        if(i < x.size() - 1 && j < x[i].size() - 1 && x[i+1][j+1] == 1) return false;
    } else if(x[i][j] == 2){
        // check 1                                                                                                                                                                                                                                                              
        if(i > 0 && x[i-1][j] == 1) return false;
        if(i < x.size() - 1 && x[i+1][j] == 1) return false;
        if(j > 0 && x[i][j-1] == 1) return false;
        if(j < x[i].size() - 1 && x[i][j+1] == 1) return false;
        // check 2                                                                                                                                                                                                                                                              
        if(i > 0 && j < x[i].size() - 1 && x[i-1][j+1] == 2) return false;
        if(i < x.size() - 1 && j > 0 && x[i+1][j-1] == 2) return false;
    }
    /* cout << "INSIDE CAN BE EXteNDED RIGHT BEFORE CHECKPOS: " << i << " " << j << '\n'; */
    return true;
}

void extend(vector<vector<int>> &x, int count, int& max, vector<vector<int>> &maxx, int i, int j) {
  if(i >= x.size()) {
    if (count > max) {
      max = count;
      maxx = x;
    }
  } else {
    for(int z=1; z <= 3; z++) {
      x[i][j] = z;
      if(can_be_extended(x, i, j)) {
        auto i2j2 = nextPos(x, i, j);
        auto i2 = std::get<0>(i2j2);
        auto j2 = std::get<1>(i2j2);
        z < 3 ? extend(x, count + 1, max, maxx, i2, j2) : extend(x, count, max, maxx, i2, j2);
      }
    }
  }
}

int main() {
    std::vector<std::vector<int>> x {
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1}
    };
    int max = 0;
    std::vector<std::vector<int>> maxx;
    int count = 0;
    extend(x, count, max, maxx, 0, 0);
    cout << "DONE" << '\n';
    for(int i=0; i < maxx.size(); i++) {
      for(int j=0; j < maxx[i].size(); j++) {
        cout << maxx[i][j] << ' ';
      }
      cout << '\n';
    }
    exit(0);
    
}

