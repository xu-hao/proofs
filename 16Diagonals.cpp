#include <bits/stdc++.h>

using namespace std;

void checkPos(const vector<vector<int>> &x, int &i, int &j) {
    if (j == x[i].size() - 1) {
        if (i == x.size() - 1) return; // this is the end
        // otherwise, we need to move to the next row;
        i++;
        j = 0;
        return;
    } else {
        /* cout << "INSIDE CHECKPOS: " << i << " " << j << '\n'; */
        j++;
        return;
    }
}

void checkBackwards(const vector<vector<int>> &x, int &i, int &j) {
    if (j == 0) {
        if (i == 0) return;
        // otherwise, we need to move to the previous row;
        i--;
        j = x[i].size() - 1;
        return;
    } else {
        j--;
        return;
    }
}

bool can_be_extended(const vector<vector<int>> &x, int &i, int &j) {
    if(x[i][j] == 1) {
        // check 2
        if(i > 0 && x[i-1][j] == 2) return false;
        if(i < x.size() - 1 && x[i+1][j] == 2) return false;
        if(j > 0 && x[i][j-1] == 2) return false;
        if(j < x[i].size() - 1 && x[i][j+1] == 2) return false;
        // check 1
        if(i > 0 && j < x[i].size() - 1 && x[i-1][j+1] == 1) return false;
        if(i < x.size() - 1 && j > 0 && x[i+1][j-1] == 1) return false;
    } else if(x[i][j] == 2){
        // check 1
        if(i > 0 && x[i-1][j] == 1) return false;
        if(i < x.size() - 1 && x[i+1][j] == 1)
        if(j > 0 && x[i][j-1] == 1) return false;
        if(j < x[i].size() - 1 && x[i][j+1] == 1) return false;
        // check 2
        if(i > 0 && j > 0 && x[i-1][j-1] == 2) return false;
        if(i < x.size() - 1 && j < x[i].size() - 1 && x[i+1][j+1] == 2) return false;
    }
    /* cout << "INSIDE CAN BE EXteNDED RIGHT BEFORE CHECKPOS: " << i << " " << j << '\n'; */
    checkPos(x, i, j);
    return true;
}

void extend(vector<vector<int>> &x, int n, int count, int i, int j) {
    /* cout << "COUNT AT START: " << count << " position: " << i << ' ' << j << '\n'; */
    if(count == n) {
        cout << "DONE" << '\n';
        for(int i=0; i < x.size(); i++) {
            for(int j=0; j < x[i].size(); j++) {
                cout << x[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
        /* for(int i=0; i < x.size(); i++) { */
        /*     for(int j=0; j < x[i].size(); j++) { */
        /*         cout << x[i][j] << ' '; */
        /*     } */
        /*     cout << '\n'; */
        /* } */
/* cout << '\n'; */

    /* cout << "COUNT RIGHT BEFORE FOR LOOP: " << count << " position: " << i << ' ' << j << '\n'; */
    for(int z=1; z <= 3; z++) {
        x[i][j] = z;
        /* cout << "Z: " << z << '\n'; */
        if(can_be_extended(x, i, j)) {
            if(count >= 13) {
                for(int i=0; i < x.size(); i++) {
                    for(int j=0; j < x[i].size(); j++) {
                        cout << x[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << "COUNT: " << count << '\n';
            }
            /* if(count++ == n) { */
            /*     cout << "DONE" << '\n'; */
            /*     for(int i=0; i < x.size(); i++) { */
            /*         for(int j=0; j < x[i].size(); j++) { */
            /*             cout << x[i][j] << ' '; */
            /*         } */
            /*         cout << '\n'; */
            /*     } */
            /*     exit(0); */
            /* } */
            /* count--; */
            /* cout << "COUNT: " << count << '\n'; */
            if(i == x.size() - 1 && j == x[i].size() - 1 && count != n - 1) {
                x[i][j] = 3;
                return;
            }
            /* cout << "COUNT CAN BE EXTENDED: " << count << " position: " << i << ' ' << j << '\n'; */
            z < 3 ? extend(x, n, ++count, i, j) : extend(x, n, count, i, j);
            if(z != 3) --count;
        } else {
            /* cout << "COUNT CANNOT BE EXTENDED: " << count << " position: " << i << ' ' << j << '\n'; */
        }
    }

    /* checkBackwards(x, i, j); */
    /* x[i][j] = -1; */
    return;

    /* if(x[i][j] == -1) { */
    /*     x[i][j] = 1; */ 
    /*     if(can_be_extended(x, i, j)) { */
    /*         extend(x, n, ++count, i, j); */
    /*     } */
    /*     if(x[i][j] == 1) { */
    /*         x[i][j] = 2; */
    /*         if(can_be_extended(x, i, j)) { */
    /*             extend(x, n, ++count, i, j); */
    /*         } */
    /*         if(x[i][j] == 2) { */
    /*             x[i][j] = 0; */
    /*             if(can_be_extended(x, i, j)) { */
    /*                 extend(x, n, count, i, j); */
    /*             } */
    /*             x[i][j] = -1; */
    /*             /1* checkBackwards(x, i, j); *1/ */
    /*             count--; */
    /*         } */
    /*     } */
    /* } */
}

int main() {
    std::vector<std::vector<int>> x {
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1}
    };
    int count = 0;
    extend(x, 15, count, 0, 0);
        /* for(int i=0; i < x.size(); i++) { */
        /*     for(int j=0; j < x[i].size(); j++) { */
        /*         cout << x[i][j] << ' '; */
        /*     } */
        /*     cout << '\n'; */
        /* } */
}
