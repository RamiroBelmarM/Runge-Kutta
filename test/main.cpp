#include "./../src/rk.h"
#include <iostream>
int main(){
    std::vector<double> coeficiente;
    coeficiente.push_back(10.0); //alpha
    coeficiente.push_back(28.0); //beta
    coeficiente.push_back(8.0/3.0); //gamma

    RK lorenz;
    lorenz.init_coeff(coeficiente);
    
    
    std::vector<double> trayectoria;
    trayectoria.push_back(1.0);
    trayectoria.push_back(1.0);
    trayectoria.push_back(1.0);

    for (int i=0; i<5000; ++i){
        std::cout<<trayectoria[0]<<'\t'<<trayectoria[1]<<'\t'<<trayectoria[2]<<std::endl;
        trayectoria=lorenz.make_rk4(trayectoria);
    }
    
    return 0;
}