//
//  InitialViewModel.swift
//  SwiftGimbal
//
//  Created by Michael Thongvanh on 11/26/14.
//  Copyright (c) 2014 Chisel Apps. All rights reserved.
//

import Foundation
//MARK: - Protocol Declarations -
protocol BeaconTableViewDelegate {
    
}

//MARK: Enumerations -

class InitialViewModel: NSObject {
    weak var parentView: UIView?
    var pulseView: PulseView?
    var itemStrengthLabel: UILabel?
    var transmitterLabel: UILabel?
    var beaconTableView: UITableView?
    
    class func viewModel(parentView: UIView) -> InitialViewModel {
        var model: InitialViewModel = InitialViewModel()
        model.parentView = parentView
        return model
    }
    
    func setupViews() {
        pulseView = PulseView(frame: CGRectMake(0, 0, 150, 150))
        parentView?.addSubview(pulseView!)
        // ensure pulseView isn't obscuring the labels
        parentView?.bringSubviewToFront(itemStrengthLabel!)
        parentView?.bringSubviewToFront(transmitterLabel!)
        
        var centerXConstraint = NSLayoutConstraint(item: pulseView!, attribute: NSLayoutAttribute.CenterX, relatedBy: NSLayoutRelation.Equal, toItem: parentView, attribute: NSLayoutAttribute.CenterX, multiplier: 1.0, constant: 0)
        var centerYConstraint = NSLayoutConstraint(item: pulseView!, attribute: NSLayoutAttribute.CenterY, relatedBy: NSLayoutRelation.Equal, toItem: parentView, attribute: NSLayoutAttribute.CenterY, multiplier: 1.0, constant: 0)
        parentView?.addConstraints([centerXConstraint,centerYConstraint])
        
        pulseView?.growShrinkCircle(true, duration: 0.85, size: nil)
    }
    
    func configureCell(tableView: UITableView, indexPath: NSIndexPath, beacon: CHABeacon) -> UITableViewCell {
        var cell = tableView.dequeueReusableCellWithIdentifier("beaconCell", forIndexPath: indexPath) as UITableViewCell
        cell.textLabel.text = beacon.identifier
        return cell
    }
    
    func sawBeacon(beacon: FYXTransmitter, rssiStrength: NSNumber) {
        pulseView?.changePulseColor(beacon, rssiStrength: rssiStrength)
        updateLabels(rssiStrength: rssiStrength, beacon: beacon)
    }
    
    func departed(beacon: FYXTransmitter) {
        itemStrengthLabel?.text = "0"
        transmitterLabel?.text = ""
        pulseView?.departed()
    }
    
    func updateLabels(rssiStrength strength: NSNumber, beacon: FYXTransmitter) {
        itemStrengthLabel?.text = "\(strength)".stringByTrimmingCharactersInSet(NSCharacterSet(charactersInString: "-"))
        transmitterLabel?.text = "\(beacon.identifier)"
    }
}