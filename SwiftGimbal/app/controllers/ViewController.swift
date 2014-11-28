//
//  ViewController.swift
//  SwiftGimbal
//
//  Created by Michael Thongvanh on 11/25/14.
//  Copyright (c) 2014 Chisel Apps. All rights reserved.
//

import UIKit

class ViewController: UIViewController, BeaconManagerDelegate, UITableViewDelegate, UITableViewDataSource  {
    //MARK: Properties
    var gimbalBeaconManager: GimbalBeaconManager!
    var viewModel: InitialViewModel?
    var pulseView: PulseView?
    var activeBeacon: CHABeacon?
    
    @IBOutlet weak var sightingLabel: UILabel!
    @IBOutlet weak var transmitterNameLabel: UILabel!
    @IBOutlet weak var beaconTableView: UITableView!
    
    
    //MARK: ViewController LifeCycle
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        gimbalBeaconManager = GimbalBeaconManager(sightingManager:FYXSightingManager(),currentViewController:self, delegate: self)
        setupInitialViews()
    }
    
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        navigationController?.setNavigationBarHidden(true, animated: false)
    }
    
    override func viewDidAppear(animated: Bool) {
        super.viewDidAppear(animated)
        gimbalBeaconManager.startBeaconService()
    }
    
    //MARK: ViewController Setup
    func setupInitialViews() {
        viewModel = InitialViewModel.viewModel(self.view)
        viewModel?.itemStrengthLabel = sightingLabel
        viewModel?.transmitterLabel = transmitterNameLabel
        viewModel?.setupViews()
        
        viewModel?.beaconTableView = beaconTableView
        viewModel?.beaconTableView?.delegate = self
        viewModel?.beaconTableView?.dataSource = self
        beaconTableView.layoutMargins = UIEdgeInsetsZero
    }
    
    //MARK: - Protocol Conformance -
    //MARK: BeaconManagerDelegate
    func didReceiveSighting(transmitter: FYXTransmitter, strength: NSNumber) {
        if let currentActiveBeacon = activeBeacon {
            if isActiveBeacon(transmitter.identifier) {
                viewModel?.sawBeacon(transmitter, rssiStrength: strength)
            }
        } else {
            activeBeacon = gimbalBeaconManager.retrieveLocalBeacon(transmitter.identifier)
            beaconTableView.reloadData()
        }
    }
    
    func didDepartFrom(transmitter: FYXTransmitter) {
        if let currentActiveBeacon = activeBeacon {
            if isActiveBeacon(transmitter.identifier) {
                viewModel?.departed(transmitter)
            }
        }
        beaconTableView.reloadData()
    }
    
    func discoveredNewBeacon(transmitter: CHABeacon) {
        beaconTableView.reloadData()
    }
    
    //MARK: UITableViewDataSource and Delegate
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
         return gimbalBeaconManager.sightedBeacons.count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        var cell = viewModel?.configureCell(tableView, indexPath: indexPath, beacon: gimbalBeaconManager.sightedBeacons[indexPath.row])
        return cell!
    }
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        tableView.deselectRowAtIndexPath(indexPath, animated: true)
        activeBeacon = gimbalBeaconManager.sightedBeacons[indexPath.row]
    }
    
    //MARK: Helper Functions
    func isActiveBeacon(identifier: NSString) -> Bool {
        return activeBeacon?.identifier == identifier
    }
}

