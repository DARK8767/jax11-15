// Q1.Write a C++ program to implement a class ‘student’ to overload following functions as follows:
// a. int maximum(int, int) – returns the maximum score of two students
// b. int maximum(int *a, int arraylength) – returns the maximum score from an array ‘a’

#include <iostream>
using namespace std;

class student {
public:
    int maximum(int a, int b) {
        return a > b ? a : b;
    }
    int maximum(int *a, int arraylength) {
        int maxscore = a[0];
        for(int i=1; i<arraylength; i++) {
            if(a[i] > maxscore) {
                maxscore = a[i];
            }
        }
        return maxscore;
    }
};

int main() {
    student s;
    int score1 = 80, score2 = 90;
    int scores[] = {85, 92, 88, 90, 87};
    int num_scores = sizeof(scores)/sizeof(scores[0]);
    cout << "Maximum score of two students: " << s.maximum(score1, score2) << endl;
    cout << "Maximum score from an array: " << s.maximum(scores, num_scores) << endl;
    return 0;
}
