#include "BoxPlatform.h"
#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"
#include "Game.h"

void CBoxPlatform::RenderBox(int spriteIds[9]) {
    CSprites* sprites = CSprites::GetInstance();

    for (int i = 0; i < boxHeight; ++i) {
        float yy = y + UNIT_SIZE * i;

        for (int k = 0; k < boxWidth; ++k) {
            float xx = x + UNIT_SIZE * k;
            int spriteIndex = 4; //Center

            if (i == 0) {
                if (k == 0)
                    spriteIndex = 0; //TopLeft
                else if (k == boxWidth - 1) {
                    spriteIndex = 2; //TopRight
                    sprites->Get(ID_SPRITE_BOX_PLATFORM_SHADOW_CORNER)->Draw(xx + UNIT_SIZE, yy); //TopRightShadow
                }
                else
                    spriteIndex = 1; //TopMid
            }
            else if (i == boxHeight - 1) {
                if (k == 0)
                    spriteIndex = 6; //BottomLeft
                else if (k == boxWidth - 1) {
                    spriteIndex = 8; //BottomRight
                    sprites->Get(ID_SPRITE_BOX_PLATFORM_SHADOW_EDGE)->Draw(xx + UNIT_SIZE, yy); //BottomRightShadow
                }
                else
                    spriteIndex = 7; //BottomMid
            }
            else {
                if (k == 0)
                    spriteIndex = 3; //EdgeLeft
                else if (k == boxWidth - 1) {
                    spriteIndex = 5; //EdgeRight
                    sprites->Get(ID_SPRITE_BOX_PLATFORM_SHADOW_EDGE)->Draw(xx + UNIT_SIZE, yy); //EdgeRightShadow
                }
            }

            sprites->Get(spriteIds[spriteIndex])->Draw(xx, yy);
        }
    }
}

void CBoxPlatform::Render()
{
    int whiteBoxSprites[9] = {
        ID_SPRITE_BOX_PLATFORM_WHITE_1,
        ID_SPRITE_BOX_PLATFORM_WHITE_2,
        ID_SPRITE_BOX_PLATFORM_WHITE_3,
        ID_SPRITE_BOX_PLATFORM_WHITE_4,
        ID_SPRITE_BOX_PLATFORM_WHITE_5,
        ID_SPRITE_BOX_PLATFORM_WHITE_6,
        ID_SPRITE_BOX_PLATFORM_WHITE_7,
        ID_SPRITE_BOX_PLATFORM_WHITE_8,
        ID_SPRITE_BOX_PLATFORM_WHITE_9
    };

    int greenBoxSprites[9] = {
        ID_SPRITE_BOX_PLATFORM_GREEN_1,
        ID_SPRITE_BOX_PLATFORM_GREEN_2,
        ID_SPRITE_BOX_PLATFORM_GREEN_3,
        ID_SPRITE_BOX_PLATFORM_GREEN_4,
        ID_SPRITE_BOX_PLATFORM_GREEN_5,
        ID_SPRITE_BOX_PLATFORM_GREEN_6,
        ID_SPRITE_BOX_PLATFORM_GREEN_7,
        ID_SPRITE_BOX_PLATFORM_GREEN_8,
        ID_SPRITE_BOX_PLATFORM_GREEN_9
    };

    int pinkBoxSprites[9] = {
        ID_SPRITE_BOX_PLATFORM_PINK_1,
        ID_SPRITE_BOX_PLATFORM_PINK_2,
        ID_SPRITE_BOX_PLATFORM_PINK_3,
        ID_SPRITE_BOX_PLATFORM_PINK_4,
        ID_SPRITE_BOX_PLATFORM_PINK_5,
        ID_SPRITE_BOX_PLATFORM_PINK_6,
        ID_SPRITE_BOX_PLATFORM_PINK_7,
        ID_SPRITE_BOX_PLATFORM_PINK_8,
        ID_SPRITE_BOX_PLATFORM_PINK_9
    };

    int blueBoxSprites[9] = {
        ID_SPRITE_BOX_PLATFORM_BLUE_1,
        ID_SPRITE_BOX_PLATFORM_BLUE_2,
        ID_SPRITE_BOX_PLATFORM_BLUE_3,
        ID_SPRITE_BOX_PLATFORM_BLUE_4,
        ID_SPRITE_BOX_PLATFORM_BLUE_5,
        ID_SPRITE_BOX_PLATFORM_BLUE_6,
        ID_SPRITE_BOX_PLATFORM_BLUE_7,
        ID_SPRITE_BOX_PLATFORM_BLUE_8,
        ID_SPRITE_BOX_PLATFORM_BLUE_9
    };

    switch (color) {
    case COLOR_WHITE:
        RenderBox(whiteBoxSprites);
        break;
    case COLOR_GREEN:
        RenderBox(greenBoxSprites);
        break;
    case COLOR_PINK:
        RenderBox(pinkBoxSprites);
        break;
    case COLOR_BLUE:
        RenderBox(blueBoxSprites);
        break;
    default:
        break;
    }
	//RenderBoundingBox();
}

void CBoxPlatform::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE * this->boxWidth;
	b = t + UNIT_SIZE * this->boxHeight;
}

int CBoxPlatform::IsDirectionColliable(float nx, float ny)
{
	if (nx == 0 && ny == -1) return 1;
	else return 0;
}