#include "./../src/rk.h"
#include <iostream>
int main(){
    //coeficiente para lorenz        alpha, beta, gamma
    std::vector<double> coeficiente={10.0,28.0,8.0/3.0};

    RK lorenz;
    lorenz.init_coeff(coeficiente);
    
    //m=3 -> trayectoria (x=1,y=1,z=1)
    std::vector<double> trayectoria ={1.0,1.0,1.0};

    for (int i=0; i<5000; ++i){
        std::cout<<trayectoria[0]<<'\t'<<trayectoria[1]<<'\t'<<trayectoria[2]<<std::endl;
        trayectoria=lorenz.make_rk4(trayectoria);
    }
    
    return 0;
}