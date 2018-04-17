# ofxBlurUtils
openframeworks addon, 
ping pong blur and other fx.

A lot of Blur with less passes.  

In each i pass the sampling distance changes:

mode0: 1           * distance  (normal)

mode1: i           * distance

mode2: npasses-i   * distance

mode3: i * i       * distance




Examples:

* example_simple.
Simplest use of the addon.

* example_rgb.
RGB blur with, gain, x/y distances, compensation.

* example_tiltShift.
Not working yet.


