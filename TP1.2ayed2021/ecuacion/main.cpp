#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double r,x,y,a,b,c,s;
    cout << "Hello world!" << endl;
    cin>>a;
    cin>>b;
    cin>>c;
    if( b==0 || c==0){              //incompleta
        if(c==0){

            y=-b/a;
            x=0;
            cout<<"rices: "<<x<<" "<<y;
        }
        if(b==0){
            if((c<0 && a<0)||(c>0 && a>0) ){
                 cout<<"no existen racies reales";
            }
            if((c<0 && a>0)||(c>0 && a<0)) {
                cout<<"raices: -+"<<sqrt(abs(c/a));
            }

        }

    }else{                          //completa

        r=pow(b,2)-(4*a*c);
        if(r>0){                    //x1!=x2
            x=(-b+sqrt(r))/(2*a);
            y=(-b-sqrt(r))/(2*a);
            cout<<"raices distintas:"<<x<<"  "<<y;
        }
        if(r<0){                //sin raices
            cout<<"no existen raices ";
        }
        if(r==0){                   //raices iguales
            x=y=-b/(2*a);
            cout<<"raices iguales:"<<x<<"  "<<y;
        }

    }
    return 0;

}
