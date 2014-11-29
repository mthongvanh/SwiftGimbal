SwiftGimbal
===========

A small Swift project that implements the Gimbal Platform SDK (v1.30.1 11/19/2014). It focuses on Proximity detection and employs the FYXVisitDelegate. Arrivals, departures and sightings are handled by the rather simple GimbalBeaconManager. This app aims to show others how to get the SDK up and running in Swift. 

This project was built for iOS 8.1 using Xcode 6.2.


Running SwiftGimbal
===================
This project assumes that you've setup your Gimbal Beacons with either a Series 10 (or 20) Recommended configuration. For further information: [Configure a Gimbal Beacon for use with the Gimbal SDK](http://gimbal.com/doc/proximity/ios.html#beacon_configuration). 

To successfully range the beacons, there is no need to modify any code. However, you must complete a few steps outlined in the [Gimbal Proximity Quickstart](http://gimbal.com/doc/ios_proximity_quickstart.html), and you must modify a few files found in the project.

1. [Create a Developer Account in the Gimbal Manager](https://manager.gimbal.com/login/users/sign_up)

2. [Create a new Gimbal Application](http://gimbal.com/doc/ios_proximity_quickstart.html#create_app). Things to note here are:

	a. Bundle ID
	b. Application ID
	c. Secret
	d. Callback urls
	
3. In Xcode change the project's bundle ID to the same bundle ID of the Gimbal Application that you've created.

4. Next you will modify the UserContext.plist by entering your Gimbal API Key.

5. (Optional) Modify the text that will appear in the Location Services dialogue box.

6. Finally, modify the GimbalApplicationInfo.plist by entering your Application ID, Secret and Callback urls.


	









