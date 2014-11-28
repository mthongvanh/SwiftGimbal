//
//  InitialViewModel.swift
//  SwiftGimbal
//
//  Created by Michael Thongvanh on 11/26/14.
//  Copyright (c) 2014 Chisel Apps. All rights reserved.
//

import Foundation

class InitialViewModel: NSObject {
    weak var parentView: UIView?
    var pulseView: PulseView?
    var itemStrengthLabel: UILabel?
    var transmitterLabel: UILabel?
    
    class func viewModel(parentView: UIView) -> InitialViewModel {
        var model: InitialViewModel = InitialViewModel()
        model.parentView = parentView
        return model
    }
    
    func setupViews() {
        pulseView = PulseView(frame: CGRectMake(0, 0, 150, 150))
        parentView?.addSubview(pulseView!)
        parentView?.bringSubviewToFront(itemStrengthLabel!)
        parentView?.bringSubviewToFront(transmitterLabel!)
        
        var centerXConstraint = NSLayoutConstraint(item: pulseView!, attribute: NSLayoutAttribute.CenterX, relatedBy: NSLayoutRelation.Equal, toItem: parentView, attribute: NSLayoutAttribute.CenterX, multiplier: 1.0, constant: 0)
        var centerYConstraint = NSLayoutConstraint(item: pulseView!, attribute: NSLayoutAttribute.CenterY, relatedBy: NSLayoutRelation.Equal, toItem: parentView, attribute: NSLayoutAttribute.CenterY, multiplier: 1.0, constant: 0)
        parentView?.addConstraints([centerXConstraint,centerYConstraint])
        
        pulseView?.growShrinkCircle(true, duration: 0.85, size: nil)
    }
    
    func sawBeacon(beacon: FYXTransmitter, rssiStrength: NSNumber) {
        pulseView?.changePulseSize(beacon, rssiStrength: rssiStrength)
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