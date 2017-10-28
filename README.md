Halloween
=========

### Halloween decorations from a number of sources. Basically this repository has code for:  
* Evil Working Skull3 - An Arduino-controlled skull with a working, servo-controlled, jaw and neck. I had red LEDs in the eye sockets but have since removed those. They may come back next year!  
* An Arduino-controlled Wav player that plays through a bunch of wavs. It seems to play them pretty randomly, perhaps not  
* A demon rat on an OpenBuilds V-rail gantry that is belt-driven, stepper-motor powered.  
* The Demon Rat itself has Neopixel eyes and mouth inserted into it's interior. They eyes glow brightly and alternate colors.  

### Regarding Evil Working Skull3 - Skully (the Skull), the timing seems to work better on this 10/27/2017 update. Essentially the process is this:
* Include servo driver
* Name your servos  
  + myservo is the jaw  
  + myservo1 is the neck
* Set the servo starting positions = 0 on both: might be interesting to tweak later?  
* Void Setup = Declare and initialize the pins that drive the servos  
  + Pin 9 = jaw  
  + Pin 10 = neck  
* Void Loop  
  + Rotate the neck (servo1) 75 degrees and pause  
  + Rotate the jaw (servo) 30 degrees  
  + Rotate the jaw (servo) back to initial position 0 degrees and pause  
  + Rotate the neck (servo1) back to 0 degrees and pause  
* Delay for 10000 ms
* Restart the Void Loop
