#include "../include/cyclone/pcontacts.h"

using namespace cyclone;

void ParticleContact::resolve(real duration) {
    resolveVelocity(duration);
    resolveInterpenetration(duration);
}

real ParticleContact::calculateSeparatingVelocity() const {
    Vector3 relativeVelocity = particle[0]->getVelocity();
    if (particle[1]) {
        relativeVelocity -= particle[1]->getVelocity();
    }
    return relativeVelocity * contactNormal;
}

void ParticleContact::resolveVelocity(real duration) const {

    // velocity in direction of impact
    real separatingVelocity = calculateSeparatingVelocity();

    if (separatingVelocity > 0) {
        return;
    }   

    // Calculate new separating velocity
    real newSepVelocity = -separatingVelocity * restitution;
    real deltaVelocity = newSepVelocity - separatingVelocity;

    // Apply change to velocity of each particle in proprotion to its inverse mass
    real totalInverseMass = particle[0]->getInverseMass();
    if (particle[1]) {
        totalInverseMass += particle[1]->getInverseMass();
    }
    if (totalInverseMass <=0) return;

    // Apply impulses
    real impulse = deltaVelocity / totalInverseMass;
    Vector3 impulsePerIMass = contactNormal * impulse;

    particle[0]->setVelocity(particle[0]->getVelocity() + impulsePerIMass * particle[0]->getInverseMass());
    if (particle[1])
    {
        // Particle 1 goes in the opposite direction.
        particle[1]->setVelocity(particle[1]->getVelocity() + impulsePerIMass * -particle[1]->getInverseMass());
    }


}

void ParticleContact::resolveInterpenetration(real duration) {
    if (penetration <= 0) return;

    real totalInverseMass = particle[0]->getInverseMass();
    if (particle[1]) totalInverseMass += particle[1]->getInverseMass();

    if (totalInverseMass <= 0) return;

    Vector3 movePerIMass = contactNormal * (-penetration / totalInverseMass);

    // apply resolution
    particle[0]->setPosition(particle[0]->getPosition() + movePerIMass * particle[0]->getInverseMass());

    if (particle[1]) {
        particle[1]->setPosition(particle[1]->getPosition() + movePerIMass * particle[1]->getInverseMass());
    }
}