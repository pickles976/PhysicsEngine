#include <iostream>

#include "./include/cyclone/particle.h"
#include "./include/cyclone/pfgen.h"


using namespace cyclone;

int main() {

    real const dt = 0.01f;
    Particle a, b;

    a.setPosition(Vector3{0,0,0});
    a.setMass(1.0);
    a.setDamping(0.995);

    b.setPosition(Vector3{1,1,1});
    b.setMass(1.0);
    b.setDamping(0.995);

    ParticleForceRegistry registry;
    ParticleSpring psA(&b, 1.0f, 2.0f);
    registry.add(&a, &psA);
    ParticleSpring psB(&a, 1.0f, 2.0f);
    registry.add(&b, &psB);

    for (int i = 0; i< 5;i++) {
        registry.updateForces(dt);
        a.integrate(dt);
        b.integrate(dt);
        registry.print();
    }

    std::cout << "Ran successfully!" << std::endl;

    return 0;
}