// bns5273
// p2

#include <iostream>
using namespace std;

void alg(int position, int open, int closed, int n){
    static char perm[1000];
    if(n > 0){
        if(closed == n){
            cout << perm << endl;
            return;
        }
        else{
            if(open < n){ // depth
                perm[position] = '(';
                alg(position+1, open+1, closed, n);
            }
            if(open > closed){ // width
                perm[position] = ')';
                alg(position+1, open, closed+1, n);
            }
        }
    }
    return;
}

int main() {
	int n;
// 	cout << "Please enter an integer: ";
	cin >> n;

	alg(0, 0, 0, n);
	return 0;
}

/*
2
(())
()()

3
((()))
(()())
(())()
()(())
()()()

4
(((())))
((()()))
((())())
((()))()
(()(()))
(()()())
(()())()
(())(())
(())()()
()((()))
()(()())
()(())()
()()(())
()()()()
*/