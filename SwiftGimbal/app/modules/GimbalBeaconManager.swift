//
//  GimbalBeaconManager.swift
//  SwiftGimbal
//
//  Created by Michael Thongvanh on 11/25/14.
//  Copyright (c) 2014 Chisel Apps. All rights reserved.
//

import Foundation
//MARK: - Protocol Declarations -
protocol BeaconManagerDelegate {
    func didReceiveSighting(transmitter: FYXTransmitter, strength: NSNumber)
    func didDepartFrom(transmitter: FYXTransmitter)
}

//MARK: - GIMBAL BEACON MANAGER
class GimbalBeaconManager: NSObject, FYXSightingDelegate, FYXVisitDelegate, FYXSessionDelegate, FYXBluetoothStateUpdateDelegate {
    //MARK: - Properties -
    var sightingManager: FYXSightingManager?
    var visitManager: FYXVisitManager?
    var delegate: BeaconManagerDelegate?
    var activeBeaconIdentifier: NSString?
    weak var currentViewController: UIViewController?
    
    
    init(sightingManager: FYXSightingManager, currentViewController: UIViewController, delegate: BeaconManagerDelegate) {
        super.init()
        self.currentViewController = currentViewController
        
        self.sightingManager = sightingManager
        self.sightingManager!.delegate = self
        
        // make sure to get arrivals and departures
        self.visitManager = FYXVisitManager()
        self.visitManager!.delegate = self
        self.delegate = delegate
    }

    //MARK: - Protocol Conformance -
    //MARK: FYXSightingManager
    func didReceiveSighting(transmitter: FYXTransmitter!, time: NSDate!, RSSI: NSNumber!) {
        delegate?.didReceiveSighting(transmitter,strength:RSSI)
        activeBeaconIdentifier = transmitter.identifier
    }

    //MARK: FYXVisitDelegate
    func didArrive(visit: FYXVisit!) {
        NSLog("arrived at beacon \(visit.transmitter.identifier)")
        activeBeaconIdentifier = visit.transmitter.identifier
    }
    
    func didDepart(visit: FYXVisit!) {
        if visit.transmitter.identifier == activeBeaconIdentifier {
            NSLog("departed from beacon \(visit.transmitter.identifier)")
            activeBeaconIdentifier = nil
            delegate?.didDepartFrom(visit.transmitter)
        }
    }
    
    //MARK: FYXSessionDelegate
    func sessionStarted() {
        self.sightingManager!.scanWithOptions([FYXSightingOptionSignalStrengthWindowKey:NSNumber(int: FYXSightingOptionSignalStrengthWindowLarge)])
        self.visitManager!.start()
    }
    
    func sessionCreateFailed(error: NSError!) {
        NSLog("\nError creating beacon session: \(error)\n\(error.userInfo)")
    }
    
    //MARK: FYXBluetoothStatusUpdate
    func bluetoothBecameAvailable() {
        FYX.enableLocationUpdates()
        NSLog("\nBluetooth has become available: started location updates")
        self.startBeaconService()
    }
    
    func bluetoothBecameUnavailable() {
        FYX.disableLocationUpdates()
        NSLog("\nBluetooth has been disabled: ended location updates")
    }
    
    //MARK: - Helper Functions -
    func startBeaconService() {
        // retrieve our application info from the plist to authorize with Gimbal Servers
        var applicationInfo = loadPlist("GimbalManagerApplicationInfo")
        
        FYX.setAppId(applicationInfo["GimbalApplicationID"]!.string,
            appSecret:applicationInfo["GimbalSecret"] as String,
            callbackUrl:applicationInfo["CallbackURL"] as String)
        FYX.startServiceAndAuthorizeWithViewController(currentViewController, delegate: self)
    }
    
    func loadPlist(plistName: String) -> NSDictionary {
        var anError: NSError? = nil
        var propertyListFilePath = NSBundle.mainBundle().pathForResource(plistName, ofType: "plist")?
        var propertyListData: NSData? = NSData(contentsOfFile:propertyListFilePath!, options: NSDataReadingOptions.DataReadingMappedIfSafe, error: &anError)
        var listFormat = NSPropertyListFormat.XMLFormat_v1_0
        return NSPropertyListSerialization.propertyListWithData(propertyListData!, options:0, format: &listFormat, error:&anError) as NSDictionary
    }
}