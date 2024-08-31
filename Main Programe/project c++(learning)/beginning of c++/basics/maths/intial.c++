#include<iostream>
using namespace std;
int main(){


    //*     ()
    //*     * / %
    //*     + -
    //*     =


    cout<<1*2+3+4<<endl;

    cout<<2+2/2*(3-4)%5<<endl;
    //* {2+2/2*(-1)%5}
    //* {2+(-1)%5}
    //* {-1+2}
    //* {1}

    float x = (3+1-3)*1/2%2;
    cout<<x<<endl;
    //* {1/2}
    
    
    cout<<3*2/6+5%5<<endl;
    //* {1}
    


}