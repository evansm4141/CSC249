#include <iostream>
#include "Plane.h"
#include "RunwayReserver.h"


using namespace std;

int main()
{
    cout << "Welcome to the Runway Reservation System" << endl;

    RunwayReserver rrs = RunwayReserver();
    Plane myPlane = Plane("N12345");
    bool result = rrs.add(myPlane, 10.0);
    cout << result << endl;

    return 0;
}
