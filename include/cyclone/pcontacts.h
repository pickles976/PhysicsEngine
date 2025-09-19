#ifndef CYCLONE_PCONTACTS_H
#define CYCLONE_PCONTACTS_H

#include "core.h"
#include "particle.h"
#include "precision.h"

namespace cyclone {

class ParticleContact {
    public:
        Particle* particle[2];
        real restitution;
        Vector3 contactNormal;
    protected:
        void resolve(real duration);
        real calculateSeparatingVelocity() const;
    private:
        void resolveVelocity(real duration) const;
        real penetration;
        void resolveInterpenetration(real duration);

};

}


#endif