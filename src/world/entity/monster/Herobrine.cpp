#include "Herobrine.h"
#include "../../level/Level.h"
#include "../player/Player.h"
#include "../../../util/Mth.h"

Herobrine::Herobrine(Level* level) : super(level), stalkTick(0) {
    // Reuse the humanoid zombie renderer/model, but use a distinct entity ID.
    textureName = "mob/zombie.png";
    runSpeed = 0.62f;
    attackDamage = 5;
}

int Herobrine::getEntityTypeId() const { return MobTypes::Herobrine; }

void Herobrine::aiStep() {
    super::aiStep();
    if (level->isClientSide || removed) return;
    // A rare, unsettling disappearance when the player gets close.
    if (++stalkTick > 80) {
        stalkTick = 0;
        Player* player = level->getNearestPlayer(this, 7.0f);
        if (player && random.nextInt(5) == 0) {
            float angle = random.nextFloat() * 6.2831853f;
            float distance = 11.0f + random.nextFloat() * 5.0f;
            float nx = player->x + Mth::cos(angle) * distance;
            float nz = player->z + Mth::sin(angle) * distance;
            int ground = level->getTopSolidBlock(Mth::floor(nx), Mth::floor(nz));
            if (ground > 1 && ground < Level::DEPTH - 2)
                moveTo(nx, (float)ground, nz, random.nextFloat() * 360.0f, 0);
        }
    }
}
