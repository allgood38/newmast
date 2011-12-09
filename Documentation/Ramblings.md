





# The Skipper Class
Here is where the route is going to be laid out. Its going to get the general coordinates from some kind of data source, such as the SD card and give them to the navigational class.

Depending on how the Navigation Control class is implemented will affect how complicated this class needs to be.

# Navigation Control Class
Tells the boat what direction to sail in, based off a waypoint it has been given. It should attempt to generate sub-points which are seperated by types of manuovers, such as sailing straight or tacking.

Navigation conrol will take care telling the Sail Control and Rudder control what they should be doing at any given moment. Its two subclasses will try to execute any command given to them and return an error value if they fail to do so. If a failure occurs, it will be up to the navigation control to handle it.

Failure would require some way to diagnose why the last manuever  wasn’t completed, this could be anything from hardware failure to changing weather condtions, although it will most likely be weather conditions.

# Sail Control Class
Will keep the sails trimmed so that it is always catching the  wind, based on input from the wind sensor. It will also contain instructions for executing a tack or jibe manuver, which can be called at any point in time.

# Rudder Control Class
Wil control the position of the rudder. In good conditions it will simply point the boat in the direction indicated by the Navigation control. Whenever a tack or jibe must be performed, it will take control of the sail control class and attempt the manuaver. If the rudder control is unable to turn the boat the correct number of degrees within a given time, it will throw an error to the navigation control, which should determine how to deal with it.

# The WindSense Class
Just deals with retrieving data from the Wind Sensor, it needs to be told when to update, but has an internal timer to let you know when it thinks its out of date.

## Debugging Class 
To get the arduino to work, found article here (http://arduinonut.blogspot.com/2008/04/ufat.html)