# SwiftGimbal

A small Swift project that implements the **Gimbal Platform SDK (v1.30.1 11/19/2014)**. This app aims to show others how to get the SDK up and running in Swift. It focuses on Proximity detection and employs the FYXVisitDelegate. Arrivals, departures and sightings are handled by the rather simple GimbalBeaconManager. 

_**This project was built for iOS 8.1 using Xcode 6.2**_

---

## To Run SwiftGimbal
<br>
This project assumes that you've setup your Gimbal Beacons with the Series 10 (or 20) Recommended configuration. For further information: [Configure a Gimbal Beacon for use with the Gimbal SDK](http://gimbal.com/doc/proximity/ios.html#beacon_configuration).

To successfully range there is no need to modify any code. However, you must complete a few steps outlined in the [Gimbal Proximity Quickstart](http://gimbal.com/doc/ios_proximity_quickstart.html), and you must modify a few files found in the project.

1. [Create a Developer Account in the Gimbal Manager](https://manager.gimbal.com/login/users/sign_up)

2. [Create a new Gimbal Application](http://gimbal.com/doc/ios_proximity_quickstart.html). You must use a new unique **_Bundle ID_** for your Gimbal Application. In the Gimbal Manager dashboard, open your application so you see the information below.<br><br>
	<img src="https://farm8.staticflickr.com/7562/15288356283_7c3fed7300_o.jpg" width="640" height="758" alt="gimbal manager app info"><br><br>
	**_Things to note:_**
	a. Bundle ID
	b. Gimbal Production API Key	
	c. Application ID
	d. Gimbal Secret
	e. Callback urls
	<br><br>
3. Change the project's **_bundle ID_** to the same bundle ID of the Gimbal Application
	<br><br>
<img src="https://farm8.staticflickr.com/7500/15720523688_21fc1e2df4_o.jpg" width="800" height="632" alt="xcode project bundle id">

4. Modify the **_UserContext.plist_** by entering your **_Gimbal API Key_**
	<br><br>
<img src="https://farm8.staticflickr.com/7534/15720523528_f3d4e5a44d_c.jpg" width="800" height="486" alt="xcode project production api key">

5. Modify the **_GimbalApplicationInfo.plist_** by entering your **_Application ID, Secret and Callback url_**
	<br><br>
<img src="https://farm8.staticflickr.com/7501/15722241697_fab3cb5925_c.jpg" width="800" height="526" alt="xcode project key secret callback">

6. Create the **_url scheme_** from the **_Callback urls_**.
	<br><br>
<img src="https://farm8.staticflickr.com/7530/15285749254_cbd267187c_c.jpg" width="800" height="378" alt="xcode project url scheme">

7. (Optional) In the **_Info.plist_** Change the text in **_NSLocationAlwaysUsageDescription_** that will appear when the application prompts the user to allow Location Services to access the user's location.  
	<br>
<img src="https://farm8.staticflickr.com/7496/15720523608_c2ff003c9e_c.jpg" width="800" height="277" alt="xcode project location services alert">


	









