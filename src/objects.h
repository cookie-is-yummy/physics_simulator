#ifndef PHYSICS_SIM_OBJECTS_H
#define PHYSICS_SIM_OBJECTS_H
#include <bits/stdc++.h>
#include <raylib.h>
#include <vector>
#include <utility>
using namespace std;
class SimpleObject {

public:
    Vector2 position;
    Vector2 velocity;
    double mass;
    Color colour;

    SimpleObject(Vector2 p, Vector2 v, double m, Color c);
    SimpleObject(Vector2 p, Color c);

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void drawBorders() = 0;
    virtual void checkCollision(std::vector<std::pair<Vector2, Vector2>> surfaces) = 0;
    virtual void checkCollision(std::vector<SimpleObject> surfaces) = 0;
    virtual std::vector<std::pair<Vector2, Vector2>> getSurfaces() = 0;
};

class RectangleObject : public SimpleObject {
public:
    Vector2 dimensions;
    Vector2 centreOfMass;
    double angle = 0.0f;
    double angularVelocity;
    double radius;

    RectangleObject(Vector2 position, Vector2 dimensions, Color colour);

    void update() override;
    void draw() override;
    void drawBorders() override;
    Vector2 rotatePoint(Vector2 point);
    std::vector<std::pair<Vector2, Vector2>> getSurfaces() override;
    void checkCollision(std::vector<std::pair<Vector2, Vector2>> surfaces) override; // Implement this method
    void checkCollision(std::vector<SimpleObject> objects) override;
};

#endif // PHYSICS_SIM_OBJECTS_H