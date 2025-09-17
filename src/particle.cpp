#include <assert.h>
#include <cyclone/particle.h>

using namespace cyclone;

void Particle::integrate(real duration) {
    assert(duration > 0.0);

    // Update linear position
    position.addScaledVector(velocity, duration);

    // get acceleration from force
    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);

    // Update linear velocity from acceleration
    velocity.addScaledVector(resultingAcc, duration);

    // Add drag
    velocity *= real_pow(damping, duration);

    // Clear forces
    clearAccumulator();
}


void Particle::clearAccumulator() {
    forceAccum.clear();
}

void Particle::addForce(const Vector3& force) {
    forceAccum += force;
}