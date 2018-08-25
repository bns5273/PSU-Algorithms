/* 
 * Author: bns5273
 * p1
 */

#include <cstdlib>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include <valarray>

using namespace std;

/*
 * 
 */

stack<int> alg(queue<int> a, stack<int> station, int b){
//    cout << "|" << a.size() << "| ";
    if(station.empty() && a.empty()){       // end. success. return empty stack
        return station;
    }
    else if(station.empty() && !a.empty()){ // continue.
        station.push(a.front());
        a.pop();
        return alg(a, station, b);
    }
    else{                                   // station is not empty. continue
        if(station.top() == b){
//            cout << station.top() << "<>" << b << "y ";
            station.pop();
            b++;
            return alg(a, station, b);
        }
        else{
            
            if(a.empty()){                  // end. fail. return populated stack
//                cout << station.top() << "<>" << b << "xx ";
                return station;
            }
            else{
//                cout << station.top() << "<>" << b << "x ";
                station.push(a.front());
                a.pop();
                return alg(a, station, b);
            }
        }
    }
}

int main(int argc, char** argv) {
    queue<int> a;
    stack<int> station;
    int n;
    int l;
    
    ifstream in;
    ofstream out;
    in.open("lab1in.txt");
    out.open("lab1out.txt");
    
    int i = 0;
    if(in.is_open()){
        while(in >> n){
            if(i == 0 && n == 0){ // end of file
//                cout << "end of file";
            }
            else if(i == 0){ // beginning of block
                l = n;
                i++;
//                cout << "new block, length " << l << "\n";
            }
            else{
                if(n == 0){ // end of block
                    i = 0;
                    out << "\n";
                }
                else{ // train data
                    a.push(n);
//                    cout << n << " ";
                    if(i >= l){ // end of train
                        
//                        cout << std::boolalpha << alg(a, station, 1, l).empty() << "\n";
                        if(alg(a, station, 1).empty()){
                            out << "Yes\n";
                        }
                        else{
                            out << "No\n";
                        }
                        a = {};
                        i = 0;
                    }
                    i++;
                }
            }
        }
        in.close();
        out.close();
    }
    else{
        cout << "Unable to open file";
    }
    return 0;
}

/* sample output
No
No
No
No
No
No
No

*/