//
//  ViewController.swift
//  SwiftGimbal
//
//  Created by Michael Thongvanh on 11/25/14.
//  Copyright (c) 2014 Chisel Apps. All rights reserved.
//

import UIKit

class ViewController: UIViewController, BeaconManagerDelegate,UITableViewDelegate  {
    //MARK: Properties
    var gimbalBeaconManager: GimbalBeaconManager!
    var viewModel: InitialViewModel?
    var pulseView: PulseView?
    
    @IBOutlet weak var sightingLabel: UILabel!
    @IBOutlet weak var transmitterNameLabel: UILabel!
    
    
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
    }
    
    //MARK: - Protocol Conformance -
    //MARK: BeaconManagerDelegate
    func didReceiveSighting(transmitter: FYXTransmitter, strength: NSNumber) {
        viewModel?.sawBeacon(transmitter, rssiStrength: strength)
    }
    
    func didDepartFrom(transmitter: FYXTransmitter) {
        viewModel?.departed(transmitter)
    }

}

