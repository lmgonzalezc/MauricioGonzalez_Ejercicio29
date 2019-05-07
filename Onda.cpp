#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    double C=0.5;  
    double t_max = 6.0;
    double dt = 0.01;
    double t;
    double eta;
    double dx = 0.01;
    int ns = 101;
    double To[ns][3];
    double Tn[ns][3];
    int i;
    ofstream outfile;

    for(i=0;i<ns;i++){
        To[i][0] = sin(i*M_PI/100);
    }
    Tn[0][0] = 0.0;
    Tn[ns-1][0] = 0.0;

    eta = (C * C)/ ((dx/dt)*(dx/dt));
    cout << eta << endl;


    outfile.open("Onda.dat");
    while(t < t_max){
        for(i=1;i<ns-1;i++){
            Tn[i][1] = To[i][0] + eta * (To[i+1][0]+To[i-1][0]-2.0*To[i][0]);
            Tn[i][2] = 2.0 * To[i][1] - To[i][0] + eta * (To[i+1][0]+To[i-1][0]-2.0*To[i][0]);
        }
        for(i=0;i<ns;i++){
        outfile << Tn[i][0] << " " << Tn[i][1] << " " << Tn[i][2];
        }
        outfile << "\n";
        for(i=1;i<ns-1;i++){
            To[i][0] = Tn[i][0];
            To[i][1] = Tn[i][1];
        }
        t = t + dt;
    }
    outfile.close();
    return 0;
}
