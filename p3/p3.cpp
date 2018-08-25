// ide.c9.io

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int getX(string in){
    return (int) toupper(in.at(0)) -65;
}

int getY(string in){
    return (int) in.at(1) -49;
}

bool verify(int in){
    if(in >= 0 && in <= 7)
        return true;
    else{
        // cout << "OUT OF BOUNDS ERROR" << endl;
        return false;
    }
}

struct iter{
    int x, y, i;
    iter() {}
    iter(int xin, int yin, int iin){
        x = xin;
        y = yin;
        i = iin;
    }
};

int knight(int cx, int cy, int dx, int dy){
    int moves[8][2] = {
        {-2, -1}, {-2, 1},
        {-1, 2}, {-1, -2},
        {1, 2}, {1, -2},
        {2, 1}, {2, -1}
    };
    bool visited[8][8];
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            visited[x][y] = false;
        }
    }
    
    iter i;
    std::queue<iter> q;
    q.push(iter(cx, cy, 0));
    visited[cx][cy] = true;
    
    while(!q.empty()){
        
        i = q.front();
        q.pop();
        visited[i.x][i.y] = true;
        
        // cout << i.i << " - " << i.x << " " << i.y << endl;
        if(i.x == dx && i.y == dy)
            return i.i;
        
        for(int m = 0; m < 8; m++){
            cx = i.x + moves[m][0]; // "moves" knight, x
            cy = i.y + moves[m][1]; // "moves" knight, y
            
            if(verify(cx) && verify(cy) && !visited[cx][cy])
                q.push(iter(cx, cy, i.i+1));
        }
    }
}

int main(){
    string origin, destination;
    int ox, oy, dx, dy;
    ifstream input;
    input.open("input.txt");
    
    while(input >> origin){
        // input >> origin;
        input >> destination;
        
        ox = getX(origin);
        oy = getY(origin);
        dx = getX(destination);
        dy = getY(destination);
        
        cout << "To get from " << origin 
        << " to " << destination 
        << " takes " << knight(ox, oy, dx, dy) 
        << " knight moves." << endl;
        
    }
    
    input.close();
    return 0;
}