#include <iostream>

#include "./include/cyclone/particle.h"
#include "./include/cyclone/pfgen.h"


using namespace cyclone;

int main() {

    real const dt = 0.001f;
    Particle a, b;
    ParticleForceRegistry registry;
    ParticleSpring psA(&b, 1.0f, 2.0f);
    registry.add(&a, &psA);
    ParticleSpring psB(&a, 1.0f, 2.0f);
    registry.add(&b, &psB);

    registry.updateForces(dt);

    std::cout << "Ran successfully!" << std::endl;

    return 0;
}