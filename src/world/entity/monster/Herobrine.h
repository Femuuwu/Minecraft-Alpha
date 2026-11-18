#ifndef NET_MINECRAFT_WORLD_ENTITY_MONSTER__Herobrine_H__
#define NET_MINECRAFT_WORLD_ENTITY_MONSTER__Herobrine_H__
#include "Zombie.h"
class Herobrine : public Zombie {
    typedef Zombie super;
public:
    explicit Herobrine(Level* level);
    virtual int getEntityTypeId() const;
    virtual void aiStep();
private:
    int stalkTick;
};
#endif
