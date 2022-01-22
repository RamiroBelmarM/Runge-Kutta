#ifndef __RK__
#define __RK__
#include <vector>
class RK{
    private:
        typedef unsigned int uint;
        typedef std::vector<double> dvector;
        double dt=0.01;
        int m=3;
        dvector coeff;

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
    public:
        RK(){
            dvector().swap(coeff);
            for (uint i=0; i<m; i++)
                coeff.push_back(0.0);
            return;
        }
        void init_coeff(dvector input){
            coeff=input;
            return;
        }
        dvector make_rk4(dvector input){
            return rk4(input);
        }
        dvector make_rk1(dvector input){
            return rk1(input);
        }

    private:
        dvector rk4( dvector u0 ){
            if (u0.size()!=m)
                return u0;

            dvector f0, f1, f2, f3;
            dvector u1, u2, u3;
            dvector u;

            int i;

            f0 = ode(u0);
            for ( i = 0; i < m; i++ )
                u1.push_back(u0[i] + dt * f0[i] / 2.0);
            
            f1 = ode( u1 );
            for ( i = 0; i < m; i++ )
                u2.push_back( u0[i] + dt * f1[i] / 2.0);
            
            f2 = ode( u2 );
            for ( i = 0; i < m; i++ )
                u3.push_back(u0[i] + dt * f2[i]);

            f3 = ode (u3 );
            for ( i = 0; i < m; i++ )
                u.push_back(u0[i] + dt * ( f0[i] + 2.0 * f1[i] + 2.0 * f2[i] + f3[i] ) / 6.0);

            return u;
        }
        dvector rk1( dvector u0 ){
            if (u0.size()!=m)
                return u0;

            dvector f0;
            dvector u1;
            int i;

            f0 = ode( u0);

            for ( i = 0; i < m; i++ )
                u1.push_back(u0[i] + dt * f0[i] / 2.0);

            return u1;
        }

};

#endif