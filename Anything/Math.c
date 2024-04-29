#include<stdio.h>
#include<math.h>

int main()
{
    float v, s, t, dv, ds, dt;
    t = 0.56;
    ds = +-2;
    dt = +-0.06;
    s = 42;
    v = s/t;
    dv = sqrt(pow(ds/s,2)+pow(dt/t,2))*v;
    v = v*3600/1000;
    dv = dv*3600/1000;
    printf("Speed of Ferrari FF = %.3f km/hr\n", v);
    printf("Deviation of Speed = %.3f km/hr", dv);
    return 0;
}
