# Runge-Kutta RK4 RK1
plantilla integrador para sistemas de ecuaciones diferenciales ordinarias

# modificar función ode para lo que convenga 
```cpp
// del rk.h
//modificar ode()
//para lorenz 
m=3 //dimension del ODE, lorenz -> m=3
coeff={10,28,8/3} //vector de coeficientes, lorenz -> a,b,c
dt // paso h, default -> 0.01
dvector ode(dvector x){ //dvector -> std::vector<double>

    dvector temp;
    double *dxdt;
    dxdt = new double[m];

    dxdt[0] = coeff[0] * ( x[1] - x[0] );           //dx = a(y-x)
    dxdt[1] = x[0] * ( coeff[1] - x[2] ) - x[1];    //dy = x(b-z)-y
    dxdt[2] = x[0] * x[1] - coeff[2] * x[2];        //dz = xy-cz

    for (uint i=0; i<m ; ++i)
        temp.push_back(dxdt[i]);
    
    delete [] dxdt;
    return temp;
    
}
```



```cpp
//en main, ver carpeta test/
#include "./../src/rk.h"
int main(){
    //inicia objeto RK
    RK lorenz;

    //vector de coeficientes
    std::vector<double> coeficientes={10.0,28.0,8.0/3.0};
    lorenz.init_coeff(coeficientes);
    
    //trayectoria
    std::vector<double> trayectoria={1.0,1.0,1.0};

    for (int i=0; i<5000; ++i){
        //re calcula la trayectoria
        trayectoria=lorenz.make_rk4(trayectoria);
    }
    
    return 0;
}

```

# imagen de prueba, sistema lorenz

![Alt text](https://raw.githubusercontent.com/RamiroBelmarM/Runge-Kutta/main/test/lorenz_test.png)