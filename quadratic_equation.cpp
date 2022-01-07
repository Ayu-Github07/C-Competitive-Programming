//Define header files for the STDIN/STDOUT
#include<bits/stdc++.h>
using namespace std;

//Define the main function
int main(){
    //Declare the integer variables for the coefficient of quadratic-equation.
    int a,b,c;
    //Ask for the values of the coefficient from the user
    cout<<"Enter the values of a,b and c: ";
    cin>>a>>b>>c;

    //Compute the determinant of the quadratic-equation
    int D = (b*b)-(4*a*c);

    //Compute the solutions of the equation using quadratic formula
    int X = ((-b)+sqrt(D))/2*a;
    int Y = ((-b)-sqrt(D))/2*a;

    cout<<"The solution of the equation are: "<<X<<" "<<Y<<endl;
    return 0;
}