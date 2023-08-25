/*
Problem Name: Dice Roll Expectation
Problem Difficulty: None
Problem Constraints: No Constraints
Problem Description:
In a game of fair dice(6 sides) throw, what is the expected number of throws to make sure that all 6 outcomes appear atleast once? Round off the ans to next integer.*/

#include<iostream>
using namespace std;
int main() {
	cout<<"15"<<endl;
	return 0;
}

/*It's not hard to write down the expected number of rolls for a single die. You need one roll to see the first face. After that, the probability of rolling a different number is 5/6. Therefore, on average, you expect the second face after 6/5 rolls. After that value appears, the probability of rolling a new face is 4/6, and therefore you expect the third face after 6/4 rolls. Continuing this process leads to the conclusion that the expected number of rolls before all six faces appear is

6/6 + 6/5 + 6/4 + 6/3 + 6/2 + 6/1 = 14.7 rolls.*/
