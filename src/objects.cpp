#include <math.h>
#include "objects.h"
#include <raylib.h>
#include <bits/stdc++.h>
#include "objects.h"  // Include the header file
#include <cmath>

const int PIXELS_PER_METER = 64;
const int FPS = 60;
using namespace std;

// Implement the SimpleObject constructors
SimpleObject::SimpleObject(Vector2 p, Vector2 v, double m, Color c)
    : position(p), velocity(v), mass(m), colour(c) {}

SimpleObject::SimpleObject(Vector2 p, Color c)
    : position(p), velocity({0.0f, 0.0f}), mass(0.0), colour(c) {}

// Implement the RectangleObject constructor
RectangleObject::RectangleObject(Vector2 pos, Vector2 dim, Color col)
    : SimpleObject(pos, col), dimensions(dim) {
    centreOfMass = {dimensions.x / 2 + position.x, dimensions.y / 2 + position.y};
    cout << centreOfMass.x << " " << centreOfMass.y << "\n";
    angle = 0.0f;
    angularVelocity = 0.0f;
}

// Implement the update method
void RectangleObject::update() {
    if (abs(velocity.x) < 0.1) {
        velocity.x = 0;
    }
    if (abs(velocity.y) < 0.1) {
        velocity.y = 0;
    }
    position.x += (velocity.x / FPS) * PIXELS_PER_METER;
    position.y += (velocity.y / FPS) * PIXELS_PER_METER;
    angle += (angularVelocity / FPS);
}

// Implement the rotatePoint method
Vector2 RectangleObject::rotatePoint(Vector2 point) {
    double radian_angle = (angle * (PI / 180));
    return {
        position.x + point.x * static_cast<float>(cos(radian_angle)) - point.y * static_cast<float>(sin(radian_angle)),
        position.y + point.x * static_cast<float>(sin(radian_angle)) + point.y * static_cast<float>(cos(radian_angle))
    };
}

// Implement the getSurfaces method
std::vector<std::pair<Vector2, Vector2>> RectangleObject::getSurfaces() {
    std::vector<Vector2> points;
    points.push_back(rotatePoint({-dimensions.x / 2, dimensions.y / 2}));
    points.push_back(rotatePoint({dimensions.x / 2, dimensions.y / 2}));
    points.push_back(rotatePoint({dimensions.x / 2, -dimensions.y / 2}));
    points.push_back(rotatePoint({-dimensions.x / 2, -dimensions.y / 2}));

    std::vector<std::pair<Vector2, Vector2>> surfaces;
    surfaces.emplace_back(points[0], points[1]);
    surfaces.emplace_back(points[1], points[2]);
    surfaces.emplace_back(points[2], points[3]);
    surfaces.emplace_back(points[3], points[0]);
    return surfaces;
}

// Implement the draw method
void RectangleObject::draw() {
    DrawRectanglePro({ position.x, position.y, dimensions.x, dimensions.y }, // Rectangle position and size
        {dimensions.x / 2, dimensions.y / 2}, // Origin for rotation (center of rectangle)
        angle,  // Rotation angle
        colour);
}

void RectangleObject::drawBorders() {
    for (auto surface: getSurfaces()) {
        DrawLine(surface.first.x, surface.first.y, surface.second.x, surface.second.y, colour);
    }
}

void RectangleObject::checkCollision(vector<SimpleObject> objects) {
    for (auto surface: getSurfaces()) {

    }
    // for each surface, check if intersecting with own surfaces.
}







// check if lines are whatever whatever

// what the world mannnnn??gwat tiem is it bro

// Implement the checkCollision method
void RectangleObject::checkCollision(vector<pair<Vector2, Vector2>> surfaces) {
    for (auto surface: getSurfaces()) {
        int length = 50; // Desired length of the perpendicular line
        Vector2 surface_mp((surface.first.x + surface.second.x) / 2, (surface.first.y + surface.second.y) / 2);

        double dx = surface.second.x - surface.first.x;
        double dy = surface.second.y - surface.first.y;

        // Calculate the length of the line segment
        double segment_length = sqrt(dx * dx + dy * dy);

        // Normalize the direction vector (dx, dy)
        double norm_dx = dx / segment_length;
        double norm_dy = dy / segment_length;

        // Calculate the outward-facing perpendicular vector
        int delta_x = -length * norm_dy;  // Perpendicular direction
        int delta_y = length * norm_dx;

        // Draw circles and the outward-facing line
        DrawCircle(surface_mp.x, surface_mp.y, 6, RED);
        DrawCircle(surface_mp.x, surface_mp.y, 4, WHITE);
        DrawLine(surface_mp.x, surface_mp.y, surface_mp.x + delta_x, surface_mp.y + delta_y, RED);
    }
    // for each surface, check if intersecting with own surfaces.
}

class BallObject {

};

class PolyObject {

};

class BezierObject {

};



