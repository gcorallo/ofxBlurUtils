# ofxBlurUtils
openframeworks addon, 
ping pong blur and other fx.

A lot of Blur with less passes.  

In each i pass the sampling distance changes:

mode0: 1 (normal)

mode1: i

mode2: npasses-i

mode3: i * i




Examples:

* example_simple.
Simplest use of the addon.

* example_rgb.
RGB blur with, gain, x/y distances, compensation.

* example_tiltShift.
Not implemented yet.


