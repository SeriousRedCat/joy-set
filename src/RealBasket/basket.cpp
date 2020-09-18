#include "basket.hpp"
#include "common/physicalstage.hpp"
#include "common/resourcemanager.hpp"
#include "ipractice.hpp"
#include "igame.hpp"

Basket::Basket(PhysicalStage* _stage, double _x, double _height, double _r):
    GameObject(_stage)
{
    SBoundary leg, joint, board, boardJoint, ring1, ring2;

    leg.Width = 0.1;
    leg.Height = _height;
    leg.X = _x;
    leg.Y = _height/2;

    joint.Width = 0.2;
    joint.Height = leg.Width;
    joint.X = leg.X - leg.Width/2 - joint.Width/2;
    joint.Y = leg.Height - leg.Width/2;

    board.Width = 0.1;
    board.Height = 1.0;
    board.X = joint.X - joint.Width/2 - board.Width/2;
    board.Y = joint.Y;

    boardJoint.Width = 0.15;
    boardJoint.Height = 0.05;
    boardJoint.X = board.X - board.Width/2 - boardJoint.Width/2;
    boardJoint.Y = board.Y - 0.25*board.Height;

    ring1.Radius = boardJoint.Height/2;
    ring1.X = boardJoint.X - boardJoint.Width/2;
    ring1.Y = boardJoint.Y;

    ring2.Radius = ring1.Radius;
    ring2.X = ring1.X - _r*2 - ring1.Radius*2;
    ring2.Y = ring1.Y;

    m_baseX = (ring1.X + ring2.X) / 2.;
    m_height = ring1.Y;

    b2BodyDef bdef;
    bdef.type = b2_staticBody;

    b2PolygonShape pshape;
    b2FixtureDef fdef;

    //stojak
    bdef.position.Set(leg.X, leg.Y);

    pshape.SetAsBox(leg.Width/2, leg.Height/2);

    fdef.shape = &pshape;
    fdef.density = 1;
    fdef.friction = 1;
    fdef.restitution = 0.8;

    auto fixture = addPart(bdef, fdef)->GetFixtureList();
    fixture->SetUserData(this);
    {
        sf::Sprite* sprite = new sf::Sprite(m_stage->game()->resources()->texture("concrete"), sf::IntRect(0, 0, leg.Width * m_stage->pixelsPerMeter(), leg.Height * m_stage->pixelsPerMeter()));
        sprite->setOrigin(leg.Width * m_stage->pixelsPerMeter() / 2., leg.Height * m_stage->pixelsPerMeter() / 2.);
        assignSprite(fixture, sprite);
    }

    //poprzeczka
    bdef.position.Set(joint.X, joint.Y);
    pshape.SetAsBox(joint.Width/2., joint.Height/2.);

    fixture = addPart(bdef, fdef)->GetFixtureList();
    fixture->SetUserData(this);
    {
        sf::Sprite* sprite = new sf::Sprite(m_stage->game()->resources()->texture("concrete"), sf::IntRect(0, 0, joint.Width * m_stage->pixelsPerMeter(), joint.Height * m_stage->pixelsPerMeter()));
        sprite->setOrigin(joint.Width * m_stage->pixelsPerMeter() / 2., joint.Height * m_stage->pixelsPerMeter() / 2.);
        assignSprite(fixture, sprite);
    }

    //tablica
    bdef.position.Set(board.X, board.Y);
    pshape.SetAsBox(board.Width/2, board.Height/2);

    fdef.restitution = 0.5;
    fixture = addPart(bdef, fdef)->GetFixtureList();
    fixture->SetUserData(this);
    {
        sf::Sprite* sprite = new sf::Sprite(m_stage->game()->resources()->texture("concrete"), sf::IntRect(0, 0, board.Width * m_stage->pixelsPerMeter(), board.Height * m_stage->pixelsPerMeter()));
        sprite->setOrigin(board.Width * m_stage->pixelsPerMeter() / 2, board.Height * m_stage->pixelsPerMeter() / 2);
        assignSprite(fixture, sprite);
    }

    //poprzeczka obręczy
    bdef.position.Set(boardJoint.X, boardJoint.Y);
    pshape.SetAsBox(boardJoint.Width/2., boardJoint.Height/2.);

    fixture = addPart(bdef, fdef)->GetFixtureList();
    fixture->SetUserData(this);
    {
        sf::Sprite* sprite = new sf::Sprite(m_stage->game()->resources()->texture("concrete"), sf::IntRect(0, 0, boardJoint.Width * m_stage->pixelsPerMeter(), boardJoint.Height * m_stage->pixelsPerMeter()));
        sprite->setOrigin(boardJoint.Width * m_stage->pixelsPerMeter() / 2, boardJoint.Height * m_stage->pixelsPerMeter() / 2);
        assignSprite(fixture, sprite);
    }

    //pierwsza część obręczy
    b2CircleShape cshape;
    fdef.shape = &cshape;

    bdef.position.Set(ring1.X, ring1.Y);
    cshape.m_radius = ring1.Radius;
    fixture = addPart(bdef, fdef)->GetFixtureList();
    fixture->SetUserData(this);
    {
        sf::CircleShape* circle = new sf::CircleShape(ring1.Radius * m_stage->pixelsPerMeter());
        circle->setTexture(&(m_stage->game()->resources()->texture("concrete")));
        circle->setOrigin(ring1.Radius * m_stage->pixelsPerMeter(), ring1.Radius * m_stage->pixelsPerMeter());
        assignSprite(fixture, circle);
    }

    //druga część obręczy
    bdef.position.Set(ring2.X, ring2.Y);
    cshape.m_radius = ring2.Radius;
    fixture = addPart(bdef, fdef)->GetFixtureList();
    fixture->SetUserData(this);
    {
        sf::CircleShape* circle = new sf::CircleShape(ring2.Radius * m_stage->pixelsPerMeter());
        circle->setTexture(&(m_stage->game()->resources()->texture("concrete")));
        circle->setOrigin(ring2.Radius * m_stage->pixelsPerMeter(), ring2.Radius * m_stage->pixelsPerMeter());
        assignSprite(fixture, circle);
    }

    b2EdgeShape eshape;
    eshape.Set(b2Vec2(ring1.X, ring1.Y), b2Vec2(ring2.X, ring2.Y));
    bdef.position.Set(0, 0);
    fdef.shape = &eshape;
    fdef.isSensor = true;
    fdef.filter.categoryBits = static_cast<int>(EnFixtureType::POINT_SENSOR);
    fdef.filter.maskBits = static_cast<int>(EnFixtureType::BALL);
    fixture = addPart(bdef, fdef)->GetFixtureList();
    fixture->SetUserData(this);
}

double Basket::height() const
{
    return m_height;
}

double Basket::baseX() const
{
    return m_baseX;
}
