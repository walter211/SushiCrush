#ifndef __PlayLayer_H__
#define __PlayLayer_H__

#include "cocos2d.h"

USING_NS_CC;

class SushiSprite;

class PlayLayer : public Layer
{
public:
    PlayLayer();
    ~PlayLayer();
    static Scene* createScene();
    CREATE_FUNC(PlayLayer);
    
    virtual bool init() override;
    virtual void update(float dt) override;
    virtual bool onTouchBegan(Touch *touch, Event *unused) override;
    virtual void onTouchMoved(Touch *touch, Event *unused) override;
private:
    SpriteBatchNode *spriteSheet;
    SushiSprite **m_matrix;// 2D array which store (SushiSprite *).
    int m_width;
    int m_height;
    // for rapid count position
    float m_matrixLeftBottomX;
    float m_matrixLeftBottomY;
    bool m_isTouchEnable;// is need to deal with touch event
    SushiSprite *m_touchBeganSushi;
    bool m_isAnimationing;
    
    void initMatrix();
    void createAndDropSushi(int row, int col);
    Point positionOfItem(int row, int col);
    void checkAndRemoveChain();
    void getColChain(SushiSprite *sushi, std::list<SushiSprite *> &chainList);
    void getRowChain(SushiSprite *sushi, std::list<SushiSprite *> &chainList);
    void removeSushi(std::list<SushiSprite *> &sushiList);
    void explodeSushi(SushiSprite *sushi);
    void fillVacancies();
    SushiSprite *sushiOfPoint(Point *point);
    void swapSushi(SushiSprite *first, SushiSprite *second);
};

#endif /* defined(__PlayLayer_H__) */
