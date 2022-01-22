# Runge-Kutta RK4 RK1
plantilla integrador para sistemas ecuaciones diferenciales ordinarias

# modificar función ode para lo que convenga 
```cpp
// del rk.h
m=3 //dimension del ODE
coeff={10,28,8/3} //vector de coeficientes
dt // paso h

//modificar ode()
//para lorenz 
//dvector -> std::vector<double>
dvector ode(dvector x){
    dvector temp;
    double *dxdt;
    dxdt = new double[m];

    dxdt[0] = coeff[0] * ( x[1] - x[0] );
    dxdt[1] = x[0] * ( coeff[1] - x[2] ) - x[1];
    dxdt[2] = x[0] * x[1] - coeff[2] * x[2];

    for (uint i=0; i<m ; ++i)
        temp.push_back(dxdt[i]);
    
    delete [] dxdt;
    return temp;
}
```



```cpp
//en main
#include "./../src/rk.h"
int main(){
    //inicia objeto RK
    RK lorenz;

    //vector de coeficientes
    lorenz.init_coeff(coeficiente);
    
    //trayectoria
    std::vector<double> trayectoria;

    for (int i=0; i<5000; ++i){
        //re calcula la trayectoria
        trayectoria=lorenz.make_rk4(trayectoria);
    }
    
    return 0;
}

```

# imagen de prueba, sistema lorenz

![Alt text](https://raw.githubusercontent.com/RamiroBelmarM/Runge-Kutta/main/test/lorenz_test.png)