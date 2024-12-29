
# Physics Simulator
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)

This markdown document documents my naive journey in 
exploring implementing physics simulations in c++, 
fully from scratch.

From implementing collision detection to *insert*, the aim
is to fully show my thought process whilst working towards a 
intuitive explanation of algorithms in physics simulators.

To make it such that this wouldn't be entirely impossible, I chose
to rely on [raylib](https://github.com/raysan05/raylib) for
graphics.

## 1. Drawing Elements
My final goal with this project is to create my own game 
using the physics simulator I develop. As a result, 
customisation related to drawing shapes is evidently necessary.

I decided to implement 4 shapes:
- Rectangle
- Circle
- Polygon
- Bezier Shape 

For each element, I wish to have customisation over the color, border,
border width, border mitre, fill, fill gradient / texture and so on,
hopefully all encapsulated into a singular class / object.

Of course, I also needed to include customisation over scale_x,
scale_y and angle. 

### 1.1 Rectangle
To

